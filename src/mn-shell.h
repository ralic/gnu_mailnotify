/* Generated by GOB (v2.0.11)   (do not edit directly) */

#include <glib.h>
#include <glib-object.h>


#include <gtk/gtk.h>
#include "mn-mailboxes.h"
#include "mn-mailbox-properties-dialog.h"

#ifndef __MN_SHELL_H__
#define __MN_SHELL_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


/*
 * Type checking and casting macros
 */
#define MN_TYPE_SHELL	(mn_shell_get_type())
#define MN_SHELL(obj)	G_TYPE_CHECK_INSTANCE_CAST((obj), mn_shell_get_type(), MNShell)
#define MN_SHELL_CONST(obj)	G_TYPE_CHECK_INSTANCE_CAST((obj), mn_shell_get_type(), MNShell const)
#define MN_SHELL_CLASS(klass)	G_TYPE_CHECK_CLASS_CAST((klass), mn_shell_get_type(), MNShellClass)
#define MN_IS_SHELL(obj)	G_TYPE_CHECK_INSTANCE_TYPE((obj), mn_shell_get_type ())

#define MN_SHELL_GET_CLASS(obj)	G_TYPE_INSTANCE_GET_CLASS((obj), mn_shell_get_type(), MNShellClass)

/* Private structure type */
typedef struct _MNShellPrivate MNShellPrivate;

/*
 * Main object structure
 */
#ifndef __TYPEDEF_MN_SHELL__
#define __TYPEDEF_MN_SHELL__
typedef struct _MNShell MNShell;
#endif
struct _MNShell {
	GObject __parent__;
	/*< public >*/
	MNMailboxes * mailboxes;
	/*< private >*/
	MNShellPrivate *_priv;
};

/*
 * Class definition
 */
typedef struct _MNShellClass MNShellClass;
struct _MNShellClass {
	GObjectClass __parent__;
};


/*
 * Public methods
 */
GType	mn_shell_get_type	(void);
MNShell * 	mn_shell_new	(void);
void 	mn_shell_display_about_dialog	(MNShell * self);
void 	mn_shell_display_welcome_dialog	(MNShell * self);
void 	mn_shell_report	(MNShell * self,
					char ** report);
void 	mn_shell_add_mailbox_properties_dialog	(MNShell * self,
					MNMailboxPropertiesDialog * dialog);
MNMailboxPropertiesDialog * 	mn_shell_get_mailbox_properties_dialog	(MNShell * self,
					MNURI * uri);


  extern MNShell *mn_shell;


typedef enum {
	MN_POSITION_TOP_LEFT,
	MN_POSITION_TOP_RIGHT,
	MN_POSITION_BOTTOM_LEFT,
	MN_POSITION_BOTTOM_RIGHT
} MNPosition;
#define MN_TYPE_POSITION mn_position_get_type()
GType mn_position_get_type (void);


typedef enum {
	MN_ACTION_DISPLAY_MAIN_WINDOW,
	MN_ACTION_LAUNCH_MAIL_READER,
	MN_ACTION_UPDATE_MAIL_STATUS
} MNAction;
#define MN_TYPE_ACTION mn_action_get_type()
GType mn_action_get_type (void);


typedef enum {
	MN_TOOLBAR_STYLE_ICONS = GTK_TOOLBAR_ICONS,
	MN_TOOLBAR_STYLE_TEXT = GTK_TOOLBAR_TEXT,
	MN_TOOLBAR_STYLE_BOTH = GTK_TOOLBAR_BOTH,
	MN_TOOLBAR_STYLE_BOTH_HORIZ = GTK_TOOLBAR_BOTH_HORIZ,
	MN_TOOLBAR_STYLE_DESKTOP_DEFAULT
} MNToolbarStyle;
#define MN_TYPE_TOOLBAR_STYLE mn_toolbar_style_get_type()
GType mn_toolbar_style_get_type (void);


typedef enum {
	MN_ASPECT_SOURCE_THEME,
	MN_ASPECT_SOURCE_CUSTOM
} MNAspectSource;
#define MN_TYPE_ASPECT_SOURCE mn_aspect_source_get_type()
GType mn_aspect_source_get_type (void);


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif
