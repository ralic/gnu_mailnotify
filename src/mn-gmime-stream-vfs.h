/* Generated by GOB (v2.0.11)   (do not edit directly) */

#include <glib.h>
#include <glib-object.h>


#include <libgnomevfs/gnome-vfs.h>
#include <gmime/gmime.h>

#ifndef __MN_GMIME_STREAM_VFS_H__
#define __MN_GMIME_STREAM_VFS_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


/*
 * Type checking and casting macros
 */
#define MN_TYPE_GMIME_STREAM_VFS	(mn_gmime_stream_vfs_get_type())
#define MN_GMIME_STREAM_VFS(obj)	G_TYPE_CHECK_INSTANCE_CAST((obj), mn_gmime_stream_vfs_get_type(), MNGMimeStreamVFS)
#define MN_GMIME_STREAM_VFS_CONST(obj)	G_TYPE_CHECK_INSTANCE_CAST((obj), mn_gmime_stream_vfs_get_type(), MNGMimeStreamVFS const)
#define MN_GMIME_STREAM_VFS_CLASS(klass)	G_TYPE_CHECK_CLASS_CAST((klass), mn_gmime_stream_vfs_get_type(), MNGMimeStreamVFSClass)
#define MN_IS_GMIME_STREAM_VFS(obj)	G_TYPE_CHECK_INSTANCE_TYPE((obj), mn_gmime_stream_vfs_get_type ())

#define MN_GMIME_STREAM_VFS_GET_CLASS(obj)	G_TYPE_INSTANCE_GET_CLASS((obj), mn_gmime_stream_vfs_get_type(), MNGMimeStreamVFSClass)

/* Private structure type */
typedef struct _MNGMimeStreamVFSPrivate MNGMimeStreamVFSPrivate;

/*
 * Main object structure
 */
#ifndef __TYPEDEF_MN_GMIME_STREAM_VFS__
#define __TYPEDEF_MN_GMIME_STREAM_VFS__
typedef struct _MNGMimeStreamVFS MNGMimeStreamVFS;
#endif
struct _MNGMimeStreamVFS {
	GMimeStream __parent__;
	/*< private >*/
	MNGMimeStreamVFSPrivate *_priv;
};

/*
 * Class definition
 */
typedef struct _MNGMimeStreamVFSClass MNGMimeStreamVFSClass;
struct _MNGMimeStreamVFSClass {
	GMimeStreamClass __parent__;
};


/*
 * Public methods
 */
GType	mn_gmime_stream_vfs_get_type	(void);
GMimeStream * 	mn_gmime_stream_vfs_new	(GnomeVFSHandle * handle,
					const char * uri);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif