/* Generated by GOB (v2.0.11)   (do not edit directly) */

#include <glib.h>
#include <glib-object.h>


#include <gtk/gtk.h>

#ifndef __MN_SYSTEM_MAILBOX_PROPERTIES_H__
#define __MN_SYSTEM_MAILBOX_PROPERTIES_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


/*
 * Type checking and casting macros
 */
#define MN_TYPE_SYSTEM_MAILBOX_PROPERTIES	(mn_system_mailbox_properties_get_type())
#define MN_SYSTEM_MAILBOX_PROPERTIES(obj)	G_TYPE_CHECK_INSTANCE_CAST((obj), mn_system_mailbox_properties_get_type(), MNSystemMailboxProperties)
#define MN_SYSTEM_MAILBOX_PROPERTIES_CONST(obj)	G_TYPE_CHECK_INSTANCE_CAST((obj), mn_system_mailbox_properties_get_type(), MNSystemMailboxProperties const)
#define MN_SYSTEM_MAILBOX_PROPERTIES_CLASS(klass)	G_TYPE_CHECK_CLASS_CAST((klass), mn_system_mailbox_properties_get_type(), MNSystemMailboxPropertiesClass)
#define MN_IS_SYSTEM_MAILBOX_PROPERTIES(obj)	G_TYPE_CHECK_INSTANCE_TYPE((obj), mn_system_mailbox_properties_get_type ())

#define MN_SYSTEM_MAILBOX_PROPERTIES_GET_CLASS(obj)	G_TYPE_INSTANCE_GET_CLASS((obj), mn_system_mailbox_properties_get_type(), MNSystemMailboxPropertiesClass)

/* Private structure type */
typedef struct _MNSystemMailboxPropertiesPrivate MNSystemMailboxPropertiesPrivate;

/*
 * Main object structure
 */
#ifndef __TYPEDEF_MN_SYSTEM_MAILBOX_PROPERTIES__
#define __TYPEDEF_MN_SYSTEM_MAILBOX_PROPERTIES__
typedef struct _MNSystemMailboxProperties MNSystemMailboxProperties;
#endif
struct _MNSystemMailboxProperties {
	GtkLabel __parent__;
	/*< private >*/
	MNSystemMailboxPropertiesPrivate *_priv;
};

/*
 * Class definition
 */
typedef struct _MNSystemMailboxPropertiesClass MNSystemMailboxPropertiesClass;
struct _MNSystemMailboxPropertiesClass {
	GtkLabelClass __parent__;
};


/*
 * Public methods
 */
GType	mn_system_mailbox_properties_get_type	(void);

/*
 * Argument wrapping macros
 */
#if defined(__GNUC__) && !defined(__STRICT_ANSI__)
#define MN_SYSTEM_MAILBOX_PROPERTIES_GET_PROP_LABEL(arg)	"label", __extension__ ({gchar **z = (arg); z;})
#define MN_SYSTEM_MAILBOX_PROPERTIES_PROP_SIZE_GROUP(arg)    	"size_group", __extension__ ({GObject *z = (arg); z;})
#define MN_SYSTEM_MAILBOX_PROPERTIES_GET_PROP_SIZE_GROUP(arg)	"size_group", __extension__ ({GObject **z = (arg); z;})
#define MN_SYSTEM_MAILBOX_PROPERTIES_GET_PROP_COMPLETE(arg)	"complete", __extension__ ({gboolean *z = (arg); z;})
#else /* __GNUC__ && !__STRICT_ANSI__ */
#define MN_SYSTEM_MAILBOX_PROPERTIES_GET_PROP_LABEL(arg)	"label",(gchar **)(arg)
#define MN_SYSTEM_MAILBOX_PROPERTIES_PROP_SIZE_GROUP(arg)    	"size_group",(GObject *)(arg)
#define MN_SYSTEM_MAILBOX_PROPERTIES_GET_PROP_SIZE_GROUP(arg)	"size_group",(GObject **)(arg)
#define MN_SYSTEM_MAILBOX_PROPERTIES_GET_PROP_COMPLETE(arg)	"complete",(gboolean *)(arg)
#endif /* __GNUC__ && !__STRICT_ANSI__ */


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif