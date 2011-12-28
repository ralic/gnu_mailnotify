/* 
 * Copyright (c) 2004 Jean-Yves Lefort <jylefort@brutele.be>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#include "config.h"
#include <stdio.h>		/* required by stdlib.h on Darwin */
#include <stdlib.h>		/* required by sys/socket.h on Darwin */
#include <stdarg.h>
#include <string.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <glib.h>
#include <glib/gi18n.h>
#include <eel/eel-alert-dialog.h>
#ifdef WITH_SSL
#include <openssl/err.h>
#include "mn-ssl.h"
#endif /* WITH_SSL */
#ifdef WITH_SASL
#include <sasl/sasl.h>
#include <sasl/saslutil.h>
#include "mn-sasl.h"
#endif /* WITH_SASL */
#include "mn-util.h"
#include "mn-client-session.h"
#include "mn-conf.h"

/*** cpp *********************************************************************/

#define READ_BUFSIZE				2048
  
/*** types *******************************************************************/

struct _MNClientSession
{
  MNClientSessionState		*states;
  MNClientSessionCallbacks	*callbacks;
  char				*hostname;
  int				port;
  int				s;
  MNClientSessionState		*state;
  char				*error;
  MNClientSessionPrivate	*private;
  GByteArray			*input_buffer;
  unsigned int			bytes_to_remove;
  
#ifdef WITH_SSL
  SSL				*ssl;
#endif

#ifdef WITH_SASL
  gboolean			sasl_available;
  sasl_conn_t			*sasl_conn;
  const char			*sasl_initial_clientout;
  unsigned int			sasl_initial_clientoutlen;
  const char			*sasl_clientout;
  unsigned int			sasl_clientoutlen;
  int				sasl_ssf;
  unsigned int			sasl_maxoutbuf;
#endif /* WITH_SASL */
};

/*** variables ***************************************************************/

#ifdef WITH_SASL
static sasl_callback_t sasl_callbacks[] = {
  { SASL_CB_USER, NULL, NULL },
  { SASL_CB_AUTHNAME, NULL, NULL },
  { SASL_CB_PASS, NULL, NULL },

  { SASL_CB_LIST_END, NULL, NULL }
};
#endif /* WITH_SASL */

/*** functions ***************************************************************/

static struct addrinfo *mn_client_session_resolve (MNClientSession *session);
static int mn_client_session_connect (MNClientSession *session, struct addrinfo *addrinfo);

#ifdef WITH_SSL
static gboolean mn_client_session_ssl_verify (MNClientSession *session);
static gboolean mn_client_session_run_untrusted_dialog (const char *hostname,
							const char *reason);
#endif

static int mn_client_session_enter_state (MNClientSession *session, int id);
static gboolean mn_client_session_handle_input (MNClientSession *session, const char *input);

static void mn_client_session_prepare_input_buffer (MNClientSession *session);

#ifdef WITH_SASL
static int mn_client_session_write_base64 (MNClientSession *session,
					   const char *buf,
					   unsigned int len);
static gboolean mn_client_session_sasl_fill_interact (MNClientSession *session,
						      sasl_interact_t *interact,
						      const char *unknown_notice);
static char *mn_client_session_sasl_get_ip_port (const struct sockaddr *addr);
#endif /* WITH_SASL */

/*** implementation **********************************************************/

gboolean
mn_client_session_run (MNClientSessionState *states,
		       MNClientSessionCallbacks *callbacks,
#ifdef WITH_SSL
		       gboolean use_ssl,
#endif
		       const char *hostname,
		       int port,
		       MNClientSessionPrivate *private,
		       GError **err)
{
  MNClientSession session;
  struct addrinfo *addrinfo;
  const char *line;

  g_return_val_if_fail(states != NULL, FALSE);
  g_return_val_if_fail(callbacks != NULL, FALSE);
  g_return_val_if_fail(callbacks->response_new != NULL, FALSE);
  g_return_val_if_fail(callbacks->response_free != NULL, FALSE);
  g_return_val_if_fail(hostname != NULL, FALSE);

  memset(&session, 0, sizeof(session));
  session.states = states;
  session.callbacks = callbacks;
  session.hostname = g_strdup(hostname);
  session.port = port;
  session.private = private;

  addrinfo = mn_client_session_resolve(&session);
  if (! addrinfo)
    goto end;

  session.s = mn_client_session_connect(&session, addrinfo);
  freeaddrinfo(addrinfo);
  if (session.s < 0)
    goto end;

#ifdef WITH_SSL
  if (use_ssl)
    {
      if (! mn_client_session_enable_ssl(&session))
	goto end;
    }
#endif /* WITH_SSL */

  mn_client_session_enter_state(&session, MN_CLIENT_SESSION_INITIAL_STATE);

  session.input_buffer = g_byte_array_new();
  while ((line = mn_client_session_read_line(&session)))
    if (! mn_client_session_handle_input(&session, line))
      break;
  g_byte_array_free(session.input_buffer, TRUE);
  
 end:
  g_free(session.hostname);
  if (session.s >= 0)
    while (close(session.s) < 0 && errno == EINTR);
#ifdef WITH_SSL
  if (session.ssl)
    SSL_free(session.ssl);
#endif /* WITH_SSL */
#ifdef WITH_SASL
  if (session.sasl_available)
    {
      if (session.sasl_conn)
	sasl_dispose(&session.sasl_conn);
      mn_sasl_unuse();
    }
#endif /* WITH_SASL */
  if (session.error)
    {
      g_set_error(err, 0, 0, "%s", session.error);
      g_free(session.error);
      return FALSE;
    }
  else
    return TRUE;
}

static struct addrinfo *
mn_client_session_resolve (MNClientSession *session)
{
  char *servname;
  struct addrinfo hints;
  struct addrinfo *addrinfo;
  int status;

  g_return_val_if_fail(session != NULL, NULL);

  memset(&hints, 0, sizeof(hints));
#ifdef WITH_IPV6
  hints.ai_family = PF_UNSPEC;
#else
  hints.ai_family = PF_INET;
#endif /* WITH_IPV6 */
  hints.ai_socktype = SOCK_STREAM;

  mn_client_session_notice(session, _("resolving %s"), session->hostname);

  servname = g_strdup_printf("%i", session->port);
  status = getaddrinfo(session->hostname, servname, &hints, &addrinfo);
  g_free(servname);

  if (status == 0)
    return addrinfo;
  else
    {
      mn_client_session_error(session, _("unable to resolve %s: %s"), session->hostname, gai_strerror(status));
      return NULL;
    }
}

static int
mn_client_session_connect (MNClientSession *session, struct addrinfo *addrinfo)
{
  struct addrinfo *a;

  g_return_val_if_fail(session != NULL, -1);
  g_return_val_if_fail(addrinfo != NULL, -1);

  /* iterate over addrinfo to find a working address (RFC 3484) */
  for (a = addrinfo; a; a = a->ai_next)
    {
      int status;
      int s;
      char ip[NI_MAXHOST];

      status = getnameinfo(a->ai_addr,
			   a->ai_addrlen,
			   ip,
			   sizeof(ip),
			   NULL,
			   0,
			   NI_NUMERICHOST);
      g_return_val_if_fail(status == 0, -1);
      
      if (a->ai_family == AF_INET)
	((struct sockaddr_in *) a->ai_addr)->sin_port = g_htons(session->port);
#ifdef WITH_IPV6
      else if (a->ai_family == AF_INET6)
	((struct sockaddr_in6 *) a->ai_addr)->sin6_port = g_htons(session->port);
#endif /* WITH_IPV6 */
      else
	{
	  mn_client_session_notice(session, _("%s: unsupported address family"), ip);
	  continue;
	}

      s = socket(a->ai_family, SOCK_STREAM, 0);
      if (s < 0)
	{
	  mn_client_session_notice(session, _("%s: unable to create socket: %s"), ip, g_strerror(errno));
	  continue;
	}

      mn_client_session_notice(session, _("connecting to %s (%s) port %i"), session->hostname, ip, session->port);
      if (connect(s, a->ai_addr, a->ai_addrlen) < 0)
	{
	  mn_client_session_notice(session, _("unable to connect: %s"), g_strerror(errno));
	  close(s);
	}
      else
	{
	  mn_client_session_notice(session, _("connected successfully"));
	  return s;		/* success */
	}
    }
  
  /* if reached, we couldn't find a working address */
  mn_client_session_error(session, _("unable to connect to %s"), session->hostname);
  return -1;
}

