/* Generated by GOB (v2.0.14)   (do not edit directly) */

/* End world hunger, donate to the World Food Programme, http://www.wfp.org */

#define GOB_VERSION_MAJOR 2
#define GOB_VERSION_MINOR 0
#define GOB_VERSION_PATCHLEVEL 14

#define selfp (self->_priv)

#include <string.h> /* memset() */

#include "mn-text-table.h"

#include "mn-text-table-private.h"

#ifdef G_LIKELY
#define ___GOB_LIKELY(expr) G_LIKELY(expr)
#define ___GOB_UNLIKELY(expr) G_UNLIKELY(expr)
#else /* ! G_LIKELY */
#define ___GOB_LIKELY(expr) (expr)
#define ___GOB_UNLIKELY(expr) (expr)
#endif /* G_LIKELY */

#line 38 "mn-text-table.gob"

#include "mn-util.h"

#define HORIZONTAL_SPACING	12
#define VERTICAL_SPACING	0

#define COLUMN_SIZE(self, column) \
  g_array_index((self)->_priv->column_sizes, int, (column))

struct _MNTextTableCell
{
  PangoLayout	*layout;	/* NULL for a blank cell */
  gboolean	dirty;
  int		width;
  int		height;
};

#line 44 "mn-text-table.c"
/* self casting macros */
#define SELF(x) MN_TEXT_TABLE(x)
#define SELF_CONST(x) MN_TEXT_TABLE_CONST(x)
#define IS_SELF(x) MN_IS_TEXT_TABLE(x)
#define TYPE_SELF MN_TYPE_TEXT_TABLE
#define SELF_CLASS(x) MN_TEXT_TABLE_CLASS(x)

#define SELF_GET_CLASS(x) MN_TEXT_TABLE_GET_CLASS(x)

/* self typedefs */
typedef MNTextTable Self;
typedef MNTextTableClass SelfClass;

/* here are local prototypes */
static void mn_text_table_class_init (MNTextTableClass * c) G_GNUC_UNUSED;
static void mn_text_table_init (MNTextTable * self) G_GNUC_UNUSED;
static void mn_text_table_row_free (Row * row) G_GNUC_UNUSED;
static void mn_text_table_cell_free (MNTextTableCell * cell) G_GNUC_UNUSED;
static void ___4_mn_text_table_realize (GtkWidget * widget) G_GNUC_UNUSED;
static gboolean ___5_mn_text_table_expose_event (GtkWidget * widget, GdkEventExpose * event) G_GNUC_UNUSED;
static void ___6_mn_text_table_size_request (GtkWidget * widget, GtkRequisition * requisition) G_GNUC_UNUSED;
static void mn_text_table_set_dirty (MNTextTable * self) G_GNUC_UNUSED;
static void mn_text_table_context_changed (MNTextTable * self) G_GNUC_UNUSED;
static void mn_text_table_relayout (MNTextTable * self) G_GNUC_UNUSED;
static void mn_text_table_redraw (MNTextTable * self, GdkEventExpose * event) G_GNUC_UNUSED;
static void ___real_mn_text_table_clear (MNTextTable * self);
static void mn_text_table_append_cell_real (MNTextTable * self, MNTextTableCell * cell) G_GNUC_UNUSED;

/* pointer to the class of our parent */
static GtkDrawingAreaClass *parent_class = NULL;

/* Short form macros */
#define self_row_free mn_text_table_row_free
#define self_cell_free mn_text_table_cell_free
#define self_set_dirty mn_text_table_set_dirty
#define self_context_changed mn_text_table_context_changed
#define self_relayout mn_text_table_relayout
#define self_redraw mn_text_table_redraw
#define self_clear mn_text_table_clear
#define self_append_text_cell mn_text_table_append_text_cell
#define self_append_text_cell_from_markup mn_text_table_append_text_cell_from_markup
#define self_append_text_cell_from_layout mn_text_table_append_text_cell_from_layout
#define self_append_blank_cell mn_text_table_append_blank_cell
#define self_append_cell_real mn_text_table_append_cell_real
#define self_cell_set_text mn_text_table_cell_set_text
#define self_line_break mn_text_table_line_break
GType
mn_text_table_get_type (void)
{
	static GType type = 0;

	if ___GOB_UNLIKELY(type == 0) {
		static const GTypeInfo info = {
			sizeof (MNTextTableClass),
			(GBaseInitFunc) NULL,
			(GBaseFinalizeFunc) NULL,
			(GClassInitFunc) mn_text_table_class_init,
			(GClassFinalizeFunc) NULL,
			NULL /* class_data */,
			sizeof (MNTextTable),
			0 /* n_preallocs */,
			(GInstanceInitFunc) mn_text_table_init,
			NULL
		};

		type = g_type_register_static (GTK_TYPE_DRAWING_AREA, "MNTextTable", &info, (GTypeFlags)0);
	}

	return type;
}

