/* Generated by GOB (v2.0.11)   (do not edit directly) */

#include <glib.h>
#include <glib-object.h>


#include "mn-mailbox.h"

#ifndef __MN_MH_MAILBOX_H__
#define __MN_MH_MAILBOX_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


/*
 * Type checking and casting macros
 */
#define MN_TYPE_MH_MAILBOX	(mn_mh_mailbox_get_type())
#define MN_MH_MAILBOX(obj)	G_TYPE_CHECK_INSTANCE_CAST((obj), mn_mh_mailbox_get_type(), MNMHMailbox)
#define MN_MH_MAILBOX_CONST(obj)	G_TYPE_CHECK_INSTANCE_CAST((obj), mn_mh_mailbox_get_type(), MNMHMailbox const)
#define MN_MH_MAILBOX_CLASS(klass)	G_TYPE_CHECK_CLASS_CAST((klass), mn_mh_mailbox_get_type(), MNMHMailboxClass)
#define MN_IS_MH_MAILBOX(obj)	G_TYPE_CHECK_INSTANCE_TYPE((obj), mn_mh_mailbox_get_type ())

#define MN_MH_MAILBOX_GET_CLASS(obj)	G_TYPE_INSTANCE_GET_CLASS((obj), mn_mh_mailbox_get_type(), MNMHMailboxClass)

/*
 * Main object structure
 */
#ifndef __TYPEDEF_MN_MH_MAILBOX__
#define __TYPEDEF_MN_MH_MAILBOX__
typedef struct _MNMHMailbox MNMHMailbox;
#endif
struct _MNMHMailbox {
	MNMailbox __parent__;
};

/*
 * Class definition
 */
typedef struct _MNMHMailboxClass MNMHMailboxClass;
struct _MNMHMailboxClass {
	MNMailboxClass __parent__;
};


/*
 * Public methods
 */
GType	mn_mh_mailbox_get_type	(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif
