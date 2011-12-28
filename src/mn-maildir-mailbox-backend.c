/* Generated by GOB (v2.0.14)   (do not edit directly) */

/* End world hunger, donate to the World Food Programme, http://www.wfp.org */

#define GOB_VERSION_MAJOR 2
#define GOB_VERSION_MINOR 0
#define GOB_VERSION_PATCHLEVEL 14

#define selfp (self->_priv)

#include "mn-maildir-mailbox-backend.h"

#include "mn-maildir-mailbox-backend-private.h"

#ifdef G_LIKELY
#define ___GOB_LIKELY(expr) G_LIKELY(expr)
#define ___GOB_UNLIKELY(expr) G_UNLIKELY(expr)
#else /* ! G_LIKELY */
#define ___GOB_LIKELY(expr) (expr)
#define ___GOB_UNLIKELY(expr) (expr)
#endif /* G_LIKELY */

#line 26 "mn-maildir-mailbox-backend.gob"

#include "config.h"
#include <string.h>
#include <stdlib.h>
#include <glib/gi18n.h>
#include <eel/eel.h>
#include "mn-mailbox-private.h"
#include "mn-reentrant-mailbox-private.h"
#include "mn-vfs-mailbox-backend-private.h"
#include "mn-vfs.h"
#include "mn-util.h"
#include "mn-message-mime.h"

#line 38 "mn-maildir-mailbox-backend.c"
/* self casting macros */
#define SELF(x) MN_MAILDIR_MAILBOX_BACKEND(x)
#define SELF_CONST(x) MN_MAILDIR_MAILBOX_BACKEND_CONST(x)
#define IS_SELF(x) MN_IS_MAILDIR_MAILBOX_BACKEND(x)
#define TYPE_SELF MN_TYPE_MAILDIR_MAILBOX_BACKEND
#define SELF_CLASS(x) MN_MAILDIR_MAILBOX_BACKEND_CLASS(x)

#define SELF_GET_CLASS(x) MN_MAILDIR_MAILBOX_BACKEND_GET_CLASS(x)

/* self typedefs */
typedef MNMaildirMailboxBackend Self;
typedef MNMaildirMailboxBackendClass SelfClass;

/* here are local prototypes */
static void mn_maildir_mailbox_backend_init (MNMaildirMailboxBackend * o) G_GNUC_UNUSED;
static void mn_maildir_mailbox_backend_class_init (MNMaildirMailboxBackendClass * class) G_GNUC_UNUSED;
static void ___2_mn_maildir_mailbox_backend_monitor_cb (MNVFSMailboxBackend * backend, const char * info_uri, GnomeVFSMonitorEventType event_type) G_GNUC_UNUSED;
static gboolean ___3_mn_maildir_mailbox_backend_is (MNVFSMailboxBackend * dummy, MNVFSMailboxBackendClass * class, MNVFSMailbox * mailbox) G_GNUC_UNUSED;
static void mn_maildir_mailbox_backend_monitor_directory (MNMaildirMailboxBackend * self, unsigned long check_id, const char * dir) G_GNUC_UNUSED;
static gboolean mn_maildir_mailbox_backend_scan_directory (MNMaildirMailboxBackend * self, unsigned long check_id, const char * dir, gboolean new, GSList ** messages, GError ** err) G_GNUC_UNUSED;
static void ___6_mn_maildir_mailbox_backend_check (MNVFSMailboxBackend * backend, unsigned long check_id) G_GNUC_UNUSED;
static int mn_maildir_mailbox_backend_flags_sort_cb (const void * a, const void * b) G_GNUC_UNUSED;
static gboolean ___8_mn_maildir_mailbox_backend_mark_as_read (MNVFSMailboxBackend * dummy, MNVFSMessage * message, GError ** err) G_GNUC_UNUSED;

/* pointer to the class of our parent */
static MNVFSMailboxBackendClass *parent_class = NULL;

/* Short form macros */
#define self_monitor_directory mn_maildir_mailbox_backend_monitor_directory
#define self_scan_directory mn_maildir_mailbox_backend_scan_directory
#define self_flags_sort_cb mn_maildir_mailbox_backend_flags_sort_cb
GType
mn_maildir_mailbox_backend_get_type (void)
{
	static GType type = 0;

	if ___GOB_UNLIKELY(type == 0) {
		static const GTypeInfo info = {
			sizeof (MNMaildirMailboxBackendClass),
			(GBaseInitFunc) NULL,
			(GBaseFinalizeFunc) NULL,
			(GClassInitFunc) mn_maildir_mailbox_backend_class_init,
			(GClassFinalizeFunc) NULL,
			NULL /* class_data */,
			sizeof (MNMaildirMailboxBackend),
			0 /* n_preallocs */,
			(GInstanceInitFunc) mn_maildir_mailbox_backend_init,
			NULL
		};

		type = g_type_register_static (MN_TYPE_VFS_MAILBOX_BACKEND, "MNMaildirMailboxBackend", &info, (GTypeFlags)0);
	}

	return type;
}

/* a macro for creating a new object of our type */
#define GET_NEW ((MNMaildirMailboxBackend *)g_object_new(mn_maildir_mailbox_backend_get_type(), NULL))

/* a function for creating a new object of our type */
#include <stdarg.h>
static MNMaildirMailboxBackend * GET_NEW_VARG (const char *first, ...) G_GNUC_UNUSED;
static MNMaildirMailboxBackend *
GET_NEW_VARG (const char *first, ...)
{
	MNMaildirMailboxBackend *ret;
	va_list ap;
	va_start (ap, first);
	ret = (MNMaildirMailboxBackend *)g_object_new_valist (mn_maildir_mailbox_backend_get_type (), first, ap);
	va_end (ap);
	return ret;
}

static void 
mn_maildir_mailbox_backend_init (MNMaildirMailboxBackend * o G_GNUC_UNUSED)
{
#define __GOB_FUNCTION__ "MN:Maildir:Mailbox:Backend::init"
}
#undef __GOB_FUNCTION__
#line 42 "mn-maildir-mailbox-backend.gob"
static void 
mn_maildir_mailbox_backend_class_init (MNMaildirMailboxBackendClass * class G_GNUC_UNUSED)
#line 121 "mn-maildir-mailbox-backend.c"
{
#define __GOB_FUNCTION__ "MN:Maildir:Mailbox:Backend::class_init"
	MNVFSMailboxBackendClass *mn_vfs_mailbox_backend_class = (MNVFSMailboxBackendClass *)class;

	parent_class = g_type_class_ref (MN_TYPE_VFS_MAILBOX_BACKEND);

#line 47 "mn-maildir-mailbox-backend.gob"
	mn_vfs_mailbox_backend_class->monitor_cb = ___2_mn_maildir_mailbox_backend_monitor_cb;
#line 69 "mn-maildir-mailbox-backend.gob"
	mn_vfs_mailbox_backend_class->is = ___3_mn_maildir_mailbox_backend_is;
#line 187 "mn-maildir-mailbox-backend.gob"
	mn_vfs_mailbox_backend_class->check = ___6_mn_maildir_mailbox_backend_check;
#line 231 "mn-maildir-mailbox-backend.gob"
	mn_vfs_mailbox_backend_class->mark_as_read = ___8_mn_maildir_mailbox_backend_mark_as_read;
#line 136 "mn-maildir-mailbox-backend.c"
 {
#line 43 "mn-maildir-mailbox-backend.gob"

    MN_VFS_MAILBOX_BACKEND_CLASS(class)->format = "Maildir";
  
#line 142 "mn-maildir-mailbox-backend.c"
 }
}
#undef __GOB_FUNCTION__



#line 47 "mn-maildir-mailbox-backend.gob"
static void 
___2_mn_maildir_mailbox_backend_monitor_cb (MNVFSMailboxBackend * backend G_GNUC_UNUSED, const char * info_uri, GnomeVFSMonitorEventType event_type)
#line 152 "mn-maildir-mailbox-backend.c"
#define PARENT_HANDLER(___backend,___info_uri,___event_type) \
	{ if(MN_VFS_MAILBOX_BACKEND_CLASS(parent_class)->monitor_cb) \
		(* MN_VFS_MAILBOX_BACKEND_CLASS(parent_class)->monitor_cb)(___backend,___info_uri,___event_type); }
{
#define __GOB_FUNCTION__ "MN:Maildir:Mailbox:Backend::monitor_cb"
{
#line 51 "mn-maildir-mailbox-backend.gob"
	
    if (event_type == GNOME_VFS_MONITOR_EVENT_CHANGED
	|| event_type == GNOME_VFS_MONITOR_EVENT_DELETED
	|| event_type == GNOME_VFS_MONITOR_EVENT_CREATED)
      {
	char *filename;

	filename = eel_uri_get_basename(info_uri);
	if (filename)
	  {
	    if (filename[0] != '.')
	      mn_reentrant_mailbox_queue_check(MN_REENTRANT_MAILBOX(backend->mailbox));

	    g_free(filename);
	  }
      }
  }}
