/* Generated by GOB (v2.0.11)   (do not edit directly) */

#include <glib.h>
#include <glib-object.h>


#include <gtk/gtk.h>

#ifndef __MN_TOOLTIPS_H__
#define __MN_TOOLTIPS_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


/*
 * Type checking and casting macros
 */
#define MN_TYPE_TOOLTIPS	(mn_tooltips_get_type())
#define MN_TOOLTIPS(obj)	G_TYPE_CHECK_INSTANCE_CAST((obj), mn_tooltips_get_type(), MNTooltips)
#define MN_TOOLTIPS_CONST(obj)	G_TYPE_CHECK_INSTANCE_CAST((obj), mn_tooltips_get_type(), MNTooltips const)
#define MN_TOOLTIPS_CLASS(klass)	G_TYPE_CHECK_CLASS_CAST((klass), mn_tooltips_get_type(), MNTooltipsClass)
#define MN_IS_TOOLTIPS(obj)	G_TYPE_CHECK_INSTANCE_TYPE((obj), mn_tooltips_get_type ())

#define MN_TOOLTIPS_GET_CLASS(obj)	G_TYPE_INSTANCE_GET_CLASS((obj), mn_tooltips_get_type(), MNTooltipsClass)

/* Private structure type */
typedef struct _MNTooltipsPrivate MNTooltipsPrivate;

/*
 * Main object structure
 */
#ifndef __TYPEDEF_MN_TOOLTIPS__
#define __TYPEDEF_MN_TOOLTIPS__
typedef struct _MNTooltips MNTooltips;
#endif
struct _MNTooltips {
	GObject __parent__;
	/*< private >*/
	MNTooltipsPrivate *_priv;
};

/*
 * Class definition
 */
typedef struct _MNTooltipsClass MNTooltipsClass;
struct _MNTooltipsClass {
	GObjectClass __parent__;
};


/*
 * Public methods
 */
GType	mn_tooltips_get_type	(void);
void 	mn_tooltips_set_tip_widget	(MNTooltips * self,
					GtkWidget * widget,
					GtkWidget * tip_widget);
void 	mn_tooltips_toggle_keyboard_mode	(GtkWidget * widget);
MNTooltips * 	mn_tooltips_new	(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif
