/* Generated by GOB (v2.0.11)   (do not edit directly) */

#ifndef __MN_IMAP_MAILBOX_PRIVATE_H__
#define __MN_IMAP_MAILBOX_PRIVATE_H__

#include "mn-imap-mailbox.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


#line 32 "mn-imap-mailbox.gob"

#include "mn-client-session.h"

#line 18 "mn-imap-mailbox-private.h"
struct _MNIMAPMailboxPrivate {
#line 143 "mn-imap-mailbox.gob"
	int removed;
#line 145 "mn-imap-mailbox.gob"
	MNClientSessionPrivate * idle_session;
#line 146 "mn-imap-mailbox.gob"
	GMutex * idle_session_mutex;
#line 26 "mn-imap-mailbox-private.h"
};

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif