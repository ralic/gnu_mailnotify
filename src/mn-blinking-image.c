/* Generated by GOB (v2.0.11) on Sun Oct 31 18:41:22 2004
   (do not edit directly) */

/* End world hunger, donate to the World Food Programme, http://www.wfp.org */

#define GOB_VERSION_MAJOR 2
#define GOB_VERSION_MINOR 0
#define GOB_VERSION_PATCHLEVEL 11

#define selfp (self->_priv)

#include <string.h> /* memset() */

#include "mn-blinking-image.h"

#include "mn-blinking-image-private.h"

#ifdef G_LIKELY
#define ___GOB_LIKELY(expr) G_LIKELY(expr)
#define ___GOB_UNLIKELY(expr) G_UNLIKELY(expr)
#else /* ! G_LIKELY */
#define ___GOB_LIKELY(expr) (expr)
#define ___GOB_UNLIKELY(expr) (expr)
#endif /* G_LIKELY */

#line 24 "mn-blinking-image.gob"

#include "config.h"
#include <glib/gi18n.h>

#line 32 "mn-blinking-image.c"
/* self casting macros */
#define SELF(x) MN_BLINKING_IMAGE(x)
#define SELF_CONST(x) MN_BLINKING_IMAGE_CONST(x)
#define IS_SELF(x) MN_IS_BLINKING_IMAGE(x)
#define TYPE_SELF MN_TYPE_BLINKING_IMAGE
#define SELF_CLASS(x) MN_BLINKING_IMAGE_CLASS(x)

#define SELF_GET_CLASS(x) MN_BLINKING_IMAGE_GET_CLASS(x)

/* self typedefs */
typedef MNBlinkingImage Self;
typedef MNBlinkingImageClass SelfClass;

/* here are local prototypes */
static void ___object_set_property (GObject *object, guint property_id, const GValue *value, GParamSpec *pspec);
static void ___object_get_property (GObject *object, guint property_id, GValue *value, GParamSpec *pspec);
static void mn_blinking_image_init (MNBlinkingImage * o) G_GNUC_UNUSED;
static void mn_blinking_image_class_init (MNBlinkingImageClass * c) G_GNUC_UNUSED;
static void ___3_mn_blinking_image_finalize (GObject * object) G_GNUC_UNUSED;
static void mn_blinking_image_update (MNBlinkingImage * self, gboolean is_on) G_GNUC_UNUSED;
static gboolean mn_blinking_image_timeout_cb (gpointer data) G_GNUC_UNUSED;

enum {
	PROP_0,
	PROP_BLINKING
};

/* pointer to the class of our parent */
static GtkImageClass *parent_class = NULL;

/* Short form macros */
#define self_get_blinking mn_blinking_image_get_blinking
#define self_set_blinking mn_blinking_image_set_blinking
#define self_update mn_blinking_image_update
#define self_timeout_cb mn_blinking_image_timeout_cb
#define self_new_from_stock mn_blinking_image_new_from_stock
GType
mn_blinking_image_get_type (void)
{
	static GType type = 0;

	if ___GOB_UNLIKELY(type == 0) {
		static const GTypeInfo info = {
			sizeof (MNBlinkingImageClass),
			(GBaseInitFunc) NULL,
			(GBaseFinalizeFunc) NULL,
			(GClassInitFunc) mn_blinking_image_class_init,
			(GClassFinalizeFunc) NULL,
			NULL /* class_data */,
			sizeof (MNBlinkingImage),
			0 /* n_preallocs */,
			(GInstanceInitFunc) mn_blinking_image_init,
			NULL
		};

		type = g_type_register_static (GTK_TYPE_IMAGE, "MNBlinkingImage", &info, (GTypeFlags)0);
	}

	return type;
}

/* a macro for creating a new object of our type */
#define GET_NEW ((MNBlinkingImage *)g_object_new(mn_blinking_image_get_type(), NULL))

/* a function for creating a new object of our type */
#include <stdarg.h>
static MNBlinkingImage * GET_NEW_VARG (const char *first, ...) G_GNUC_UNUSED;
static MNBlinkingImage *
GET_NEW_VARG (const char *first, ...)
{
	MNBlinkingImage *ret;
	va_list ap;
	va_start (ap, first);
	ret = (MNBlinkingImage *)g_object_new_valist (mn_blinking_image_get_type (), first, ap);
	va_end (ap);
	return ret;
}


