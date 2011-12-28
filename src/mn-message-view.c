/* Generated by GOB (v2.0.14)   (do not edit directly) */

/* End world hunger, donate to the World Food Programme, http://www.wfp.org */

#define GOB_VERSION_MAJOR 2
#define GOB_VERSION_MINOR 0
#define GOB_VERSION_PATCHLEVEL 14

#define selfp (self->_priv)

#include <string.h> /* memset() */

#include "mn-message-view.h"

#include "mn-message-view-private.h"

#ifdef G_LIKELY
#define ___GOB_LIKELY(expr) G_LIKELY(expr)
#define ___GOB_UNLIKELY(expr) G_UNLIKELY(expr)
#else /* ! G_LIKELY */
#define ___GOB_LIKELY(expr) (expr)
#define ___GOB_UNLIKELY(expr) (expr)
#endif /* G_LIKELY */

#line 30 "mn-message-view.gob"

#include "mn-locked-callback.h"
#include "mn-util.h"

typedef struct
{
  MNMessageView		*self;
  MNTextTableCell	*cell;
  GList			*link;
  time_t		past_time;
} PastTimeCell;

static GQueue *past_time_cells;
static MNLockedGSource *past_time_cells_timeout_source = NULL;

#line 42 "mn-message-view.c"
/* self casting macros */
#define SELF(x) MN_MESSAGE_VIEW(x)
#define SELF_CONST(x) MN_MESSAGE_VIEW_CONST(x)
#define IS_SELF(x) MN_IS_MESSAGE_VIEW(x)
#define TYPE_SELF MN_TYPE_MESSAGE_VIEW
#define SELF_CLASS(x) MN_MESSAGE_VIEW_CLASS(x)

#define SELF_GET_CLASS(x) MN_MESSAGE_VIEW_GET_CLASS(x)

/* self typedefs */
typedef MNMessageView Self;
typedef MNMessageViewClass SelfClass;

/* here are local prototypes */
static void ___object_set_property (GObject *object, guint property_id, const GValue *value, GParamSpec *pspec);
static void mn_message_view_init (MNMessageView * o) G_GNUC_UNUSED;
static void mn_message_view_class_init (MNMessageViewClass * class) G_GNUC_UNUSED;
static void ___3_mn_message_view_finalize (GObject * object) G_GNUC_UNUSED;
static void ___4_mn_message_view_realize (GtkWidget * widget) G_GNUC_UNUSED;
static void mn_message_view_update (MNMessageView * self, GSList * messages) G_GNUC_UNUSED;
static void ___6_mn_message_view_clear (MNTextTable * table) G_GNUC_UNUSED;
static void mn_message_view_clear_past_time_cells (MNMessageView * self) G_GNUC_UNUSED;
static gboolean mn_message_view_update_past_time_cells_cb (gpointer data) G_GNUC_UNUSED;
static void mn_message_view_update_past_time_cell (PastTimeCell * pcell, time_t now) G_GNUC_UNUSED;

enum {
	PROP_0,
	PROP_MESSAGES
};

/* pointer to the class of our parent */
static MNTextTableClass *parent_class = NULL;

/* Short form macros */
#define self_set_messages mn_message_view_set_messages
#define self_update mn_message_view_update
#define self_append_past_time_cell mn_message_view_append_past_time_cell
#define self_clear_past_time_cells mn_message_view_clear_past_time_cells
#define self_update_past_time_cells_cb mn_message_view_update_past_time_cells_cb
#define self_update_past_time_cell mn_message_view_update_past_time_cell
GType
mn_message_view_get_type (void)
{
	static GType type = 0;

	if ___GOB_UNLIKELY(type == 0) {
		static const GTypeInfo info = {
			sizeof (MNMessageViewClass),
			(GBaseInitFunc) NULL,
			(GBaseFinalizeFunc) NULL,
			(GClassInitFunc) mn_message_view_class_init,
			(GClassFinalizeFunc) NULL,
			NULL /* class_data */,
			sizeof (MNMessageView),
			0 /* n_preallocs */,
			(GInstanceInitFunc) mn_message_view_init,
			NULL
		};

		type = g_type_register_static (MN_TYPE_TEXT_TABLE, "MNMessageView", &info, (GTypeFlags)G_TYPE_FLAG_ABSTRACT);
	}

	return type;
}

/* a macro for creating a new object of our type */
#define GET_NEW ((MNMessageView *)g_object_new(mn_message_view_get_type(), NULL))

/* a function for creating a new object of our type */
#include <stdarg.h>
static MNMessageView * GET_NEW_VARG (const char *first, ...) G_GNUC_UNUSED;
static MNMessageView *
GET_NEW_VARG (const char *first, ...)
{
	MNMessageView *ret;
	va_list ap;
	va_start (ap, first);
	ret = (MNMessageView *)g_object_new_valist (mn_message_view_get_type (), first, ap);
	va_end (ap);
	return ret;
}


static void
___finalize(GObject *obj_self)
{
#define __GOB_FUNCTION__ "MN:Message:View::finalize"
	MNMessageView *self G_GNUC_UNUSED = MN_MESSAGE_VIEW (obj_self);
	gpointer priv G_GNUC_UNUSED = self->_priv;
#line 61 "mn-message-view.gob"
	___3_mn_message_view_finalize(obj_self);
#line 134 "mn-message-view.c"
}
#undef __GOB_FUNCTION__

static void 
mn_message_view_init (MNMessageView * o G_GNUC_UNUSED)
{
#define __GOB_FUNCTION__ "MN:Message:View::init"
	o->_priv = G_TYPE_INSTANCE_GET_PRIVATE(o,MN_TYPE_MESSAGE_VIEW,MNMessageViewPrivate);
}
#undef __GOB_FUNCTION__
#line 56 "mn-message-view.gob"
static void 
mn_message_view_class_init (MNMessageViewClass * class G_GNUC_UNUSED)
#line 148 "mn-message-view.c"
{
#define __GOB_FUNCTION__ "MN:Message:View::class_init"
	GObjectClass *g_object_class G_GNUC_UNUSED = (GObjectClass*) class;
	GtkWidgetClass *gtk_widget_class = (GtkWidgetClass *)class;
	MNTextTableClass *mn_text_table_class = (MNTextTableClass *)class;

	g_type_class_add_private(class,sizeof(MNMessageViewPrivate));

	parent_class = g_type_class_ref (MN_TYPE_TEXT_TABLE);

#line 61 "mn-message-view.gob"
	g_object_class->finalize = ___finalize;
#line 71 "mn-message-view.gob"
	gtk_widget_class->realize = ___4_mn_message_view_realize;
#line 163 "mn-message-view.c"
	class->update = NULL;
#line 92 "mn-message-view.gob"
	mn_text_table_class->clear = ___6_mn_message_view_clear;
#line 167 "mn-message-view.c"
	g_object_class->set_property = ___object_set_property;
    {
	GParamSpec   *param_spec;

	param_spec = g_param_spec_pointer
		("messages" /* name */,
		 NULL /* nick */,
		 NULL /* blurb */,
		 (GParamFlags)(G_PARAM_WRITABLE));
	g_object_class_install_property (g_object_class,
		PROP_MESSAGES,
		param_spec);
    }
 {
#line 57 "mn-message-view.gob"

    past_time_cells = g_queue_new();
  
#line 186 "mn-message-view.c"
 }
}
#undef __GOB_FUNCTION__

static void
___object_set_property (GObject *object,
	guint property_id,
	const GValue *VAL G_GNUC_UNUSED,
	GParamSpec *pspec G_GNUC_UNUSED)
