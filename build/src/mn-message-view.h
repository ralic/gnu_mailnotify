/* Generated by GOB (v2.0.15)   (do not edit directly) */

#include <glib.h>
#include <glib-object.h>


#include "mn-text-table.h"
#include "mn-message.h"

#ifndef __MN_MESSAGE_VIEW_H__
#define __MN_MESSAGE_VIEW_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


/*
 * Type checking and casting macros
 */
#define MN_TYPE_MESSAGE_VIEW	(mn_message_view_get_type())
#define MN_MESSAGE_VIEW(obj)	G_TYPE_CHECK_INSTANCE_CAST((obj), mn_message_view_get_type(), MNMessageView)
#define MN_MESSAGE_VIEW_CONST(obj)	G_TYPE_CHECK_INSTANCE_CAST((obj), mn_message_view_get_type(), MNMessageView const)
#define MN_MESSAGE_VIEW_CLASS(klass)	G_TYPE_CHECK_CLASS_CAST((klass), mn_message_view_get_type(), MNMessageViewClass)
#define MN_IS_MESSAGE_VIEW(obj)	G_TYPE_CHECK_INSTANCE_TYPE((obj), mn_message_view_get_type ())

#define MN_MESSAGE_VIEW_GET_CLASS(obj)	G_TYPE_INSTANCE_GET_CLASS((obj), mn_message_view_get_type(), MNMessageViewClass)

/* Private structure type */
typedef struct _MNMessageViewPrivate MNMessageViewPrivate;

/*
 * Main object structure
 */
#ifndef __TYPEDEF_MN_MESSAGE_VIEW__
#define __TYPEDEF_MN_MESSAGE_VIEW__
typedef struct _MNMessageView MNMessageView;
#endif
struct _MNMessageView {
	MNTextTable __parent__;
	/*< private >*/
	MNMessageViewPrivate *_priv;
};

/*
 * Class definition
 */
typedef struct _MNMessageViewClass MNMessageViewClass;
struct _MNMessageViewClass {
	MNTextTableClass __parent__;
	void (* append_header) (MNMessageView * self);
	void (* append_message) (MNMessageView * self, MNMessage * message, time_t now);
	void (* append_message_separator) (MNMessageView * self);
};


/*
 * Public methods
 */
GType	mn_message_view_get_type	(void) G_GNUC_CONST;
#line 63 "src/mn-message-view.gob"
void 	mn_message_view_set_messages	(MNMessageView * self,
					GSList * messages);
#line 65 "mn-message-view.h"

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif