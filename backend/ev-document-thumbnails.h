/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8; c-indent-level: 8 -*- */
/*
 *  Copyright (C) 2004 Anders Carlsson
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 *
 */

#ifndef EV_DOCUMENT_THUMBNAILS_H
#define EV_DOCUMENT_THUMBNAILS_H

#include <gdk-pixbuf/gdk-pixbuf.h>

G_BEGIN_DECLS

#define EV_TYPE_DOCUMENT_THUMBNAILS         (ev_document_thumbnails_get_type ())
#define EV_DOCUMENT_THUMBNAILS(o)                   (G_TYPE_CHECK_INSTANCE_CAST ((o), EV_TYPE_DOCUMENT_THUMBNAILS, EvDocumentThumbnails))
#define EV_DOCUMENT_THUMBNAILS_IFACE(k)     (G_TYPE_CHECK_CLASS_CAST((k), EV_TYPE_DOCUMENT_THUMBNAILS, EvDocumentThumbnailsIface))
#define EV_IS_DOCUMENT_THUMBNAILS(o)        (G_TYPE_CHECK_INSTANCE_TYPE ((o), EV_TYPE_DOCUMENT_THUMBNAILS))
#define EV_IS_DOCUMENT_THUMBNAILS_IFACE(k)          (G_TYPE_CHECK_CLASS_TYPE ((k), EV_TYPE_DOCUMENT_THUMBNAILS))
#define EV_DOCUMENT_THUMBNAILS_GET_IFACE(inst) (G_TYPE_INSTANCE_GET_INTERFACE ((inst), EV_TYPE_DOCUMENT_THUMBNAILS, EvDocumentThumbnailsIface))

typedef struct _EvDocumentThumbnails    EvDocumentThumbnails;
typedef struct _EvDocumentThumbnailsIface       EvDocumentThumbnailsIface;

struct _EvDocumentThumbnailsIface
{
        GTypeInterface base_iface;

        /* Methods  */
        GdkPixbuf *  (* get_thumbnail)  (EvDocumentThumbnails *document,
                                         gint                  page,
                                         gint                  size,
					 gboolean              border);
        void         (* get_dimensions) (EvDocumentThumbnails *document,
					 gint                  page,
					 gint                  suggested_width,
					 gint                 *width,
					 gint                 *height);
};

GType      ev_document_thumbnails_get_type       (void);
GdkPixbuf *ev_document_thumbnails_get_thumbnail  (EvDocumentThumbnails *document,
                                                  gint                  page,
                                                  gint                  size,
                                                  gboolean              border);
void       ev_document_thumbnails_get_dimensions (EvDocumentThumbnails *document,
                                                  gint                  page,
                                                  gint                  size,
                                                  gint                 *width,
                                                  gint                 *height);

G_END_DECLS

#endif
