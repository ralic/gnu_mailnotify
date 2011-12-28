/* Generated by GOB (v2.0.11) on Sun Mar  6 22:34:26 2005
   (do not edit directly) */

/* End world hunger, donate to the World Food Programme, http://www.wfp.org */

#define GOB_VERSION_MAJOR 2
#define GOB_VERSION_MINOR 0
#define GOB_VERSION_PATCHLEVEL 11

#define selfp (self->_priv)

#include "mn-mbox-mailbox.h"

#include "mn-mbox-mailbox-private.h"

#ifdef G_LIKELY
#define ___GOB_LIKELY(expr) G_LIKELY(expr)
#define ___GOB_UNLIKELY(expr) G_UNLIKELY(expr)
#else /* ! G_LIKELY */
#define ___GOB_LIKELY(expr) (expr)
#define ___GOB_UNLIKELY(expr) (expr)
#endif /* G_LIKELY */

#line 27 "mn-mbox-mailbox.gob"

#include "config.h"
#include <string.h>
#include <glib/gi18n.h>
#include <gdk/gdk.h>
#include "mn-mailbox-private.h"
#include "mn-vfs.h"
#include "mn-message-mime.h"
#include "mn-gmime-stream-vfs.h"
#include "mn-util.h"

#line 37 "mn-mbox-mailbox.c"
/* self casting macros */
#define SELF(x) MN_MBOX_MAILBOX(x)
#define SELF_CONST(x) MN_MBOX_MAILBOX_CONST(x)
#define IS_SELF(x) MN_IS_MBOX_MAILBOX(x)
#define TYPE_SELF MN_TYPE_MBOX_MAILBOX
#define SELF_CLASS(x) MN_MBOX_MAILBOX_CLASS(x)

#define SELF_GET_CLASS(x) MN_MBOX_MAILBOX_GET_CLASS(x)

/* self typedefs */
typedef MNmboxMailbox Self;
typedef MNmboxMailboxClass SelfClass;

/* here are local prototypes */
static void mn_mbox_mailbox_init (MNmboxMailbox * o) G_GNUC_UNUSED;
static void mn_mbox_mailbox_class_init (MNmboxMailboxClass * class) G_GNUC_UNUSED;
static GObject * ___2_mn_mbox_mailbox_constructor (GType type, unsigned int n_construct_properties, GObjectConstructParam * construct_params) G_GNUC_UNUSED;
static gboolean ___3_mn_mbox_mailbox_impl_is (MNMailbox * dummy, MNURI * uri) G_GNUC_UNUSED;
static void ___4_mn_mbox_mailbox_impl_check (MNMailbox * mailbox) G_GNUC_UNUSED;

/* pointer to the class of our parent */
static MNMailboxClass *parent_class = NULL;

GType
mn_mbox_mailbox_get_type (void)
{
	static GType type = 0;

	if ___GOB_UNLIKELY(type == 0) {
		static const GTypeInfo info = {
			sizeof (MNmboxMailboxClass),
			(GBaseInitFunc) NULL,
			(GBaseFinalizeFunc) NULL,
			(GClassInitFunc) mn_mbox_mailbox_class_init,
			(GClassFinalizeFunc) NULL,
			NULL /* class_data */,
			sizeof (MNmboxMailbox),
			0 /* n_preallocs */,
			(GInstanceInitFunc) mn_mbox_mailbox_init,
			NULL
		};

		type = g_type_register_static (MN_TYPE_MAILBOX, "MNmboxMailbox", &info, (GTypeFlags)0);
	}

	return type;
}

/* a macro for creating a new object of our type */
#define GET_NEW ((MNmboxMailbox *)g_object_new(mn_mbox_mailbox_get_type(), NULL))

/* a function for creating a new object of our type */
#include <stdarg.h>
static MNmboxMailbox * GET_NEW_VARG (const char *first, ...) G_GNUC_UNUSED;
static MNmboxMailbox *
GET_NEW_VARG (const char *first, ...)
{
	MNmboxMailbox *ret;
	va_list ap;
	va_start (ap, first);
	ret = (MNmboxMailbox *)g_object_new_valist (mn_mbox_mailbox_get_type (), first, ap);
	va_end (ap);
	return ret;
}


static void
___finalize(GObject *obj_self)
{
#define __GOB_FUNCTION__ "MN:mbox:Mailbox::finalize"
	MNmboxMailbox *self G_GNUC_UNUSED = MN_MBOX_MAILBOX (obj_self);
	gpointer priv G_GNUC_UNUSED = self->_priv;
	if(G_OBJECT_CLASS(parent_class)->finalize) \
		(* G_OBJECT_CLASS(parent_class)->finalize)(obj_self);
}
#undef __GOB_FUNCTION__

static void 
mn_mbox_mailbox_init (MNmboxMailbox * o G_GNUC_UNUSED)
{
#define __GOB_FUNCTION__ "MN:mbox:Mailbox::init"
	o->_priv = G_TYPE_INSTANCE_GET_PRIVATE(o,TYPE_SELF,MNmboxMailboxPrivate);
}
#undef __GOB_FUNCTION__
#line 43 "mn-mbox-mailbox.gob"
static void 
mn_mbox_mailbox_class_init (MNmboxMailboxClass * class G_GNUC_UNUSED)
#line 125 "mn-mbox-mailbox.c"
{
#define __GOB_FUNCTION__ "MN:mbox:Mailbox::class_init"
	GObjectClass *g_object_class G_GNUC_UNUSED = (GObjectClass*) class;
	MNMailboxClass *mn_mailbox_class = (MNMailboxClass *)class;

	g_type_class_add_private(class,sizeof(MNmboxMailboxPrivate));

	parent_class = g_type_class_ref (MN_TYPE_MAILBOX);

#line 48 "mn-mbox-mailbox.gob"
	g_object_class->constructor = ___2_mn_mbox_mailbox_constructor;
#line 72 "mn-mbox-mailbox.gob"
	mn_mailbox_class->impl_is = ___3_mn_mbox_mailbox_impl_is;
#line 113 "mn-mbox-mailbox.gob"
	mn_mailbox_class->impl_check = ___4_mn_mbox_mailbox_impl_check;
#line 141 "mn-mbox-mailbox.c"
	g_object_class->finalize = ___finalize;
 {
#line 44 "mn-mbox-mailbox.gob"

    MN_MAILBOX_CLASS(class)->format = "mbox";
  
#line 148 "mn-mbox-mailbox.c"
 }
}
#undef __GOB_FUNCTION__



#line 48 "mn-mbox-mailbox.gob"
static GObject * 
___2_mn_mbox_mailbox_constructor (GType type G_GNUC_UNUSED, unsigned int n_construct_properties, GObjectConstructParam * construct_params)
#line 158 "mn-mbox-mailbox.c"
#define PARENT_HANDLER(___type,___n_construct_properties,___construct_params) \
	((G_OBJECT_CLASS(parent_class)->constructor)? \
		(* G_OBJECT_CLASS(parent_class)->constructor)(___type,___n_construct_properties,___construct_params): \
		((GObject * )0))
{
#define __GOB_FUNCTION__ "MN:mbox:Mailbox::constructor"
{
#line 50 "mn-mbox-mailbox.gob"
	
    GObject *object;
    MNMailbox *self;

    object = PARENT_HANDLER(type, n_construct_properties, construct_params);
    self = MN_MAILBOX(object);
    
    GDK_THREADS_ENTER();

    mn_mailbox_monitor(self,
		       self->uri->text,
		       GNOME_VFS_MONITOR_FILE,
		       MN_MAILBOX_MONITOR_EVENT_CHANGED
		       | MN_MAILBOX_MONITOR_EVENT_DELETED
		       | MN_MAILBOX_MONITOR_EVENT_CREATED);

    gdk_flush();
    GDK_THREADS_LEAVE();

    return object;
  }}
#line 188 "mn-mbox-mailbox.c"
#undef __GOB_FUNCTION__
#undef PARENT_HANDLER

#line 72 "mn-mbox-mailbox.gob"
static gboolean 
___3_mn_mbox_mailbox_impl_is (MNMailbox * dummy G_GNUC_UNUSED, MNURI * uri)
#line 195 "mn-mbox-mailbox.c"
#define PARENT_HANDLER(___dummy,___uri) \
	((MN_MAILBOX_CLASS(parent_class)->impl_is)? \
		(* MN_MAILBOX_CLASS(parent_class)->impl_is)(___dummy,___uri): \
		((gboolean )0))
{
#define __GOB_FUNCTION__ "MN:mbox:Mailbox::impl_is"
#line 72 "mn-mbox-mailbox.gob"
	g_return_val_if_fail (uri != NULL, (gboolean )0);
#line 72 "mn-mbox-mailbox.gob"
	g_return_val_if_fail (MN_IS_URI (uri), (gboolean )0);
#line 206 "mn-mbox-mailbox.c"
{
#line 74 "mn-mbox-mailbox.gob"
	
    gboolean is = FALSE;
    
    if (uri->vfs)
      {
	GnomeVFSFileInfo *file_info;
	
	file_info = gnome_vfs_file_info_new();
	if (gnome_vfs_get_file_info_uri(uri->vfs, file_info, GNOME_VFS_FILE_INFO_FOLLOW_LINKS) == GNOME_VFS_OK
	    && file_info->valid_fields & GNOME_VFS_FILE_INFO_FIELDS_TYPE
	    && file_info->valid_fields & GNOME_VFS_FILE_INFO_FIELDS_SIZE
	    && file_info->type == GNOME_VFS_FILE_TYPE_REGULAR)
	  {
	    if (file_info->size == 0) /* can be an empty mbox */
	      is = TRUE;
	    else
	      {
		GnomeVFSHandle *handle;
		
		if (gnome_vfs_open_uri(&handle, uri->vfs, GNOME_VFS_OPEN_READ) == GNOME_VFS_OK)
		  {
		    char buf[5];
		    GnomeVFSFileSize bytes_read;
		
		    if (gnome_vfs_read(handle, buf, sizeof(buf), &bytes_read) == GNOME_VFS_OK
			&& bytes_read == sizeof(buf)
			&& ! strncmp(buf, "From ", sizeof(buf)))
		      is = TRUE;
		
		    gnome_vfs_close(handle);
		  }
	      }
	  }
	gnome_vfs_file_info_unref(file_info);
      }
    
    return is;
  }}
#line 247 "mn-mbox-mailbox.c"
#undef __GOB_FUNCTION__
#undef PARENT_HANDLER

#line 113 "mn-mbox-mailbox.gob"
static void 
___4_mn_mbox_mailbox_impl_check (MNMailbox * mailbox G_GNUC_UNUSED)
#line 254 "mn-mbox-mailbox.c"
#define PARENT_HANDLER(___mailbox) \
	{ if(MN_MAILBOX_CLASS(parent_class)->impl_check) \
		(* MN_MAILBOX_CLASS(parent_class)->impl_check)(___mailbox); }
{
#define __GOB_FUNCTION__ "MN:mbox:Mailbox::impl_check"
#line 113 "mn-mbox-mailbox.gob"
	g_return_if_fail (mailbox != NULL);
#line 113 "mn-mbox-mailbox.gob"
	g_return_if_fail (MN_IS_MAILBOX (mailbox));
#line 264 "mn-mbox-mailbox.c"
{
#line 115 "mn-mbox-mailbox.gob"
	
    Self *self = SELF(mailbox);
    gboolean check = TRUE;
    
    if (mn_mailbox_get_must_poll(mailbox))
      {
	GnomeVFSFileInfo *file_info;

	/* we're polling, so check only if the mailbox has changed since our last check */

	file_info = gnome_vfs_file_info_new();
	if (gnome_vfs_get_file_info_uri(mailbox->uri->vfs, file_info, GNOME_VFS_FILE_INFO_FOLLOW_LINKS) == GNOME_VFS_OK)
	  {
	    if (file_info->mtime == selfp->last_mtime)
	      check = FALSE;
	    else
	      selfp->last_mtime = file_info->mtime;
	  }
	gnome_vfs_file_info_unref(file_info);
      }

    if (check)
      {
	GnomeVFSResult result;
	GnomeVFSHandle *handle;

	result = gnome_vfs_open_uri(&handle, mailbox->uri->vfs, GNOME_VFS_OPEN_READ);
	if (result == GNOME_VFS_OK)
	  {
	    GMimeStream *stream;
	    GMimeParser *parser;
	    GSList *messages = NULL;

	    stream = mn_gmime_stream_vfs_new(handle, mailbox->uri->text);
	    parser = g_mime_parser_new_with_stream(stream);
	    g_object_unref(stream);

	    g_mime_parser_set_scan_from(parser, TRUE);
	    
	    while (! g_mime_parser_eos(parser))
	      {
		GMimeMessage *mime_message;

		mime_message = g_mime_parser_construct_message(parser);
		if (mime_message)
		  {
		    const char *status;
		    
		    status = g_mime_message_get_header(mime_message, "Status");
		    if (! (status && (strchr(status, 'O') || strchr(status, 'R'))))
		      messages = g_slist_append(messages, mn_message_new_from_mime_message(mailbox->uri, mime_message));

		    g_object_unref(mime_message);
		  }
	      }

	    g_object_unref(parser);
	    gnome_vfs_close(handle);
	    
	    GDK_THREADS_ENTER();
	    mn_mailbox_set_messages(mailbox, messages);
	    gdk_flush();
	    GDK_THREADS_LEAVE();

	    mn_g_object_slist_free(messages);
	  }
	else
	  {
	    GDK_THREADS_ENTER();
	    mn_mailbox_set_error(mailbox, _("unable to open mailbox: %s"), gnome_vfs_result_to_string(result));
	    gdk_flush();
	    GDK_THREADS_LEAVE();
	  }
      }

    GDK_THREADS_ENTER();
    mn_mailbox_end_check(mailbox);
    gdk_flush();
    GDK_THREADS_LEAVE();
  }}
#line 347 "mn-mbox-mailbox.c"
#undef __GOB_FUNCTION__
#undef PARENT_HANDLER
