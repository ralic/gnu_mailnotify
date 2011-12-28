/* Generated by GOB (v2.0.15)   (do not edit directly) */

#include <glib.h>
#include <glib-object.h>


#include "mn-base-mbox-mailbox-backend.h"

#ifndef __MN_MBOX_MAILBOX_BACKEND_H__
#define __MN_MBOX_MAILBOX_BACKEND_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


/*
 * Type checking and casting macros
 */
#define MN_TYPE_MBOX_MAILBOX_BACKEND	(mn_mbox_mailbox_backend_get_type())
#define MN_MBOX_MAILBOX_BACKEND(obj)	G_TYPE_CHECK_INSTANCE_CAST((obj), mn_mbox_mailbox_backend_get_type(), MNMboxMailboxBackend)
#define MN_MBOX_MAILBOX_BACKEND_CONST(obj)	G_TYPE_CHECK_INSTANCE_CAST((obj), mn_mbox_mailbox_backend_get_type(), MNMboxMailboxBackend const)
#define MN_MBOX_MAILBOX_BACKEND_CLASS(klass)	G_TYPE_CHECK_CLASS_CAST((klass), mn_mbox_mailbox_backend_get_type(), MNMboxMailboxBackendClass)
#define MN_IS_MBOX_MAILBOX_BACKEND(obj)	G_TYPE_CHECK_INSTANCE_TYPE((obj), mn_mbox_mailbox_backend_get_type ())

#define MN_MBOX_MAILBOX_BACKEND_GET_CLASS(obj)	G_TYPE_INSTANCE_GET_CLASS((obj), mn_mbox_mailbox_backend_get_type(), MNMboxMailboxBackendClass)

/*
 * Main object structure
 */
#ifndef __TYPEDEF_MN_MBOX_MAILBOX_BACKEND__
#define __TYPEDEF_MN_MBOX_MAILBOX_BACKEND__
typedef struct _MNMboxMailboxBackend MNMboxMailboxBackend;
#endif
struct _MNMboxMailboxBackend {
	MNBaseMboxMailboxBackend __parent__;
};

/*
 * Class definition
 */
typedef struct _MNMboxMailboxBackendClass MNMboxMailboxBackendClass;
struct _MNMboxMailboxBackendClass {
	MNBaseMboxMailboxBackendClass __parent__;
};


/*
 * Public methods
 */
GType	mn_mbox_mailbox_backend_get_type	(void) G_GNUC_CONST;

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif