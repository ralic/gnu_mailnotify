/* Generated by GOB (v2.0.11) on Sun Oct 31 18:41:22 2004
   (do not edit directly) */

/* End world hunger, donate to the World Food Programme, http://www.wfp.org */

#define GOB_VERSION_MAJOR 2
#define GOB_VERSION_MINOR 0
#define GOB_VERSION_PATCHLEVEL 11

#define selfp (self->_priv)

#include <string.h> /* memset() */

#include "mn-shell.h"

#include "mn-shell-private.h"

#ifdef G_LIKELY
#define ___GOB_LIKELY(expr) G_LIKELY(expr)
#define ___GOB_UNLIKELY(expr) G_UNLIKELY(expr)
#else /* ! G_LIKELY */
#define ___GOB_LIKELY(expr) (expr)
#define ___GOB_UNLIKELY(expr) (expr)
#endif /* G_LIKELY */

#line 27 "mn-shell.gob"

#include "config.h"
#include <errno.h>
#include <gnome.h>
#include <eel/eel.h>
#include "mn-properties.h"
#include "mn-util.h"
#include "mn-conf.h"
#include "mn-mailboxes.h"
#include "mn-unsupported-mailbox.h"
#include "mn-about-dialog.h"
#include "mn-summary.h"
#include "mn-summary-popup.h"
#include "mn-summary-dialog.h"

  MNShell *mn_shell = NULL;

#line 45 "mn-shell.c"
/* self casting macros */
#define SELF(x) MN_SHELL(x)
#define SELF_CONST(x) MN_SHELL_CONST(x)
#define IS_SELF(x) MN_IS_SHELL(x)
#define TYPE_SELF MN_TYPE_SHELL
#define SELF_CLASS(x) MN_SHELL_CLASS(x)

#define SELF_GET_CLASS(x) MN_SHELL_GET_CLASS(x)

/* self typedefs */
typedef MNShell Self;
typedef MNShellClass SelfClass;

/* here are local prototypes */
static void mn_shell_class_init (MNShellClass * c) G_GNUC_UNUSED;
static void mn_shell_init (MNShell * self) G_GNUC_UNUSED;
static void ___2_mn_shell_finalize (GObject * object) G_GNUC_UNUSED;
static void mn_shell_mailboxes_messages_changed_h (MNMailboxes * mailboxes, gboolean has_new, gpointer user_data) G_GNUC_UNUSED;
static void mn_shell_init_icon (MNShell * self) G_GNUC_UNUSED;
static void mn_shell_notify_blink_on_errors_cb (GConfClient * client, guint cnxn_id, GConfEntry * entry, gpointer user_data) G_GNUC_UNUSED;
static void mn_shell_notify_mail_reader_cb (GConfClient * client, guint cnxn_id, GConfEntry * entry, gpointer user_data) G_GNUC_UNUSED;
static void mn_shell_icon_activate_h (MNMailIcon * icon, gpointer user_data) G_GNUC_UNUSED;
static void mn_shell_icon_activate_summary_h (MNMailIcon * icon, gpointer user_data) G_GNUC_UNUSED;
static void mn_shell_icon_activate_mail_reader_h (MNMailIcon * icon, gpointer user_data) G_GNUC_UNUSED;
static void mn_shell_icon_activate_update_h (MNMailIcon * icon, gpointer user_data) G_GNUC_UNUSED;
static void mn_shell_icon_activate_properties_h (MNMailIcon * icon, gpointer user_data) G_GNUC_UNUSED;
static void mn_shell_icon_activate_help_h (MNMailIcon * icon, gpointer user_data) G_GNUC_UNUSED;
static void mn_shell_icon_activate_about_h (MNMailIcon * icon, gpointer user_data) G_GNUC_UNUSED;
static void mn_shell_icon_activate_remove_h (MNMailIcon * icon, gpointer user_data) G_GNUC_UNUSED;
static void mn_shell_icon_destroy_h (GtkObject * object, gpointer user_data) G_GNUC_UNUSED;
static void mn_shell_update_sensitivity (MNShell * self) G_GNUC_UNUSED;
static void mn_shell_update_icon (MNShell * self) G_GNUC_UNUSED;
static void mn_shell_update_tooltip (MNShell * self) G_GNUC_UNUSED;
static GtkWidget * mn_shell_tooltip_section_new (GtkVBox * vbox, const char * title) G_GNUC_UNUSED;
static void mn_shell_tooltip_text_section_new (GtkVBox * vbox, const char * title, const char * text) G_GNUC_UNUSED;

/* pointer to the class of our parent */
static GObjectClass *parent_class = NULL;

/* Short form macros */
#define self_mailboxes_messages_changed_h mn_shell_mailboxes_messages_changed_h
#define self_init_icon mn_shell_init_icon
#define self_notify_blink_on_errors_cb mn_shell_notify_blink_on_errors_cb
#define self_notify_mail_reader_cb mn_shell_notify_mail_reader_cb
#define self_icon_activate_h mn_shell_icon_activate_h
#define self_icon_activate_summary_h mn_shell_icon_activate_summary_h
#define self_icon_activate_mail_reader_h mn_shell_icon_activate_mail_reader_h
#define self_icon_activate_update_h mn_shell_icon_activate_update_h
#define self_icon_activate_properties_h mn_shell_icon_activate_properties_h
#define self_icon_activate_help_h mn_shell_icon_activate_help_h
#define self_icon_activate_about_h mn_shell_icon_activate_about_h
#define self_icon_activate_remove_h mn_shell_icon_activate_remove_h
#define self_icon_destroy_h mn_shell_icon_destroy_h
#define self_update_sensitivity mn_shell_update_sensitivity
#define self_update_icon mn_shell_update_icon
#define self_update_tooltip mn_shell_update_tooltip
#define self_tooltip_section_new mn_shell_tooltip_section_new
#define self_tooltip_text_section_new mn_shell_tooltip_text_section_new
#define self_new mn_shell_new
#define self_display_about mn_shell_display_about
#define self_run_welcome mn_shell_run_welcome
#define self_report mn_shell_report
GType
mn_shell_get_type (void)
{
	static GType type = 0;

	if ___GOB_UNLIKELY(type == 0) {
		static const GTypeInfo info = {
			sizeof (MNShellClass),
			(GBaseInitFunc) NULL,
			(GBaseFinalizeFunc) NULL,
			(GClassInitFunc) mn_shell_class_init,
			(GClassFinalizeFunc) NULL,
			NULL /* class_data */,
			sizeof (MNShell),
			0 /* n_preallocs */,
			(GInstanceInitFunc) mn_shell_init,
			NULL
		};

		type = g_type_register_static (G_TYPE_OBJECT, "MNShell", &info, (GTypeFlags)0);
	}

	return type;
}

/* a macro for creating a new object of our type */
#define GET_NEW ((MNShell *)g_object_new(mn_shell_get_type(), NULL))

/* a function for creating a new object of our type */
#include <stdarg.h>
static MNShell * GET_NEW_VARG (const char *first, ...) G_GNUC_UNUSED;
static MNShell *
GET_NEW_VARG (const char *first, ...)
{
	MNShell *ret;
	va_list ap;
	va_start (ap, first);
	ret = (MNShell *)g_object_new_valist (mn_shell_get_type (), first, ap);
	va_end (ap);
	return ret;
}


static void
___dispose (GObject *obj_self)
{
#define __GOB_FUNCTION__ "MN:Shell::dispose"
	MNShell *self G_GNUC_UNUSED = MN_SHELL (obj_self);
	if (G_OBJECT_CLASS (parent_class)->dispose) \
		(* G_OBJECT_CLASS (parent_class)->dispose) (obj_self);
#line 47 "mn-shell.gob"
	if(self->mailboxes) { g_object_unref ((gpointer) self->mailboxes); self->mailboxes = NULL; }
#line 160 "mn-shell.c"
}
#undef __GOB_FUNCTION__


static void
___finalize(GObject *obj_self)
{
#define __GOB_FUNCTION__ "MN:Shell::finalize"
	MNShell *self G_GNUC_UNUSED = MN_SHELL (obj_self);
	gpointer priv G_GNUC_UNUSED = self->_priv;
#line 78 "mn-shell.gob"
	___2_mn_shell_finalize(obj_self);
#line 173 "mn-shell.c"
}
#undef __GOB_FUNCTION__

static void 
mn_shell_class_init (MNShellClass * c G_GNUC_UNUSED)
{
#define __GOB_FUNCTION__ "MN:Shell::class_init"
	GObjectClass *g_object_class G_GNUC_UNUSED = (GObjectClass*) c;

	g_type_class_add_private(c,sizeof(MNShellPrivate));

	parent_class = g_type_class_ref (G_TYPE_OBJECT);

#line 78 "mn-shell.gob"
	g_object_class->finalize = ___finalize;
#line 189 "mn-shell.c"
	g_object_class->dispose = ___dispose;
}
#undef __GOB_FUNCTION__
#line 52 "mn-shell.gob"
static void 
mn_shell_init (MNShell * self G_GNUC_UNUSED)
#line 196 "mn-shell.c"
{
#define __GOB_FUNCTION__ "MN:Shell::init"
	self->_priv = G_TYPE_INSTANCE_GET_PRIVATE(self,TYPE_SELF,MNShellPrivate);
#line 47 "mn-shell.gob"
	self->mailboxes = mn_mailboxes_new();
#line 202 "mn-shell.c"
 {
#line 53 "mn-shell.gob"

    g_return_if_fail(mn_shell == NULL);
    mn_shell = self;
    eel_add_weak_pointer(&mn_shell);

    self_init_icon(self);

    eel_gconf_notification_add(MN_CONF_BLINK_ON_ERRORS, self_notify_blink_on_errors_cb, self);
    eel_gconf_notification_add(MN_CONF_COMMANDS_MAIL_READER_NAMESPACE, self_notify_mail_reader_cb, self);

    g_object_connect(self->mailboxes,
		     "signal::messages-changed", self_mailboxes_messages_changed_h, self,
		     "swapped-signal::notify::must-poll", self_update_sensitivity, self,
		     "swapped-signal::list-changed", self_update_tooltip, self,
		     "swapped-signal::list-changed", self_update_icon, self,
		     "swapped-signal::has-new-changed", self_update_tooltip, self,
		     "swapped-signal::has-new-changed", self_update_icon, self,
		     "swapped-signal::error-changed", self_update_tooltip, self,
		     "swapped-signal::error-changed", self_update_icon, self,
		     "swapped-signal::messages-changed", self_update_tooltip, self,
		     NULL);

    mn_summary_popup_init();
  
#line 229 "mn-shell.c"
 }
}
#undef __GOB_FUNCTION__



#line 78 "mn-shell.gob"
static void 
___2_mn_shell_finalize (GObject * object G_GNUC_UNUSED)
#line 239 "mn-shell.c"
#define PARENT_HANDLER(___object) \
	{ if(G_OBJECT_CLASS(parent_class)->finalize) \
		(* G_OBJECT_CLASS(parent_class)->finalize)(___object); }
{
#define __GOB_FUNCTION__ "MN:Shell::finalize"
{
#line 80 "mn-shell.gob"
	
    gtk_main_quit();
    PARENT_HANDLER(object);
  }}
#line 251 "mn-shell.c"
#undef __GOB_FUNCTION__
#undef PARENT_HANDLER

#line 85 "mn-shell.gob"
static void 
mn_shell_mailboxes_messages_changed_h (MNMailboxes * mailboxes, gboolean has_new, gpointer user_data)
#line 258 "mn-shell.c"
{
#define __GOB_FUNCTION__ "MN:Shell::mailboxes_messages_changed_h"
#line 85 "mn-shell.gob"
	g_return_if_fail (mailboxes != NULL);
#line 85 "mn-shell.gob"
	g_return_if_fail (MN_IS_MAILBOXES (mailboxes));
#line 85 "mn-shell.gob"
	g_return_if_fail (user_data != NULL);
#line 267 "mn-shell.c"
{
#line 89 "mn-shell.gob"
	
    if (has_new)
      {
	gnome_triggers_do(_("You have new mail."), NULL, "mail-notification", "new-mail", NULL);
	if (eel_gconf_get_boolean(MN_CONF_COMMANDS_NEW_MAIL_ENABLED))
	  mn_execute_command(MN_CONF_COMMANDS_NEW_MAIL_COMMAND);
      }
  }}
#line 278 "mn-shell.c"
#undef __GOB_FUNCTION__

#line 98 "mn-shell.gob"
static void 
mn_shell_init_icon (MNShell * self)
#line 284 "mn-shell.c"
{
#define __GOB_FUNCTION__ "MN:Shell::init_icon"
#line 98 "mn-shell.gob"
	g_return_if_fail (self != NULL);
#line 98 "mn-shell.gob"
	g_return_if_fail (MN_IS_SHELL (self));
#line 291 "mn-shell.c"
{
#line 100 "mn-shell.gob"
	
    selfp->icon = MN_MAIL_ICON(mn_mail_icon_new());

    g_object_connect(selfp->icon,
		     "signal::activate", self_icon_activate_h, self,
		     "signal::activate-mail-reader", self_icon_activate_mail_reader_h, self,
		     "signal::activate-summary", self_icon_activate_summary_h, self,
		     "signal::activate-update", self_icon_activate_update_h, self,
		     "signal::activate-properties", self_icon_activate_properties_h, self,
		     "signal::activate-help", self_icon_activate_help_h, self,
		     "signal::activate-about", self_icon_activate_about_h, self,
		     "signal::activate-remove", self_icon_activate_remove_h, self,
		     "signal::destroy", self_icon_destroy_h, self,
		     NULL);
		     
    self_update_sensitivity(self);
    self_update_icon(self);
  }}
