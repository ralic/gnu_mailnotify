/* Generated by GOB (v2.0.15)   (do not edit directly) */

/* End world hunger, donate to the World Food Programme, http://www.wfp.org */

#define GOB_VERSION_MAJOR 2
#define GOB_VERSION_MINOR 0
#define GOB_VERSION_PATCHLEVEL 15

#define selfp (self->_priv)

#include <string.h> /* memset() */

#include "mn-evolution-client.h"

#include "mn-evolution-client-private.h"

#ifdef G_LIKELY
#define ___GOB_LIKELY(expr) G_LIKELY(expr)
#define ___GOB_UNLIKELY(expr) G_UNLIKELY(expr)
#else /* ! G_LIKELY */
#define ___GOB_LIKELY(expr) (expr)
#define ___GOB_UNLIKELY(expr) (expr)
#endif /* G_LIKELY */

#line 24 "src/mn-evolution-client.gob"

#include "mn-shell.h"
#include "mn-evolution.h"
#include "mn-util.h"

#line 32 "mn-evolution-client.c"
/* self casting macros */
#define SELF(x) MN_EVOLUTION_CLIENT(x)
#define SELF_CONST(x) MN_EVOLUTION_CLIENT_CONST(x)
#define IS_SELF(x) MN_IS_EVOLUTION_CLIENT(x)
#define TYPE_SELF MN_TYPE_EVOLUTION_CLIENT
#define SELF_CLASS(x) MN_EVOLUTION_CLIENT_CLASS(x)

#define SELF_GET_CLASS(x) MN_EVOLUTION_CLIENT_GET_CLASS(x)

/* self typedefs */
typedef MNEvolutionClient Self;
typedef MNEvolutionClientClass SelfClass;

/* here are local prototypes */
static void ___object_set_property (GObject *object, guint property_id, const GValue *value, GParamSpec *pspec);
static void ___object_get_property (GObject *object, guint property_id, GValue *value, GParamSpec *pspec);
#line 0 "src/mn-evolution-client.gob"
static void mn_evolution_client_class_init (MNEvolutionClientClass * c);
#line 51 "mn-evolution-client.c"
#line 43 "src/mn-evolution-client.gob"
static void mn_evolution_client_init (MNEvolutionClient * self);
#line 54 "mn-evolution-client.c"
#line 48 "src/mn-evolution-client.gob"
static void mn_evolution_client_connect_name_owner_signal (MNEvolutionClient * self);
#line 57 "mn-evolution-client.c"
#line 63 "src/mn-evolution-client.gob"
static void mn_evolution_client_disconnect_name_owner_signal (MNEvolutionClient * self);
#line 60 "mn-evolution-client.c"
#line 77 "src/mn-evolution-client.gob"
static void mn_evolution_client_connect (MNEvolutionClient * self);
#line 63 "mn-evolution-client.c"
#line 110 "src/mn-evolution-client.gob"
static void mn_evolution_client_name_owner_changed_h (DBusGProxy * proxy, const char * service_name, const char * old_owner, const char * new_owner, gpointer user_data);
#line 66 "mn-evolution-client.c"
#line 128 "src/mn-evolution-client.gob"
static void mn_evolution_client_proxy_destroy_h (DBusGProxy * proxy, gpointer user_data);
#line 69 "mn-evolution-client.c"

enum {
	PROP_0,
	PROP_PROXY
};

/* pointer to the class of our parent */
static GObjectClass *parent_class = NULL;

/* Short form macros */
#define self_get_proxy mn_evolution_client_get_proxy
#define self_set_proxy mn_evolution_client_set_proxy
#define self_connect_name_owner_signal mn_evolution_client_connect_name_owner_signal
#define self_disconnect_name_owner_signal mn_evolution_client_disconnect_name_owner_signal
#define self_connect mn_evolution_client_connect
#define self_name_owner_changed_h mn_evolution_client_name_owner_changed_h
#define self_proxy_destroy_h mn_evolution_client_proxy_destroy_h
#define self_get mn_evolution_client_get
GType
mn_evolution_client_get_type (void)
{
	static GType type = 0;

	if ___GOB_UNLIKELY(type == 0) {
		static const GTypeInfo info = {
			sizeof (MNEvolutionClientClass),
			(GBaseInitFunc) NULL,
			(GBaseFinalizeFunc) NULL,
			(GClassInitFunc) mn_evolution_client_class_init,
			(GClassFinalizeFunc) NULL,
			NULL /* class_data */,
			sizeof (MNEvolutionClient),
			0 /* n_preallocs */,
			(GInstanceInitFunc) mn_evolution_client_init,
			NULL
		};

		type = g_type_register_static (G_TYPE_OBJECT, "MNEvolutionClient", &info, (GTypeFlags)0);
	}

	return type;
}

/* a macro for creating a new object of our type */
#define GET_NEW ((MNEvolutionClient *)g_object_new(mn_evolution_client_get_type(), NULL))

/* a function for creating a new object of our type */
#include <stdarg.h>
static MNEvolutionClient * GET_NEW_VARG (const char *first, ...) G_GNUC_UNUSED;
static MNEvolutionClient *
GET_NEW_VARG (const char *first, ...)
{
	MNEvolutionClient *ret;
	va_list ap;
	va_start (ap, first);
	ret = (MNEvolutionClient *)g_object_new_valist (mn_evolution_client_get_type (), first, ap);
	va_end (ap);
	return ret;
}


static void
___finalize(GObject *obj_self)
{
#define __GOB_FUNCTION__ "MN:Evolution:Client::finalize"
	MNEvolutionClient *self G_GNUC_UNUSED = MN_EVOLUTION_CLIENT (obj_self);
	gpointer priv G_GNUC_UNUSED = self->_priv;
	if(G_OBJECT_CLASS(parent_class)->finalize) \
		(* G_OBJECT_CLASS(parent_class)->finalize)(obj_self);
}
#undef __GOB_FUNCTION__

