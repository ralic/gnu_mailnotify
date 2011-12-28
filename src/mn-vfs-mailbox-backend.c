/* Generated by GOB (v2.0.12) on Tue Aug  9 22:01:57 2005
   (do not edit directly) */

/* End world hunger, donate to the World Food Programme, http://www.wfp.org */

#define GOB_VERSION_MAJOR 2
#define GOB_VERSION_MINOR 0
#define GOB_VERSION_PATCHLEVEL 12

#define selfp (self->_priv)

#include <string.h> /* memset() */

#include "mn-vfs-mailbox-backend.h"

#include "mn-vfs-mailbox-backend-private.h"

#ifdef G_LIKELY
#define ___GOB_LIKELY(expr) G_LIKELY(expr)
#define ___GOB_UNLIKELY(expr) G_UNLIKELY(expr)
#else /* ! G_LIKELY */
#define ___GOB_LIKELY(expr) (expr)
#define ___GOB_UNLIKELY(expr) (expr)
#endif /* G_LIKELY */

#line 25 "mn-vfs-mailbox-backend.gob"

#include "config.h"
#include <glib/gi18n.h>
#include <gtk/gtk.h>
#include "mn-mailbox-private.h"
#include "mn-reentrant-mailbox-private.h"
#include "mn-vfs-mailbox-private.h"
#include "mn-conf.h"
#include "mn-util.h"

#line 38 "mn-vfs-mailbox-backend.c"
/* self casting macros */
#define SELF(x) MN_VFS_MAILBOX_BACKEND(x)
#define SELF_CONST(x) MN_VFS_MAILBOX_BACKEND_CONST(x)
#define IS_SELF(x) MN_IS_VFS_MAILBOX_BACKEND(x)
#define TYPE_SELF MN_TYPE_VFS_MAILBOX_BACKEND
#define SELF_CLASS(x) MN_VFS_MAILBOX_BACKEND_CLASS(x)

#define SELF_GET_CLASS(x) MN_VFS_MAILBOX_BACKEND_GET_CLASS(x)

/* self typedefs */
typedef MNVFSMailboxBackend Self;
typedef MNVFSMailboxBackendClass SelfClass;

/* here are local prototypes */
static void ___object_set_property (GObject *object, guint property_id, const GValue *value, GParamSpec *pspec);
static void ___object_get_property (GObject *object, guint property_id, GValue *value, GParamSpec *pspec);
static void mn_vfs_mailbox_backend_init (MNVFSMailboxBackend * o) G_GNUC_UNUSED;
static void mn_vfs_mailbox_backend_class_init (MNVFSMailboxBackendClass * c) G_GNUC_UNUSED;
static void ___1_mn_vfs_mailbox_backend_finalize (GObject * object) G_GNUC_UNUSED;
static void mn_vfs_mailbox_backend_real_monitor_cb (GnomeVFSMonitorHandle * handle, const char * monitor_uri, const char * info_uri, GnomeVFSMonitorEventType event_type, gpointer user_data) G_GNUC_UNUSED;
static void ___real_mn_vfs_mailbox_backend_monitor_cb (MNVFSMailboxBackend * self, const char * info_uri, GnomeVFSMonitorEventType event_type);
static void mn_vfs_mailbox_backend_monitor_cb (MNVFSMailboxBackend * self, const char * info_uri, GnomeVFSMonitorEventType event_type) G_GNUC_UNUSED;

enum {
	PROP_0,
	PROP_MAILBOX
};

/* pointer to the class of our parent */
static GObjectClass *parent_class = NULL;

/* Short form macros */
#define self_monitor mn_vfs_mailbox_backend_monitor
#define self_real_monitor_cb mn_vfs_mailbox_backend_real_monitor_cb
#define self_monitor_cb mn_vfs_mailbox_backend_monitor_cb
#define self_is mn_vfs_mailbox_backend_is
#define self_check mn_vfs_mailbox_backend_check
#define self_lock mn_vfs_mailbox_backend_lock
#define self_unlock mn_vfs_mailbox_backend_unlock
GType
mn_vfs_mailbox_backend_get_type (void)
{
	static GType type = 0;

	if ___GOB_UNLIKELY(type == 0) {
		static const GTypeInfo info = {
			sizeof (MNVFSMailboxBackendClass),
			(GBaseInitFunc) NULL,
			(GBaseFinalizeFunc) NULL,
			(GClassInitFunc) mn_vfs_mailbox_backend_class_init,
			(GClassFinalizeFunc) NULL,
			NULL /* class_data */,
			sizeof (MNVFSMailboxBackend),
			0 /* n_preallocs */,
			(GInstanceInitFunc) mn_vfs_mailbox_backend_init,
			NULL
		};

		type = g_type_register_static (G_TYPE_OBJECT, "MNVFSMailboxBackend", &info, (GTypeFlags)0);
	}

	return type;
}

/* a macro for creating a new object of our type */
#define GET_NEW ((MNVFSMailboxBackend *)g_object_new(mn_vfs_mailbox_backend_get_type(), NULL))

/* a function for creating a new object of our type */
#include <stdarg.h>
static MNVFSMailboxBackend * GET_NEW_VARG (const char *first, ...) G_GNUC_UNUSED;
static MNVFSMailboxBackend *
GET_NEW_VARG (const char *first, ...)
{
	MNVFSMailboxBackend *ret;
	va_list ap;
	va_start (ap, first);
	ret = (MNVFSMailboxBackend *)g_object_new_valist (mn_vfs_mailbox_backend_get_type (), first, ap);
	va_end (ap);
	return ret;
}


static void
___finalize(GObject *obj_self)
{
#define __GOB_FUNCTION__ "MN:VFS:Mailbox:Backend::finalize"
	MNVFSMailboxBackend *self G_GNUC_UNUSED = MN_VFS_MAILBOX_BACKEND (obj_self);
	gpointer priv G_GNUC_UNUSED = self->_priv;
#line 52 "mn-vfs-mailbox-backend.gob"
	___1_mn_vfs_mailbox_backend_finalize(obj_self);
#line 129 "mn-vfs-mailbox-backend.c"
#line 48 "mn-vfs-mailbox-backend.gob"
	if(self->_priv->mutex) { g_mutex_free ((gpointer) self->_priv->mutex); self->_priv->mutex = NULL; }
#line 132 "mn-vfs-mailbox-backend.c"
}
#undef __GOB_FUNCTION__

static void 
mn_vfs_mailbox_backend_init (MNVFSMailboxBackend * o G_GNUC_UNUSED)
{
#define __GOB_FUNCTION__ "MN:VFS:Mailbox:Backend::init"
	o->_priv = G_TYPE_INSTANCE_GET_PRIVATE(o,MN_TYPE_VFS_MAILBOX_BACKEND,MNVFSMailboxBackendPrivate);
#line 48 "mn-vfs-mailbox-backend.gob"
	o->_priv->mutex = g_mutex_new();
#line 143 "mn-vfs-mailbox-backend.c"
}
#undef __GOB_FUNCTION__
static void 
mn_vfs_mailbox_backend_class_init (MNVFSMailboxBackendClass * c G_GNUC_UNUSED)
{
#define __GOB_FUNCTION__ "MN:VFS:Mailbox:Backend::class_init"
	GObjectClass *g_object_class G_GNUC_UNUSED = (GObjectClass*) c;

	g_type_class_add_private(c,sizeof(MNVFSMailboxBackendPrivate));

	parent_class = g_type_class_ref (G_TYPE_OBJECT);

#line 52 "mn-vfs-mailbox-backend.gob"
	g_object_class->finalize = ___finalize;
#line 139 "mn-vfs-mailbox-backend.gob"
	c->monitor_cb = ___real_mn_vfs_mailbox_backend_monitor_cb;
#line 160 "mn-vfs-mailbox-backend.c"
	c->is = NULL;
	c->check = NULL;
	g_object_class->get_property = ___object_get_property;
	g_object_class->set_property = ___object_set_property;
    {
	GParamSpec   *param_spec;

	param_spec = g_param_spec_pointer
		("mailbox" /* name */,
		 NULL /* nick */,
		 NULL /* blurb */,
		 (GParamFlags)(G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT_ONLY));
	g_object_class_install_property (g_object_class,
		PROP_MAILBOX,
		param_spec);
    }
}
#undef __GOB_FUNCTION__