#line 312 "mn-shell.c"
#undef __GOB_FUNCTION__

#line 119 "mn-shell.gob"
static void 
mn_shell_notify_blink_on_errors_cb (GConfClient * client, guint cnxn_id, GConfEntry * entry, gpointer user_data)
#line 318 "mn-shell.c"
{
#define __GOB_FUNCTION__ "MN:Shell::notify_blink_on_errors_cb"
#line 119 "mn-shell.gob"
	g_return_if_fail (user_data != NULL);
#line 323 "mn-shell.c"
{
#line 124 "mn-shell.gob"
	
    Self *self = user_data;

    GDK_THREADS_ENTER();
    self_update_icon(self);
    GDK_THREADS_LEAVE();
  }}
#line 333 "mn-shell.c"
#undef __GOB_FUNCTION__

#line 132 "mn-shell.gob"
static void 
mn_shell_notify_mail_reader_cb (GConfClient * client, guint cnxn_id, GConfEntry * entry, gpointer user_data)
#line 339 "mn-shell.c"
{
#define __GOB_FUNCTION__ "MN:Shell::notify_mail_reader_cb"
#line 132 "mn-shell.gob"
	g_return_if_fail (user_data != NULL);
#line 344 "mn-shell.c"
{
#line 137 "mn-shell.gob"
	
    Self *self = user_data;

    GDK_THREADS_ENTER();
    self_update_sensitivity(self);
    GDK_THREADS_LEAVE();
  }}
#line 354 "mn-shell.c"
#undef __GOB_FUNCTION__

#line 145 "mn-shell.gob"
static void 
mn_shell_icon_activate_h (MNMailIcon * icon, gpointer user_data)
#line 360 "mn-shell.c"
{
#define __GOB_FUNCTION__ "MN:Shell::icon_activate_h"
#line 145 "mn-shell.gob"
	g_return_if_fail (icon != NULL);
#line 145 "mn-shell.gob"
	g_return_if_fail (MN_IS_MAIL_ICON (icon));
#line 145 "mn-shell.gob"
	g_return_if_fail (user_data != NULL);
#line 369 "mn-shell.c"
{
#line 148 "mn-shell.gob"
	
    MNAction action;

    action = mn_conf_get_enum_value(MN_TYPE_ACTION, MN_CONF_DOUBLE_CLICK_ACTION);

    switch (action)
      {
      case MN_ACTION_DISPLAY_MAIL_SUMMARY:
	mn_summary_dialog_display();
	break;

      case MN_ACTION_LAUNCH_MAIL_READER:
	if (eel_gconf_get_boolean(MN_CONF_COMMANDS_MAIL_READER_ENABLED))
	  mn_execute_command(MN_CONF_COMMANDS_MAIL_READER_COMMAND);
	break;

      default:
	g_return_if_reached();
      }
  }}
#line 392 "mn-shell.c"
#undef __GOB_FUNCTION__

#line 169 "mn-shell.gob"
static void 
mn_shell_icon_activate_summary_h (MNMailIcon * icon, gpointer user_data)
#line 398 "mn-shell.c"
{
#define __GOB_FUNCTION__ "MN:Shell::icon_activate_summary_h"
#line 169 "mn-shell.gob"
	g_return_if_fail (icon != NULL);
#line 169 "mn-shell.gob"
	g_return_if_fail (MN_IS_MAIL_ICON (icon));
#line 169 "mn-shell.gob"
	g_return_if_fail (user_data != NULL);
#line 407 "mn-shell.c"
{
#line 172 "mn-shell.gob"
	
    mn_summary_dialog_display();
  }}
#line 413 "mn-shell.c"
#undef __GOB_FUNCTION__

#line 176 "mn-shell.gob"
static void 
mn_shell_icon_activate_mail_reader_h (MNMailIcon * icon, gpointer user_data)
#line 419 "mn-shell.c"
{
#define __GOB_FUNCTION__ "MN:Shell::icon_activate_mail_reader_h"
#line 176 "mn-shell.gob"
	g_return_if_fail (icon != NULL);
#line 176 "mn-shell.gob"
	g_return_if_fail (MN_IS_MAIL_ICON (icon));
#line 176 "mn-shell.gob"
	g_return_if_fail (user_data != NULL);
#line 428 "mn-shell.c"
{
#line 179 "mn-shell.gob"
	
    if (eel_gconf_get_boolean(MN_CONF_COMMANDS_MAIL_READER_ENABLED))
      mn_execute_command(MN_CONF_COMMANDS_MAIL_READER_COMMAND);
  }}
#line 435 "mn-shell.c"
#undef __GOB_FUNCTION__

#line 184 "mn-shell.gob"
static void 
mn_shell_icon_activate_update_h (MNMailIcon * icon, gpointer user_data)
#line 441 "mn-shell.c"
{
#define __GOB_FUNCTION__ "MN:Shell::icon_activate_update_h"
#line 184 "mn-shell.gob"
	g_return_if_fail (icon != NULL);
#line 184 "mn-shell.gob"
	g_return_if_fail (MN_IS_MAIL_ICON (icon));
#line 184 "mn-shell.gob"
	g_return_if_fail (user_data != NULL);
#line 450 "mn-shell.c"
{
#line 187 "mn-shell.gob"
	
    Self *self = user_data;
    mn_mailboxes_check(self->mailboxes);
  }}
#line 457 "mn-shell.c"
#undef __GOB_FUNCTION__

#line 192 "mn-shell.gob"
static void 
mn_shell_icon_activate_properties_h (MNMailIcon * icon, gpointer user_data)
#line 463 "mn-shell.c"
{
#define __GOB_FUNCTION__ "MN:Shell::icon_activate_properties_h"
#line 192 "mn-shell.gob"
	g_return_if_fail (icon != NULL);
#line 192 "mn-shell.gob"
	g_return_if_fail (MN_IS_MAIL_ICON (icon));
#line 192 "mn-shell.gob"
	g_return_if_fail (user_data != NULL);
#line 472 "mn-shell.c"
{
#line 195 "mn-shell.gob"
	
    mn_properties_display();
  }}
#line 478 "mn-shell.c"
#undef __GOB_FUNCTION__

#line 199 "mn-shell.gob"
static void 
mn_shell_icon_activate_help_h (MNMailIcon * icon, gpointer user_data)
#line 484 "mn-shell.c"
{
#define __GOB_FUNCTION__ "MN:Shell::icon_activate_help_h"
#line 199 "mn-shell.gob"
	g_return_if_fail (icon != NULL);
#line 199 "mn-shell.gob"
	g_return_if_fail (MN_IS_MAIL_ICON (icon));
#line 199 "mn-shell.gob"
	g_return_if_fail (user_data != NULL);
#line 493 "mn-shell.c"
{
#line 202 "mn-shell.gob"
	
    mn_display_help(NULL, NULL);
  }}
#line 499 "mn-shell.c"
#undef __GOB_FUNCTION__

#line 206 "mn-shell.gob"
static void 
mn_shell_icon_activate_about_h (MNMailIcon * icon, gpointer user_data)
#line 505 "mn-shell.c"
{
#define __GOB_FUNCTION__ "MN:Shell::icon_activate_about_h"
#line 206 "mn-shell.gob"
	g_return_if_fail (icon != NULL);
#line 206 "mn-shell.gob"
	g_return_if_fail (MN_IS_MAIL_ICON (icon));
#line 206 "mn-shell.gob"
	g_return_if_fail (user_data != NULL);
#line 514 "mn-shell.c"
{
#line 209 "mn-shell.gob"
	
    Self *self = user_data;
    self_display_about(self);
  }}
#line 521 "mn-shell.c"
#undef __GOB_FUNCTION__

#line 214 "mn-shell.gob"
static void 
mn_shell_icon_activate_remove_h (MNMailIcon * icon, gpointer user_data)
#line 527 "mn-shell.c"
{
#define __GOB_FUNCTION__ "MN:Shell::icon_activate_remove_h"
#line 214 "mn-shell.gob"
	g_return_if_fail (icon != NULL);
#line 214 "mn-shell.gob"
	g_return_if_fail (MN_IS_MAIL_ICON (icon));
#line 214 "mn-shell.gob"
	g_return_if_fail (user_data != NULL);
#line 536 "mn-shell.c"
{
#line 217 "mn-shell.gob"
	
    Self *self = user_data;
    g_object_unref(self);
  }}
#line 543 "mn-shell.c"
#undef __GOB_FUNCTION__

#line 222 "mn-shell.gob"
static void 
mn_shell_icon_destroy_h (GtkObject * object, gpointer user_data)
#line 549 "mn-shell.c"
{
#define __GOB_FUNCTION__ "MN:Shell::icon_destroy_h"
#line 222 "mn-shell.gob"
	g_return_if_fail (object != NULL);
#line 222 "mn-shell.gob"
	g_return_if_fail (GTK_IS_OBJECT (object));
#line 222 "mn-shell.gob"
	g_return_if_fail (user_data != NULL);
#line 558 "mn-shell.c"
{
#line 225 "mn-shell.gob"
	
    Self *self = user_data;

    /* The Notification Area applet has been terminated. Recreate the icon. */
    self_init_icon(self);
  }}
#line 567 "mn-shell.c"
#undef __GOB_FUNCTION__

#line 232 "mn-shell.gob"
static void 
mn_shell_update_sensitivity (MNShell * self)
#line 573 "mn-shell.c"
{
#define __GOB_FUNCTION__ "MN:Shell::update_sensitivity"
#line 232 "mn-shell.gob"
	g_return_if_fail (self != NULL);
#line 232 "mn-shell.gob"
	g_return_if_fail (MN_IS_SHELL (self));
#line 580 "mn-shell.c"
{
#line 234 "mn-shell.gob"
	
    gboolean mail_reader_sensitive = FALSE;

    if (eel_gconf_get_boolean(MN_CONF_COMMANDS_MAIL_READER_ENABLED))
      {
	char *mail_reader;

	mail_reader = eel_gconf_get_string(MN_CONF_COMMANDS_MAIL_READER_COMMAND);
	if (mail_reader)
	  {
	    mail_reader_sensitive = TRUE;
	    g_free(mail_reader);
	  }
      }
    
    gtk_widget_set_sensitive(selfp->icon->mail_reader_item, mail_reader_sensitive);
    gtk_widget_set_sensitive(selfp->icon->update_item, mn_mailboxes_get_must_poll(self->mailboxes));
  }}
#line 601 "mn-shell.c"
#undef __GOB_FUNCTION__

#line 253 "mn-shell.gob"
static void 
mn_shell_update_icon (MNShell * self)
#line 607 "mn-shell.c"
{
#define __GOB_FUNCTION__ "MN:Shell::update_icon"
#line 253 "mn-shell.gob"
	g_return_if_fail (self != NULL);
#line 253 "mn-shell.gob"
	g_return_if_fail (MN_IS_SHELL (self));
#line 614 "mn-shell.c"
{
#line 255 "mn-shell.gob"
	
    GSList *mailboxes;
    GSList *l;
    int n_new = 0;
    gboolean blink = FALSE;

    mailboxes = mn_mailboxes_get(self->mailboxes);
    MN_LIST_FOREACH(l, mailboxes)
      {
	MNMailbox *mailbox = l->data;

	if (mn_mailbox_get_has_new(mailbox))
	  n_new++;
	if (! blink && (mn_mailbox_get_error(mailbox) || MN_IS_UNSUPPORTED_MAILBOX(mailbox)))
	  blink = TRUE;
      }

    if (blink && ! eel_gconf_get_boolean(MN_CONF_BLINK_ON_ERRORS))
      blink = FALSE;
    
    if (selfp->n_new > 0 && n_new == 0 && eel_gconf_get_boolean(MN_CONF_COMMANDS_MAIL_READ_ENABLED))
      mn_execute_command(MN_CONF_COMMANDS_MAIL_READ_COMMAND);
    selfp->n_new = n_new;
    
    if (n_new > 0 || blink)
      {
	mn_blinking_image_set_blinking(MN_BLINKING_IMAGE(selfp->icon->image), blink);
	gtk_widget_show(GTK_WIDGET(selfp->icon));
      }
    else
      gtk_widget_hide(GTK_WIDGET(selfp->icon));
  }}
#line 649 "mn-shell.c"
#undef __GOB_FUNCTION__

