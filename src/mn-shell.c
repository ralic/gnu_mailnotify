/* Generated by GOB (v2.0.9) on Thu Sep  9 01:42:01 2004
   (do not edit directly) */

/* End world hunger, donate to the World Food Programme, http://www.wfp.org */

#define GOB_VERSION_MAJOR 2
#define GOB_VERSION_MINOR 0
#define GOB_VERSION_PATCHLEVEL 9

#define selfp (self->_priv)

#include "mn-shell.h"

#include "mn-shell-private.h"

#ifdef G_LIKELY
#define ___GOB_LIKELY(expr) G_LIKELY(expr)
#define ___GOB_UNLIKELY(expr) G_UNLIKELY(expr)
#else /* ! G_LIKELY */
#define ___GOB_LIKELY(expr) (expr)
#define ___GOB_UNLIKELY(expr) (expr)
#endif /* G_LIKELY */

#line 25 "mn-shell.gob"

#include "config.h"
#include <errno.h>
#include <gnome.h>
#include "mn-properties.h"
#include "mn-util.h"
#include "mn-conf.h"
#include "mn-mailboxes.h"
#include "mn-unsupported-mailbox.h"
#include "mn-about-dialog.h"

  MNShell *mn_shell = NULL;

#line 39 "mn-shell.c"
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
static void mn_shell_mailboxes_list_changed_h (MNMailboxes * mailboxes, gpointer user_data) G_GNUC_UNUSED;
static void mn_shell_mailboxes_status_changed_h (MNMailboxes * mailboxes, gpointer user_data) G_GNUC_UNUSED;
static void mn_shell_init_icon (MNShell * self) G_GNUC_UNUSED;
static void mn_shell_notify_double_clicked_command_cb (GConfClient * client, guint cnxn_id, GConfEntry * entry, gpointer user_data) G_GNUC_UNUSED;
static void mn_shell_notify_blink_on_errors_cb (GConfClient * client, guint cnxn_id, GConfEntry * entry, gpointer user_data) G_GNUC_UNUSED;
static void mn_shell_icon_activate_h (MNMailIcon * icon, gpointer user_data) G_GNUC_UNUSED;
static void mn_shell_icon_activate_run_h (MNMailIcon * icon, gpointer user_data) G_GNUC_UNUSED;
static void mn_shell_icon_activate_update_h (MNMailIcon * icon, gpointer user_data) G_GNUC_UNUSED;
static void mn_shell_icon_activate_properties_h (MNMailIcon * icon, gpointer user_data) G_GNUC_UNUSED;
static void mn_shell_icon_activate_help_h (MNMailIcon * icon, gpointer user_data) G_GNUC_UNUSED;
static void mn_shell_icon_activate_about_h (MNMailIcon * icon, gpointer user_data) G_GNUC_UNUSED;
static void mn_shell_icon_activate_remove_h (MNMailIcon * icon, gpointer user_data) G_GNUC_UNUSED;
static void mn_shell_icon_destroy_h (GtkObject * object, gpointer user_data) G_GNUC_UNUSED;
static void mn_shell_run_double_clicked_command (MNShell * self) G_GNUC_UNUSED;
static void mn_shell_update_command (MNShell * self) G_GNUC_UNUSED;
static void mn_shell_update_sensitivity (MNShell * self) G_GNUC_UNUSED;
static void mn_shell_update_icon (MNShell * self) G_GNUC_UNUSED;

/* pointer to the class of our parent */
static GObjectClass *parent_class = NULL;

/* Short form macros */
#define self_mailboxes_list_changed_h mn_shell_mailboxes_list_changed_h
#define self_mailboxes_status_changed_h mn_shell_mailboxes_status_changed_h
#define self_init_icon mn_shell_init_icon
#define self_notify_double_clicked_command_cb mn_shell_notify_double_clicked_command_cb
#define self_notify_blink_on_errors_cb mn_shell_notify_blink_on_errors_cb
#define self_icon_activate_h mn_shell_icon_activate_h
#define self_icon_activate_run_h mn_shell_icon_activate_run_h
#define self_icon_activate_update_h mn_shell_icon_activate_update_h
#define self_icon_activate_properties_h mn_shell_icon_activate_properties_h
#define self_icon_activate_help_h mn_shell_icon_activate_help_h
#define self_icon_activate_about_h mn_shell_icon_activate_about_h
#define self_icon_activate_remove_h mn_shell_icon_activate_remove_h
#define self_icon_destroy_h mn_shell_icon_destroy_h
#define self_run_double_clicked_command mn_shell_run_double_clicked_command
#define self_update_command mn_shell_update_command
#define self_update_sensitivity mn_shell_update_sensitivity
#define self_update_icon mn_shell_update_icon
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
#line 41 "mn-shell.gob"
	if(self->mailboxes) { ((*(void (*)(void *))g_object_unref)) (self->mailboxes); self->mailboxes = NULL; }
#line 152 "mn-shell.c"
}
#undef __GOB_FUNCTION__


static void
___finalize(GObject *obj_self)
{
#define __GOB_FUNCTION__ "MN:Shell::finalize"
	MNShell *self  G_GNUC_UNUSED = MN_SHELL (obj_self);
	gpointer priv = self->_priv;
#line 58 "mn-shell.gob"
	___2_mn_shell_finalize(obj_self);
#line 165 "mn-shell.c"
	g_free (priv);
}
#undef __GOB_FUNCTION__

static void 
mn_shell_class_init (MNShellClass * c G_GNUC_UNUSED)
{
#define __GOB_FUNCTION__ "MN:Shell::class_init"
	GObjectClass *g_object_class G_GNUC_UNUSED = (GObjectClass*) c;

	parent_class = g_type_class_ref (G_TYPE_OBJECT);

#line 58 "mn-shell.gob"
	g_object_class->finalize = ___finalize;
#line 180 "mn-shell.c"
	g_object_class->dispose = ___dispose;
}
#undef __GOB_FUNCTION__
#line 45 "mn-shell.gob"
static void 
mn_shell_init (MNShell * self G_GNUC_UNUSED)
#line 187 "mn-shell.c"
{
#define __GOB_FUNCTION__ "MN:Shell::init"
	self->_priv = g_new0 (MNShellPrivate, 1);
#line 41 "mn-shell.gob"
	self->mailboxes = mn_mailboxes_new();
#line 193 "mn-shell.c"
 {
#line 46 "mn-shell.gob"

    g_return_if_fail(mn_shell == NULL);
    g_object_add_weak_pointer(G_OBJECT(self), (gpointer *) &mn_shell);

    self_init_icon(self);
    eel_gconf_notification_add(MN_CONF_COMMANDS_DOUBLE_CLICKED_COMMAND, self_notify_double_clicked_command_cb, self);
    eel_gconf_notification_add(MN_CONF_BLINK_ON_ERRORS, self_notify_blink_on_errors_cb, self);

    g_signal_connect(G_OBJECT(self->mailboxes), "list-changed", G_CALLBACK(self_mailboxes_list_changed_h), self);
    g_signal_connect(G_OBJECT(self->mailboxes), "status-changed", G_CALLBACK(self_mailboxes_status_changed_h), self);
  
#line 207 "mn-shell.c"
 }
}
#undef __GOB_FUNCTION__



#line 58 "mn-shell.gob"
static void 
___2_mn_shell_finalize (GObject * object G_GNUC_UNUSED)
#line 217 "mn-shell.c"
#define PARENT_HANDLER(___object) \
	{ if(G_OBJECT_CLASS(parent_class)->finalize) \
		(* G_OBJECT_CLASS(parent_class)->finalize)(___object); }
{
#define __GOB_FUNCTION__ "MN:Shell::finalize"
{
#line 60 "mn-shell.gob"
	
    gtk_main_quit();
    PARENT_HANDLER(object);
  }}
#line 229 "mn-shell.c"
#undef __GOB_FUNCTION__
#undef PARENT_HANDLER

