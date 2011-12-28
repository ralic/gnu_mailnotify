/* Generated by GOB (v2.0.14)   (do not edit directly) */

/* End world hunger, donate to the World Food Programme, http://www.wfp.org */

#define GOB_VERSION_MAJOR 2
#define GOB_VERSION_MINOR 0
#define GOB_VERSION_PATCHLEVEL 14

#define selfp (self->_priv)

#include <string.h> /* memset() */

#include "mn-evolution-mailbox.h"

#include "mn-evolution-mailbox-private.h"

#ifdef G_LIKELY
#define ___GOB_LIKELY(expr) G_LIKELY(expr)
#define ___GOB_UNLIKELY(expr) G_UNLIKELY(expr)
#else /* ! G_LIKELY */
#define ___GOB_LIKELY(expr) (expr)
#define ___GOB_UNLIKELY(expr) (expr)
#endif /* G_LIKELY */

#line 33 "mn-evolution-mailbox.gob"

#include "config.h"
#include <glib/gi18n.h>
#include <libbonobo.h>
#include "mn-evolution.h"
#include "mn-mailbox-private.h"
#include "mn-reentrant-mailbox-private.h"
#include "mn-message.h"
#include "mn-util.h"
#include "mn-stock.h"
#include "mn-evolution-message.h"
#include "mn-evolution-glue-client.h"

static GStaticMutex listeners_mutex = G_STATIC_MUTEX_INIT;

#line 42 "mn-evolution-mailbox.c"
/* self casting macros */
#define SELF(x) MN_EVOLUTION_MAILBOX(x)
#define SELF_CONST(x) MN_EVOLUTION_MAILBOX_CONST(x)
#define IS_SELF(x) MN_IS_EVOLUTION_MAILBOX(x)
#define TYPE_SELF MN_TYPE_EVOLUTION_MAILBOX
#define SELF_CLASS(x) MN_EVOLUTION_MAILBOX_CLASS(x)

#define SELF_GET_CLASS(x) MN_EVOLUTION_MAILBOX_GET_CLASS(x)

/* self typedefs */
typedef MNEvolutionMailbox Self;
typedef MNEvolutionMailboxClass SelfClass;

/* here are local prototypes */
static void ___object_set_property (GObject *object, guint property_id, const GValue *value, GParamSpec *pspec);
static void ___object_get_property (GObject *object, guint property_id, GValue *value, GParamSpec *pspec);
static void mn_evolution_mailbox_class_init (MNEvolutionMailboxClass * class) G_GNUC_UNUSED;
static void mn_evolution_mailbox_init (MNEvolutionMailbox * self) G_GNUC_UNUSED;
static void ___3_mn_evolution_mailbox_seal (MNMailbox * mailbox) G_GNUC_UNUSED;
static void ___4_mn_evolution_mailbox_dispose (GObject * object) G_GNUC_UNUSED;
static void mn_evolution_mailbox_listener_cb (BonoboListener * listener, const char * event_name, const CORBA_any * any, CORBA_Environment * env, gpointer user_data) G_GNUC_UNUSED;
static void ___6_mn_evolution_mailbox_reentrant_check (MNReentrantMailbox * mailbox, unsigned long check_id) G_GNUC_UNUSED;

enum {
	PROP_0,
	PROP_URI,
	PROP_FOLDER_NAME
};

/* pointer to the class of our parent */
static MNReentrantMailboxClass *parent_class = NULL;

/* Short form macros */
#define self_listener_cb mn_evolution_mailbox_listener_cb
GType
mn_evolution_mailbox_get_type (void)
{
	static GType type = 0;

	if ___GOB_UNLIKELY(type == 0) {
		static const GTypeInfo info = {
			sizeof (MNEvolutionMailboxClass),
			(GBaseInitFunc) NULL,
			(GBaseFinalizeFunc) NULL,
			(GClassInitFunc) mn_evolution_mailbox_class_init,
			(GClassFinalizeFunc) NULL,
			NULL /* class_data */,
			sizeof (MNEvolutionMailbox),
			0 /* n_preallocs */,
			(GInstanceInitFunc) mn_evolution_mailbox_init,
			NULL
		};

		type = g_type_register_static (MN_TYPE_REENTRANT_MAILBOX, "MNEvolutionMailbox", &info, (GTypeFlags)0);
	}

	return type;
}

/* a macro for creating a new object of our type */
#define GET_NEW ((MNEvolutionMailbox *)g_object_new(mn_evolution_mailbox_get_type(), NULL))