#line 177 "mn-maildir-mailbox-backend.c"
#undef __GOB_FUNCTION__
#undef PARENT_HANDLER

#line 69 "mn-maildir-mailbox-backend.gob"
static gboolean 
___3_mn_maildir_mailbox_backend_is (MNVFSMailboxBackend * dummy G_GNUC_UNUSED, MNVFSMailboxBackendClass * class, MNVFSMailbox * mailbox)
#line 184 "mn-maildir-mailbox-backend.c"
#define PARENT_HANDLER(___dummy,___class,___mailbox) \
	((MN_VFS_MAILBOX_BACKEND_CLASS(parent_class)->is)? \
		(* MN_VFS_MAILBOX_BACKEND_CLASS(parent_class)->is)(___dummy,___class,___mailbox): \
		((gboolean )0))
{
#define __GOB_FUNCTION__ "MN:Maildir:Mailbox:Backend::is"
{
#line 73 "mn-maildir-mailbox-backend.gob"
	
    int i; 
    static const char *constitutive_dirs[] = { "cur", "new", "tmp" };
    gboolean is = FALSE;

    for (i = 0; i < G_N_ELEMENTS(constitutive_dirs); i++)
      {
	GnomeVFSURI *dir_uri;

	dir_uri = gnome_vfs_uri_append_path(mailbox->vfs_uri, constitutive_dirs[i]);
	is = mn_vfs_test(dir_uri, G_FILE_TEST_IS_DIR);
	gnome_vfs_uri_unref(dir_uri);

	if (! is)
	  break;
      }

    return is;
  }}
#line 212 "mn-maildir-mailbox-backend.c"
#undef __GOB_FUNCTION__
#undef PARENT_HANDLER

#line 93 "mn-maildir-mailbox-backend.gob"
static void 
mn_maildir_mailbox_backend_monitor_directory (MNMaildirMailboxBackend * self, unsigned long check_id, const char * dir)
#line 219 "mn-maildir-mailbox-backend.c"
{
#define __GOB_FUNCTION__ "MN:Maildir:Mailbox:Backend::monitor_directory"
#line 93 "mn-maildir-mailbox-backend.gob"
	g_return_if_fail (self != NULL);
#line 93 "mn-maildir-mailbox-backend.gob"
	g_return_if_fail (MN_IS_MAILDIR_MAILBOX_BACKEND (self));
#line 93 "mn-maildir-mailbox-backend.gob"
	g_return_if_fail (dir != NULL);
#line 228 "mn-maildir-mailbox-backend.c"
{
#line 95 "mn-maildir-mailbox-backend.gob"
	
    MNVFSMailboxBackend *backend = MN_VFS_MAILBOX_BACKEND(self);
    GnomeVFSURI *uri;
    char *text_uri;

    uri = gnome_vfs_uri_append_path(backend->mailbox->vfs_uri, dir);
    text_uri = gnome_vfs_uri_to_string(uri, GNOME_VFS_URI_HIDE_NONE);
    gnome_vfs_uri_unref(uri);

    mn_vfs_mailbox_backend_monitor(backend, check_id, text_uri, GNOME_VFS_MONITOR_DIRECTORY);
    g_free(text_uri);
  }}
#line 243 "mn-maildir-mailbox-backend.c"
#undef __GOB_FUNCTION__