#line 65 "mn-shell.gob"
static void 
mn_shell_mailboxes_list_changed_h (MNMailboxes * mailboxes, gpointer user_data)
#line 236 "mn-shell.c"
{
#define __GOB_FUNCTION__ "MN:Shell::mailboxes_list_changed_h"
#line 65 "mn-shell.gob"
	g_return_if_fail (mailboxes != NULL);
#line 65 "mn-shell.gob"
	g_return_if_fail (MN_IS_MAILBOXES (mailboxes));
#line 65 "mn-shell.gob"
	g_return_if_fail (user_data != NULL);
#line 245 "mn-shell.c"
{
#line 68 "mn-shell.gob"
	
    Self *self = user_data;
    
    self_update_sensitivity(self);
    self_update_icon(self);
  }}
#line 254 "mn-shell.c"
#undef __GOB_FUNCTION__

#line 75 "mn-shell.gob"
static void 
mn_shell_mailboxes_status_changed_h (MNMailboxes * mailboxes, gpointer user_data)
#line 260 "mn-shell.c"
{
#define __GOB_FUNCTION__ "MN:Shell::mailboxes_status_changed_h"
#line 75 "mn-shell.gob"
	g_return_if_fail (mailboxes != NULL);
#line 75 "mn-shell.gob"
	g_return_if_fail (MN_IS_MAILBOXES (mailboxes));
#line 75 "mn-shell.gob"
	g_return_if_fail (user_data != NULL);
#line 269 "mn-shell.c"
{
#line 78 "mn-shell.gob"
	
    Self *self = user_data;

    self_update_icon(self);
  }}
#line 277 "mn-shell.c"
#undef __GOB_FUNCTION__

#line 84 "mn-shell.gob"
static void 
mn_shell_init_icon (MNShell * self)
#line 283 "mn-shell.c"
{
#define __GOB_FUNCTION__ "MN:Shell::init_icon"
#line 84 "mn-shell.gob"
	g_return_if_fail (self != NULL);
#line 84 "mn-shell.gob"
	g_return_if_fail (MN_IS_SHELL (self));
#line 290 "mn-shell.c"
{
#line 86 "mn-shell.gob"
	
    selfp->icon = MN_MAIL_ICON(mn_mail_icon_new());

    g_signal_connect(G_OBJECT(selfp->icon), "activate", G_CALLBACK(self_icon_activate_h), self);
    g_signal_connect(G_OBJECT(selfp->icon), "activate-run", G_CALLBACK(self_icon_activate_run_h), self);
    g_signal_connect(G_OBJECT(selfp->icon), "activate-update", G_CALLBACK(self_icon_activate_update_h), self);
    g_signal_connect(G_OBJECT(selfp->icon), "activate-properties", G_CALLBACK(self_icon_activate_properties_h), self);
    g_signal_connect(G_OBJECT(selfp->icon), "activate-help", G_CALLBACK(self_icon_activate_help_h), self);
    g_signal_connect(G_OBJECT(selfp->icon), "activate-about", G_CALLBACK(self_icon_activate_about_h), self);
    g_signal_connect(G_OBJECT(selfp->icon), "activate-remove", G_CALLBACK(self_icon_activate_remove_h), self);
    g_signal_connect(G_OBJECT(selfp->icon), "destroy", G_CALLBACK(self_icon_destroy_h), self);

    self_update_command(self);
    self_update_sensitivity(self);
    self_update_icon(self);
  }}
#line 309 "mn-shell.c"
#undef __GOB_FUNCTION__

#line 103 "mn-shell.gob"
static void 
mn_shell_notify_double_clicked_command_cb (GConfClient * client, guint cnxn_id, GConfEntry * entry, gpointer user_data)
#line 315 "mn-shell.c"
{
#define __GOB_FUNCTION__ "MN:Shell::notify_double_clicked_command_cb"
#line 103 "mn-shell.gob"
	g_return_if_fail (user_data != NULL);
#line 320 "mn-shell.c"
{
#line 108 "mn-shell.gob"
	
    Self *self = user_data;

    GDK_THREADS_ENTER();
    self_update_command(self);
    GDK_THREADS_LEAVE();
  }}
#line 330 "mn-shell.c"
#undef __GOB_FUNCTION__

