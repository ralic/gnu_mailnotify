/* Generated by GOB (v2.0.14)   (do not edit directly) */

/* End world hunger, donate to the World Food Programme, http://www.wfp.org */

#define GOB_VERSION_MAJOR 2
#define GOB_VERSION_MINOR 0
#define GOB_VERSION_PATCHLEVEL 14

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

#line 27 "mn-gmail-mailbox-properties.gob"

#include "config.h"
#include <glib/gi18n.h>
#include "mn-mailbox-properties.h"
#include "mn-mailbox-properties-private.h"
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
static void mn_gmail_mailbox_properties_class_init (MNGmailMailboxPropertiesClass * class) G_GNUC_UNUSED;
static void mn_gmail_mailbox_properties_init (MNGmailMailboxProperties * self) G_GNUC_UNUSED;
static void ___3_mn_gmail_mailbox_properties_set_mailbox (MNMailboxProperties * properties, MNMailbox * mailbox) G_GNUC_UNUSED;
static MNMailbox * ___4_mn_gmail_mailbox_properties_get_mailbox (MNMailboxProperties * properties) G_GNUC_UNUSED;

enum {
	PROP_0,
	PROP_DEFAULT_NAME
};

/* pointer to the class of our parent */
static MNAuthenticatedMailboxPropertiesClass *parent_class = NULL;

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
#line 45 "mn-gmail-mailbox-properties.gob"
	if(self->_priv->location) { g_free ((gpointer) self->_priv->location); self->_priv->location = NULL; }
#line 120 "mn-gmail-mailbox-properties.c"
}
#undef __GOB_FUNCTION__

#line 57 "mn-gmail-mailbox-properties.gob"
static void 
mn_gmail_mailbox_properties_class_init (MNGmailMailboxPropertiesClass * class G_GNUC_UNUSED)
#line 127 "mn-gmail-mailbox-properties.c"
{
#define __GOB_FUNCTION__ "MN:Gmail:Mailbox:Properties::class_init"
	GObjectClass *g_object_class G_GNUC_UNUSED = (GObjectClass*) class;
	MNMailboxPropertiesClass *mn_mailbox_properties_class = (MNMailboxPropertiesClass *)class;

	g_type_class_add_private(class,sizeof(MNGmailMailboxPropertiesPrivate));

	parent_class = g_type_class_ref (MN_TYPE_AUTHENTICATED_MAILBOX_PROPERTIES);

#line 82 "mn-gmail-mailbox-properties.gob"
	mn_mailbox_properties_class->set_mailbox = ___3_mn_gmail_mailbox_properties_set_mailbox;
#line 93 "mn-gmail-mailbox-properties.gob"
	mn_mailbox_properties_class->get_mailbox = ___4_mn_gmail_mailbox_properties_get_mailbox;
#line 141 "mn-gmail-mailbox-properties.c"
	g_object_class->finalize = ___finalize;
	g_object_class->get_property = ___object_get_property;
    {
	g_object_class_override_property (g_object_class,
		PROP_DEFAULT_NAME,
		"default_name");
    }
 {
#line 58 "mn-gmail-mailbox-properties.gob"

    MNMailboxPropertiesClass *p_class = MN_MAILBOX_PROPERTIES_CLASS(class);

    p_class->type = "gmail";
    p_class->stock_id = MN_STOCK_GMAIL;
    p_class->combo_label = "Gmail";
  
#line 158 "mn-gmail-mailbox-properties.c"
 }
}
#undef __GOB_FUNCTION__
#line 66 "mn-gmail-mailbox-properties.gob"
static void 
mn_gmail_mailbox_properties_init (MNGmailMailboxProperties * self G_GNUC_UNUSED)
#line 165 "mn-gmail-mailbox-properties.c"
{
#define __GOB_FUNCTION__ "MN:Gmail:Mailbox:Properties::init"
	self->_priv = G_TYPE_INSTANCE_GET_PRIVATE(self,MN_TYPE_GMAIL_MAILBOX_PROPERTIES,MNGmailMailboxPropertiesPrivate);
 {
#line 67 "mn-gmail-mailbox-properties.gob"

    MNMailboxProperties *properties = MN_MAILBOX_PROPERTIES(self);
    MNAuthenticatedMailboxProperties *auth = MN_AUTHENTICATED_MAILBOX_PROPERTIES(self);

    gtk_box_pack_start(GTK_BOX(auth->account_vbox), auth->username_vbox, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(auth->account_vbox), auth->password_vbox, FALSE, FALSE, 0);

    properties->entries = mn_g_slist_append_elements(properties->entries,
						     auth->username_entry,
						     auth->password_entry,
						     NULL);

    g_signal_connect_swapped(auth->username_entry, "changed", G_CALLBACK(mn_mailbox_properties_notify_default_name), self);
  
#line 185 "mn-gmail-mailbox-properties.c"
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
	case PROP_DEFAULT_NAME:
		{
#line 49 "mn-gmail-mailbox-properties.gob"

      const char *username;

      username = gtk_entry_get_text(GTK_ENTRY(MN_AUTHENTICATED_MAILBOX_PROPERTIES(self)->username_entry));

      g_value_take_string(VAL, mn_gmail_mailbox_build_name(*username ? username : NULL));
    
#line 212 "mn-gmail-mailbox-properties.c"
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



#line 82 "mn-gmail-mailbox-properties.gob"
static void 
___3_mn_gmail_mailbox_properties_set_mailbox (MNMailboxProperties * properties G_GNUC_UNUSED, MNMailbox * mailbox)
#line 232 "mn-gmail-mailbox-properties.c"
#define PARENT_HANDLER(___properties,___mailbox) \
	{ if(MN_MAILBOX_PROPERTIES_CLASS(parent_class)->set_mailbox) \
		(* MN_MAILBOX_PROPERTIES_CLASS(parent_class)->set_mailbox)(___properties,___mailbox); }
{
#define __GOB_FUNCTION__ "MN:Gmail:Mailbox:Properties::set_mailbox"
{
#line 84 "mn-gmail-mailbox-properties.gob"
	
    Self *self = SELF(properties);
    MNGmailMailbox *gmail_mailbox = MN_GMAIL_MAILBOX(mailbox);

    PARENT_HANDLER(properties, mailbox);

    selfp->location = g_strdup(gmail_mailbox->location);
  }}
#line 248 "mn-gmail-mailbox-properties.c"
#undef __GOB_FUNCTION__
#undef PARENT_HANDLER

#line 93 "mn-gmail-mailbox-properties.gob"
static MNMailbox * 
___4_mn_gmail_mailbox_properties_get_mailbox (MNMailboxProperties * properties G_GNUC_UNUSED)
#line 255 "mn-gmail-mailbox-properties.c"
#define PARENT_HANDLER(___properties) \
	((MN_MAILBOX_PROPERTIES_CLASS(parent_class)->get_mailbox)? \
		(* MN_MAILBOX_PROPERTIES_CLASS(parent_class)->get_mailbox)(___properties): \
		((MNMailbox * )0))
{
#define __GOB_FUNCTION__ "MN:Gmail:Mailbox:Properties::get_mailbox"
{
#line 95 "mn-gmail-mailbox-properties.gob"
	
    Self *self = SELF(properties);
    MNMailbox *mailbox;

    mailbox = PARENT_HANDLER(properties);

    if (selfp->location)
      g_object_set(mailbox, MN_GMAIL_MAILBOX_PROP_LOCATION(selfp->location), NULL);

    return mailbox;
  }}
#line 275 "mn-gmail-mailbox-properties.c"
#undef __GOB_FUNCTION__
#undef PARENT_HANDLER