static void
___object_set_property (GObject *object,
	guint property_id,
	const GValue *VAL G_GNUC_UNUSED,
	GParamSpec *pspec G_GNUC_UNUSED)
#define __GOB_FUNCTION__ "MN:VFS:Mailbox:Backend::set_property"
{
	MNVFSMailboxBackend *self G_GNUC_UNUSED;

	self = MN_VFS_MAILBOX_BACKEND (object);

	switch (property_id) {
	case PROP_MAILBOX:
		{
#line 46 "mn-vfs-mailbox-backend.gob"
self->mailbox = g_value_get_pointer (VAL);
#line 196 "mn-vfs-mailbox-backend.c"
		}
		break;
	default:
/* Apparently in g++ this is needed, glib is b0rk */
#ifndef __PRETTY_FUNCTION__
#  undef G_STRLOC
#  define G_STRLOC	__FILE__ ":" G_STRINGIFY (__LINE__)
#endif
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}
#undef __GOB_FUNCTION__

static void
___object_get_property (GObject *object,
	guint property_id,
	GValue *VAL G_GNUC_UNUSED,
	GParamSpec *pspec G_GNUC_UNUSED)
#define __GOB_FUNCTION__ "MN:VFS:Mailbox:Backend::get_property"
{
	MNVFSMailboxBackend *self G_GNUC_UNUSED;

	self = MN_VFS_MAILBOX_BACKEND (object);

	switch (property_id) {
	case PROP_MAILBOX:
		{
#line 46 "mn-vfs-mailbox-backend.gob"
g_value_set_pointer (VAL, self->mailbox);
#line 227 "mn-vfs-mailbox-backend.c"
		}
		break;
	default:
/* Apparently in g++ this is needed, glib is b0rk */
#ifndef __PRETTY_FUNCTION__
#  undef G_STRLOC
#  define G_STRLOC	__FILE__ ":" G_STRINGIFY (__LINE__)
#endif
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}
#undef __GOB_FUNCTION__



#line 52 "mn-vfs-mailbox-backend.gob"
static void 
___1_mn_vfs_mailbox_backend_finalize (GObject * object G_GNUC_UNUSED)
#line 247 "mn-vfs-mailbox-backend.c"
#define PARENT_HANDLER(___object) \
	{ if(G_OBJECT_CLASS(parent_class)->finalize) \
		(* G_OBJECT_CLASS(parent_class)->finalize)(___object); }
{
#define __GOB_FUNCTION__ "MN:VFS:Mailbox:Backend::finalize"
{
#line 54 "mn-vfs-mailbox-backend.gob"
	
    Self *self = SELF(object);

    if (selfp->monitor_handle)
      {
	gnome_vfs_monitor_cancel(selfp->monitor_handle);
	selfp->monitor_handle = NULL;
      }

    PARENT_HANDLER(object);
  }}
#line 266 "mn-vfs-mailbox-backend.c"
#undef __GOB_FUNCTION__
#undef PARENT_HANDLER

#line 66 "mn-vfs-mailbox-backend.gob"
void 
mn_vfs_mailbox_backend_monitor (MNVFSMailboxBackend * self, unsigned long check_id, const char * uri, GnomeVFSMonitorType monitor_type)
#line 273 "mn-vfs-mailbox-backend.c"
{
#define __GOB_FUNCTION__ "MN:VFS:Mailbox:Backend::monitor"
#line 66 "mn-vfs-mailbox-backend.gob"
	g_return_if_fail (self != NULL);
#line 66 "mn-vfs-mailbox-backend.gob"
	g_return_if_fail (MN_IS_VFS_MAILBOX_BACKEND (self));
#line 66 "mn-vfs-mailbox-backend.gob"
	g_return_if_fail (uri != NULL);
#line 282 "mn-vfs-mailbox-backend.c"
{
#line 71 "mn-vfs-mailbox-backend.gob"
	
    GnomeVFSResult result;
    GnomeVFSMonitorHandle *handle;

    g_return_if_fail(SELF_GET_CLASS(self)->monitor_cb != NULL);
    
    self_lock(self);

    handle = selfp->monitor_handle;

    self_unlock(self);

    if (handle)
      return;

    result = gnome_vfs_monitor_add(&handle,
				   uri,
				   monitor_type,
				   self_real_monitor_cb,
				   self);

    if (result == GNOME_VFS_OK)
      {
	self_lock(self);

	if (! selfp->monitor_handle)
	  {
	    selfp->monitor_handle = handle;
	    handle = NULL;
	  }

	self_unlock(self);

	if (handle)
	  gnome_vfs_monitor_cancel(handle);
      }
    else
      {
	GDK_THREADS_ENTER();

	if (! mn_reentrant_mailbox_check_aborted_unlocked(MN_REENTRANT_MAILBOX(self->mailbox), check_id)
	    && ! selfp->monitor_handle
	    && result != self->mailbox->contents_monitor_result)
	  {
	    self->mailbox->contents_monitor_result = result;

	    mn_mailbox_warning(MN_MAILBOX(self->mailbox), _("unable to monitor mailbox contents (%s), poll mode activated"), gnome_vfs_result_to_string(result));
	    mn_vfs_mailbox_monitor_error_dialog();

	    if (! MN_MAILBOX(self->mailbox)->must_poll)
	      mn_mailbox_set_must_poll(MN_MAILBOX(self->mailbox), TRUE);
	  }

	gdk_flush();
	GDK_THREADS_LEAVE();
      }
  }}
#line 342 "mn-vfs-mailbox-backend.c"
#undef __GOB_FUNCTION__

#line 129 "mn-vfs-mailbox-backend.gob"
static void 
mn_vfs_mailbox_backend_real_monitor_cb (GnomeVFSMonitorHandle * handle, const char * monitor_uri, const char * info_uri, GnomeVFSMonitorEventType event_type, gpointer user_data)
#line 348 "mn-vfs-mailbox-backend.c"
{
#define __GOB_FUNCTION__ "MN:VFS:Mailbox:Backend::real_monitor_cb"
{
#line 135 "mn-vfs-mailbox-backend.gob"
	
    self_monitor_cb(user_data, info_uri, event_type);
  }}
#line 356 "mn-vfs-mailbox-backend.c"
#undef __GOB_FUNCTION__

#line 139 "mn-vfs-mailbox-backend.gob"
static void 
mn_vfs_mailbox_backend_monitor_cb (MNVFSMailboxBackend * self, const char * info_uri, GnomeVFSMonitorEventType event_type)
#line 362 "mn-vfs-mailbox-backend.c"
{
	MNVFSMailboxBackendClass *klass;
#line 139 "mn-vfs-mailbox-backend.gob"
	g_return_if_fail (self != NULL);
#line 139 "mn-vfs-mailbox-backend.gob"
	g_return_if_fail (MN_IS_VFS_MAILBOX_BACKEND (self));
#line 369 "mn-vfs-mailbox-backend.c"
	klass = MN_VFS_MAILBOX_BACKEND_GET_CLASS(self);

	if(klass->monitor_cb)
		(*klass->monitor_cb)(self,info_uri,event_type);
}
#line 139 "mn-vfs-mailbox-backend.gob"
static void 
___real_mn_vfs_mailbox_backend_monitor_cb (MNVFSMailboxBackend * self G_GNUC_UNUSED, const char * info_uri, GnomeVFSMonitorEventType event_type)
#line 378 "mn-vfs-mailbox-backend.c"
{
#define __GOB_FUNCTION__ "MN:VFS:Mailbox:Backend::monitor_cb"
{
#line 143 "mn-vfs-mailbox-backend.gob"
	
    if (event_type == GNOME_VFS_MONITOR_EVENT_CHANGED
	|| event_type == GNOME_VFS_MONITOR_EVENT_DELETED
	|| event_type == GNOME_VFS_MONITOR_EVENT_CREATED)
      mn_reentrant_mailbox_queue_check(MN_REENTRANT_MAILBOX(self->mailbox));
  }}
#line 389 "mn-vfs-mailbox-backend.c"
#undef __GOB_FUNCTION__

#line 150 "mn-vfs-mailbox-backend.gob"
gboolean 
mn_vfs_mailbox_backend_is (MNVFSMailboxBackend * self, MNVFSMailbox * mailbox)
#line 395 "mn-vfs-mailbox-backend.c"
{
	MNVFSMailboxBackendClass *klass;
#line 150 "mn-vfs-mailbox-backend.gob"
	g_return_val_if_fail (self != NULL, (gboolean )0);
#line 150 "mn-vfs-mailbox-backend.gob"
	g_return_val_if_fail (MN_IS_VFS_MAILBOX_BACKEND (self), (gboolean )0);
#line 402 "mn-vfs-mailbox-backend.c"
	klass = MN_VFS_MAILBOX_BACKEND_GET_CLASS(self);

	if(klass->is)
		return (*klass->is)(self,mailbox);
	else
		return (gboolean )(0);
}

#line 153 "mn-vfs-mailbox-backend.gob"
void 
mn_vfs_mailbox_backend_check (MNVFSMailboxBackend * self, unsigned long check_id)
#line 414 "mn-vfs-mailbox-backend.c"
{
	MNVFSMailboxBackendClass *klass;
#line 153 "mn-vfs-mailbox-backend.gob"
	g_return_if_fail (self != NULL);
#line 153 "mn-vfs-mailbox-backend.gob"
	g_return_if_fail (MN_IS_VFS_MAILBOX_BACKEND (self));
#line 421 "mn-vfs-mailbox-backend.c"
	klass = MN_VFS_MAILBOX_BACKEND_GET_CLASS(self);

	if(klass->check)
		(*klass->check)(self,check_id);
}

#line 156 "mn-vfs-mailbox-backend.gob"
void 
mn_vfs_mailbox_backend_lock (MNVFSMailboxBackend * self)
#line 431 "mn-vfs-mailbox-backend.c"
{
#define __GOB_FUNCTION__ "MN:VFS:Mailbox:Backend::lock"
#line 156 "mn-vfs-mailbox-backend.gob"
	g_return_if_fail (self != NULL);
#line 156 "mn-vfs-mailbox-backend.gob"
	g_return_if_fail (MN_IS_VFS_MAILBOX_BACKEND (self));
#line 438 "mn-vfs-mailbox-backend.c"
{
#line 158 "mn-vfs-mailbox-backend.gob"
	
    g_mutex_lock(selfp->mutex);
  }}
#line 444 "mn-vfs-mailbox-backend.c"
#undef __GOB_FUNCTION__

#line 162 "mn-vfs-mailbox-backend.gob"
void 
mn_vfs_mailbox_backend_unlock (MNVFSMailboxBackend * self)
#line 450 "mn-vfs-mailbox-backend.c"
{
#define __GOB_FUNCTION__ "MN:VFS:Mailbox:Backend::unlock"
#line 162 "mn-vfs-mailbox-backend.gob"
	g_return_if_fail (self != NULL);
#line 162 "mn-vfs-mailbox-backend.gob"
	g_return_if_fail (MN_IS_VFS_MAILBOX_BACKEND (self));
#line 457 "mn-vfs-mailbox-backend.c"
{
#line 164 "mn-vfs-mailbox-backend.gob"
	
    g_mutex_unlock(selfp->mutex);
  }}
#line 463 "mn-vfs-mailbox-backend.c"
#undef __GOB_FUNCTION__