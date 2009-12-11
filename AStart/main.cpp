/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  AStart test
 *
 *        Version:  1.0
 *        Created:  2009年04月21日 10时58分10秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  wind (xihe), xihels@gmail.com
 *        Company:  cyclon
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cstring>
#include "asnode.h"

#include <gtk/gtk.h>
#include <gdk/gdkkeysyms.h>

const int WIDTH = 800;
const int HEIGHT = 600;
char g_map[HEIGHT][WIDTH];

void initmap()
{
	memset(g_map, 1, WIDTH * HEIGHT * sizeof(char));
	srand(time(NULL));
	for (int i = 1; i < HEIGHT - 10; i+=10) {
		for (int j = 1; j < WIDTH - 10; j+=10) {
			int val = !(rand() % 3);
			for (int y = i; y < i + 10; y++)
				for (int x = j; x < j + 10; x++)
					g_map[y][x] = val;

		}
	}
}
void drawmap()
{
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			switch (g_map[i][j]) {
				case 0:
					printf(" ");
					break;
				case 1:
					printf("+");
					break;
				case 2:
					printf("*");
					break;
			}
		}
		printf("\n");
	}
}

bool check_map(int x, int y)
{
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return true;
	return g_map[y][x];
}


static GdkPixmap *pixmap = NULL;

static void draw_brush (GtkWidget *widget, gint x, gint y)
{

	GdkRectangle update_rect;

	update_rect.x = x;
	update_rect.y = y;
	update_rect.width = 1;
	update_rect.height = 1;

	/* Paint to the pixmap, where we store our state */
	if (g_map[y][x]) {
		gdk_draw_rectangle (pixmap,
				widget->style->black_gc,
				TRUE,
				update_rect.x, update_rect.y,
				update_rect.width, update_rect.height);
	} else {
		gdk_draw_rectangle (pixmap,
				widget->style->white_gc,
				TRUE,
				update_rect.x, update_rect.y,
				update_rect.width, update_rect.height);
	}

	/* Now invalidate the affected region of the drawing area. */
	//gdk_window_invalidate_rect (widget->window,
			//&update_rect,
			//FALSE);
}

static gboolean scribble_configure_event (GtkWidget *widget, GdkEventConfigure *event, gpointer data)
{

	if (pixmap)
		g_object_unref (pixmap);

	pixmap = gdk_pixmap_new (widget->window,
			widget->allocation.width,
			widget->allocation.height,
			-1);

	/* Initialize the pixmap to white */
	//gdk_draw_rectangle (pixmap,
			//widget->style->white_gc,
			//TRUE,
			//0, 0,
			//widget->allocation.width,
			//widget->allocation.height);
	
	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			draw_brush(widget, x, y);
		}
	}

	

	/* We've handled the configure event, no need for further processing. */
	return TRUE;
}


static gint scribble_expose (GtkWidget *widget, GdkEventExpose *event)
{
	gdk_draw_drawable (widget->window,
			widget->style->fg_gc[GTK_WIDGET_STATE (widget)],
			pixmap,
			/* Only copy the area that was exposed. */
			event->area.x, event->area.y,
			event->area.x, event->area.y,
			event->area.width, event->area.height);	

	return FALSE;
}

static gboolean scribble_button_press_event (GtkWidget      *widget,
		GdkEventButton *event,
		gpointer        data)
{	
	static int sx = -1;
	static int sy = -1;
	static int ex = -1;
	static int ey = -1;
	if (-1 == sx) {
		sx = (int)event->x;
		sy = (int)event->y;
		return TRUE;
	}

	ex = (int)event->x;
	ey = (int)event->y;

	ASFinder finder;
	ASNode* p = finder.find(sx, sy, ex, ey, check_map);
	if (!p)
		printf("ERROR\n");
	else {
		int i = 0;
		while (p) {
			i++;
			int x = p->x;
			int y = p->y;
			g_map[y][x] = 2;
			p = p->parent;
		}
		printf("i = %d\n", i);

		for (int y = 0; y < 600; y++) {
			for (int x = 0; x < 800; x++) {
				draw_brush(widget, x, y);
			}
		}
		GdkRectangle update_rect;

		update_rect.x = 0;
		update_rect.y = 0;
		update_rect.width = WIDTH;
		update_rect.height = HEIGHT;
		gdk_window_invalidate_rect (widget->window,
				&update_rect,
				FALSE);
	}
	sx = -1;
	return TRUE;
}

int main ( int argc, char *argv[] )
{
	initmap();
	GtkWidget* win;
	GtkWidget* da;
	gtk_init(&argc, &argv);

	win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	da = gtk_drawing_area_new();
	gtk_container_add(GTK_CONTAINER(win), da);

	gtk_widget_set_events (da, gtk_widget_get_events (da)
			| GDK_LEAVE_NOTIFY_MASK
			| GDK_BUTTON_PRESS_MASK
			| GDK_POINTER_MOTION_MASK
			| GDK_POINTER_MOTION_HINT_MASK);

	g_signal_connect(win, "delete-event", G_CALLBACK(gtk_main_quit), NULL);
	g_signal_connect(da, "button-press-event", G_CALLBACK(scribble_button_press_event), NULL);
	g_signal_connect (da,"configure-event", G_CALLBACK (scribble_configure_event), NULL);
	g_signal_connect(da, "expose-event", G_CALLBACK(scribble_expose), NULL);


	gtk_window_resize(GTK_WINDOW(win), 800, 600);
	gtk_widget_show_all(win);
	gtk_main();
	return 0;



	//return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