#ifdef WITH_SSL
gboolean
mn_client_session_enable_ssl (MNClientSession *session)
{
  SSL_CTX *ctx;
  GError *err = NULL;
  
  g_return_val_if_fail(session != NULL, FALSE);

  ctx = mn_ssl_init(&err);
  if (! ctx)
    {
      mn_client_session_error(session, _("unable to initialize the OpenSSL library: %s"), err->message);
      g_error_free(err);
      return FALSE;
    }
  
  session->ssl = SSL_new(ctx);
  if (! session->ssl)
    {
      mn_client_session_error(session, _("unable to create a SSL/TLS object: %s"), mn_ssl_get_error());
      return FALSE;
    }

  if (! SSL_set_fd(session->ssl, session->s))
    {
      mn_client_session_error(session, _("unable to set the SSL/TLS file descriptor: %s"), mn_ssl_get_error());
      return FALSE;
    }

  if (SSL_connect(session->ssl) != 1)
    {
      mn_client_session_error(session, _("unable to perform the SSL/TLS handshake: %s"), mn_ssl_get_error());
      return FALSE;
    }
  
  if (! mn_client_session_ssl_verify(session))
    {
      mn_client_session_error(session, _("untrusted server"));
      return FALSE;
    }
  
  mn_client_session_notice(session, _("a SSL/TLS layer is now active (%s, %s %i-bit)"),
			   SSL_get_version(session->ssl),
			   SSL_get_cipher(session->ssl),
			   SSL_get_cipher_bits(session->ssl, NULL));

  return TRUE;
}

static gboolean
mn_client_session_ssl_verify (MNClientSession *session)
{
  X509 *cert;
  gboolean status = FALSE;

  g_return_val_if_fail(session->ssl != NULL, FALSE);

  cert = SSL_get_peer_certificate(session->ssl);
  if (cert)
    {
      long verify_result;

      verify_result = SSL_get_verify_result(session->ssl);
      if (verify_result == X509_V_OK)
	status = TRUE;
      else
	{
	  unsigned char md5sum[16];
	  unsigned char fingerprint[40];
	  int md5len;
	  int i;
	  unsigned char *f;
	  GSList *gconf_fingerprints;

	  /* calculate the MD5 hash of the raw certificate */
	  md5len = sizeof(md5sum);
	  X509_digest(cert, EVP_md5(), md5sum, &md5len);
	  for (i = 0, f = fingerprint; i < 16; i++, f += 3)
	    sprintf(f, "%.2x%c", md5sum[i], i != 15 ? ':' : '\0');

	  gconf_fingerprints = eel_gconf_get_string_list(MN_CONF_TRUSTED_X509_CERTIFICATES);

	  if (mn_g_str_slist_find(gconf_fingerprints, fingerprint) != NULL)
	    status = TRUE;
	  else
	    {
	      char *reason;

	      reason = g_strdup_printf(_("%s, fingerprint: %s"),
				       X509_verify_cert_error_string(verify_result),
				       fingerprint);

	      if (mn_client_session_run_untrusted_dialog(session->hostname, reason))
		{
		  status = TRUE;
		  gconf_fingerprints = g_slist_append(gconf_fingerprints, g_strdup(fingerprint));
		  eel_gconf_set_string_list(MN_CONF_TRUSTED_X509_CERTIFICATES, gconf_fingerprints);
		}
	    }
	  
	  eel_g_slist_free_deep(gconf_fingerprints);
	}

      X509_free(cert);
    }
  else
    {
      char *server;
      GSList *gconf_servers = NULL;

      server = g_strdup_printf("%s:%i", session->hostname, session->port);
      gconf_servers = eel_gconf_get_string_list(MN_CONF_TRUSTED_SERVERS);

      if (mn_g_str_slist_find(gconf_servers, server) != NULL)
	status = TRUE;
      else
	{
	  if (mn_client_session_run_untrusted_dialog(session->hostname, _("missing certificate")))
	    {
	      status = TRUE;
	      gconf_servers = g_slist_append(gconf_servers, g_strdup(server));
	      eel_gconf_set_string_list(MN_CONF_TRUSTED_SERVERS, gconf_servers);
	    }
	}

      g_free(server);
      eel_g_slist_free_deep(gconf_servers);
    }

  return status;
}

static gboolean
mn_client_session_run_untrusted_dialog (const char *hostname,
					const char *reason)
{
  GtkWidget *dialog;
  char *secondary;
  gboolean status;

  g_return_val_if_fail(hostname != NULL, FALSE);
  g_return_val_if_fail(reason != NULL, FALSE);

  secondary = g_strdup_printf(_("Mail Notification was unable to trust \"%s\" "
				"(%s). It is possible that someone is "
				"intercepting your communication to obtain "
				"your confidential information.\n"
				"\n"
				"You should only connect to the server if you "
				"are certain you are connected to \"%s\". "
				"If you choose to connect to the server, this "
				"message will not be shown again."),
			      hostname, reason, hostname);
  
  GDK_THREADS_ENTER();

  dialog = eel_alert_dialog_new(NULL,
				GTK_DIALOG_DESTROY_WITH_PARENT,
				GTK_MESSAGE_WARNING,
				GTK_BUTTONS_NONE,
				_("Connect to untrusted server?"),
				secondary,
				NULL);

  gtk_dialog_add_button(GTK_DIALOG(dialog), GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL);
  gtk_dialog_add_button(GTK_DIALOG(dialog), _("Co_nnect"), GTK_RESPONSE_OK);
			
  status = gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_OK;
  gtk_widget_destroy(dialog);
  
  gdk_flush();
  GDK_THREADS_LEAVE();

  g_free(secondary);
  return status;
}
#endif /* WITH_SSL */

static int
mn_client_session_enter_state (MNClientSession *session, int id)
{
  int i;
  
  g_return_val_if_fail(session != NULL, 0);

  for (i = 0; session->states[i].id; i++)
    if (session->states[i].id == id)
      {
	session->state = &session->states[i];
	return session->state->enter_cb
	  ? session->state->enter_cb(session, session->private)
	  : MN_CLIENT_SESSION_RESULT_CONTINUE;
      }

  g_return_val_if_reached(0);
}

static gboolean
mn_client_session_handle_input (MNClientSession *session, const char *input)
{
  MNClientSessionResponse *response;
  gboolean cont = TRUE;

  g_return_val_if_fail(session != NULL, FALSE);
  g_return_val_if_fail(input != NULL, FALSE);

  response = session->callbacks->response_new(session, input, session->private);
  if (response)
    {
      int result;

      g_return_val_if_fail(session->state->handle_cb != NULL, FALSE);
      result = session->state->handle_cb(session, response, session->private);

    loop:
      switch (result)
	{
	case MN_CLIENT_SESSION_RESULT_CONTINUE:
	  break;

	case MN_CLIENT_SESSION_RESULT_BAD_RESPONSE_FOR_CONTEXT:
	  mn_client_session_error(session, _("response \"%s\" is not valid in current context"), input);
	  cont = FALSE;
	  break;
	  
	case MN_CLIENT_SESSION_RESULT_END:
	  cont = FALSE;
	  break;
	  
	case 0:			/* assertion failed somewhere */
	  g_return_val_if_reached(FALSE);

	default:
	  if (result > 0)	/* state */
	    result = mn_client_session_enter_state(session, result);
	  else			/* custom result */
	    {
	      g_return_val_if_fail(session->callbacks->custom_handler != NULL, FALSE);
	      result = session->callbacks->custom_handler(session, response, result, session->private);
	    }
	  goto loop;
	}

      session->callbacks->response_free(session, response, session->private);
    }
  else
    {
      mn_client_session_error(session, _("unable to parse response \"%s\""), input);
      cont = FALSE;
    }

  return cont;
}

static void
mn_client_session_prepare_input_buffer (MNClientSession *session)
{
  g_return_if_fail(session != NULL);

  if (session->bytes_to_remove)
    {
      g_byte_array_remove_range(session->input_buffer, 0, session->bytes_to_remove);
      session->bytes_to_remove = 0;
    }
}

static gboolean
mn_client_session_fill_input_buffer (MNClientSession *session)
{
  char buf[READ_BUFSIZE];
  ssize_t bytes_read;
  const char *in = NULL;
  unsigned int inlen;
  
  g_return_val_if_fail(session != NULL, FALSE);

  if (session->callbacks->pre_read)
    session->callbacks->pre_read(session, session->private);

#ifdef WITH_SSL
  if (session->ssl)
    bytes_read = SSL_read(session->ssl, buf, sizeof(buf));
  else
#endif /* WITH_SSL */
    do
      bytes_read = read(session->s, buf, sizeof(buf));
    while (bytes_read < 0 && errno == EINTR);
	  
  if (session->callbacks->post_read)
    session->callbacks->post_read(session, session->private);

  if (bytes_read <= 0)
    {
#ifdef WITH_SSL
      if (session->ssl)
	mn_client_session_error(session, _("unable to read from server: %s"), mn_ssl_get_error());
      else
#endif /* WITH_SSL */
	{
	  if (bytes_read == 0)
	    mn_client_session_error(session, _("unable to read from server: EOF"));
	  else
	    mn_client_session_error(session, _("unable to read from server: %s"), g_strerror(errno));
	}
      return FALSE;
    }

#ifdef WITH_SASL
  if (session->sasl_ssf)
    {
      if (sasl_decode(session->sasl_conn, buf, bytes_read, &in, &inlen) != SASL_OK)
	{
	  mn_client_session_error(session, _("unable to decode data using SASL: %s"), sasl_errdetail(session->sasl_conn));
	  return FALSE;
	}
    }
#endif /* WITH_SASL */

  if (! in)
    {
      in = buf;
      inlen = bytes_read;
    }

  g_byte_array_append(session->input_buffer, in, inlen);
  return TRUE;
}