#line 288 "mn-shell.gob"
static void 
mn_shell_update_tooltip (MNShell * self)
#line 655 "mn-shell.c"
{
#define __GOB_FUNCTION__ "MN:Shell::update_tooltip"
#line 288 "mn-shell.gob"
	g_return_if_fail (self != NULL);
#line 288 "mn-shell.gob"
	g_return_if_fail (MN_IS_SHELL (self));
#line 662 "mn-shell.c"
{
#line 290 "mn-shell.gob"
	
    GtkWidget *vbox;
    GSList *mailboxes;
    GSList *messages;

    vbox = gtk_vbox_new(FALSE, 18);

    mailboxes = mn_mailboxes_get(self->mailboxes);
    if (mailboxes)
      {
	GSList *l;
	GString *new_string;
	GString *error_string;
	GString *unsupported_string;

	new_string = g_string_new(NULL);
	error_string = g_string_new(NULL);
	unsupported_string = g_string_new(NULL);

	MN_LIST_FOREACH(l, mailboxes)
          {
	    MNMailbox *mailbox = l->data;
	    const char *name;
	    const char *error;

	    name = mn_mailbox_get_name(mailbox);
	    error = mn_mailbox_get_error(mailbox);
	    
	    if (mn_mailbox_get_has_new(mailbox))
	      {
		int n_messages;

		if (*new_string->str)
		  g_string_append_c(new_string, '\n');
		g_string_append(new_string, name);
		
		n_messages = g_slist_length(mn_mailbox_get_messages(mailbox));
		if (n_messages > 0)
		  g_string_append_printf(new_string, " (%i)", n_messages);
	      }
	    
	    if (error)
	      {
		if (*error_string->str)
		  g_string_append_c(error_string, '\n');
		g_string_append_printf(error_string, "%s: %s", name, error);
	      }
	  
	    if (MN_IS_UNSUPPORTED_MAILBOX(mailbox))
	      {
		if (*unsupported_string->str)
		  g_string_append_c(unsupported_string, '\n');
		g_string_append_printf(unsupported_string, "%s: %s", name, mn_unsupported_mailbox_get_reason(MN_UNSUPPORTED_MAILBOX(mailbox)));
	      }
	  }

	if (*new_string->str)
	  self_tooltip_text_section_new(GTK_VBOX(vbox), _("Mailboxes Having New Mail"), new_string->str);
	if (*error_string->str)
	  self_tooltip_text_section_new(GTK_VBOX(vbox), _("Errors"), error_string->str);
	if (*unsupported_string->str)
	  self_tooltip_text_section_new(GTK_VBOX(vbox), _("Unsupported Mailboxes"), unsupported_string->str);

	g_string_free(new_string, TRUE);
	g_string_free(error_string, TRUE);
	g_string_free(unsupported_string, TRUE);
      }

    messages = mn_mailboxes_get_messages(mn_shell->mailboxes);
    if (messages)
      {
	GtkWidget *hbox;
	GtkWidget *messages_vbox;
	
	hbox = self_tooltip_section_new(GTK_VBOX(vbox), _("Mail Summary"));

	messages_vbox = gtk_vbox_new(FALSE, 0);
	mn_summary_update(GTK_VBOX(messages_vbox), messages, FALSE);
	mn_g_object_slist_free(messages);

	gtk_box_pack_start(GTK_BOX(hbox), messages_vbox, TRUE, TRUE, 0);
      }

    gtk_widget_show_all(vbox);
    mn_mail_icon_set_tip_widget(selfp->icon, vbox);
  }}
#line 751 "mn-shell.c"
#undef __GOB_FUNCTION__

#line 377 "mn-shell.gob"
static GtkWidget * 
mn_shell_tooltip_section_new (GtkVBox * vbox, const char * title)
#line 757 "mn-shell.c"
{
#define __GOB_FUNCTION__ "MN:Shell::tooltip_section_new"
#line 377 "mn-shell.gob"
	g_return_val_if_fail (vbox != NULL, (GtkWidget * )0);
#line 377 "mn-shell.gob"
	g_return_val_if_fail (GTK_IS_VBOX (vbox), (GtkWidget * )0);
#line 377 "mn-shell.gob"
	g_return_val_if_fail (title != NULL, (GtkWidget * )0);
#line 766 "mn-shell.c"
{
#line 380 "mn-shell.gob"
	
    GtkWidget *child_vbox;
    char *markup;
    GtkWidget *label;
    GtkWidget *hbox;

    child_vbox = gtk_vbox_new(FALSE, 6);

    markup = g_markup_printf_escaped("<span weight=\"bold\">%s</span>", title);
    label = gtk_label_new(markup);
    g_free(markup);

    gtk_misc_set_alignment(GTK_MISC(label), 0.0, 0.5);
    gtk_label_set_use_markup(GTK_LABEL(label), TRUE);

    gtk_box_pack_start(GTK_BOX(child_vbox), label, FALSE, FALSE, 0);

    hbox = gtk_hbox_new(FALSE, 0);

    label = gtk_label_new("    ");
    gtk_box_pack_start(GTK_BOX(hbox), label, FALSE, FALSE, 0);

    gtk_box_pack_start(GTK_BOX(child_vbox), hbox, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), child_vbox, TRUE, TRUE, 0);

    return hbox;
  }}
#line 796 "mn-shell.c"
#undef __GOB_FUNCTION__

