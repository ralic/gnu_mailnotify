/* Generated by GOB (v2.0.14)   (do not edit directly) */

#ifndef __MN_SHELL_PRIVATE_H__
#define __MN_SHELL_PRIVATE_H__

#include "mn-shell.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

struct _MNShellPrivate {
#line 62 "mn-shell.gob"
	gboolean has_new;
#line 64 "mn-shell.gob"
	GtkWidget * properties_dialog;
#line 65 "mn-shell.gob"
	GSList * mailbox_properties_dialogs;
#line 66 "mn-shell.gob"
	GtkWidget * about_dialog;
#line 22 "mn-shell-private.h"
};

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif
