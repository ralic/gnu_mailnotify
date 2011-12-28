/* Generated by GOB (v2.0.15)   (do not edit directly) */

/* End world hunger, donate to the World Food Programme, http://www.wfp.org */

#define GOB_VERSION_MAJOR 2
#define GOB_VERSION_MINOR 0
#define GOB_VERSION_PATCHLEVEL 15

#define selfp (self->_priv)

#include <string.h> /* memset() */

#include "mn-gmail-mailbox-properties.h"

#include "mn-gmail-mailbox-properties-private.h"

#ifdef G_LIKELY
#define ___GOB_LIKELY(expr) G_LIKELY(expr)
#define ___GOB_UNLIKELY(expr) G_UNLIKELY(expr)
#else /* ! G_LIKELY */
#define ___GOB_LIKELY(expr) (expr)
#define ___GOB_UNLIKELY(expr) (expr)
#endif /* G_LIKELY */

#line 25 "src/mn-gmail-mailbox-properties.gob"

#include <glib/gi18n.h>
#include "mn-mailbox-properties.h"
#include "mn-mailbox-properties-private.h"
#include "mn-authenticated-mailbox-properties-private.h"
#include "mn-util.h"
#include "mn-properties-dialog.h"
#include "mn-authenticated-mailbox.h"
#include "mn-gmail-mailbox.h"
#include "mn-stock.h"

#line 38 "mn-gmail-mailbox-properties.c"
/* self casting macros */
#define SELF(x) MN_GMAIL_MAILBOX_PROPERTIES(x)
#define SELF_CONST(x) MN_GMAIL_MAILBOX_PROPERTIES_CONST(x)
#define IS_SELF(x) MN_IS_GMAIL_MAILBOX_PROPERTIES(x)
#define TYPE_SELF MN_TYPE_GMAIL_MAILBOX_PROPERTIES
#define SELF_CLASS(x) MN_GMAIL_MAILBOX_PROPERTIES_CLASS(x)

#define SELF_GET_CLASS(x) MN_GMAIL_MAILBOX_PROPERTIES_GET_CLASS(x)

/* self typedefs */
typedef MNGmailMailboxProperties Self;
typedef MNGmailMailboxPropertiesClass SelfClass;

/* here are local prototypes */
static void ___object_get_property (GObject *object, guint property_id, GValue *value, GParamSpec *pspec);
#line 85 "src/mn-gmail-mailbox-properties.gob"
static void mn_gmail_mailbox_properties_class_init (MNGmailMailboxPropertiesClass * class);
#line 56 "mn-gmail-mailbox-properties.c"
#line 94 "src/mn-gmail-mailbox-properties.gob"
static void mn_gmail_mailbox_properties_init (MNGmailMailboxProperties * self);
#line 59 "mn-gmail-mailbox-properties.c"
#line 138 "src/mn-gmail-mailbox-properties.gob"
static void mn_gmail_mailbox_properties_check_toggled_h (GtkToggleButton * togglebutton, gpointer user_data);
#line 62 "mn-gmail-mailbox-properties.c"
#line 149 "src/mn-gmail-mailbox-properties.gob"
static void ___4_mn_gmail_mailbox_properties_set_mailbox (MNMailboxProperties * properties, MNMailbox * mailbox);
#line 65 "mn-gmail-mailbox-properties.c"
#line 166 "src/mn-gmail-mailbox-properties.gob"
static MNMailbox * ___5_mn_gmail_mailbox_properties_get_mailbox (MNMailboxProperties * properties);
#line 68 "mn-gmail-mailbox-properties.c"

enum {
	PROP_0,
	PROP_COMPLETE,
	PROP_DEFAULT_NAME
};

/* pointer to the class of our parent */
static MNAuthenticatedMailboxPropertiesClass *parent_class = NULL;

/* Short form macros */
#define self_check_toggled_h mn_gmail_mailbox_properties_check_toggled_h
GType
mn_gmail_mailbox_properties_get_type (void)
{
	static GType type = 0;

	if ___GOB_UNLIKELY(type == 0) {
		static const GTypeInfo info = {
			sizeof (MNGmailMailboxPropertiesClass),
			(GBaseInitFunc) NULL,
			(GBaseFinalizeFunc) NULL,
			(GClassInitFunc) mn_gmail_mailbox_properties_class_init,
			(GClassFinalizeFunc) NULL,
			NULL /* class_data */,
			sizeof (MNGmailMailboxProperties),
			0 /* n_preallocs */,
			(GInstanceInitFunc) mn_gmail_mailbox_properties_init,
			NULL
		};

		type = g_type_register_static (MN_TYPE_AUTHENTICATED_MAILBOX_PROPERTIES, "MNGmailMailboxProperties", &info, (GTypeFlags)0);
	}

	return type;
}

/* a macro for creating a new object of our type */
#define GET_NEW ((MNGmailMailboxProperties *)g_object_new(mn_gmail_mailbox_properties_get_type(), NULL))

/* a function for creating a new object of our type */
#include <stdarg.h>
static MNGmailMailboxProperties * GET_NEW_VARG (const char *first, ...) G_GNUC_UNUSED;
static MNGmailMailboxProperties *
GET_NEW_VARG (const char *first, ...)
{
	MNGmailMailboxProperties *ret;
	va_list ap;
	va_start (ap, first);
	ret = (MNGmailMailboxProperties *)g_object_new_valist (mn_gmail_mailbox_properties_get_type (), first, ap);
	va_end (ap);
	return ret;
}


static void
___finalize(GObject *obj_self)
{
#define __GOB_FUNCTION__ "MN:Gmail:Mailbox:Properties::finalize"
	MNGmailMailboxProperties *self G_GNUC_UNUSED = MN_GMAIL_MAILBOX_PROPERTIES (obj_self);
	gpointer priv G_GNUC_UNUSED = self->_priv;
	if(G_OBJECT_CLASS(parent_class)->finalize) \
		(* G_OBJECT_CLASS(parent_class)->finalize)(obj_self);
#line 46 "src/mn-gmail-mailbox-properties.gob"
	if(self->_priv->location) { g_free ((gpointer) self->_priv->location); self->_priv->location = NULL; }
#line 134 "mn-gmail-mailbox-properties.c"
}
#undef __GOB_FUNCTION__

