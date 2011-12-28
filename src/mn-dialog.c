/* Generated by GOB (v2.0.14)   (do not edit directly) */

/* End world hunger, donate to the World Food Programme, http://www.wfp.org */

#define GOB_VERSION_MAJOR 2
#define GOB_VERSION_MINOR 0
#define GOB_VERSION_PATCHLEVEL 14

#define selfp (self->_priv)

#include <string.h> /* memset() */

#include "mn-dialog.h"

#include "mn-dialog-private.h"

#ifdef G_LIKELY
#define ___GOB_LIKELY(expr) G_LIKELY(expr)
#define ___GOB_UNLIKELY(expr) G_UNLIKELY(expr)
#else /* ! G_LIKELY */
#define ___GOB_LIKELY(expr) (expr)
#define ___GOB_UNLIKELY(expr) (expr)
#endif /* G_LIKELY */
/* self casting macros */
#define SELF(x) MN_DIALOG(x)
#define SELF_CONST(x) MN_DIALOG_CONST(x)
#define IS_SELF(x) MN_IS_DIALOG(x)
#define TYPE_SELF MN_TYPE_DIALOG
#define SELF_CLASS(x) MN_DIALOG_CLASS(x)

#define SELF_GET_CLASS(x) MN_DIALOG_GET_CLASS(x)

/* self typedefs */
typedef MNDialog Self;
typedef MNDialogClass SelfClass;

/* here are local prototypes */
static void mn_dialog_class_init (MNDialogClass * c) G_GNUC_UNUSED;
static void mn_dialog_init (MNDialog * self) G_GNUC_UNUSED;

/* pointer to the class of our parent */
static GtkDialogClass *parent_class = NULL;

GType
mn_dialog_get_type (void)
{
	static GType type = 0;

	if ___GOB_UNLIKELY(type == 0) {
		static const GTypeInfo info = {
			sizeof (MNDialogClass),
			(GBaseInitFunc) NULL,
			(GBaseFinalizeFunc) NULL,
			(GClassInitFunc) mn_dialog_class_init,
			(GClassFinalizeFunc) NULL,
			NULL /* class_data */,
			sizeof (MNDialog),
			0 /* n_preallocs */,
			(GInstanceInitFunc) mn_dialog_init,
			NULL
		};

		type = g_type_register_static (GTK_TYPE_DIALOG, "MNDialog", &info, (GTypeFlags)G_TYPE_FLAG_ABSTRACT);
	}

	return type;
}

/* a macro for creating a new object of our type */
#define GET_NEW ((MNDialog *)g_object_new(mn_dialog_get_type(), NULL))

/* a function for creating a new object of our type */
#include <stdarg.h>
static MNDialog * GET_NEW_VARG (const char *first, ...) G_GNUC_UNUSED;
static MNDialog *
GET_NEW_VARG (const char *first, ...)
{
	MNDialog *ret;
	va_list ap;
	va_start (ap, first);
	ret = (MNDialog *)g_object_new_valist (mn_dialog_get_type (), first, ap);
	va_end (ap);
	return ret;
}

static void 
mn_dialog_class_init (MNDialogClass * c G_GNUC_UNUSED)
{
#define __GOB_FUNCTION__ "MN:Dialog::class_init"

	parent_class = g_type_class_ref (GTK_TYPE_DIALOG);

}
#undef __GOB_FUNCTION__
#line 28 "mn-dialog.gob"
static void 
mn_dialog_init (MNDialog * self G_GNUC_UNUSED)
#line 99 "mn-dialog.c"
{
#define __GOB_FUNCTION__ "MN:Dialog::init"
 {
#line 29 "mn-dialog.gob"

    gtk_container_set_border_width(GTK_CONTAINER(self), 5);
    gtk_dialog_set_has_separator(GTK_DIALOG(self), FALSE);
    gtk_box_set_spacing(GTK_BOX(GTK_DIALOG(self)->vbox), 2);
  
#line 109 "mn-dialog.c"
 }
}
#undef __GOB_FUNCTION__