static void 
mn_evolution_client_class_init (MNEvolutionClientClass * c G_GNUC_UNUSED)
{
#define __GOB_FUNCTION__ "MN:Evolution:Client::class_init"
	GObjectClass *g_object_class G_GNUC_UNUSED = (GObjectClass*) c;

	g_type_class_add_private(c,sizeof(MNEvolutionClientPrivate));

	parent_class = g_type_class_ref (G_TYPE_OBJECT);

	g_object_class->finalize = ___finalize;
	g_object_class->get_property = ___object_get_property;
	g_object_class->set_property = ___object_set_property;
    {
	GParamSpec   *param_spec;

	param_spec = g_param_spec_pointer
		("proxy" /* name */,
		 NULL /* nick */,
		 NULL /* blurb */,
		 (GParamFlags)(G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (g_object_class,
		PROP_PROXY,
		param_spec);
    }
}
#undef __GOB_FUNCTION__
#line 43 "src/mn-evolution-client.gob"
static void 
mn_evolution_client_init (MNEvolutionClient * self G_GNUC_UNUSED)
{
#line 173 "mn-evolution-client.c"
#define __GOB_FUNCTION__ "MN:Evolution:Client::init"
	self->_priv = G_TYPE_INSTANCE_GET_PRIVATE(self,MN_TYPE_EVOLUTION_CLIENT,MNEvolutionClientPrivate);
 {
#line 44 "src/mn-evolution-client.gob"

    self_connect(self);
  
#line 181 "mn-evolution-client.c"
 }
}
#undef __GOB_FUNCTION__

static void
___object_set_property (GObject *object,
	guint property_id,
	const GValue *VAL G_GNUC_UNUSED,
	GParamSpec *pspec G_GNUC_UNUSED)
#define __GOB_FUNCTION__ "MN:Evolution:Client::set_property"
{
	MNEvolutionClient *self G_GNUC_UNUSED;

	self = MN_EVOLUTION_CLIENT (object);

	switch (property_id) {
	case PROP_PROXY:
		{
#line 39 "src/mn-evolution-client.gob"
self->proxy = g_value_get_pointer (VAL);
#line 202 "mn-evolution-client.c"
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
#define __GOB_FUNCTION__ "MN:Evolution:Client::get_property"
{
	MNEvolutionClient *self G_GNUC_UNUSED;

	self = MN_EVOLUTION_CLIENT (object);

	switch (property_id) {
	case PROP_PROXY:
		{
#line 39 "src/mn-evolution-client.gob"
g_value_set_pointer (VAL, self->proxy);
#line 233 "mn-evolution-client.c"
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


#line 39 "src/mn-evolution-client.gob"
DBusGProxy * 
mn_evolution_client_get_proxy (MNEvolutionClient * self)
{
#line 253 "mn-evolution-client.c"
#define __GOB_FUNCTION__ "MN:Evolution:Client::get_proxy"
{
#line 39 "src/mn-evolution-client.gob"
		DBusGProxy* val; g_object_get (G_OBJECT (self), "proxy", &val, NULL); return val;
}}
#line 259 "mn-evolution-client.c"
#undef __GOB_FUNCTION__

#line 39 "src/mn-evolution-client.gob"
void 
mn_evolution_client_set_proxy (MNEvolutionClient * self, DBusGProxy * val)
{
#line 266 "mn-evolution-client.c"
#define __GOB_FUNCTION__ "MN:Evolution:Client::set_proxy"
{
#line 39 "src/mn-evolution-client.gob"
		g_object_set (G_OBJECT (self), "proxy", val, NULL);
}}
#line 272 "mn-evolution-client.c"
#undef __GOB_FUNCTION__


#line 48 "src/mn-evolution-client.gob"
static void 
mn_evolution_client_connect_name_owner_signal (MNEvolutionClient * self)
{
#line 280 "mn-evolution-client.c"
#define __GOB_FUNCTION__ "MN:Evolution:Client::connect_name_owner_signal"
#line 48 "src/mn-evolution-client.gob"
	g_return_if_fail (self != NULL);
#line 48 "src/mn-evolution-client.gob"
	g_return_if_fail (MN_IS_EVOLUTION_CLIENT (self));
#line 286 "mn-evolution-client.c"
{
#line 50 "src/mn-evolution-client.gob"
	
    if (selfp->name_owner_signal_connected)
      return;

    dbus_g_proxy_connect_signal(mn_shell->session_bus_proxy,
				"NameOwnerChanged",
				G_CALLBACK(self_name_owner_changed_h),
				self,
				NULL);

    selfp->name_owner_signal_connected = TRUE;
  }}
#line 301 "mn-evolution-client.c"
#undef __GOB_FUNCTION__

#line 63 "src/mn-evolution-client.gob"
static void 
mn_evolution_client_disconnect_name_owner_signal (MNEvolutionClient * self)
{
#line 308 "mn-evolution-client.c"
#define __GOB_FUNCTION__ "MN:Evolution:Client::disconnect_name_owner_signal"
#line 63 "src/mn-evolution-client.gob"
	g_return_if_fail (self != NULL);
#line 63 "src/mn-evolution-client.gob"
	g_return_if_fail (MN_IS_EVOLUTION_CLIENT (self));
#line 314 "mn-evolution-client.c"
{
#line 65 "src/mn-evolution-client.gob"
	
    if (! selfp->name_owner_signal_connected)
      return;

    dbus_g_proxy_disconnect_signal(mn_shell->session_bus_proxy,
				   "NameOwnerChanged",
				   G_CALLBACK(self_name_owner_changed_h),
				   self);

    selfp->name_owner_signal_connected = FALSE;
  }}
#line 328 "mn-evolution-client.c"
#undef __GOB_FUNCTION__

#line 77 "src/mn-evolution-client.gob"
static void 
mn_evolution_client_connect (MNEvolutionClient * self)
{
#line 335 "mn-evolution-client.c"
#define __GOB_FUNCTION__ "MN:Evolution:Client::connect"
#line 77 "src/mn-evolution-client.gob"
	g_return_if_fail (self != NULL);
#line 77 "src/mn-evolution-client.gob"
	g_return_if_fail (MN_IS_EVOLUTION_CLIENT (self));
#line 341 "mn-evolution-client.c"
{
#line 79 "src/mn-evolution-client.gob"
	
    DBusGProxy *proxy;

    g_return_if_fail(self->proxy == NULL);

    proxy = dbus_g_proxy_new_for_name_owner(mn_shell->session_bus,
					    MN_EVOLUTION_SERVER_SERVICE,
					    MN_EVOLUTION_SERVER_PATH,
					    MN_EVOLUTION_SERVER_INTERFACE,
					    NULL);
    if (proxy)
      {
	self_disconnect_name_owner_signal(self);

	dbus_g_proxy_add_signal(proxy,
				MN_EVOLUTION_SERVER_SIGNAL_FOLDER_CHANGED,
				G_TYPE_STRING,	/* uri */
				G_TYPE_INVALID);
	dbus_g_proxy_add_signal(proxy,
				MN_EVOLUTION_SERVER_SIGNAL_MESSAGE_READING,
				G_TYPE_STRING,	/* uri */
				G_TYPE_INVALID);

	g_signal_connect(proxy, "destroy", G_CALLBACK(self_proxy_destroy_h), self);

	self_set_proxy(self, proxy);
      }
    else
      self_connect_name_owner_signal(self);
  }}
#line 374 "mn-evolution-client.c"
#undef __GOB_FUNCTION__

#line 110 "src/mn-evolution-client.gob"
static void 
mn_evolution_client_name_owner_changed_h (DBusGProxy * proxy, const char * service_name, const char * old_owner, const char * new_owner, gpointer user_data)
{
#line 381 "mn-evolution-client.c"
#define __GOB_FUNCTION__ "MN:Evolution:Client::name_owner_changed_h"
{
#line 116 "src/mn-evolution-client.gob"
	
    Self *self = user_data;

    /* this is a main loop callback */
    GDK_THREADS_ENTER();

    if (! strcmp(service_name, MN_EVOLUTION_SERVER_SERVICE) && *new_owner)
      self_connect(self);

    GDK_THREADS_LEAVE();
  }}
#line 396 "mn-evolution-client.c"
#undef __GOB_FUNCTION__

#line 128 "src/mn-evolution-client.gob"
static void 
mn_evolution_client_proxy_destroy_h (DBusGProxy * proxy, gpointer user_data)
{
#line 403 "mn-evolution-client.c"
#define __GOB_FUNCTION__ "MN:Evolution:Client::proxy_destroy_h"
{
#line 130 "src/mn-evolution-client.gob"
	
    Self *self = user_data;

    /* this is a main loop callback */
    GDK_THREADS_ENTER();

    self_set_proxy(self, NULL);
    self_connect_name_owner_signal(self);

    GDK_THREADS_LEAVE();
  }}
#line 418 "mn-evolution-client.c"
#undef __GOB_FUNCTION__

#line 142 "src/mn-evolution-client.gob"
MNEvolutionClient * 
mn_evolution_client_get (void)
{
#line 425 "mn-evolution-client.c"
#define __GOB_FUNCTION__ "MN:Evolution:Client::get"
{
#line 144 "src/mn-evolution-client.gob"
	
    static Self *self = NULL;

    /* does not need to be thread-safe */
    if (! self)
      self = GET_NEW;

    return self;
  }}
#line 438 "mn-evolution-client.c"
#undef __GOB_FUNCTION__