/**
 * mn_client_session_read:
 * @session: a #MNClientSession object to read from
 * @nbytes: the number of bytes to read
 *
 * Reads exactly @nbytes from @session. If an error occurs,
 * mn_client_session_error() will be called on @session.
 *
 * Return value: a pointer to a buffer containing @nbytes on success,
 *               %NULL on failure. The pointer will be valid until the
 *               next call to mn_client_session_read() or
 *               mn_client_session_read_line().
 **/
gconstpointer
mn_client_session_read (MNClientSession *session, unsigned int nbytes)
{
  GString *printable;
  int i;

  g_return_val_if_fail(session != NULL, FALSE);
  g_return_val_if_fail(session->input_buffer != NULL, FALSE);
  g_return_val_if_fail(nbytes >= 0, FALSE);

  mn_client_session_prepare_input_buffer(session);

  while (session->input_buffer->len < nbytes)
    if (! mn_client_session_fill_input_buffer(session))
      return FALSE;

  session->bytes_to_remove = nbytes;

  printable = g_string_new(NULL);
  for (i = 0; i < nbytes; i++)
    if (g_ascii_isprint(session->input_buffer->data[i]))
      g_string_append_c(printable, session->input_buffer->data[i]);
    else
      g_string_append_printf(printable, "<%02X>", (int) session->input_buffer->data[i]);
  mn_client_session_notice(session, "< %s", printable->str);
  g_string_free(printable, TRUE);
  
  return session->input_buffer->data;
}

/**
 * mn_client_session_read_line:
 * @session: a #MNClientSession object to read from
 *
 * Reads a crlf-terminated line from @session. If an error occurs,
 * mn_client_session_error() will be called on @session.
 *
 * Return value: the line read on success, %NULL on failure. The
 *               pointer will be valid until the next call to
 *               mn_client_session_read() or mn_client_session_read_line().
 **/
const char *
mn_client_session_read_line (MNClientSession *session)
{
  char *terminator;
  const char *line;

  g_return_val_if_fail(session != NULL, NULL);
  g_return_val_if_fail(session->input_buffer != NULL, NULL);

  mn_client_session_prepare_input_buffer(session);

  while (! (session->input_buffer->data
	    && (terminator = g_strstr_len(session->input_buffer->data,
					  session->input_buffer->len,
					  "\r\n"))))
    if (! mn_client_session_fill_input_buffer(session))
      return NULL;
    
  *terminator = 0;
  session->bytes_to_remove = terminator - (char *) session->input_buffer->data + 2;

  line = session->input_buffer->data;
  mn_client_session_notice(session, "< %s", line);

  return line;
}