#line 116 "mn-shell.gob"
static void 
mn_shell_notify_blink_on_errors_cb (GConfClient * client, guint cnxn_id, GConfEntry * entry, gpointer user_data)
#line 336 "mn-shell.c"
{
#define __GOB_FUNCTION__ "MN:Shell::notify_blink_on_errors_cb"
#line 116 "mn-shell.gob"
	g_return_if_fail (user_data != NULL);
#line 341 "mn-shell.c"
{
#line 121 "mn-shell.gob"
	
    Self *self = user_data;

    GDK_THREADS_ENTER();
    self_update_icon(self);
    GDK_THREADS_LEAVE();
  }}
#line 351 "mn-shell.c"
#undef __GOB_FUNCTION__

#line 129 "mn-shell.gob"
static void 
mn_shell_icon_activate_h (MNMailIcon * icon, gpointer user_data)
#line 357 "mn-shell.c"
{
#define __GOB_FUNCTION__ "MN:Shell::icon_activate_h"
#line 129 "mn-shell.gob"
	g_return_if_fail (icon != NULL);
#line 129 "mn-shell.gob"
	g_return_if_fail (MN_IS_MAIL_ICON (icon));
#line 129 "mn-shell.gob"
	g_return_if_fail (user_data != NULL);
#line 366 "mn-shell.c"
{
#line 132 "mn-shell.gob"
	
    Self *self = user_data;
    if (eel_gconf_get_boolean(MN_CONF_COMMANDS_DOUBLE_CLICKED_ENABLED))
      self_run_double_clicked_command(self);
  }}
#line 374 "mn-shell.c"
#undef __GOB_FUNCTION__

#line 138 "mn-shell.gob"
static void 
mn_shell_icon_activate_run_h (MNMailIcon * icon, gpointer user_data)
#line 380 "mn-shell.c"
{
#define __GOB_FUNCTION__ "MN:Shell::icon_activate_run_h"
#line 138 "mn-shell.gob"
	g_return_if_fail (icon != NULL);
#line 138 "mn-shell.gob"
	g_return_if_fail (MN_IS_MAIL_ICON (icon));
#line 138 "mn-shell.gob"
	g_return_if_fail (user_data != NULL);
#line 389 "mn-shell.c"
{
#line 141 "mn-shell.gob"
	
    Self *self = user_data;
    self_run_double_clicked_command(self);
  }}
#line 396 "mn-shell.c"
#undef __GOB_FUNCTION__

#line 146 "mn-shell.gob"
static void 
mn_shell_icon_activate_update_h (MNMailIcon * icon, gpointer user_data)
#line 402 "mn-shell.c"
{
#define __GOB_FUNCTION__ "MN:Shell::icon_activate_update_h"
#line 146 "mn-shell.gob"
	g_return_if_fail (icon != NULL);
#line 146 "mn-shell.gob"
	g_return_if_fail (MN_IS_MAIL_ICON (icon));
#line 146 "mn-shell.gob"
	g_return_if_fail (user_data != NULL);
#line 411 "mn-shell.c"
{
#line 149 "mn-shell.gob"
	
    Self *self = user_data;
    mn_mailboxes_check(self->mailboxes);
  }}
#line 418 "mn-shell.c"
#undef __GOB_FUNCTION__

#line 154 "mn-shell.gob"
static void 
mn_shell_icon_activate_properties_h (MNMailIcon * icon, gpointer user_data)
#line 424 "mn-shell.c"
{
#define __GOB_FUNCTION__ "MN:Shell::icon_activate_properties_h"
#line 154 "mn-shell.gob"
	g_return_if_fail (icon != NULL);
#line 154 "mn-shell.gob"
	g_return_if_fail (MN_IS_MAIL_ICON (icon));
#line 154 "mn-shell.gob"
	g_return_if_fail (user_data != NULL);
#line 433 "mn-shell.c"
{
#line 157 "mn-shell.gob"
	
    mn_properties_display();
  }}
#line 439 "mn-shell.c"
#undef __GOB_FUNCTION__

#line 161 "mn-shell.gob"
static void 
mn_shell_icon_activate_help_h (MNMailIcon * icon, gpointer user_data)
#line 445 "mn-shell.c"
{
#define __GOB_FUNCTION__ "MN:Shell::icon_activate_help_h"
#line 161 "mn-shell.gob"
	g_return_if_fail (icon != NULL);
#line 161 "mn-shell.gob"
	g_return_if_fail (MN_IS_MAIL_ICON (icon));
#line 161 "mn-shell.gob"
	g_return_if_fail (user_data != NULL);
#line 454 "mn-shell.c"
{
#line 164 "mn-shell.gob"
	
    mn_display_help(NULL);
  }}
#line 460 "mn-shell.c"
#undef __GOB_FUNCTION__

#line 168 "mn-shell.gob"
static void 
mn_shell_icon_activate_about_h (MNMailIcon * icon, gpointer user_data)
#line 466 "mn-shell.c"
{
#define __GOB_FUNCTION__ "MN:Shell::icon_activate_about_h"
#line 168 "mn-shell.gob"
	g_return_if_fail (icon != NULL);
#line 168 "mn-shell.gob"
	g_return_if_fail (MN_IS_MAIL_ICON (icon));
#line 168 "mn-shell.gob"
	g_return_if_fail (user_data != NULL);
#line 475 "mn-shell.c"
{
#line 171 "mn-shell.gob"
	
    Self *self = user_data;
    self_display_about(self);
  }}
#line 482 "mn-shell.c"
#undef __GOB_FUNCTION__

#line 176 "mn-shell.gob"
static void 
mn_shell_icon_activate_remove_h (MNMailIcon * icon, gpointer user_data)
#line 488 "mn-shell.c"
{
#define __GOB_FUNCTION__ "MN:Shell::icon_activate_remove_h"
#line 176 "mn-shell.gob"
	g_return_if_fail (icon != NULL);
#line 176 "mn-shell.gob"
	g_return_if_fail (MN_IS_MAIL_ICON (icon));
#line 176 "mn-shell.gob"
	g_return_if_fail (user_data != NULL);
#line 497 "mn-shell.c"
{
#line 179 "mn-shell.gob"
	
    Self *self = user_data;
    g_object_unref(self);
  }}
#line 504 "mn-shell.c"
#undef __GOB_FUNCTION__

#line 184 "mn-shell.gob"
static void 
mn_shell_icon_destroy_h (GtkObject * object, gpointer user_data)
#line 510 "mn-shell.c"
{
#define __GOB_FUNCTION__ "MN:Shell::icon_destroy_h"
#line 184 "mn-shell.gob"
	g_return_if_fail (object != NULL);
#line 184 "mn-shell.gob"
	g_return_if_fail (GTK_IS_OBJECT (object));
#line 184 "mn-shell.gob"
	g_return_if_fail (user_data != NULL);
#line 519 "mn-shell.c"
{
#line 187 "mn-shell.gob"
	
    Self *self = user_data;

    /* The Notification Area applet has been terminated. Recreate the icon. */
    self_init_icon(self);
  }}
#line 528 "mn-shell.c"
#undef __GOB_FUNCTION__

#line 194 "mn-shell.gob"
static void 
mn_shell_run_double_clicked_command (MNShell * self)
#line 534 "mn-shell.c"
{
#define __GOB_FUNCTION__ "MN:Shell::run_double_clicked_command"
#line 194 "mn-shell.gob"
	g_return_if_fail (self != NULL);
#line 194 "mn-shell.gob"
	g_return_if_fail (MN_IS_SHELL (self));
#line 541 "mn-shell.c"
{
#line 196 "mn-shell.gob"
	
    char *command;

    command = eel_gconf_get_string(MN_CONF_COMMANDS_DOUBLE_CLICKED_COMMAND);
    if (command)
      {
	if (gnome_execute_shell(NULL, command) < 0)
	  mn_error_dialog(NULL,
			  _("A command error has occurred"),
			  _("Unable to execute double-clicked command: %s."),
			  g_strerror(errno));
	
	g_free(command);
      }
  }}
#line 559 "mn-shell.c"
#undef __GOB_FUNCTION__

#line 212 "mn-shell.gob"
static void 
mn_shell_update_command (MNShell * self)
#line 565 "mn-shell.c"
{
#define __GOB_FUNCTION__ "MN:Shell::update_command"
#line 212 "mn-shell.gob"
	g_return_if_fail (self != NULL);
#line 212 "mn-shell.gob"
	g_return_if_fail (MN_IS_SHELL (self));
#line 572 "mn-shell.c"
{
#line 214 "mn-shell.gob"
	
    char *command;

    command = eel_gconf_get_string(MN_CONF_COMMANDS_DOUBLE_CLICKED_COMMAND);
    mn_mail_icon_set_command(selfp->icon, command);
    g_free(command);
  }}
#line 582 "mn-shell.c"
#undef __GOB_FUNCTION__

#line 222 "mn-shell.gob"
static void 
mn_shell_update_sensitivity (MNShell * self)
#line 588 "mn-shell.c"
{
#define __GOB_FUNCTION__ "MN:Shell::update_sensitivity"
#line 222 "mn-shell.gob"
	g_return_if_fail (self != NULL);
#line 222 "mn-shell.gob"
	g_return_if_fail (MN_IS_SHELL (self));
#line 595 "mn-shell.c"
{
#line 224 "mn-shell.gob"
	
    gtk_widget_set_sensitive(selfp->icon->update_item, mn_mailboxes_has_manual(self->mailboxes));
  }}
#line 601 "mn-shell.c"
#undef __GOB_FUNCTION__

#line 228 "mn-shell.gob"
static void 
mn_shell_update_icon (MNShell * self)
#line 607 "mn-shell.c"
{
#define __GOB_FUNCTION__ "MN:Shell::update_icon"
#line 228 "mn-shell.gob"
	g_return_if_fail (self != NULL);
#line 228 "mn-shell.gob"
	g_return_if_fail (MN_IS_SHELL (self));
#line 614 "mn-shell.c"
{
#line 230 "mn-shell.gob"
	
    GSList *mailboxes;
    gboolean show = FALSE;
    gboolean blink = FALSE;
    GString *tooltip = NULL;

    mailboxes = mn_mailboxes_get(self->mailboxes);
    if (mailboxes)
      {
	GSList *l;
	static int old_n_new = 0;
	int n_new = 0;
	int n_error = 0;
	int n_unsupported = 0;
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
		n_new++;
		if (*new_string->str)
		  g_string_append_c(new_string, '\n');
		g_string_append_printf(new_string, "    %s", name);
	      }
	    
	    if (error)
	      {
		n_error++;
		if (*error_string->str)
		  g_string_append_c(error_string, '\n');
		g_string_append_printf(error_string, "    %s (%s)", name, error);
	      }
	  
	    if (MN_IS_UNSUPPORTED_MAILBOX(mailbox))
	      {
		n_unsupported++;
		if (*unsupported_string->str)
		  g_string_append_c(unsupported_string, '\n');
		g_string_append_printf(unsupported_string, "    %s (%s)", name, mn_unsupported_mailbox_get_reason(MN_UNSUPPORTED_MAILBOX(mailbox)));
	      }
	  }

	if (n_new > 0)
	  show = TRUE;
	if ((n_error > 0 || n_unsupported > 0) && eel_gconf_get_boolean(MN_CONF_BLINK_ON_ERRORS))
	  blink = TRUE;
	
	if (n_new > 0)
	  g_string_prepend(new_string, ngettext("The following mailbox has new mail:\n",
						"The following mailboxes have new mail:\n",
						n_new));
	else
	  g_string_prepend(new_string, _("You have no new mail."));
	
	if (n_error > 0)
	  g_string_prepend(error_string, ngettext("The following mailbox reported an error:\n",
						  "The following mailboxes reported an error:\n",
						  n_error));
      
	if (n_unsupported > 0)
	  g_string_prepend(unsupported_string, ngettext("The following mailbox is unsupported:\n",
							"The following mailboxes are unsupported:\n",
							n_unsupported));
	
	tooltip = g_string_new(new_string->str);
	if (n_error > 0)
	  g_string_append_printf(tooltip, "\n\n%s", error_string->str);
	if (n_unsupported > 0)
	  g_string_append_printf(tooltip, "\n\n%s", unsupported_string->str);
	
	g_string_free(new_string, TRUE);
	g_string_free(error_string, TRUE);
	g_string_free(unsupported_string, TRUE);
	
	if (old_n_new == 0 && n_new > 0)
	  {
	    gnome_triggers_do(_("You have new mail."), NULL, "mail-notification", "new-mail", NULL);
	    if (eel_gconf_get_boolean(MN_CONF_COMMANDS_NEW_MAIL_ENABLED))
	      {
		char *command;
		
		command = eel_gconf_get_string(MN_CONF_COMMANDS_NEW_MAIL_COMMAND);
		if (command)
		  {
		    if (gnome_execute_shell(NULL, command) < 0)
		      mn_error_dialog(NULL,
				      _("A command error has occurred in Mail Notification"),
				      _("Unable to execute new mail command: %s."),
				      g_strerror(errno));
		    
		    g_free(command);
		  }
	      }
	  }
	old_n_new = n_new;
      }
    
    if (show || blink)
      {
	mn_tooltips_set_tip(selfp->icon->tooltips, GTK_WIDGET(selfp->icon), tooltip->str);
	mn_blinking_image_set_blinking(MN_BLINKING_IMAGE(selfp->icon->image), blink);
	gtk_widget_show(GTK_WIDGET(selfp->icon));
      }
    else
      gtk_widget_hide(GTK_WIDGET(selfp->icon));

    if (tooltip)
      g_string_free(tooltip, TRUE);
  }}
#line 740 "mn-shell.c"
#undef __GOB_FUNCTION__

#line 354 "mn-shell.gob"
MNShell * 
mn_shell_new (void)
#line 746 "mn-shell.c"
{
#define __GOB_FUNCTION__ "MN:Shell::new"
{
#line 356 "mn-shell.gob"
	
    return MN_SHELL(GET_NEW);
  }}
#line 754 "mn-shell.c"
#undef __GOB_FUNCTION__

#line 360 "mn-shell.gob"
void 
mn_shell_display_about (MNShell * self)
#line 760 "mn-shell.c"
{
#define __GOB_FUNCTION__ "MN:Shell::display_about"
#line 360 "mn-shell.gob"
	g_return_if_fail (self != NULL);
#line 360 "mn-shell.gob"
	g_return_if_fail (MN_IS_SHELL (self));
#line 767 "mn-shell.c"
{
#line 362 "mn-shell.gob"
	
    if (selfp->about)
      {
	gtk_window_present(GTK_WINDOW(selfp->about));
	return;
      }
    
    selfp->about = mn_about_dialog_new();
    g_object_add_weak_pointer(G_OBJECT(selfp->about), (gpointer *) &selfp->about);
    gtk_widget_show(GTK_WIDGET(selfp->about));
  }}
#line 781 "mn-shell.c"
#undef __GOB_FUNCTION__

#line 374 "mn-shell.gob"
void 
mn_shell_run_welcome (MNShell * self)
#line 787 "mn-shell.c"
{
#define __GOB_FUNCTION__ "MN:Shell::run_welcome"
#line 374 "mn-shell.gob"
	g_return_if_fail (self != NULL);
#line 374 "mn-shell.gob"
	g_return_if_fail (MN_IS_SHELL (self));
#line 794 "mn-shell.c"
{
#line 376 "mn-shell.gob"
	
    GtkWidget *dialog;
    int response;

    mn_create_interface("welcome", "dialog", &dialog, NULL);
    gtk_dialog_set_default_response(GTK_DIALOG(dialog), GTK_RESPONSE_OK);

    response = gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);

    if (response == GTK_RESPONSE_OK)
      mn_properties_display();
  }}
#line 810 "mn-shell.c"
#undef __GOB_FUNCTION__

#line 390 "mn-shell.gob"
void 
mn_shell_report (MNShell * self, char ** report)
#line 816 "mn-shell.c"
{
#define __GOB_FUNCTION__ "MN:Shell::report"
#line 390 "mn-shell.gob"
	g_return_if_fail (self != NULL);
#line 390 "mn-shell.gob"
	g_return_if_fail (MN_IS_SHELL (self));
#line 390 "mn-shell.gob"
	g_return_if_fail (report != NULL);
#line 825 "mn-shell.c"
{
#line 392 "mn-shell.gob"
	
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
#line 853 "mn-shell.c"
#undef __GOB_FUNCTION__
