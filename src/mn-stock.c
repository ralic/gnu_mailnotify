/* 
 * Copyright (C) 2004, 2005 Jean-Yves Lefort <jylefort@brutele.be>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#include "config.h"
#include <glib/gi18n.h>
#include <gtk/gtk.h>
#include "mn-stock.h"
#include "mn-util.h"

/*** constants ***************************************************************/

static const GtkStockItem items[] = {
  { MN_STOCK_SELECT_ALL, N_("Select _All"), 0, 0, NULL },
  { MN_STOCK_LEAVE_FULLSCREEN, N_("Leave Fullscreen"), 0, 0, NULL },
  { MN_STOCK_CONNECT, N_("Co_nnect"), 0, 0, NULL }
};

/*** implementation **********************************************************/

void
mn_stock_init (void)
{
  const struct
  {
    const char	*stock_id;
    const char	*filename;
    const char	*icon_name;
    const char	*source_stock_id;
  } icons[] = {
    { MN_STOCK_MAIL,			NULL, "stock_mail" },
    { MN_STOCK_LOCAL,			NULL, "stock_folder" },
    { MN_STOCK_REMOTE,			NULL, "stock_internet" },
    { MN_STOCK_POLLED,			NULL, "stock_timer" },
    { MN_STOCK_UNKNOWN,			NULL, "stock_unknown" },
    { MN_STOCK_ERROR,			NULL, NULL, GTK_STOCK_DIALOG_ERROR },
#ifdef WITH_GMAIL
    { MN_STOCK_GMAIL,			MN_IMAGE_FILE(UIDIR, "gmail.png") },
#endif
#if defined(WITH_MBOX) || defined(WITH_MH) || defined(WITH_MAILDIR) || defined(WITH_SYLPHEED)
    { MN_STOCK_SYSTEM_MAILBOX,		NULL, "gnome-system" },
#endif
#ifdef WITH_EVOLUTION
    { MN_STOCK_EVOLUTION_MAILBOX,	NULL, "evolution" },
#endif
    { MN_STOCK_SELECT_ALL,		NULL, "stock_select-all" },
    { MN_STOCK_MAIL_SUMMARY,		MN_IMAGE_FILE(GNOMEPIXMAPSDIR, "mail-notification.png") },
    { MN_STOCK_MAIL_READER,		NULL, "stock_mail-handling" },
    { MN_STOCK_MAIN_WINDOW,		MN_IMAGE_FILE(UIDIR, "main-window.png") },
    { MN_STOCK_LEAVE_FULLSCREEN,	NULL, "stock_leave-fullscreen" },
    { MN_STOCK_CONNECT,			NULL, NULL, GTK_STOCK_CONNECT }
  };
  GtkIconFactory *factory;
  GtkIconTheme *icon_theme;
  int i;

  factory = gtk_icon_factory_new();
  gtk_icon_factory_add_default(factory);
  icon_theme = gtk_icon_theme_get_default();

  for (i = 0; i < G_N_ELEMENTS(icons); i++)
    {
      GtkIconSet *icon_set;
      
      if (icons[i].filename)
	{
	  GdkPixbuf *pixbuf;
	  
	  pixbuf = mn_pixbuf_new(icons[i].filename);
	  if (pixbuf)
	    {
	      icon_set = gtk_icon_set_new_from_pixbuf(pixbuf);
	      g_object_unref(pixbuf);
	    }
	  else
	    icon_set = gtk_icon_set_new();
	}
      else if (icons[i].icon_name)
	{
	  GtkIconSource *icon_source;
	  
	  icon_set = gtk_icon_set_new();
	  icon_source = gtk_icon_source_new();
	  gtk_icon_source_set_icon_name(icon_source, icons[i].icon_name);
	  gtk_icon_set_add_source(icon_set, icon_source);
	  gtk_icon_source_free(icon_source);
	}
      else if (icons[i].source_stock_id)
	{
	  icon_set = gtk_icon_factory_lookup_default(icons[i].source_stock_id);
	  gtk_icon_set_ref(icon_set);
	}
      else
	g_assert_not_reached();

      gtk_icon_factory_add(factory, icons[i].stock_id, icon_set);
      gtk_icon_set_unref(icon_set);
    }
  
  g_object_unref(factory);

  gtk_stock_add_static(items, G_N_ELEMENTS(items));
}