#define __GOB_FUNCTION__ "MN:Message:View::set_property"
{
	MNMessageView *self G_GNUC_UNUSED;

	self = MN_MESSAGE_VIEW (object);

	switch (property_id) {
	case PROP_MESSAGES:
		{
#line 52 "mn-message-view.gob"

      self_update(self, g_value_get_pointer(VAL));
    
#line 209 "mn-message-view.c"
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


#line 52 "mn-message-view.gob"
void 
mn_message_view_set_messages (MNMessageView * self, gpointer val)
#line 228 "mn-message-view.c"
{
#define __GOB_FUNCTION__ "MN:Message:View::set_messages"
{
#line 50 "mn-message-view.gob"
		g_object_set (G_OBJECT (self), "messages", val, NULL);
}}
#line 235 "mn-message-view.c"
#undef __GOB_FUNCTION__


#line 61 "mn-message-view.gob"
static void 
___3_mn_message_view_finalize (GObject * object G_GNUC_UNUSED)
#line 242 "mn-message-view.c"
#define PARENT_HANDLER(___object) \
	{ if(G_OBJECT_CLASS(parent_class)->finalize) \
		(* G_OBJECT_CLASS(parent_class)->finalize)(___object); }
{
#define __GOB_FUNCTION__ "MN:Message:View::finalize"
{
#line 63 "mn-message-view.gob"
	
    Self *self = SELF(object);

    self_clear_past_time_cells(self);

    PARENT_HANDLER(object);
  }}
#line 257 "mn-message-view.c"
#undef __GOB_FUNCTION__
#undef PARENT_HANDLER

#line 71 "mn-message-view.gob"
static void 
___4_mn_message_view_realize (GtkWidget * widget G_GNUC_UNUSED)
#line 264 "mn-message-view.c"
#define PARENT_HANDLER(___widget) \
	{ if(GTK_WIDGET_CLASS(parent_class)->realize) \
		(* GTK_WIDGET_CLASS(parent_class)->realize)(___widget); }
{
#define __GOB_FUNCTION__ "MN:Message:View::realize"
{
#line 73 "mn-message-view.gob"
	
    GtkWidget *toplevel;
    GtkStateType state;

    PARENT_HANDLER(widget);

    /* set a transparent background */

    toplevel = gtk_widget_get_toplevel(widget);
    g_assert(toplevel != NULL);
    g_assert(toplevel->style != NULL);

    for (state = GTK_STATE_NORMAL; state <= GTK_STATE_INSENSITIVE; state++)
      gtk_widget_modify_bg(widget, state, &toplevel->style->bg[state]);
  }}
#line 287 "mn-message-view.c"
#undef __GOB_FUNCTION__
#undef PARENT_HANDLER

#line 89 "mn-message-view.gob"
static void 
mn_message_view_update (MNMessageView * self, GSList * messages)
#line 294 "mn-message-view.c"
{
	MNMessageViewClass *klass;
#line 89 "mn-message-view.gob"
	g_return_if_fail (self != NULL);
#line 89 "mn-message-view.gob"
	g_return_if_fail (MN_IS_MESSAGE_VIEW (self));
#line 301 "mn-message-view.c"
	klass = MN_MESSAGE_VIEW_GET_CLASS(self);

	if(klass->update)
		(*klass->update)(self,messages);
}

#line 92 "mn-message-view.gob"
static void 
___6_mn_message_view_clear (MNTextTable * table G_GNUC_UNUSED)
#line 311 "mn-message-view.c"
#define PARENT_HANDLER(___table) \
	{ if(MN_TEXT_TABLE_CLASS(parent_class)->clear) \
		(* MN_TEXT_TABLE_CLASS(parent_class)->clear)(___table); }
{
#define __GOB_FUNCTION__ "MN:Message:View::clear"
{
#line 94 "mn-message-view.gob"
	
    self_clear_past_time_cells(SELF(table));

    PARENT_HANDLER(table);
  }}
#line 324 "mn-message-view.c"
#undef __GOB_FUNCTION__
#undef PARENT_HANDLER

#line 100 "mn-message-view.gob"
void 
mn_message_view_append_past_time_cell (MNMessageView * self, time_t past_time, time_t now)
#line 331 "mn-message-view.c"
{
#define __GOB_FUNCTION__ "MN:Message:View::append_past_time_cell"
#line 100 "mn-message-view.gob"
	g_return_if_fail (self != NULL);
#line 100 "mn-message-view.gob"
	g_return_if_fail (MN_IS_MESSAGE_VIEW (self));
#line 338 "mn-message-view.c"
{
#line 102 "mn-message-view.gob"
	
    PastTimeCell *pcell;

    pcell = g_new(PastTimeCell, 1);
    pcell->self = self;
    pcell->cell = mn_text_table_append_text_cell(MN_TEXT_TABLE(self), NULL);
    pcell->link = g_list_alloc();
    pcell->link->data = pcell;
    pcell->past_time = past_time;

    self_update_past_time_cell(pcell, now);

    selfp->past_time_cells = g_slist_prepend(selfp->past_time_cells, pcell);
    g_queue_push_tail_link(past_time_cells, pcell->link);

    if (! past_time_cells_timeout_source)
      past_time_cells_timeout_source = mn_g_timeout_add_gdk_locked(500, self_update_past_time_cells_cb, NULL);
  }}
#line 359 "mn-message-view.c"
#undef __GOB_FUNCTION__

#line 121 "mn-message-view.gob"
static void 
mn_message_view_clear_past_time_cells (MNMessageView * self)
#line 365 "mn-message-view.c"
{
#define __GOB_FUNCTION__ "MN:Message:View::clear_past_time_cells"
#line 121 "mn-message-view.gob"
	g_return_if_fail (self != NULL);
#line 121 "mn-message-view.gob"
	g_return_if_fail (MN_IS_MESSAGE_VIEW (self));
#line 372 "mn-message-view.c"
{
#line 123 "mn-message-view.gob"
	
    GSList *l;

    if (! selfp->past_time_cells)
      return;

    MN_LIST_FOREACH(l, selfp->past_time_cells)
      {
	PastTimeCell *pcell = l->data;

	g_queue_delete_link(past_time_cells, pcell->link);
	g_free(pcell);
      }

    mn_g_slist_clear(&selfp->past_time_cells);

    if (g_queue_is_empty(past_time_cells))
      mn_locked_g_source_clear(&past_time_cells_timeout_source);
  }}
#line 394 "mn-message-view.c"
#undef __GOB_FUNCTION__

#line 143 "mn-message-view.gob"
static gboolean 
mn_message_view_update_past_time_cells_cb (gpointer data)
#line 400 "mn-message-view.c"
{
#define __GOB_FUNCTION__ "MN:Message:View::update_past_time_cells_cb"
{
#line 145 "mn-message-view.gob"
	
    time_t now;
    GList *l;

    now = mn_time();
    MN_QUEUE_FOREACH(l, past_time_cells)
      self_update_past_time_cell(l->data, now);

    return TRUE;		/* keep source */
  }}
#line 415 "mn-message-view.c"
#undef __GOB_FUNCTION__

#line 156 "mn-message-view.gob"
static void 
mn_message_view_update_past_time_cell (PastTimeCell * pcell, time_t now)
#line 421 "mn-message-view.c"
{
#define __GOB_FUNCTION__ "MN:Message:View::update_past_time_cell"
#line 156 "mn-message-view.gob"
	g_return_if_fail (pcell != NULL);
#line 426 "mn-message-view.c"
{
#line 158 "mn-message-view.gob"
	
    char *formatted;

    formatted = mn_format_past_time(pcell->past_time, now);
    mn_text_table_cell_set_text(MN_TEXT_TABLE(pcell->self), pcell->cell, formatted);
    g_free(formatted);
  }}
#line 436 "mn-message-view.c"
#undef __GOB_FUNCTION__