/* a macro for creating a new object of our type */
#define GET_NEW ((MNTextTable *)g_object_new(mn_text_table_get_type(), NULL))

/* a function for creating a new object of our type */
#include <stdarg.h>
static MNTextTable * GET_NEW_VARG (const char *first, ...) G_GNUC_UNUSED;
static MNTextTable *
GET_NEW_VARG (const char *first, ...)
{
	MNTextTable *ret;
	va_list ap;
	va_start (ap, first);
	ret = (MNTextTable *)g_object_new_valist (mn_text_table_get_type (), first, ap);
	va_end (ap);
	return ret;
}


static void
___finalize(GObject *obj_self)
{
#define __GOB_FUNCTION__ "MN:Text:Table::finalize"
	MNTextTable *self G_GNUC_UNUSED = MN_TEXT_TABLE (obj_self);
	gpointer priv G_GNUC_UNUSED = self->_priv;
	if(G_OBJECT_CLASS(parent_class)->finalize) \
		(* G_OBJECT_CLASS(parent_class)->finalize)(obj_self);
#define rows (self->_priv->rows)
#define VAR rows
	{
#line 80 "mn-text-table.gob"
	 mn_g_queue_free_deep_custom(VAR, (GFunc) self_row_free, NULL); }
#line 147 "mn-text-table.c"
	memset(&rows, 0, sizeof(rows));
#undef VAR
#undef rows
#define column_sizes (self->_priv->column_sizes)
#define VAR column_sizes
	{
#line 83 "mn-text-table.gob"
	 g_array_free(VAR, TRUE); }
#line 156 "mn-text-table.c"
	memset(&column_sizes, 0, sizeof(column_sizes));
#undef VAR
#undef column_sizes
}
#undef __GOB_FUNCTION__

static void 
mn_text_table_class_init (MNTextTableClass * c G_GNUC_UNUSED)
{
#define __GOB_FUNCTION__ "MN:Text:Table::class_init"
	GObjectClass *g_object_class G_GNUC_UNUSED = (GObjectClass*) c;
	GtkWidgetClass *gtk_widget_class = (GtkWidgetClass *)c;

	g_type_class_add_private(c,sizeof(MNTextTablePrivate));

	parent_class = g_type_class_ref (GTK_TYPE_DRAWING_AREA);

#line 117 "mn-text-table.gob"
	gtk_widget_class->realize = ___4_mn_text_table_realize;
#line 126 "mn-text-table.gob"
	gtk_widget_class->expose_event = ___5_mn_text_table_expose_event;
#line 140 "mn-text-table.gob"
	gtk_widget_class->size_request = ___6_mn_text_table_size_request;
#line 292 "mn-text-table.gob"
	c->clear = ___real_mn_text_table_clear;
#line 182 "mn-text-table.c"
	g_object_class->finalize = ___finalize;
}
#undef __GOB_FUNCTION__
#line 91 "mn-text-table.gob"
static void 
mn_text_table_init (MNTextTable * self G_GNUC_UNUSED)
#line 189 "mn-text-table.c"
{
#define __GOB_FUNCTION__ "MN:Text:Table::init"
	self->_priv = G_TYPE_INSTANCE_GET_PRIVATE(self,MN_TYPE_TEXT_TABLE,MNTextTablePrivate);
#line 79 "mn-text-table.gob"
	self->_priv->rows = g_queue_new();
#line 195 "mn-text-table.c"
#line 82 "mn-text-table.gob"
	self->_priv->column_sizes = g_array_new(FALSE, TRUE, sizeof(int));
#line 198 "mn-text-table.c"
#line 83 "mn-text-table.gob"
	self->_priv->dirty = TRUE;
#line 201 "mn-text-table.c"
 {
#line 92 "mn-text-table.gob"

    /* allow consumers to receive button-press-event */
    gtk_widget_add_events(GTK_WIDGET(self), GDK_BUTTON_PRESS_MASK);

    g_object_connect(self,
		     "swapped-signal::style-set", self_context_changed, self,
		     "swapped-signal::direction-changed", self_context_changed, self,
		     NULL);
  
#line 213 "mn-text-table.c"
 }
}
#undef __GOB_FUNCTION__



#line 102 "mn-text-table.gob"
static void 
mn_text_table_row_free (Row * row)
#line 223 "mn-text-table.c"
{
#define __GOB_FUNCTION__ "MN:Text:Table::row_free"
#line 102 "mn-text-table.gob"
	g_return_if_fail (row != NULL);
#line 228 "mn-text-table.c"
{
#line 104 "mn-text-table.gob"
	
    mn_g_queue_free_deep_custom(row->cells, (GFunc) self_cell_free, NULL);
    g_free(row);
  }}
#line 235 "mn-text-table.c"
#undef __GOB_FUNCTION__

#line 109 "mn-text-table.gob"
static void 
mn_text_table_cell_free (MNTextTableCell * cell)
#line 241 "mn-text-table.c"
{
#define __GOB_FUNCTION__ "MN:Text:Table::cell_free"
#line 109 "mn-text-table.gob"
	g_return_if_fail (cell != NULL);
#line 246 "mn-text-table.c"
{
#line 111 "mn-text-table.gob"
	
    if (cell->layout)
      g_object_unref(cell->layout);
    g_free(cell);
  }}
#line 254 "mn-text-table.c"
#undef __GOB_FUNCTION__

#line 117 "mn-text-table.gob"
static void 
___4_mn_text_table_realize (GtkWidget * widget G_GNUC_UNUSED)
#line 260 "mn-text-table.c"
#define PARENT_HANDLER(___widget) \
	{ if(GTK_WIDGET_CLASS(parent_class)->realize) \
		(* GTK_WIDGET_CLASS(parent_class)->realize)(___widget); }
{
#define __GOB_FUNCTION__ "MN:Text:Table::realize"
{
#line 119 "mn-text-table.gob"
	
    PARENT_HANDLER(widget);

    /* set a transparent background */
    gdk_window_set_back_pixmap(widget->window, NULL, TRUE);
  }}
#line 274 "mn-text-table.c"
#undef __GOB_FUNCTION__
#undef PARENT_HANDLER

#line 126 "mn-text-table.gob"
static gboolean 
___5_mn_text_table_expose_event (GtkWidget * widget G_GNUC_UNUSED, GdkEventExpose * event)
#line 281 "mn-text-table.c"
#define PARENT_HANDLER(___widget,___event) \
	((GTK_WIDGET_CLASS(parent_class)->expose_event)? \
		(* GTK_WIDGET_CLASS(parent_class)->expose_event)(___widget,___event): \
		((gboolean )0))
{
#define __GOB_FUNCTION__ "MN:Text:Table::expose_event"
{
#line 128 "mn-text-table.gob"
	
    Self *self = SELF(widget);

    if (GTK_WIDGET_MAPPED(widget))
      {
	self_relayout(self);
	self_redraw(self, event);
      }

    return FALSE;		/* propagate event */
  }}
#line 301 "mn-text-table.c"
#undef __GOB_FUNCTION__
#undef PARENT_HANDLER

#line 140 "mn-text-table.gob"
static void 
___6_mn_text_table_size_request (GtkWidget * widget G_GNUC_UNUSED, GtkRequisition * requisition)
#line 308 "mn-text-table.c"
#define PARENT_HANDLER(___widget,___requisition) \
	{ if(GTK_WIDGET_CLASS(parent_class)->size_request) \
		(* GTK_WIDGET_CLASS(parent_class)->size_request)(___widget,___requisition); }
{
#define __GOB_FUNCTION__ "MN:Text:Table::size_request"
{
#line 142 "mn-text-table.gob"
	
    Self *self = SELF(widget);

    self_relayout(self);

    requisition->width = selfp->width;
    requisition->height = selfp->height;
  }}
#line 324 "mn-text-table.c"
#undef __GOB_FUNCTION__
#undef PARENT_HANDLER

#line 151 "mn-text-table.gob"
static void 
mn_text_table_set_dirty (MNTextTable * self)
#line 331 "mn-text-table.c"
{
#define __GOB_FUNCTION__ "MN:Text:Table::set_dirty"
#line 151 "mn-text-table.gob"
	g_return_if_fail (self != NULL);
#line 151 "mn-text-table.gob"
	g_return_if_fail (MN_IS_TEXT_TABLE (self));
#line 338 "mn-text-table.c"
{
#line 153 "mn-text-table.gob"
	
    if (! selfp->dirty)
      {
	selfp->dirty = TRUE;
	gtk_widget_queue_resize(GTK_WIDGET(self));
      }
  }}
#line 348 "mn-text-table.c"
#undef __GOB_FUNCTION__

#line 161 "mn-text-table.gob"
static void 
mn_text_table_context_changed (MNTextTable * self)
#line 354 "mn-text-table.c"
{
#define __GOB_FUNCTION__ "MN:Text:Table::context_changed"
#line 161 "mn-text-table.gob"
	g_return_if_fail (self != NULL);
#line 161 "mn-text-table.gob"
	g_return_if_fail (MN_IS_TEXT_TABLE (self));
#line 361 "mn-text-table.c"
{
#line 163 "mn-text-table.gob"
	
    GList *la;

    MN_QUEUE_FOREACH(la, selfp->rows)
      {
	Row *row = la->data;
	GList *lb;

	MN_QUEUE_FOREACH(lb, row->cells)
	  {
	    MNTextTableCell *cell = lb->data;

	    if (cell->layout)
	      {
		pango_layout_context_changed(cell->layout);
		cell->dirty = TRUE;
	      }
	  }
      }

    self_set_dirty(self);
  }}
#line 386 "mn-text-table.c"
#undef __GOB_FUNCTION__

#line 186 "mn-text-table.gob"
static void 
mn_text_table_relayout (MNTextTable * self)
#line 392 "mn-text-table.c"
{
#define __GOB_FUNCTION__ "MN:Text:Table::relayout"
#line 186 "mn-text-table.gob"
	g_return_if_fail (self != NULL);
#line 186 "mn-text-table.gob"
	g_return_if_fail (MN_IS_TEXT_TABLE (self));
#line 399 "mn-text-table.c"
{
#line 188 "mn-text-table.gob"
	
    int i;
    GList *la;

    if (! selfp->dirty)
      return;

    selfp->width = 0;
    selfp->height = 0;

    for (i = 0; i < selfp->column_sizes->len; i++)
      COLUMN_SIZE(self, i) = 0;

    MN_QUEUE_FOREACH(la, selfp->rows)
      {
	Row *row = la->data;
	int column = 0;
	GList *lb;

	row->height = 0;

	MN_QUEUE_FOREACH(lb, row->cells)
	  {
	    MNTextTableCell *cell = lb->data;
	    int n_columns = column + 1;

	    if (cell->dirty)
	      {
		g_assert(cell->layout != NULL);

		pango_layout_get_pixel_size(cell->layout, &cell->width, &cell->height);
		cell->dirty = FALSE;
	      }

	    if (n_columns > selfp->column_sizes->len)
	      g_array_set_size(selfp->column_sizes, n_columns);

	    if (cell->width > COLUMN_SIZE(self, column))
	      COLUMN_SIZE(self, column) = cell->width;
	    if (cell->height > row->height)
	      row->height = cell->height;

	    column++;
	  }

	selfp->height += row->height;
      }

    for (i = 0; i < selfp->column_sizes->len; i++)
      selfp->width += COLUMN_SIZE(self, i);

    if (selfp->column_sizes->len > 1)
      selfp->width += HORIZONTAL_SPACING * (selfp->column_sizes->len - 1);
    if (selfp->rows->length > 1)
      selfp->height += VERTICAL_SPACING * (selfp->rows->length - 1);

    selfp->dirty = FALSE;
  }}
#line 460 "mn-text-table.c"
#undef __GOB_FUNCTION__

#line 247 "mn-text-table.gob"
static void 
mn_text_table_redraw (MNTextTable * self, GdkEventExpose * event)
#line 466 "mn-text-table.c"
{
#define __GOB_FUNCTION__ "MN:Text:Table::redraw"
#line 247 "mn-text-table.gob"
	g_return_if_fail (self != NULL);
#line 247 "mn-text-table.gob"
	g_return_if_fail (MN_IS_TEXT_TABLE (self));
#line 247 "mn-text-table.gob"
	g_return_if_fail (event != NULL);
#line 475 "mn-text-table.c"
{
#line 249 "mn-text-table.gob"
	
    GtkWidget *widget = GTK_WIDGET(self);
    GList *la;
    int y = 0;

    g_return_if_fail(selfp->dirty == FALSE);

    MN_QUEUE_FOREACH(la, selfp->rows)
      {
	Row *row = la->data;
	GList *lb;
	int x = 0;
	int column = 0;

	MN_QUEUE_FOREACH(lb, row->cells)
	  {
	    MNTextTableCell *cell = lb->data;

	    if (cell->layout)
	      gtk_paint_layout(widget->style,
			       widget->window,
			       GTK_WIDGET_STATE(widget),
			       FALSE,
			       &event->area,
			       widget,
			       NULL,
			       x,
			       y + row->height - cell->height,
			       cell->layout);

	    x += COLUMN_SIZE(self, column);
	    if (lb->next)
	      x += HORIZONTAL_SPACING;

	    column++;
	  }

	y += row->height;
	if (la->next)
	  y += VERTICAL_SPACING;
      }
  }}
#line 520 "mn-text-table.c"
#undef __GOB_FUNCTION__

#line 292 "mn-text-table.gob"
void 
mn_text_table_clear (MNTextTable * self)
#line 526 "mn-text-table.c"
{
	MNTextTableClass *klass;
#line 292 "mn-text-table.gob"
	g_return_if_fail (self != NULL);
#line 292 "mn-text-table.gob"
	g_return_if_fail (MN_IS_TEXT_TABLE (self));
#line 533 "mn-text-table.c"
	klass = MN_TEXT_TABLE_GET_CLASS(self);

	if(klass->clear)
		(*klass->clear)(self);
}
#line 292 "mn-text-table.gob"
static void 
___real_mn_text_table_clear (MNTextTable * self G_GNUC_UNUSED)
#line 542 "mn-text-table.c"
{
#define __GOB_FUNCTION__ "MN:Text:Table::clear"
{
#line 294 "mn-text-table.gob"
	
    Row *row;

    while ((row = g_queue_pop_head(selfp->rows)))
      self_row_free(row);

    g_array_set_size(selfp->column_sizes, 0);

    selfp->row = NULL;

    self_set_dirty(self);
  }}
#line 559 "mn-text-table.c"
#undef __GOB_FUNCTION__

#line 307 "mn-text-table.gob"
MNTextTableCell * 
mn_text_table_append_text_cell (MNTextTable * self, const char * text)
#line 565 "mn-text-table.c"
{
#define __GOB_FUNCTION__ "MN:Text:Table::append_text_cell"
#line 307 "mn-text-table.gob"
	g_return_val_if_fail (self != NULL, (MNTextTableCell * )0);
#line 307 "mn-text-table.gob"
	g_return_val_if_fail (MN_IS_TEXT_TABLE (self), (MNTextTableCell * )0);
#line 572 "mn-text-table.c"
{
#line 309 "mn-text-table.gob"
	
    return self_append_text_cell_from_layout(self, gtk_widget_create_pango_layout(GTK_WIDGET(self), text));
  }}
#line 578 "mn-text-table.c"
#undef __GOB_FUNCTION__

#line 313 "mn-text-table.gob"
MNTextTableCell * 
mn_text_table_append_text_cell_from_markup (MNTextTable * self, const char * markup)
#line 584 "mn-text-table.c"
{
#define __GOB_FUNCTION__ "MN:Text:Table::append_text_cell_from_markup"
#line 313 "mn-text-table.gob"
	g_return_val_if_fail (self != NULL, (MNTextTableCell * )0);
#line 313 "mn-text-table.gob"
	g_return_val_if_fail (MN_IS_TEXT_TABLE (self), (MNTextTableCell * )0);
#line 313 "mn-text-table.gob"
	g_return_val_if_fail (markup != NULL, (MNTextTableCell * )0);
#line 593 "mn-text-table.c"
{
#line 315 "mn-text-table.gob"
	
    PangoLayout *layout;

    layout = gtk_widget_create_pango_layout(GTK_WIDGET(self), NULL);
    pango_layout_set_markup(layout, markup, -1);

    return self_append_text_cell_from_layout(self, layout);
  }}
#line 604 "mn-text-table.c"
#undef __GOB_FUNCTION__