int
mn_client_session_write (MNClientSession *session,
			 const char *format,
			 ...)
{
  va_list args;
  char *str;
  char *full;
  unsigned int len;
  GByteArray *array = NULL;
  ssize_t bytes_written;
  int result = MN_CLIENT_SESSION_RESULT_CONTINUE;
  
  g_return_val_if_fail(session != NULL, 0);
  g_return_val_if_fail(format != NULL, 0);
  
  va_start(args, format);
  str = g_strdup_vprintf(format, args);
  va_end(args);

  mn_client_session_notice(session, "> %s", str);
  full = g_strconcat(str, "\r\n", NULL);
  g_free(str);
  len = strlen(full);

#ifdef WITH_SASL
  if (session->sasl_ssf)
    {
      unsigned int start = 0;

      array = g_byte_array_new();
      while (len > 0)
	{
	  unsigned int chunk_len;
	  const char *out;
	  unsigned int outlen;
	  
	  chunk_len = MIN(len, session->sasl_maxoutbuf);
	  if (sasl_encode(session->sasl_conn, full + start, chunk_len, &out, &outlen) != SASL_OK)
	    {
	      result = mn_client_session_error(session, _("unable to encode data using SASL: %s"), sasl_errdetail(session->sasl_conn));
	      goto end;
	    }
	  
	  g_byte_array_append(array, out, outlen);

	  start += chunk_len;
	  len -= chunk_len;
	}
    }
#endif /* WITH_SASL */

  if (! array)
    {
      array = g_byte_array_sized_new(len);
      g_byte_array_append(array, full, len);
    }
  
#ifdef WITH_SSL
  if (session->ssl)
    bytes_written = SSL_write(session->ssl, array->data, array->len);
  else
#endif /* WITH_SSL */
    do
      bytes_written = write(session->s, array->data, array->len);
    while (bytes_written < 0 && errno == EINTR);

  if (bytes_written <= 0)
    {
#ifdef WITH_SSL
      if (session->ssl)
	result = mn_client_session_error(session, _("unable to write to server: %s"), mn_ssl_get_error());
      else
#endif /* WITH_SSL */
	{
	  if (bytes_written == 0)
	    result = mn_client_session_error(session, _("unable to write to server: EOF"));
	  else
	    result = mn_client_session_error(session, _("unable to write to server: %s"), g_strerror(errno));
	}
    }

#ifdef WITH_SASL
 end:
#endif
  g_free(full);
  g_byte_array_free(array, TRUE);

  return result;
}

#ifdef WITH_SASL
static int
mn_client_session_write_base64 (MNClientSession *session,
				const char *buf,
				unsigned int len)
{
  unsigned int buf64len = len * 2; /* Base64 is 33% larger than the data it encodes */
  char buf64[buf64len];
  unsigned int outlen;
  char *str;
  int result;

  g_return_val_if_fail(session != NULL, 0);
  g_return_val_if_fail(buf != NULL, 0);
  
  result = sasl_encode64(buf, len, buf64, buf64len, &outlen);
  if (result != SASL_OK)
    return mn_client_session_error(session, _("unable to encode Base64: %s"), sasl_errstring(result, NULL, NULL));
  
  str = g_strndup(buf64, outlen);
  result = mn_client_session_write(session, "%s", str);
  g_free(str);

  return result;
}

static gboolean
mn_client_session_sasl_fill_interact (MNClientSession *session,
				      sasl_interact_t *interact,
				      const char *unknown_notice)
{
  sasl_interact_t *i;

  g_return_val_if_fail(session != NULL, FALSE);
  g_return_val_if_fail(interact != NULL, FALSE);

  for (i = interact; i->id; i++)
    {
      const char *data;

      switch (i->id)
	{
	case SASL_CB_USER:
	case SASL_CB_AUTHNAME:
	  data = session->callbacks->sasl_get_username(session, session->private);
	  break;
	  
	case SASL_CB_PASS:
	  data = session->callbacks->sasl_get_password(session, session->private);
	  break;

	default:
	  data = NULL;
	  mn_client_session_notice(session, unknown_notice);
	};

      if (data)
	{
	  i->result = data;
	  i->len = strlen(data);
	}
      else
	return FALSE;
    }

  return TRUE;
}

static char *
mn_client_session_sasl_get_ip_port (const struct sockaddr *addr)
{
#ifdef WITH_IPV6
  char buf[INET6_ADDRSTRLEN];
#else
  char buf[INET_ADDRSTRLEN];
#endif /* WITH_IPV6 */
  int port;

  g_return_val_if_fail(addr != NULL, NULL);

  if (addr->sa_family == AF_INET)
    {
      struct sockaddr_in *in = (struct sockaddr_in *) addr;

      if (! inet_ntop(addr->sa_family, &in->sin_addr, buf, sizeof(buf)))
	return NULL;
      port = g_ntohs(in->sin_port);
    }
#ifdef WITH_IPV6
  else if (addr->sa_family == AF_INET6)
    {
      struct sockaddr_in6 *in6 = (struct sockaddr_in6 *) addr;

      if (! inet_ntop(addr->sa_family, &in6->sin6_addr, buf, sizeof(buf)))
	return NULL;
      port = g_ntohs(in6->sin6_port);
    }
#endif
  else
    return NULL;
  
  return g_strdup_printf("%s;%i", buf, port);
}