/* a function for creating a new object of our type */
#include <stdarg.h>
static MNEvolutionMailbox * GET_NEW_VARG (const char *first, ...) G_GNUC_UNUSED;
static MNEvolutionMailbox *
GET_NEW_VARG (const char *first, ...)
{
	MNEvolutionMailbox *ret;
	va_list ap;
	va_start (ap, first);
	ret = (MNEvolutionMailbox *)g_object_new_valist (mn_evolution_mailbox_get_type (), first, ap);
	va_end (ap);
	return ret;
}


static void
___finalize(GObject *obj_self)
{
#define __GOB_FUNCTION__ "MN:Evolution:Mailbox::finalize"
	MNEvolutionMailbox *self G_GNUC_UNUSED = MN_EVOLUTION_MAILBOX (obj_self);
	gpointer priv G_GNUC_UNUSED = self->_priv;
	if(G_OBJECT_CLASS(parent_class)->finalize) \
		(* G_OBJECT_CLASS(parent_class)->finalize)(obj_self);
#line 51 "mn-evolution-mailbox.gob"
	if(self->uri) { g_free ((gpointer) self->uri); self->uri = NULL; }
#line 130 "mn-evolution-mailbox.c"
#line 58 "mn-evolution-mailbox.gob"
	if(self->folder_name) { g_free ((gpointer) self->folder_name); self->folder_name = NULL; }
#line 133 "mn-evolution-mailbox.c"
}
#undef __GOB_FUNCTION__

#line 66 "mn-evolution-mailbox.gob"
static void 
mn_evolution_mailbox_class_init (MNEvolutionMailboxClass * class G_GNUC_UNUSED)
#line 140 "mn-evolution-mailbox.c"
{
#define __GOB_FUNCTION__ "MN:Evolution:Mailbox::class_init"
	GObjectClass *g_object_class G_GNUC_UNUSED = (GObjectClass*) class;
	MNMailboxClass *mn_mailbox_class = (MNMailboxClass *)class;
	MNReentrantMailboxClass *mn_reentrant_mailbox_class = (MNReentrantMailboxClass *)class;

	g_type_class_add_private(class,sizeof(MNEvolutionMailboxPrivate));

	parent_class = g_type_class_ref (MN_TYPE_REENTRANT_MAILBOX);

#line 91 "mn-evolution-mailbox.gob"
	mn_mailbox_class->seal = ___3_mn_evolution_mailbox_seal;
#line 100 "mn-evolution-mailbox.gob"
	g_object_class->dispose = ___4_mn_evolution_mailbox_dispose;
#line 164 "mn-evolution-mailbox.gob"
	mn_reentrant_mailbox_class->reentrant_check = ___6_mn_evolution_mailbox_reentrant_check;
#line 157 "mn-evolution-mailbox.c"
	g_object_class->finalize = ___finalize;
	g_object_class->get_property = ___object_get_property;
	g_object_class->set_property = ___object_set_property;
    {
	GParamSpec   *param_spec;

	param_spec = g_param_spec_string
		("uri" /* name */,
		 NULL /* nick */,
		 NULL /* blurb */,
		 NULL /* default_value */,
		 (GParamFlags)(G_PARAM_READABLE | G_PARAM_WRITABLE | MN_MAILBOX_PARAM_REQUIRED | MN_MAILBOX_PARAM_PERMANENT));
	g_object_class_install_property (g_object_class,
		PROP_URI,
		param_spec);
	param_spec = g_param_spec_string
		("folder_name" /* name */,
		 NULL /* nick */,
		 NULL /* blurb */,
		 NULL /* default_value */,
		 (GParamFlags)(G_PARAM_READABLE | G_PARAM_WRITABLE | MN_MAILBOX_PARAM_REQUIRED | MN_MAILBOX_PARAM_PERMANENT));
	g_object_class_install_property (g_object_class,
		PROP_FOLDER_NAME,
		param_spec);
    }
 {
#line 67 "mn-evolution-mailbox.gob"

    MN_MAILBOX_CLASS(class)->type = "evolution";

    /*
     * The mailbox is only polled if the folder was not found. Since
     * this is unlikely, and since Evolution is probably running on
     * the local machine, we choose a small default check delay (1
     * minute).
     */
    MN_MAILBOX_CLASS(class)->default_check_delay = 60 * 1;

    bonobo_exception_add_handler_str(ex_GNOME_MailNotification_Evolution_Glue_FolderNotFound, _("folder not found"));
    bonobo_exception_add_handler_str(ex_GNOME_MailNotification_Evolution_Glue_MessageNotFound, _("message not found"));
  
#line 199 "mn-evolution-mailbox.c"
 }
}
#undef __GOB_FUNCTION__
#line 82 "mn-evolution-mailbox.gob"
static void 
mn_evolution_mailbox_init (MNEvolutionMailbox * self G_GNUC_UNUSED)
#line 206 "mn-evolution-mailbox.c"
{
#define __GOB_FUNCTION__ "MN:Evolution:Mailbox::init"
	self->_priv = G_TYPE_INSTANCE_GET_PRIVATE(self,MN_TYPE_EVOLUTION_MAILBOX,MNEvolutionMailboxPrivate);
 {
#line 83 "mn-evolution-mailbox.gob"

    mn_mailbox_set_format(MN_MAILBOX(self), "Evolution");
    mn_mailbox_set_stock_id(MN_MAILBOX(self), MN_STOCK_EVOLUTION_MAILBOX);

    /* we receive notifications from Evolution, no need to poll */
    mn_mailbox_set_poll(MN_MAILBOX(self), FALSE);
  
#line 219 "mn-evolution-mailbox.c"
 }
}
#undef __GOB_FUNCTION__

static void
___object_set_property (GObject *object,
	guint property_id,
	const GValue *VAL G_GNUC_UNUSED,
	GParamSpec *pspec G_GNUC_UNUSED)
#define __GOB_FUNCTION__ "MN:Evolution:Mailbox::set_property"
{
	MNEvolutionMailbox *self G_GNUC_UNUSED;

	self = MN_EVOLUTION_MAILBOX (object);

	switch (property_id) {
	case PROP_URI:
		{
#line 52 "mn-evolution-mailbox.gob"
{ char *old = self->uri; self->uri = g_value_dup_string (VAL); g_free (old); }
#line 240 "mn-evolution-mailbox.c"
		}
		break;
	case PROP_FOLDER_NAME:
		{
#line 59 "mn-evolution-mailbox.gob"
{ char *old = self->folder_name; self->folder_name = g_value_dup_string (VAL); g_free (old); }
#line 247 "mn-evolution-mailbox.c"
		}
		break;
	default:
/* Apparently in g++ this is needed, glib is b0rk */
#ifndef __PRETTY_FUNCTION__
#  undef G_STRLOC
#  define G_STRLOC	__FILE__ ":" G_STRINGIFY (__LINE__)
#endif
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}
#undef __GOB_FUNCTION__

static void
___object_get_property (GObject *object,
	guint property_id,
	GValue *VAL G_GNUC_UNUSED,
	GParamSpec *pspec G_GNUC_UNUSED)
#define __GOB_FUNCTION__ "MN:Evolution:Mailbox::get_property"
{
	MNEvolutionMailbox *self G_GNUC_UNUSED;

	self = MN_EVOLUTION_MAILBOX (object);

	switch (property_id) {
	case PROP_URI:
		{
#line 52 "mn-evolution-mailbox.gob"
g_value_set_string (VAL, self->uri);
#line 278 "mn-evolution-mailbox.c"
		}
		break;
	case PROP_FOLDER_NAME:
		{
#line 59 "mn-evolution-mailbox.gob"
g_value_set_string (VAL, self->folder_name);
#line 285 "mn-evolution-mailbox.c"
		}
		break;
	default:
/* Apparently in g++ this is needed, glib is b0rk */
#ifndef __PRETTY_FUNCTION__
#  undef G_STRLOC
#  define G_STRLOC	__FILE__ ":" G_STRINGIFY (__LINE__)
#endif
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}
#undef __GOB_FUNCTION__



#line 91 "mn-evolution-mailbox.gob"
static void 
___3_mn_evolution_mailbox_seal (MNMailbox * mailbox G_GNUC_UNUSED)
#line 305 "mn-evolution-mailbox.c"
#define PARENT_HANDLER(___mailbox) \
	{ if(MN_MAILBOX_CLASS(parent_class)->seal) \
		(* MN_MAILBOX_CLASS(parent_class)->seal)(___mailbox); }
{
#define __GOB_FUNCTION__ "MN:Evolution:Mailbox::seal"
{
#line 93 "mn-evolution-mailbox.gob"
	
    PARENT_HANDLER(mailbox);

    if (! mailbox->runtime_name)
      mailbox->runtime_name = g_strdup(SELF(mailbox)->folder_name);
  }}
#line 319 "mn-evolution-mailbox.c"
#undef __GOB_FUNCTION__
#undef PARENT_HANDLER

#line 100 "mn-evolution-mailbox.gob"
static void 
___4_mn_evolution_mailbox_dispose (GObject * object G_GNUC_UNUSED)
#line 326 "mn-evolution-mailbox.c"
#define PARENT_HANDLER(___object) \
	{ if(G_OBJECT_CLASS(parent_class)->dispose) \
		(* G_OBJECT_CLASS(parent_class)->dispose)(___object); }
{
#define __GOB_FUNCTION__ "MN:Evolution:Mailbox::dispose"
{
#line 102 "mn-evolution-mailbox.gob"
	
    Self *self = SELF(object);

    if (selfp->listener)
      {
	GNOME_MailNotification_Evolution_Glue glue;

	g_assert(selfp->glue != NULL);

	glue = mn_bonobo_unknown_get_object(selfp->glue);
	g_assert(glue != CORBA_OBJECT_NIL);

	g_static_mutex_lock(&listeners_mutex);
	mn_bonobo_event_source_client_remove_listener_locked(glue, selfp->listener, NULL);
	g_static_mutex_unlock(&listeners_mutex);

	bonobo_object_release_unref(glue, NULL);
	selfp->listener = NULL;
      }

    if (selfp->glue)
      {
	g_signal_handlers_disconnect_by_func(selfp->glue, mn_reentrant_mailbox_queue_check, self);
	mn_evolution_glue_client_unuse();
	selfp->glue = NULL;
      }

    PARENT_HANDLER(object);
  }}
#line 363 "mn-evolution-mailbox.c"
#undef __GOB_FUNCTION__
#undef PARENT_HANDLER

#line 132 "mn-evolution-mailbox.gob"
static void 
mn_evolution_mailbox_listener_cb (BonoboListener * listener, const char * event_name, const CORBA_any * any, CORBA_Environment * env, gpointer user_data)
#line 370 "mn-evolution-mailbox.c"
{
#define __GOB_FUNCTION__ "MN:Evolution:Mailbox::listener_cb"
{
#line 138 "mn-evolution-mailbox.gob"
	
    Self *self = user_data;
    const char *uri;

    if (! strcmp(event_name, MN_EVOLUTION_GLUE_EVENT_PREFIX ":" MN_EVOLUTION_GLUE_EVENT_MESSAGE_READING))
      {
	uri = BONOBO_ARG_GET_STRING(any);
	if (! strcmp(uri, self->uri))
	  {
	    time_t now = mn_time();

	    mn_reentrant_mailbox_lock(MN_REENTRANT_MAILBOX(self));
	    selfp->last_browsed = now;
	    mn_reentrant_mailbox_unlock(MN_REENTRANT_MAILBOX(self));

	    mn_reentrant_mailbox_queue_check(MN_REENTRANT_MAILBOX(self));
	  }
      }
    else if (! strcmp(event_name, MN_EVOLUTION_GLUE_EVENT_PREFIX ":" MN_EVOLUTION_GLUE_EVENT_FOLDER_CHANGED))
      {
	uri = BONOBO_ARG_GET_STRING(any);
	if (! strcmp(uri, self->uri))
	  mn_reentrant_mailbox_queue_check(MN_REENTRANT_MAILBOX(self));
      }
  }}
#line 400 "mn-evolution-mailbox.c"
#undef __GOB_FUNCTION__

#line 164 "mn-evolution-mailbox.gob"
static void 
___6_mn_evolution_mailbox_reentrant_check (MNReentrantMailbox * mailbox G_GNUC_UNUSED, unsigned long check_id)
#line 406 "mn-evolution-mailbox.c"
#define PARENT_HANDLER(___mailbox,___check_id) \
	{ if(MN_REENTRANT_MAILBOX_CLASS(parent_class)->reentrant_check) \
		(* MN_REENTRANT_MAILBOX_CLASS(parent_class)->reentrant_check)(___mailbox,___check_id); }
{
#define __GOB_FUNCTION__ "MN:Evolution:Mailbox::reentrant_check"
{
#line 166 "mn-evolution-mailbox.gob"
	
    Self *self = SELF(mailbox);
    GNOME_MailNotification_Evolution_Glue glue;
    CORBA_Environment env;
    CORBA_sequence_GNOME_MailNotification_Evolution_Message *message_seq;
    time_t last_browsed;

    mn_reentrant_mailbox_lock(mailbox);

    if (! selfp->glue)
      {
	selfp->glue = mn_evolution_glue_client_use();
	g_signal_connect_swapped(selfp->glue, "notify::object", G_CALLBACK(mn_reentrant_mailbox_queue_check), self);
      }

    glue = mn_bonobo_unknown_get_object(selfp->glue);

    if (glue == CORBA_OBJECT_NIL)
      {
	if (selfp->listener)
	  {
	    mn_bonobo_event_source_client_remove_listener_locked(CORBA_OBJECT_NIL, selfp->listener, NULL);
	    selfp->listener = NULL;
	  }
      }
    else
      {
	if (! selfp->listener)
	  selfp->listener = mn_bonobo_event_source_client_add_listener_full_locked(glue,
										   self_listener_cb,
										   MN_EVOLUTION_GLUE_EVENT_PREFIX,
										   NULL,
										   self,
										   (MNLockFunc) mn_g_static_mutex_lock,
										   (MNUnlockFunc) mn_g_static_mutex_unlock,
										   &listeners_mutex);
      }

    if (! selfp->listener && glue != CORBA_OBJECT_NIL)
      {
	bonobo_object_release_unref(glue, NULL);
	glue = CORBA_OBJECT_NIL;
      }

    last_browsed = selfp->last_browsed;

    mn_reentrant_mailbox_unlock(mailbox);

    if (glue == CORBA_OBJECT_NIL)
      {
	GDK_THREADS_ENTER();

	if (! mn_reentrant_mailbox_check_aborted_unlocked(mailbox, check_id))
	  {
	    mn_mailbox_set_error(MN_MAILBOX(self), _("unable to contact Evolution"));

	    if (mn_mailbox_get_poll(MN_MAILBOX(self)))
	      mn_mailbox_set_poll(MN_MAILBOX(self), FALSE);
	  }

	gdk_flush();
	GDK_THREADS_LEAVE();

	return;
      }

    CORBA_exception_init(&env);

    message_seq = GNOME_MailNotification_Evolution_Glue_getUnseenMessages(glue, self->uri, &env);

    if (BONOBO_EX(&env))
      {
	GDK_THREADS_ENTER();

	if (! mn_reentrant_mailbox_check_aborted_unlocked(mailbox, check_id))
	  {
	    char *errmsg;

	    errmsg = bonobo_exception_get_text(&env);
	    mn_mailbox_set_error(MN_MAILBOX(self), "%s", errmsg);
	    g_free(errmsg);

	    if (! mn_mailbox_get_poll(MN_MAILBOX(self)))
	      /*
	       * If the folder was not found, we will no longer
	       * receive events from Evolution, and we must therefore
	       * re-enable polling.
	       */
	      mn_mailbox_set_poll(MN_MAILBOX(self), TRUE);
	  }

	gdk_flush();
	GDK_THREADS_LEAVE();
      }
    else
      {
	int i;
	GSList *messages = NULL;

	for (i = 0; i < message_seq->_length; i++)
	  {
	    MNMessageFlags flags = 0;

	    if (message_seq->_buffer[i].received_time > last_browsed)
	      flags |= MN_MESSAGE_NEW;

#define unbox(str) (*(str) ? (str) : NULL)
	    messages = g_slist_prepend(messages, mn_evolution_message_new(MN_MAILBOX(mailbox),
									  message_seq->_buffer[i].sent_time,
									  message_seq->_buffer[i].id,
									  unbox(message_seq->_buffer[i].from),
									  unbox(message_seq->_buffer[i].subject),
									  flags,
									  message_seq->_buffer[i].uid));

	    if (mn_reentrant_mailbox_check_aborted(mailbox, check_id))
	      break;
	  }

	GDK_THREADS_ENTER();

	if (! mn_reentrant_mailbox_check_aborted_unlocked(mailbox, check_id))
	  {
	    mn_mailbox_set_messages(MN_MAILBOX(self), messages);

	    if (mn_mailbox_get_poll(MN_MAILBOX(self)))
	      mn_mailbox_set_poll(MN_MAILBOX(self), FALSE);
	  }

	mn_g_object_slist_free(messages);

	gdk_flush();
	GDK_THREADS_LEAVE();

	CORBA_free(message_seq);
      }

    CORBA_exception_free(&env);
    bonobo_object_release_unref(glue, NULL);
  }}
#line 554 "mn-evolution-mailbox.c"
#undef __GOB_FUNCTION__
#undef PARENT_HANDLER
