/* Generated by GOB (v2.0.11) on Thu Nov  4 11:55:05 2004
   (do not edit directly) */

/* End world hunger, donate to the World Food Programme, http://www.wfp.org */

#define GOB_VERSION_MAJOR 2
#define GOB_VERSION_MINOR 0
#define GOB_VERSION_PATCHLEVEL 11

#define selfp (self->_priv)

#include <string.h> /* memset() */

#include "mn-authenticated-mailbox.h"

#include "mn-authenticated-mailbox-private.h"

#ifdef G_LIKELY
#define ___GOB_LIKELY(expr) G_LIKELY(expr)
#define ___GOB_UNLIKELY(expr) G_UNLIKELY(expr)
#else /* ! G_LIKELY */
#define ___GOB_LIKELY(expr) (expr)
#define ___GOB_UNLIKELY(expr) (expr)
#endif /* G_LIKELY */

#line 35 "mn-authenticated-mailbox.gob"

#include "config.h"
#include <glib/gi18n.h>
#include <eel/eel.h>
#include "mn-mailbox-private.h"
#include "mn-util.h"

#line 35 "mn-authenticated-mailbox.c"
/* self casting macros */
#define SELF(x) MN_AUTHENTICATED_MAILBOX(x)
#define SELF_CONST(x) MN_AUTHENTICATED_MAILBOX_CONST(x)
#define IS_SELF(x) MN_IS_AUTHENTICATED_MAILBOX(x)
#define TYPE_SELF MN_TYPE_AUTHENTICATED_MAILBOX
#define SELF_CLASS(x) MN_AUTHENTICATED_MAILBOX_CLASS(x)

#define SELF_GET_CLASS(x) MN_AUTHENTICATED_MAILBOX_GET_CLASS(x)

/* self typedefs */
typedef MNAuthenticatedMailbox Self;
typedef MNAuthenticatedMailboxClass SelfClass;

/* here are local prototypes */
static void mn_authenticated_mailbox_init (MNAuthenticatedMailbox * o) G_GNUC_UNUSED;
static void mn_authenticated_mailbox_class_init (MNAuthenticatedMailboxClass * c) G_GNUC_UNUSED;
static MNAuthenticatedMailboxResult mn_authenticated_mailbox_impl_authenticated_check (MNAuthenticatedMailbox * self, GError ** err) G_GNUC_UNUSED;
static void ___2_mn_authenticated_mailbox_removed (MNMailbox * mailbox) G_GNUC_UNUSED;
static void ___3_mn_authenticated_mailbox_impl_check (MNMailbox * mailbox) G_GNUC_UNUSED;
static char * mn_authenticated_mailbox_password_prompt (MNAuthenticatedMailbox * self, const char * format, ...) G_GNUC_UNUSED;

/* pointer to the class of our parent */
static MNMailboxClass *parent_class = NULL;

/* Short form macros */
#define self_impl_authenticated_check mn_authenticated_mailbox_impl_authenticated_check
#define self_password_prompt mn_authenticated_mailbox_password_prompt
#define self_password_prompt_changed_h mn_authenticated_mailbox_password_prompt_changed_h
GType
mn_authenticated_mailbox_get_type (void)
{
	static GType type = 0;

	if ___GOB_UNLIKELY(type == 0) {
		static const GTypeInfo info = {
			sizeof (MNAuthenticatedMailboxClass),
			(GBaseInitFunc) NULL,
			(GBaseFinalizeFunc) NULL,
			(GClassInitFunc) mn_authenticated_mailbox_class_init,
			(GClassFinalizeFunc) NULL,
			NULL /* class_data */,
			sizeof (MNAuthenticatedMailbox),
			0 /* n_preallocs */,
			(GInstanceInitFunc) mn_authenticated_mailbox_init,
			NULL
		};

		type = g_type_register_static (MN_TYPE_MAILBOX, "MNAuthenticatedMailbox", &info, (GTypeFlags)0);
	}

	return type;
}

/* a macro for creating a new object of our type */
#define GET_NEW ((MNAuthenticatedMailbox *)g_object_new(mn_authenticated_mailbox_get_type(), NULL))

/* a function for creating a new object of our type */
#include <stdarg.h>
static MNAuthenticatedMailbox * GET_NEW_VARG (const char *first, ...) G_GNUC_UNUSED;
static MNAuthenticatedMailbox *
GET_NEW_VARG (const char *first, ...)
{
	MNAuthenticatedMailbox *ret;
	va_list ap;
	va_start (ap, first);
	ret = (MNAuthenticatedMailbox *)g_object_new_valist (mn_authenticated_mailbox_get_type (), first, ap);
	va_end (ap);
	return ret;
}


static void
___finalize(GObject *obj_self)
{
#define __GOB_FUNCTION__ "MN:Authenticated:Mailbox::finalize"
	MNAuthenticatedMailbox *self G_GNUC_UNUSED = MN_AUTHENTICATED_MAILBOX (obj_self);
	gpointer priv G_GNUC_UNUSED = self->_priv;
	if(G_OBJECT_CLASS(parent_class)->finalize) \
		(* G_OBJECT_CLASS(parent_class)->finalize)(obj_self);
#line 45 "mn-authenticated-mailbox.gob"
	if(self->password) { g_free ((gpointer) self->password); self->password = NULL; }
#line 117 "mn-authenticated-mailbox.c"
}
#undef __GOB_FUNCTION__

static void 
mn_authenticated_mailbox_init (MNAuthenticatedMailbox * o G_GNUC_UNUSED)
{
#define __GOB_FUNCTION__ "MN:Authenticated:Mailbox::init"
	o->_priv = G_TYPE_INSTANCE_GET_PRIVATE(o,TYPE_SELF,MNAuthenticatedMailboxPrivate);
#line 35 "mn-authenticated-mailbox.gob"
	o->password = NULL;
#line 128 "mn-authenticated-mailbox.c"
}
#undef __GOB_FUNCTION__
static void 
mn_authenticated_mailbox_class_init (MNAuthenticatedMailboxClass * c G_GNUC_UNUSED)
{
#define __GOB_FUNCTION__ "MN:Authenticated:Mailbox::class_init"
	GObjectClass *g_object_class G_GNUC_UNUSED = (GObjectClass*) c;
	MNMailboxClass *mn_mailbox_class = (MNMailboxClass *)c;

	g_type_class_add_private(c,sizeof(MNAuthenticatedMailboxPrivate));

	parent_class = g_type_class_ref (MN_TYPE_MAILBOX);

	c->impl_authenticated_check = NULL;
#line 51 "mn-authenticated-mailbox.gob"
	mn_mailbox_class->removed = ___2_mn_authenticated_mailbox_removed;
#line 62 "mn-authenticated-mailbox.gob"
	mn_mailbox_class->impl_check = ___3_mn_authenticated_mailbox_impl_check;
#line 147 "mn-authenticated-mailbox.c"
	g_object_class->finalize = ___finalize;
}
#undef __GOB_FUNCTION__



#line 48 "mn-authenticated-mailbox.gob"
static MNAuthenticatedMailboxResult 
mn_authenticated_mailbox_impl_authenticated_check (MNAuthenticatedMailbox * self, GError ** err)
#line 157 "mn-authenticated-mailbox.c"
{
	MNAuthenticatedMailboxClass *klass;
#line 48 "mn-authenticated-mailbox.gob"
	g_return_val_if_fail (self != NULL, (MNAuthenticatedMailboxResult )0);
#line 48 "mn-authenticated-mailbox.gob"
	g_return_val_if_fail (MN_IS_AUTHENTICATED_MAILBOX (self), (MNAuthenticatedMailboxResult )0);
#line 164 "mn-authenticated-mailbox.c"
	klass = MN_AUTHENTICATED_MAILBOX_GET_CLASS(self);

	if(klass->impl_authenticated_check)
		return (*klass->impl_authenticated_check)(self,err);
	else
		return (MNAuthenticatedMailboxResult )(0);
}

#line 51 "mn-authenticated-mailbox.gob"
static void 
___2_mn_authenticated_mailbox_removed (MNMailbox * mailbox G_GNUC_UNUSED)
#line 176 "mn-authenticated-mailbox.c"
#define PARENT_HANDLER(___mailbox) \
	{ if(MN_MAILBOX_CLASS(parent_class)->removed) \
		(* MN_MAILBOX_CLASS(parent_class)->removed)(___mailbox); }
{
#define __GOB_FUNCTION__ "MN:Authenticated:Mailbox::removed"
#line 51 "mn-authenticated-mailbox.gob"
	g_return_if_fail (mailbox != NULL);
#line 51 "mn-authenticated-mailbox.gob"
	g_return_if_fail (MN_IS_MAILBOX (mailbox));
#line 186 "mn-authenticated-mailbox.c"
{
#line 53 "mn-authenticated-mailbox.gob"
	
    Self *self = SELF(mailbox);

    if (selfp->authentication_dialog)
      gtk_dialog_response(GTK_DIALOG(selfp->authentication_dialog), GTK_RESPONSE_CANCEL);

    PARENT_HANDLER(mailbox);
  }}
#line 197 "mn-authenticated-mailbox.c"
#undef __GOB_FUNCTION__
#undef PARENT_HANDLER

#line 62 "mn-authenticated-mailbox.gob"
static void 
___3_mn_authenticated_mailbox_impl_check (MNMailbox * mailbox G_GNUC_UNUSED)
#line 204 "mn-authenticated-mailbox.c"
#define PARENT_HANDLER(___mailbox) \
	{ if(MN_MAILBOX_CLASS(parent_class)->impl_check) \
		(* MN_MAILBOX_CLASS(parent_class)->impl_check)(___mailbox); }
{
#define __GOB_FUNCTION__ "MN:Authenticated:Mailbox::impl_check"
#line 62 "mn-authenticated-mailbox.gob"
	g_return_if_fail (mailbox != NULL);
#line 62 "mn-authenticated-mailbox.gob"
	g_return_if_fail (MN_IS_MAILBOX (mailbox));
#line 214 "mn-authenticated-mailbox.c"
{
#line 64 "mn-authenticated-mailbox.gob"
	
    Self *self = SELF(mailbox);
    GError *err = NULL;
    MNAuthenticatedMailboxResult result;

    if (! self->password)
      {
  	if (mailbox->uri->password)
	  self->password = g_strdup(mailbox->uri->password);
	else
	  {
	    GDK_THREADS_ENTER();
	    /* translator: example output: Enter your password for POP3 mailbox jylefort@localhost. */
	    self->password = self_password_prompt(self, _("Enter your password for %s mailbox %s."),
						  MN_MAILBOX_GET_CLASS(mailbox)->format,
						  mn_mailbox_get_name(mailbox));
	    gdk_flush();
	    GDK_THREADS_LEAVE();

	    if (! self->password) /* cancelled */
	      goto end;
	  }
      }

    result = SELF_GET_CLASS(self)->impl_authenticated_check(self, &err);

    if (! mailbox->uri->password)
      while (result == MN_AUTHENTICATED_MAILBOX_ERROR_AUTHENTICATION)
	{
	  g_clear_error(&err);
	  g_free(self->password);

	  GDK_THREADS_ENTER();
	  /* translator: example output: ... into POP3 mailbox jylefort@localhost ... */
	  self->password = self_password_prompt(self, _("Mail Notification was unable to log into %s mailbox %s, possibly because the password you have entered is invalid.\n\nPlease re-enter your password."),
						MN_MAILBOX_GET_CLASS(mailbox)->format,
						mn_mailbox_get_name(mailbox));
	  gdk_flush();
	  GDK_THREADS_LEAVE();

	  if (! self->password)	/* cancelled */
	    goto end;

	  result = SELF_GET_CLASS(self)->impl_authenticated_check(self, &err);
	}

    if (result != MN_AUTHENTICATED_MAILBOX_OK)
      {
  	GDK_THREADS_ENTER();
	mn_mailbox_set_error(mailbox, "%s", err->message);
	gdk_flush();
	GDK_THREADS_LEAVE();
	g_error_free(err);
      }
    
  end:
    GDK_THREADS_ENTER();
    mn_mailbox_end_check(mailbox);
    gdk_flush();
    GDK_THREADS_LEAVE();
  }}
#line 278 "mn-authenticated-mailbox.c"
#undef __GOB_FUNCTION__
#undef PARENT_HANDLER

#line 126 "mn-authenticated-mailbox.gob"
static char * 
mn_authenticated_mailbox_password_prompt (MNAuthenticatedMailbox * self, const char * format, ...)
#line 285 "mn-authenticated-mailbox.c"
{
#define __GOB_FUNCTION__ "MN:Authenticated:Mailbox::password_prompt"
#line 126 "mn-authenticated-mailbox.gob"
	g_return_val_if_fail (self != NULL, (char * )0);
#line 126 "mn-authenticated-mailbox.gob"
	g_return_val_if_fail (MN_IS_AUTHENTICATED_MAILBOX (self), (char * )0);
#line 126 "mn-authenticated-mailbox.gob"
	g_return_val_if_fail (format != NULL, (char * )0);
#line 294 "mn-authenticated-mailbox.c"
{
#line 128 "mn-authenticated-mailbox.gob"
	
    GtkWidget *label;
    GtkWidget *username_label;
    GtkWidget *username_entry;
    GtkWidget *password_label;
    GtkWidget *password_entry;
    GtkSizeGroup *size_group;
    va_list args;
    char *prompt;
    char *markup;
    char *password = NULL;

    g_return_val_if_fail(selfp->authentication_dialog == NULL, NULL);

    mn_create_interface("authentication",
			"dialog", &selfp->authentication_dialog,
			"label", &label,
			"username_label", &username_label,
			"username_entry", &username_entry,
			"password_label", &password_label,
			"password_entry", &password_entry,
			NULL);

    eel_add_weak_pointer(&selfp->authentication_dialog);

    gtk_dialog_set_default_response(GTK_DIALOG(selfp->authentication_dialog), GTK_RESPONSE_OK);

    size_group = gtk_size_group_new(GTK_SIZE_GROUP_HORIZONTAL);
    gtk_size_group_add_widget(size_group, username_label);
    gtk_size_group_add_widget(size_group, password_label);
    g_object_unref(size_group);

    va_start(args, format);
    prompt = g_strdup_vprintf(format, args);
    va_end(args);

    markup = g_markup_printf_escaped(_("<span weight=\"bold\" size=\"larger\">Mail Notification requires a password</span>\n"
				       "\n"
				       "%s"),
				     prompt);
    g_free(prompt);

    gtk_label_set_markup(GTK_LABEL(label), markup);
    g_free(markup);

    gtk_entry_set_text(GTK_ENTRY(username_entry), MN_MAILBOX(self)->uri->username);

    if (gtk_dialog_run(GTK_DIALOG(selfp->authentication_dialog)) == GTK_RESPONSE_OK)
      password = g_strdup(gtk_entry_get_text(GTK_ENTRY(password_entry)));

    gtk_widget_destroy(selfp->authentication_dialog);

    return password;
  }}
#line 351 "mn-authenticated-mailbox.c"
#undef __GOB_FUNCTION__

#line 185 "mn-authenticated-mailbox.gob"
void 
mn_authenticated_mailbox_password_prompt_changed_h (gpointer user_data, GtkEditable * editable)
#line 357 "mn-authenticated-mailbox.c"
{
#define __GOB_FUNCTION__ "MN:Authenticated:Mailbox::password_prompt_changed_h"
{
#line 188 "mn-authenticated-mailbox.gob"
	
    GtkDialog *dialog = user_data;
    const char *password;

    password = gtk_entry_get_text(GTK_ENTRY(editable));
    gtk_dialog_set_response_sensitive(dialog, GTK_RESPONSE_OK, *password != 0);
  }}
#line 369 "mn-authenticated-mailbox.c"
#undef __GOB_FUNCTION__