gboolean
mn_client_session_sasl_authentication_start (MNClientSession *session,
					     const char *service,
					     GSList *mechanisms,
					     const char *forced_mechanism,
					     const char **used_mechanism,
					     gboolean initial_response)
{
  GError *err = NULL;
  int result;
  struct sockaddr name;
  socklen_t namelen;
  char *local_ip_port = NULL;
  char *remote_ip_port = NULL;

  g_return_val_if_fail(session != NULL, 0);
  g_return_val_if_fail(session->callbacks->sasl_get_username != NULL, FALSE);
  g_return_val_if_fail(session->callbacks->sasl_get_password != NULL, FALSE);
  g_return_val_if_fail(service != NULL, 0);
  g_return_val_if_fail(mechanisms != NULL, 0);

  session->sasl_available = mn_sasl_use(&err);
  if (! session->sasl_available)
    {
      mn_client_session_notice(session, _("unable to initialize the SASL library: %s"), err->message);
      g_error_free(err);
      return FALSE;
    }
  
  namelen = sizeof(name);
  if (getsockname(session->s, &name, &namelen) >= 0)
    local_ip_port = mn_client_session_sasl_get_ip_port(&name);
  else
    mn_client_session_notice(session, _("unable to retrieve local address of socket: %s"), g_strerror(errno));
  
  namelen = sizeof(name);
  if (getpeername(session->s, &name, &namelen) >= 0)
    remote_ip_port = mn_client_session_sasl_get_ip_port(&name);
  else
    mn_client_session_notice(session, _("unable to retrieve remote address of socket: %s"), g_strerror(errno));

  result = sasl_client_new(service,
			   session->hostname,
			   local_ip_port,
			   remote_ip_port,
			   sasl_callbacks,
			   0,
			   &session->sasl_conn);

  g_free(local_ip_port);
  g_free(remote_ip_port);

  if (result == SASL_OK)
    {
      sasl_security_properties_t security;
      sasl_interact_t *interact = NULL;
      GString *mechanisms_string;
      GSList *l;
      
      security.min_ssf = 0;
      security.max_ssf = 256;
      security.maxbufsize = READ_BUFSIZE;
      /* only permit plaintext mechanisms if SSL is in use */
#ifdef WITH_SSL
      if (session->ssl)
	security.security_flags = 0;
      else
#endif /* WITH_SSL */
	security.security_flags = SASL_SEC_NOPLAINTEXT;
      security.property_names = NULL;
      security.property_values = NULL;

      if (sasl_setprop(session->sasl_conn, SASL_SEC_PROPS, &security) != SASL_OK)
	mn_client_session_notice(session, _("warning: unable to set SASL security properties: %s"), sasl_errdetail(session->sasl_conn));
      
      mechanisms_string = g_string_new(NULL);
      if (forced_mechanism)
	g_string_append(mechanisms_string, forced_mechanism);
      else
	MN_LIST_FOREACH(l, mechanisms)
          {
	    if (*mechanisms_string->str)
	      g_string_append_c(mechanisms_string, ' ');
	    g_string_append(mechanisms_string, l->data);
	  }

      do
	{
	  result = sasl_client_start(session->sasl_conn,
				     mechanisms_string->str,
				     &interact,
				     initial_response ? &session->sasl_initial_clientout : NULL,
				     initial_response ? &session->sasl_initial_clientoutlen : NULL,
				     used_mechanism);

	  if (result == SASL_INTERACT)
	    {
	      if (! mn_client_session_sasl_fill_interact(session, interact, _("unable to start SASL authentication: SASL asked for something we did not know")))
		break;
	    }
	}
      while (result == SASL_INTERACT);

      g_string_free(mechanisms_string, TRUE);

      switch (result)
	{
	case SASL_OK:
	case SASL_CONTINUE:
	  return TRUE;

	case SASL_INTERACT:
	  /* could not fill interaction, nop */
	  break;

	default:
	  mn_client_session_notice(session, _("unable to start SASL authentication: %s"), sasl_errdetail(session->sasl_conn));
	}
    }
  else
    mn_client_session_notice(session, _("unable to create a SASL connection: %s"), sasl_errdetail(session->sasl_conn));

  return FALSE;
}

int
mn_client_session_sasl_authentication_step (MNClientSession *session,
					    const char *input)
{
  g_return_val_if_fail(session != NULL, 0);
  g_return_val_if_fail(input != NULL, 0);
  
  if (*input)
    {
      if (! session->sasl_initial_clientout)
	{
	  unsigned int inlen = strlen(input);
	  char buf[inlen];
	  unsigned int outlen;
	  int result;
	  
	  result = sasl_decode64(input, inlen, buf, inlen, &outlen);
	  if (result == SASL_OK)
	    {
	      sasl_interact_t *interact = NULL;
	      
	      do 
		{
		  result = sasl_client_step(session->sasl_conn,
					    buf,
					    outlen,
					    &interact,
					    &session->sasl_clientout,
					    &session->sasl_clientoutlen);
		  
		  if (result == SASL_INTERACT)
		    {
		      if (! mn_client_session_sasl_fill_interact(session, interact, _("SASL asked for something we did not know, aborting SASL authentication")))
			break;
		    }
		}
	      while (result == SASL_INTERACT);
	      
	      switch (result)
		{
		case SASL_OK:
		case SASL_CONTINUE:
		  return mn_client_session_write_base64(session, session->sasl_clientout, session->sasl_clientoutlen);
		  
		case SASL_INTERACT:
		  /* could not fill interaction, abort */
		  return mn_client_session_write(session, "*");
		  
		default:
		  mn_client_session_notice(session, _("%s, aborting SASL authentication"), sasl_errdetail(session->sasl_conn));
		  return mn_client_session_write(session, "*");
		}
	    }
	  else			/* compliance error */
	    return mn_client_session_error(session, _("unable to decode Base64 input from server: %s"), sasl_errstring(result, NULL, NULL));
	}
      else
	return mn_client_session_error(session, _("the server sent a SASL challenge, but there was a pending initial SASL client response"));
    }
  else
    {
      if (session->sasl_initial_clientout)
	{
	  int result;
	  
	  result = mn_client_session_write_base64(session, session->sasl_initial_clientout, session->sasl_initial_clientoutlen);
	  session->sasl_initial_clientout = NULL;
	  session->sasl_initial_clientoutlen = 0;
	  return result;
	}
      else
	return mn_client_session_error(session, _("the server did not send a SASL challenge, but there was no pending initial SASL client response"));
    }
}

gboolean
mn_client_session_sasl_authentication_done (MNClientSession *session)
{
  gconstpointer ptr;

  g_return_val_if_fail(session != NULL, FALSE);

  if (sasl_getprop(session->sasl_conn, SASL_SSF, &ptr) == SASL_OK)
    {
      const int *ssf = ptr;

      if (*ssf)
	{
	  if (sasl_getprop(session->sasl_conn, SASL_MAXOUTBUF, &ptr) == SASL_OK)
	    {
	      const unsigned int *maxoutbuf = ptr;

	      session->sasl_ssf = *ssf;
	      session->sasl_maxoutbuf = *maxoutbuf;

	      if (session->sasl_ssf)
		mn_client_session_notice(session, _("a SASL security layer of strength factor %i is now active"), session->sasl_ssf);
	    }
	  else
	    {
	      /* a security layer is active but we can't retrieve maxoutbuf -> fatal */
	      mn_client_session_error(session, _("unable to get SASL_MAXOUTBUF property: %s"), sasl_errdetail(session->sasl_conn));
	      return FALSE;
	    }
	}
    }
  else
    mn_client_session_notice(session, _("warning: unable to get SASL_SSF property: %s"), sasl_errdetail(session->sasl_conn));

  return TRUE;
}

int
mn_client_session_sasl_get_ssf (MNClientSession *session)
{
  g_return_val_if_fail(session != NULL, FALSE);

  return session->sasl_ssf;
}
#endif /* WITH_SASL */

void
mn_client_session_notice (MNClientSession *session,
			  const char *format,
			  ...)
{
  g_return_if_fail(session != NULL);
  g_return_if_fail(format != NULL);

  if (session->callbacks->notice)
    {
      va_list args;
      char *str;

      va_start(args, format);
      str = g_strdup_vprintf(format, args);
      va_end(args);

      session->callbacks->notice(session, str, session->private);
      g_free(str);
    }
}

int
mn_client_session_error (MNClientSession *session,
			 const char *format,
			 ...)
{
  g_return_val_if_fail(session != NULL, 0);
  g_return_val_if_fail(format != NULL, 0);

  if (! session->error)
    {
      va_list args;

      va_start(args, format);
      session->error = g_strdup_vprintf(format, args);
      va_end(args);
    }

  return MN_CLIENT_SESSION_RESULT_END;
}