#line 85 "src/mn-gmail-mailbox-properties.gob"
static void 
mn_gmail_mailbox_properties_class_init (MNGmailMailboxPropertiesClass * class G_GNUC_UNUSED)
{
#line 142 "mn-gmail-mailbox-properties.c"
#define __GOB_FUNCTION__ "MN:Gmail:Mailbox:Properties::class_init"
	GObjectClass *g_object_class G_GNUC_UNUSED = (GObjectClass*) class;
	MNMailboxPropertiesClass *mn_mailbox_properties_class = (MNMailboxPropertiesClass *)class;

	g_type_class_add_private(class,sizeof(MNGmailMailboxPropertiesPrivate));

	parent_class = g_type_class_ref (MN_TYPE_AUTHENTICATED_MAILBOX_PROPERTIES);

#line 149 "src/mn-gmail-mailbox-properties.gob"
	mn_mailbox_properties_class->set_mailbox = ___4_mn_gmail_mailbox_properties_set_mailbox;
#line 166 "src/mn-gmail-mailbox-properties.gob"
	mn_mailbox_properties_class->get_mailbox = ___5_mn_gmail_mailbox_properties_get_mailbox;
#line 155 "mn-gmail-mailbox-properties.c"
	g_object_class->finalize = ___finalize;
	g_object_class->get_property = ___object_get_property;
    {
	g_object_class_override_property (g_object_class,
		PROP_COMPLETE,
		"complete");
	g_object_class_override_property (g_object_class,
		PROP_DEFAULT_NAME,
		"default_name");
    }
 {
#line 86 "src/mn-gmail-mailbox-properties.gob"

    MNMailboxPropertiesClass *p_class = MN_MAILBOX_PROPERTIES_CLASS(class);

    p_class->type = "gmail";
    p_class->stock_id = MN_STOCK_GMAIL;
    p_class->combo_label = "Gmail";
  
#line 175 "mn-gmail-mailbox-properties.c"
 }
}
#undef __GOB_FUNCTION__
#line 94 "src/mn-gmail-mailbox-properties.gob"
static void 
mn_gmail_mailbox_properties_init (MNGmailMailboxProperties * self G_GNUC_UNUSED)
{
#line 183 "mn-gmail-mailbox-properties.c"
#define __GOB_FUNCTION__ "MN:Gmail:Mailbox:Properties::init"
	self->_priv = G_TYPE_INSTANCE_GET_PRIVATE(self,MN_TYPE_GMAIL_MAILBOX_PROPERTIES,MNGmailMailboxPropertiesPrivate);
 {
#line 95 "src/mn-gmail-mailbox-properties.gob"

    MNMailboxProperties *properties = MN_MAILBOX_PROPERTIES(self);
    MNAuthenticatedMailboxProperties *auth = MN_AUTHENTICATED_MAILBOX_PROPERTIES(self);
    GtkWidget *label_vbox;
    GtkWidget *hbox;

    gtk_box_pack_start(GTK_BOX(auth->account_vbox), auth->username_vbox, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(auth->account_vbox), auth->password_vbox, FALSE, FALSE, 0);

    /* translators: header capitalization */
    label_vbox = mn_mailbox_properties_add_general_section(properties, _("Gmail Label"));

    selfp->label_check = gtk_check_button_new_with_mnemonic(_("_Restrict to this label:"));
    gtk_size_group_add_widget(properties->label_size_group, selfp->label_check);

    selfp->label_entry = gtk_entry_new();
    gtk_widget_set_sensitive(selfp->label_entry, FALSE);

    hbox = gtk_hbox_new(FALSE, 12);
    gtk_box_pack_start(GTK_BOX(hbox), selfp->label_check, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(hbox), selfp->label_entry, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(label_vbox), hbox, FALSE, FALSE, 0);
    gtk_widget_show_all(label_vbox);

    properties->entries = mn_g_slist_append_elements(properties->entries,
						     auth->username_entry,
						     auth->password_entry,
						     selfp->label_entry,
						     NULL);

    g_signal_connect(selfp->label_check, "toggled", G_CALLBACK(self_check_toggled_h), self);

    g_object_connect(auth->username_entry,
		     "swapped-signal::changed", mn_mailbox_properties_notify_complete, self,
		     "swapped-signal::changed", mn_mailbox_properties_notify_default_name, self,
		     NULL);

    g_object_connect(selfp->label_entry,
		     "swapped-signal::changed", mn_mailbox_properties_notify_complete, self,
		     "swapped-signal::changed", mn_mailbox_properties_notify_default_name, self,
		     NULL);
  
#line 230 "mn-gmail-mailbox-properties.c"
 }
}
#undef __GOB_FUNCTION__

static void
___object_get_property (GObject *object,
	guint property_id,
	GValue *VAL G_GNUC_UNUSED,
	GParamSpec *pspec G_GNUC_UNUSED)