#line 108 "mn-maildir-mailbox-backend.gob"
static gboolean 
mn_maildir_mailbox_backend_scan_directory (MNMaildirMailboxBackend * self, unsigned long check_id, const char * dir, gboolean new, GSList ** messages, GError ** err)
#line 249 "mn-maildir-mailbox-backend.c"
{
#define __GOB_FUNCTION__ "MN:Maildir:Mailbox:Backend::scan_directory"
#line 108 "mn-maildir-mailbox-backend.gob"
	g_return_val_if_fail (self != NULL, (gboolean )0);
#line 108 "mn-maildir-mailbox-backend.gob"
	g_return_val_if_fail (MN_IS_MAILDIR_MAILBOX_BACKEND (self), (gboolean )0);
#line 108 "mn-maildir-mailbox-backend.gob"
	g_return_val_if_fail (dir != NULL, (gboolean )0);
#line 108 "mn-maildir-mailbox-backend.gob"
	g_return_val_if_fail (messages != NULL, (gboolean )0);
#line 260 "mn-maildir-mailbox-backend.c"
{
#line 115 "mn-maildir-mailbox-backend.gob"
	
    MNVFSMailboxBackend *backend = MN_VFS_MAILBOX_BACKEND(self);
    GnomeVFSURI *uri;
    GnomeVFSResult result;
    GnomeVFSResult close_result;
    GnomeVFSDirectoryHandle *handle;
    GnomeVFSFileInfo *file_info;
    gboolean aborted = FALSE;

    uri = gnome_vfs_uri_append_path(backend->mailbox->vfs_uri, dir);

    result = gnome_vfs_directory_open_from_uri(&handle, uri, GNOME_VFS_FILE_INFO_FOLLOW_LINKS);
    if (result != GNOME_VFS_OK)
      {
	g_set_error(err, 0, 0, _("unable to open folder \"%s\": %s"), dir, gnome_vfs_result_to_string(result));
	gnome_vfs_uri_unref(uri);
	return FALSE;
      }

    file_info = gnome_vfs_file_info_new();
    while ((result = gnome_vfs_directory_read_next(handle, file_info)) == GNOME_VFS_OK)
      if (file_info->name[0] != '.')
	{
	  MNMessageFlags flags = 0;

	  if (mn_reentrant_mailbox_check_aborted(MN_REENTRANT_MAILBOX(backend->mailbox), check_id))
	    {
	      aborted = TRUE;
	      break;
	    }

	  if (new)
	    flags |= MN_MESSAGE_NEW;
	  else
	    {
	      char *info;

	      /* http://cr.yp.to/proto/maildir.html */

	      info = strrchr(file_info->name, ':');
	      if (! info
		  || ! g_str_has_prefix(info + 1, "2,")
		  || strpbrk(info + 3, "ST"))
		continue; /* no info, or message seen/trashed: ignore it */
	    }

	  *messages = g_slist_prepend(*messages, mn_vfs_message_new(backend,
								    uri,
								    file_info->name,
								    flags,
								    FALSE));
	}
    gnome_vfs_uri_unref(uri);
    gnome_vfs_file_info_unref(file_info);
    close_result = gnome_vfs_directory_close(handle);

    if (! aborted)
      {
	if (result == GNOME_VFS_ERROR_EOF || result == GNOME_VFS_OK)
	  {
	    if (close_result == GNOME_VFS_OK)
	      return TRUE;
	    else
	      g_set_error(err, 0, 0, _("unable to close folder \"%s\": %s"), dir, gnome_vfs_result_to_string(close_result));
	  }
	else
	  g_set_error(err, 0, 0, _("error while reading folder \"%s\": %s"), dir, gnome_vfs_result_to_string(result));
      }

    return FALSE;
  }}
#line 334 "mn-maildir-mailbox-backend.c"
#undef __GOB_FUNCTION__

#line 187 "mn-maildir-mailbox-backend.gob"
static void 
___6_mn_maildir_mailbox_backend_check (MNVFSMailboxBackend * backend G_GNUC_UNUSED, unsigned long check_id)
#line 340 "mn-maildir-mailbox-backend.c"
#define PARENT_HANDLER(___backend,___check_id) \
	{ if(MN_VFS_MAILBOX_BACKEND_CLASS(parent_class)->check) \
		(* MN_VFS_MAILBOX_BACKEND_CLASS(parent_class)->check)(___backend,___check_id); }
{
#define __GOB_FUNCTION__ "MN:Maildir:Mailbox:Backend::check"
{
#line 189 "mn-maildir-mailbox-backend.gob"
	
    Self *self = SELF(backend);
    GSList *messages = NULL;
    GError *err = NULL;
    gboolean status;

    self_monitor_directory(self, check_id, "cur");
    self_monitor_directory(self, check_id, "new");

    status = self_scan_directory(self, check_id, "cur", FALSE, &messages, &err)
      && self_scan_directory(self, check_id, "new", TRUE, &messages, &err);

    GDK_THREADS_ENTER();

    if (! mn_reentrant_mailbox_check_aborted_unlocked(MN_REENTRANT_MAILBOX(backend->mailbox), check_id))
      {
	if (status)
	  mn_mailbox_set_messages(MN_MAILBOX(backend->mailbox), messages);
	else
	  mn_mailbox_set_error(MN_MAILBOX(backend->mailbox), "%s", err->message);
      }

    mn_g_object_slist_free(messages);

    gdk_flush();
    GDK_THREADS_LEAVE();

    if (err)
      g_error_free(err);
  }}
#line 378 "mn-maildir-mailbox-backend.c"
#undef __GOB_FUNCTION__
#undef PARENT_HANDLER

#line 220 "mn-maildir-mailbox-backend.gob"
static int 
mn_maildir_mailbox_backend_flags_sort_cb (const void * a, const void * b)
#line 385 "mn-maildir-mailbox-backend.c"
{
#define __GOB_FUNCTION__ "MN:Maildir:Mailbox:Backend::flags_sort_cb"
{
#line 222 "mn-maildir-mailbox-backend.gob"
	
    char ca = *((char *) a);
    char cb = *((char *) b);

    /* sort flags using ASCII order, see http://cr.yp.to/proto/maildir.html */

    return ca - cb;
  }}
#line 398 "mn-maildir-mailbox-backend.c"
#undef __GOB_FUNCTION__

#line 231 "mn-maildir-mailbox-backend.gob"
static gboolean 
___8_mn_maildir_mailbox_backend_mark_as_read (MNVFSMailboxBackend * dummy G_GNUC_UNUSED, MNVFSMessage * message, GError ** err)
#line 404 "mn-maildir-mailbox-backend.c"
#define PARENT_HANDLER(___dummy,___message,___err) \
	((MN_VFS_MAILBOX_BACKEND_CLASS(parent_class)->mark_as_read)? \
		(* MN_VFS_MAILBOX_BACKEND_CLASS(parent_class)->mark_as_read)(___dummy,___message,___err): \
		((gboolean )0))
{
#define __GOB_FUNCTION__ "MN:Maildir:Mailbox:Backend::mark_as_read"
{
#line 235 "mn-maildir-mailbox-backend.gob"
	
    char *old_flags;
    char *old_filename;
    char *new_filename;
    GnomeVFSURI *dir_uri;
    GnomeVFSURI *new_uri;
    GnomeVFSResult result;
    gboolean status;

    /* http://cr.yp.to/proto/maildir.html */

    old_filename = gnome_vfs_uri_extract_short_name(message->vfs_uri);

    old_flags = strrchr(old_filename, ',');
    if (old_flags)
      {
	char *new_flags;
	int old_len;
	char *base_filename;

	/* append the S (seen) flag */

	old_flags++;
	g_assert(strchr(old_flags, 'S') == NULL);

	old_len = strlen(old_flags);
	new_flags = g_new(char, old_len + 2); /* + space for S and nul */
	memcpy(new_flags, old_flags, old_len);
	new_flags[old_len] = 'S';
	new_flags[old_len + 1] = 0;
	qsort(new_flags, old_len + 1, sizeof(char), self_flags_sort_cb);

	base_filename = g_strndup(old_filename, old_flags - old_filename - 1);
	new_filename = g_strdup_printf("%s,%s", base_filename, new_flags);
	g_free(base_filename);
	g_free(new_flags);
      }
    else
      new_filename = g_strconcat(old_filename, ":2,S", NULL);

    g_free(old_filename);

    dir_uri = gnome_vfs_uri_append_path(MN_VFS_MAILBOX(MN_MESSAGE(message)->mailbox)->vfs_uri, "cur");
    new_uri = gnome_vfs_uri_append_file_name(dir_uri, new_filename);
    gnome_vfs_uri_unref(dir_uri);
    g_free(new_filename);

    result = gnome_vfs_move_uri(message->vfs_uri, new_uri, TRUE);
    status = result == GNOME_VFS_OK;
    if (! status)
      g_set_error(err, 0, 0, "%s", gnome_vfs_result_to_string(result));

    gnome_vfs_uri_unref(new_uri);

    return status;
  }}
#line 469 "mn-maildir-mailbox-backend.c"
#undef __GOB_FUNCTION__
#undef PARENT_HANDLER
