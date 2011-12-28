/* Generated by GOB (v2.0.9) on Thu Sep  9 01:42:01 2004
   (do not edit directly) */

/* End world hunger, donate to the World Food Programme, http://www.wfp.org */

#define GOB_VERSION_MAJOR 2
#define GOB_VERSION_MINOR 0
#define GOB_VERSION_PATCHLEVEL 9

#define selfp (self->_priv)

#include "mn-sylpheed-mailbox.h"

#include "mn-sylpheed-mailbox-private.h"

#ifdef G_LIKELY
#define ___GOB_LIKELY(expr) G_LIKELY(expr)
#define ___GOB_UNLIKELY(expr) G_UNLIKELY(expr)
#else /* ! G_LIKELY */
#define ___GOB_LIKELY(expr) (expr)
#define ___GOB_UNLIKELY(expr) (expr)
#endif /* G_LIKELY */

#line 22 "mn-sylpheed-mailbox.gob"

#include "config.h"
#include <glib/gi18n-lib.h>
#include "mn-mailbox-private.h"
#include "mn-vfs.h"
#include "mn-util.h"

#line 33 "mn-sylpheed-mailbox.c"
/* self casting macros */
#define SELF(x) MN_SYLPHEED_MAILBOX(x)
#define SELF_CONST(x) MN_SYLPHEED_MAILBOX_CONST(x)
#define IS_SELF(x) MN_IS_SYLPHEED_MAILBOX(x)
#define TYPE_SELF MN_TYPE_SYLPHEED_MAILBOX
#define SELF_CLASS(x) MN_SYLPHEED_MAILBOX_CLASS(x)

#define SELF_GET_CLASS(x) MN_SYLPHEED_MAILBOX_GET_CLASS(x)

/* self typedefs */
typedef MNSylpheedMailbox Self;
typedef MNSylpheedMailboxClass SelfClass;

/* here are local prototypes */
static void mn_sylpheed_mailbox_init (MNSylpheedMailbox * o) G_GNUC_UNUSED;
static void mn_sylpheed_mailbox_class_init (MNSylpheedMailboxClass * class) G_GNUC_UNUSED;
static GObject * ___2_mn_sylpheed_mailbox_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_params) G_GNUC_UNUSED;
static gboolean ___3_mn_sylpheed_mailbox_impl_is (MNMailbox * dummy, MNURI * uri) G_GNUC_UNUSED;
static void ___4_mn_sylpheed_mailbox_impl_threaded_check (MNMailbox * self) G_GNUC_UNUSED;

/* pointer to the class of our parent */
static MNMailboxClass *parent_class = NULL;

GType
mn_sylpheed_mailbox_get_type (void)
{
	static GType type = 0;

	if ___GOB_UNLIKELY(type == 0) {
		static const GTypeInfo info = {
			sizeof (MNSylpheedMailboxClass),
			(GBaseInitFunc) NULL,
			(GBaseFinalizeFunc) NULL,
			(GClassInitFunc) mn_sylpheed_mailbox_class_init,
			(GClassFinalizeFunc) NULL,
			NULL /* class_data */,
			sizeof (MNSylpheedMailbox),
			0 /* n_preallocs */,
			(GInstanceInitFunc) mn_sylpheed_mailbox_init,
			NULL
		};

		type = g_type_register_static (MN_TYPE_MAILBOX, "MNSylpheedMailbox", &info, (GTypeFlags)0);
	}

	return type;
}

/* a macro for creating a new object of our type */
#define GET_NEW ((MNSylpheedMailbox *)g_object_new(mn_sylpheed_mailbox_get_type(), NULL))

/* a function for creating a new object of our type */
#include <stdarg.h>
static MNSylpheedMailbox * GET_NEW_VARG (const char *first, ...) G_GNUC_UNUSED;
static MNSylpheedMailbox *
GET_NEW_VARG (const char *first, ...)
{
	MNSylpheedMailbox *ret;
	va_list ap;
	va_start (ap, first);
	ret = (MNSylpheedMailbox *)g_object_new_valist (mn_sylpheed_mailbox_get_type (), first, ap);
	va_end (ap);
	return ret;
}

static void 
mn_sylpheed_mailbox_init (MNSylpheedMailbox * o G_GNUC_UNUSED)
{
#define __GOB_FUNCTION__ "MN:Sylpheed:Mailbox::init"
}
#undef __GOB_FUNCTION__
#line 32 "mn-sylpheed-mailbox.gob"
static void 
mn_sylpheed_mailbox_class_init (MNSylpheedMailboxClass * class G_GNUC_UNUSED)
#line 108 "mn-sylpheed-mailbox.c"
{
#define __GOB_FUNCTION__ "MN:Sylpheed:Mailbox::class_init"
	GObjectClass *g_object_class = (GObjectClass *)class;
	MNMailboxClass *mn_mailbox_class = (MNMailboxClass *)class;

	parent_class = g_type_class_ref (MN_TYPE_MAILBOX);

#line 37 "mn-sylpheed-mailbox.gob"
	g_object_class->constructor = ___2_mn_sylpheed_mailbox_constructor;
#line 61 "mn-sylpheed-mailbox.gob"
	mn_mailbox_class->impl_is = ___3_mn_sylpheed_mailbox_impl_is;
#line 78 "mn-sylpheed-mailbox.gob"
	mn_mailbox_class->impl_threaded_check = ___4_mn_sylpheed_mailbox_impl_threaded_check;
#line 122 "mn-sylpheed-mailbox.c"
 {
#line 33 "mn-sylpheed-mailbox.gob"

    MN_MAILBOX_CLASS(class)->format = "Sylpheed";
  
#line 128 "mn-sylpheed-mailbox.c"
 }
}
#undef __GOB_FUNCTION__



#line 37 "mn-sylpheed-mailbox.gob"
static GObject * 
___2_mn_sylpheed_mailbox_constructor (GType type G_GNUC_UNUSED, guint n_construct_properties, GObjectConstructParam * construct_params)
#line 138 "mn-sylpheed-mailbox.c"
#define PARENT_HANDLER(___type,___n_construct_properties,___construct_params) \
	((G_OBJECT_CLASS(parent_class)->constructor)? \
		(* G_OBJECT_CLASS(parent_class)->constructor)(___type,___n_construct_properties,___construct_params): \
		((GObject * )0))
{
#define __GOB_FUNCTION__ "MN:Sylpheed:Mailbox::constructor"
{
#line 39 "mn-sylpheed-mailbox.gob"
	
    GObject *object;
    MNMailbox *self;

    object = PARENT_HANDLER(type, n_construct_properties, construct_params);
    self = MN_MAILBOX(object);
    
    GDK_THREADS_ENTER();

    mn_mailbox_monitor(self,
		       self->uri->text,
		       GNOME_VFS_MONITOR_DIRECTORY,
		       MN_MAILBOX_MONITOR_EVENT_CHANGED
		       | MN_MAILBOX_MONITOR_EVENT_DELETED
		       | MN_MAILBOX_MONITOR_EVENT_CREATED);

    gdk_flush();
    GDK_THREADS_LEAVE();

    return object;
  }}
#line 168 "mn-sylpheed-mailbox.c"
#undef __GOB_FUNCTION__
#undef PARENT_HANDLER

#line 61 "mn-sylpheed-mailbox.gob"
static gboolean 
___3_mn_sylpheed_mailbox_impl_is (MNMailbox * dummy G_GNUC_UNUSED, MNURI * uri)
#line 175 "mn-sylpheed-mailbox.c"
#define PARENT_HANDLER(___dummy,___uri) \
	((MN_MAILBOX_CLASS(parent_class)->impl_is)? \
		(* MN_MAILBOX_CLASS(parent_class)->impl_is)(___dummy,___uri): \
		((gboolean )0))
{
#define __GOB_FUNCTION__ "MN:Sylpheed:Mailbox::impl_is"
#line 61 "mn-sylpheed-mailbox.gob"
	g_return_val_if_fail (uri != NULL, (gboolean )0);
#line 61 "mn-sylpheed-mailbox.gob"
	g_return_val_if_fail (MN_IS_URI (uri), (gboolean )0);
#line 186 "mn-sylpheed-mailbox.c"
{
#line 63 "mn-sylpheed-mailbox.gob"
	
    gboolean is = FALSE;

    if (uri->vfs)
      {
	GnomeVFSURI *markfile_uri;

	markfile_uri = gnome_vfs_uri_append_file_name(uri->vfs, ".sylpheed_mark");
	is = mn_vfs_test(markfile_uri, G_FILE_TEST_IS_REGULAR);
	gnome_vfs_uri_unref(markfile_uri);
      }

    return is;
  }}