#line 408 "mn-shell.gob"
static void 
mn_shell_tooltip_text_section_new (GtkVBox * vbox, const char * title, const char * text)
#line 802 "mn-shell.c"
{
#define __GOB_FUNCTION__ "MN:Shell::tooltip_text_section_new"
#line 408 "mn-shell.gob"
	g_return_if_fail (vbox != NULL);
#line 408 "mn-shell.gob"
	g_return_if_fail (GTK_IS_VBOX (vbox));
#line 408 "mn-shell.gob"
	g_return_if_fail (title != NULL);
#line 408 "mn-shell.gob"
	g_return_if_fail (text != NULL);
#line 813 "mn-shell.c"
{
#line 412 "mn-shell.gob"
	
    GtkWidget *hbox;
    GtkWidget *label;

    hbox = self_tooltip_section_new(GTK_VBOX(vbox), title);

    label = gtk_label_new(text);
    gtk_misc_set_alignment(GTK_MISC(label), 0.0, 0.5);

    gtk_box_pack_start(GTK_BOX(hbox), label, TRUE, TRUE, 0);
  }}
#line 827 "mn-shell.c"
#undef __GOB_FUNCTION__

#line 424 "mn-shell.gob"
MNShell * 
mn_shell_new (void)
#line 833 "mn-shell.c"
{
#define __GOB_FUNCTION__ "MN:Shell::new"
{
#line 426 "mn-shell.gob"
	
    return GET_NEW;
  }}
#line 841 "mn-shell.c"
#undef __GOB_FUNCTION__

#line 430 "mn-shell.gob"
void 
mn_shell_display_about (MNShell * self)
#line 847 "mn-shell.c"
{
#define __GOB_FUNCTION__ "MN:Shell::display_about"
#line 430 "mn-shell.gob"
	g_return_if_fail (self != NULL);
#line 430 "mn-shell.gob"
	g_return_if_fail (MN_IS_SHELL (self));
#line 854 "mn-shell.c"
{
#line 432 "mn-shell.gob"
	
    if (selfp->about)
      {
	gtk_window_present(GTK_WINDOW(selfp->about));
	return;
      }
    
    selfp->about = mn_about_dialog_new();
    eel_add_weak_pointer(&selfp->about);
    gtk_widget_show(GTK_WIDGET(selfp->about));
  }}
#line 868 "mn-shell.c"
#undef __GOB_FUNCTION__

#line 444 "mn-shell.gob"
void 
mn_shell_run_welcome (MNShell * self)
#line 874 "mn-shell.c"
{
#define __GOB_FUNCTION__ "MN:Shell::run_welcome"
#line 444 "mn-shell.gob"
	g_return_if_fail (self != NULL);
#line 444 "mn-shell.gob"
	g_return_if_fail (MN_IS_SHELL (self));
#line 881 "mn-shell.c"
{
#line 446 "mn-shell.gob"
	
    GtkWidget *dialog;
    int response;

    mn_create_interface("welcome", "dialog", &dialog, NULL);
    gtk_dialog_set_default_response(GTK_DIALOG(dialog), GTK_RESPONSE_OK);

    response = gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);

    if (response == GTK_RESPONSE_OK)
      mn_properties_display();
  }}
#line 897 "mn-shell.c"
#undef __GOB_FUNCTION__

#line 460 "mn-shell.gob"
void 
mn_shell_report (MNShell * self, char ** report)
#line 903 "mn-shell.c"
{
#define __GOB_FUNCTION__ "MN:Shell::report"
#line 460 "mn-shell.gob"
	g_return_if_fail (self != NULL);
#line 460 "mn-shell.gob"
	g_return_if_fail (MN_IS_SHELL (self));
#line 460 "mn-shell.gob"
	g_return_if_fail (report != NULL);
#line 912 "mn-shell.c"
{
#line 462 "mn-shell.gob"
	
    GString *string;
    GSList *l;

    string = g_string_new(NULL);
    MN_LIST_FOREACH(l, mn_mailboxes_get(self->mailboxes))
      {
	MNMailbox *mailbox = l->data;
	const char *error;

	error = mn_mailbox_get_error(mailbox);

	g_string_append_printf(string, "%s\n", mailbox->uri->text);

	if (mn_mailbox_get_has_new(mailbox))
	  g_string_append(string, " has-new\n");
	if (error)
	  g_string_append_printf(string, " error %s\n", error);
	if (MN_IS_UNSUPPORTED_MAILBOX(mailbox))
	  g_string_append_printf(string, " unsupported %s\n", mn_unsupported_mailbox_get_reason(MN_UNSUPPORTED_MAILBOX(mailbox)));
      }

    *report = string->str;
    g_string_free(string, FALSE);
  }}
#line 940 "mn-shell.c"
#undef __GOB_FUNCTION__