#define __GOB_FUNCTION__ "MN:Gmail:Mailbox:Properties::get_property"
{
	MNGmailMailboxProperties *self G_GNUC_UNUSED;

	self = MN_GMAIL_MAILBOX_PROPERTIES (object);

	switch (property_id) {
	case PROP_COMPLETE:
		{
#line 50 "src/mn-gmail-mailbox-properties.gob"

      gboolean complete;

      complete = mn_authenticated_mailbox_properties_is_complete(MN_AUTHENTICATED_MAILBOX_PROPERTIES(self));
      if (complete)
	{
	  gboolean label_enabled;
	  const char *label;

	  label_enabled = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(selfp->label_check));
	  label = gtk_entry_get_text(GTK_ENTRY(selfp->label_entry));

	  if (label_enabled && ! *label)
	    complete = FALSE;
	}

      g_value_set_boolean(VAL, complete);
    
#line 268 "mn-gmail-mailbox-properties.c"
		}
		break;
	case PROP_DEFAULT_NAME:
		{
#line 71 "src/mn-gmail-mailbox-properties.gob"

      const char *username;
      gboolean label_enabled;
      const char *label;

      username = gtk_entry_get_text(GTK_ENTRY(MN_AUTHENTICATED_MAILBOX_PROPERTIES(self)->username_entry));
      g_assert(*username != 0);

      label_enabled = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(selfp->label_check));
      label = gtk_entry_get_text(GTK_ENTRY(selfp->label_entry));

      g_value_take_string(VAL, mn_gmail_mailbox_build_name(username, label_enabled ? label : NULL));
    
#line 287 "mn-gmail-mailbox-properties.c"
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



#line 138 "src/mn-gmail-mailbox-properties.gob"
static void 
mn_gmail_mailbox_properties_check_toggled_h (GtkToggleButton * togglebutton, gpointer user_data)
{
#line 308 "mn-gmail-mailbox-properties.c"
#define __GOB_FUNCTION__ "MN:Gmail:Mailbox:Properties::check_toggled_h"
{
#line 140 "src/mn-gmail-mailbox-properties.gob"
	
    Self *self = user_data;

    gtk_widget_set_sensitive(selfp->label_entry, gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(selfp->label_check)));

    g_object_notify(G_OBJECT(self), "complete");
    g_object_notify(G_OBJECT(self), "default-name");
  }}
#line 320 "mn-gmail-mailbox-properties.c"
#undef __GOB_FUNCTION__

#line 149 "src/mn-gmail-mailbox-properties.gob"
static void 
___4_mn_gmail_mailbox_properties_set_mailbox (MNMailboxProperties * properties G_GNUC_UNUSED, MNMailbox * mailbox)
#line 326 "mn-gmail-mailbox-properties.c"
#define PARENT_HANDLER(___properties,___mailbox) \
	{ if(MN_MAILBOX_PROPERTIES_CLASS(parent_class)->set_mailbox) \
		(* MN_MAILBOX_PROPERTIES_CLASS(parent_class)->set_mailbox)(___properties,___mailbox); }
{
#define __GOB_FUNCTION__ "MN:Gmail:Mailbox:Properties::set_mailbox"
{
#line 151 "src/mn-gmail-mailbox-properties.gob"
	
    Self *self = SELF(properties);
    MNGmailMailbox *gmail_mailbox = MN_GMAIL_MAILBOX(mailbox);

    PARENT_HANDLER(properties, mailbox);

    selfp->location = g_strdup(gmail_mailbox->location);

    if (gmail_mailbox->label)
      {
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(selfp->label_check), TRUE);
	gtk_entry_set_text(GTK_ENTRY(selfp->label_entry), gmail_mailbox->label);
      }
  }}
#line 348 "mn-gmail-mailbox-properties.c"
#undef __GOB_FUNCTION__
#undef PARENT_HANDLER

#line 166 "src/mn-gmail-mailbox-properties.gob"
static MNMailbox * 
___5_mn_gmail_mailbox_properties_get_mailbox (MNMailboxProperties * properties G_GNUC_UNUSED)
#line 355 "mn-gmail-mailbox-properties.c"
#define PARENT_HANDLER(___properties) \
	((MN_MAILBOX_PROPERTIES_CLASS(parent_class)->get_mailbox)? \
		(* MN_MAILBOX_PROPERTIES_CLASS(parent_class)->get_mailbox)(___properties): \
		((MNMailbox * )0))
{
#define __GOB_FUNCTION__ "MN:Gmail:Mailbox:Properties::get_mailbox"
{
#line 168 "src/mn-gmail-mailbox-properties.gob"
	
    Self *self = SELF(properties);
    MNMailbox *mailbox;

    mailbox = PARENT_HANDLER(properties);

    if (selfp->location)
      g_object_set(mailbox, MN_GMAIL_MAILBOX_PROP_LOCATION(selfp->location), NULL);

    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(selfp->label_check)))
      g_object_set(mailbox, MN_GMAIL_MAILBOX_PROP_LABEL((char *) gtk_entry_get_text(GTK_ENTRY(selfp->label_entry))), NULL);

    return mailbox;
  }}
#line 378 "mn-gmail-mailbox-properties.c"
#undef __GOB_FUNCTION__
#undef PARENT_HANDLER