#line 203 "mn-sylpheed-mailbox.c"
#undef __GOB_FUNCTION__
#undef PARENT_HANDLER

#line 78 "mn-sylpheed-mailbox.gob"
static void 
___4_mn_sylpheed_mailbox_impl_threaded_check (MNMailbox * self G_GNUC_UNUSED)
#line 210 "mn-sylpheed-mailbox.c"
#define PARENT_HANDLER(___self) \
	{ if(MN_MAILBOX_CLASS(parent_class)->impl_threaded_check) \
		(* MN_MAILBOX_CLASS(parent_class)->impl_threaded_check)(___self); }
{
#define __GOB_FUNCTION__ "MN:Sylpheed:Mailbox::impl_threaded_check"
#line 78 "mn-sylpheed-mailbox.gob"
	g_return_if_fail (self != NULL);
#line 78 "mn-sylpheed-mailbox.gob"
	g_return_if_fail (MN_IS_MAILBOX (self));
#line 220 "mn-sylpheed-mailbox.c"
{
#line 80 "mn-sylpheed-mailbox.gob"
	
    GnomeVFSResult result;
    GnomeVFSResult close_result;
    GnomeVFSDirectoryHandle *handle;
    GnomeVFSFileInfo *file_info;
    int total_count = 0;
    int mark_count = 0;

    result = gnome_vfs_directory_open_from_uri(&handle, self->uri->vfs, GNOME_VFS_FILE_INFO_FOLLOW_LINKS);
    if (result != GNOME_VFS_OK)
      {
	GDK_THREADS_ENTER();
	
	mn_mailbox_set_error(self, _("unable to open folder: %s"), gnome_vfs_result_to_string(result));
	mn_mailbox_end_check(self);
	
	gdk_flush();
	GDK_THREADS_LEAVE();
	
	return;
      }

    file_info = gnome_vfs_file_info_new();
    while ((result = gnome_vfs_directory_read_next(handle, file_info)) == GNOME_VFS_OK)
      {
	if (file_info->name[0] != '.')
	  {
	    if (mn_str_isnumeric(file_info->name))
	      total_count++;
	  }
	else if (! strcmp(file_info->name, ".sylpheed_mark") && file_info->valid_fields & GNOME_VFS_FILE_INFO_FIELDS_SIZE)
	  /*
	   * Format of a Sylpheed markfile:
	   * int version, int num, int flags, int num, int flags, ...
	   */
	  mark_count = (file_info->size - sizeof(int)) / (sizeof(int) * 2);
      }
    gnome_vfs_file_info_unref(file_info);
    close_result = gnome_vfs_directory_close(handle);
    
    GDK_THREADS_ENTER();
    
    if (result == GNOME_VFS_ERROR_EOF)
      {
	if (close_result == GNOME_VFS_OK)
	  mn_mailbox_set_has_new(self, total_count != mark_count);
	else
	  mn_mailbox_set_error(self, _("unable to close folder: %s"), gnome_vfs_result_to_string(close_result));
      }
    else
      mn_mailbox_set_error(self, _("error while reading folder: %s"), gnome_vfs_result_to_string(result));
    mn_mailbox_end_check(self);

    gdk_flush();
    GDK_THREADS_LEAVE();
  }}
#line 279 "mn-sylpheed-mailbox.c"
#undef __GOB_FUNCTION__
#undef PARENT_HANDLER