static void
___dispose (GObject *obj_self)
{
#define __GOB_FUNCTION__ "MN:Blinking:Image::dispose"
	MNBlinkingImage *self G_GNUC_UNUSED = MN_BLINKING_IMAGE (obj_self);
	if (G_OBJECT_CLASS (parent_class)->dispose) \
		(* G_OBJECT_CLASS (parent_class)->dispose) (obj_self);
#line 53 "mn-blinking-image.gob"
	if(self->_priv->on_pixbuf) { g_object_unref ((gpointer) self->_priv->on_pixbuf); self->_priv->on_pixbuf = NULL; }
#line 121 "mn-blinking-image.c"
#line 54 "mn-blinking-image.gob"
	if(self->_priv->off_pixbuf) { g_object_unref ((gpointer) self->_priv->off_pixbuf); self->_priv->off_pixbuf = NULL; }
#line 124 "mn-blinking-image.c"
}
#undef __GOB_FUNCTION__


static void
___finalize(GObject *obj_self)
{
#define __GOB_FUNCTION__ "MN:Blinking:Image::finalize"
	MNBlinkingImage *self G_GNUC_UNUSED = MN_BLINKING_IMAGE (obj_self);
	gpointer priv G_GNUC_UNUSED = self->_priv;
#line 56 "mn-blinking-image.gob"
	___3_mn_blinking_image_finalize(obj_self);
#line 137 "mn-blinking-image.c"
}
#undef __GOB_FUNCTION__

static void 
mn_blinking_image_init (MNBlinkingImage * o G_GNUC_UNUSED)
{
#define __GOB_FUNCTION__ "MN:Blinking:Image::init"
	o->_priv = G_TYPE_INSTANCE_GET_PRIVATE(o,TYPE_SELF,MNBlinkingImagePrivate);
#line 47 "mn-blinking-image.gob"
	o->_priv->is_on = TRUE;
#line 148 "mn-blinking-image.c"
}
#undef __GOB_FUNCTION__
static void 
mn_blinking_image_class_init (MNBlinkingImageClass * c G_GNUC_UNUSED)
{
#define __GOB_FUNCTION__ "MN:Blinking:Image::class_init"
	GObjectClass *g_object_class G_GNUC_UNUSED = (GObjectClass*) c;

	g_type_class_add_private(c,sizeof(MNBlinkingImagePrivate));

	parent_class = g_type_class_ref (GTK_TYPE_IMAGE);

#line 56 "mn-blinking-image.gob"
	g_object_class->finalize = ___finalize;
#line 163 "mn-blinking-image.c"
	g_object_class->dispose = ___dispose;
	g_object_class->get_property = ___object_get_property;
	g_object_class->set_property = ___object_set_property;
    {
	GParamSpec   *param_spec;

	param_spec = g_param_spec_boolean
		("blinking" /* name */,
		 NULL /* nick */,
		 _("Whether the image is blinking or not") /* blurb */,
		 FALSE /* default_value */,
		 (GParamFlags)(G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (g_object_class,
		PROP_BLINKING,
		param_spec);
    }
}
#undef __GOB_FUNCTION__

static void
___object_set_property (GObject *object,
	guint property_id,
	const GValue *VAL G_GNUC_UNUSED,
	GParamSpec *pspec G_GNUC_UNUSED)
#define __GOB_FUNCTION__ "MN:Blinking:Image::set_property"
{
	MNBlinkingImage *self G_GNUC_UNUSED;

	self = MN_BLINKING_IMAGE (object);

	switch (property_id) {
	case PROP_BLINKING:
		{
#line 35 "mn-blinking-image.gob"

      if (selfp->blinking)
	{
	  g_source_remove(selfp->timeout_id);
	  self_update(self, TRUE);
	}

      selfp->blinking = g_value_get_boolean(VAL);
      if (selfp->blinking)
	selfp->timeout_id = g_timeout_add(500, self_timeout_cb, self);
    
#line 209 "mn-blinking-image.c"
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
#define __GOB_FUNCTION__ "MN:Blinking:Image::get_property"
{
	MNBlinkingImage *self G_GNUC_UNUSED;

	self = MN_BLINKING_IMAGE (object);

	switch (property_id) {
	case PROP_BLINKING:
		{
#line 47 "mn-blinking-image.gob"

      g_value_set_boolean(VAL, selfp->blinking);
    
#line 242 "mn-blinking-image.c"
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



#line 47 "mn-blinking-image.gob"
gboolean 
mn_blinking_image_get_blinking (MNBlinkingImage * self)
#line 262 "mn-blinking-image.c"
{
#define __GOB_FUNCTION__ "MN:Blinking:Image::get_blinking"
{
#line 32 "mn-blinking-image.gob"
		gboolean val; g_object_get (G_OBJECT (self), "blinking", &val, NULL); return val;
}}
#line 269 "mn-blinking-image.c"
#undef __GOB_FUNCTION__

#line 35 "mn-blinking-image.gob"
void 
mn_blinking_image_set_blinking (MNBlinkingImage * self, gboolean val)
#line 275 "mn-blinking-image.c"
{
#define __GOB_FUNCTION__ "MN:Blinking:Image::set_blinking"
{
#line 32 "mn-blinking-image.gob"
		g_object_set (G_OBJECT (self), "blinking", val, NULL);
}}
#line 282 "mn-blinking-image.c"
#undef __GOB_FUNCTION__

#line 56 "mn-blinking-image.gob"
static void 
___3_mn_blinking_image_finalize (GObject * object G_GNUC_UNUSED)
#line 288 "mn-blinking-image.c"
#define PARENT_HANDLER(___object) \
	{ if(G_OBJECT_CLASS(parent_class)->finalize) \
		(* G_OBJECT_CLASS(parent_class)->finalize)(___object); }
{
#define __GOB_FUNCTION__ "MN:Blinking:Image::finalize"
#line 56 "mn-blinking-image.gob"
	g_return_if_fail (object != NULL);
#line 56 "mn-blinking-image.gob"
	g_return_if_fail (G_IS_OBJECT (object));
#line 298 "mn-blinking-image.c"
{
#line 58 "mn-blinking-image.gob"
	
    Self *self = SELF(object);

    if (selfp->timeout_id)
      g_source_remove(selfp->timeout_id);

    PARENT_HANDLER(object);
  }}
#line 309 "mn-blinking-image.c"
#undef __GOB_FUNCTION__
#undef PARENT_HANDLER

#line 67 "mn-blinking-image.gob"
static void 
mn_blinking_image_update (MNBlinkingImage * self, gboolean is_on)
#line 316 "mn-blinking-image.c"
{
#define __GOB_FUNCTION__ "MN:Blinking:Image::update"
#line 67 "mn-blinking-image.gob"
	g_return_if_fail (self != NULL);
#line 67 "mn-blinking-image.gob"
	g_return_if_fail (MN_IS_BLINKING_IMAGE (self));
#line 323 "mn-blinking-image.c"
{
#line 69 "mn-blinking-image.gob"
	
    gtk_image_set_from_pixbuf(GTK_IMAGE(self), is_on ? selfp->on_pixbuf : selfp->off_pixbuf);
    selfp->is_on = is_on;
  }}
#line 330 "mn-blinking-image.c"
#undef __GOB_FUNCTION__

#line 74 "mn-blinking-image.gob"
static gboolean 
mn_blinking_image_timeout_cb (gpointer data)
#line 336 "mn-blinking-image.c"
{
#define __GOB_FUNCTION__ "MN:Blinking:Image::timeout_cb"
#line 74 "mn-blinking-image.gob"
	g_return_val_if_fail (data != NULL, (gboolean )0);
#line 341 "mn-blinking-image.c"
{
#line 76 "mn-blinking-image.gob"
	
    Self *self = data;

    GDK_THREADS_ENTER();
    self_update(self, ! selfp->is_on);
    GDK_THREADS_LEAVE();

    return TRUE;
  }}
#line 353 "mn-blinking-image.c"
#undef __GOB_FUNCTION__

#line 86 "mn-blinking-image.gob"
GtkWidget * 
mn_blinking_image_new_from_stock (const char * stock_id, GtkIconSize icon_size)
#line 359 "mn-blinking-image.c"
{
#define __GOB_FUNCTION__ "MN:Blinking:Image::new_from_stock"
#line 86 "mn-blinking-image.gob"
	g_return_val_if_fail (stock_id != NULL, (GtkWidget * )0);
#line 364 "mn-blinking-image.c"
{
#line 89 "mn-blinking-image.gob"
	
    Self *self;
    int width, height;

    self = GET_NEW;

    selfp->on_pixbuf = gtk_widget_render_icon(GTK_WIDGET(self),
					      stock_id,
					      icon_size,
					      NULL);
    g_return_val_if_fail(selfp->on_pixbuf != NULL, NULL);

    width = gdk_pixbuf_get_width(selfp->on_pixbuf);
    height = gdk_pixbuf_get_height(selfp->on_pixbuf);
    
    selfp->off_pixbuf = gdk_pixbuf_new(GDK_COLORSPACE_RGB, TRUE, 8, width, height);
    gdk_pixbuf_fill(selfp->off_pixbuf, 0); /* fill with transparency */

    self_update(self, selfp->is_on);

    return GTK_WIDGET(self);
  }}
#line 389 "mn-blinking-image.c"
#undef __GOB_FUNCTION__