#line 324 "mn-text-table.gob"
MNTextTableCell * 
mn_text_table_append_text_cell_from_layout (MNTextTable * self, PangoLayout * layout)
#line 610 "mn-text-table.c"
{
#define __GOB_FUNCTION__ "MN:Text:Table::append_text_cell_from_layout"
#line 324 "mn-text-table.gob"
	g_return_val_if_fail (self != NULL, (MNTextTableCell * )0);
#line 324 "mn-text-table.gob"
	g_return_val_if_fail (MN_IS_TEXT_TABLE (self), (MNTextTableCell * )0);
#line 324 "mn-text-table.gob"
	g_return_val_if_fail (layout != NULL, (MNTextTableCell * )0);
#line 619 "mn-text-table.c"
{
#line 326 "mn-text-table.gob"
	
    MNTextTableCell *cell;

    cell = g_new(MNTextTableCell, 1);
    cell->layout = layout;
    cell->dirty = TRUE;

    self_append_cell_real(self, cell);

    return cell;
  }}
#line 633 "mn-text-table.c"
#undef __GOB_FUNCTION__

#line 338 "mn-text-table.gob"
MNTextTableCell * 
mn_text_table_append_blank_cell (MNTextTable * self, int width, int height)
#line 639 "mn-text-table.c"
{
#define __GOB_FUNCTION__ "MN:Text:Table::append_blank_cell"
#line 338 "mn-text-table.gob"
	g_return_val_if_fail (self != NULL, (MNTextTableCell * )0);
#line 338 "mn-text-table.gob"
	g_return_val_if_fail (MN_IS_TEXT_TABLE (self), (MNTextTableCell * )0);
#line 646 "mn-text-table.c"
{
#line 340 "mn-text-table.gob"
	
    MNTextTableCell *cell;

    cell = g_new(MNTextTableCell, 1);
    cell->layout = NULL;
    cell->dirty = FALSE;
    cell->width = width;
    cell->height = height;

    self_append_cell_real(self, cell);

    return cell;
  }}
#line 662 "mn-text-table.c"
#undef __GOB_FUNCTION__

#line 354 "mn-text-table.gob"
static void 
mn_text_table_append_cell_real (MNTextTable * self, MNTextTableCell * cell)
#line 668 "mn-text-table.c"
{
#define __GOB_FUNCTION__ "MN:Text:Table::append_cell_real"
#line 354 "mn-text-table.gob"
	g_return_if_fail (self != NULL);
#line 354 "mn-text-table.gob"
	g_return_if_fail (MN_IS_TEXT_TABLE (self));
#line 675 "mn-text-table.c"
{
#line 356 "mn-text-table.gob"
	
    if (! selfp->row)
      {
	selfp->row = g_new(Row, 1);
	selfp->row->cells = g_queue_new();

	g_queue_push_tail(selfp->rows, selfp->row);
      }

    g_queue_push_tail(selfp->row->cells, cell);

    self_set_dirty(self);
  }}
#line 691 "mn-text-table.c"
#undef __GOB_FUNCTION__

#line 370 "mn-text-table.gob"
void 
mn_text_table_cell_set_text (MNTextTable * self, MNTextTableCell * cell, const char * text)
#line 697 "mn-text-table.c"
{
#define __GOB_FUNCTION__ "MN:Text:Table::cell_set_text"
#line 370 "mn-text-table.gob"
	g_return_if_fail (self != NULL);
#line 370 "mn-text-table.gob"
	g_return_if_fail (MN_IS_TEXT_TABLE (self));
#line 370 "mn-text-table.gob"
	g_return_if_fail (cell != NULL);
#line 370 "mn-text-table.gob"
	g_return_if_fail (text != NULL);
#line 708 "mn-text-table.c"
{
#line 374 "mn-text-table.gob"
	
    const char *current_text;

    g_return_if_fail(cell->layout != NULL);

    current_text = pango_layout_get_text(cell->layout);
    if (! current_text || strcmp(current_text, text))
      {
	pango_layout_set_text(cell->layout, text, -1);
	cell->dirty = TRUE;
	self_set_dirty(self);
      }
  }}
#line 724 "mn-text-table.c"
#undef __GOB_FUNCTION__

#line 388 "mn-text-table.gob"
void 
mn_text_table_line_break (MNTextTable * self)
#line 730 "mn-text-table.c"
{
#define __GOB_FUNCTION__ "MN:Text:Table::line_break"
#line 388 "mn-text-table.gob"
	g_return_if_fail (self != NULL);
#line 388 "mn-text-table.gob"
	g_return_if_fail (MN_IS_TEXT_TABLE (self));
#line 737 "mn-text-table.c"
{
#line 390 "mn-text-table.gob"
	
    selfp->row = NULL;
  }}
#line 743 "mn-text-table.c"
#undef __GOB_FUNCTION__
