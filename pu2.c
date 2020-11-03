#include "auth.h"
#include "handlers.h"

int main(int argc, char *argv[]) {
	GtkWidget *window;
	gtk_init(&argc, &argv);
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "pu2");
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_window_fullscreen(GTK_WINDOW(window));
	gtk_window_set_deletable(GTK_WINDOW(window), FALSE);

	gtk_widget_add_events(GTK_WINDOW(window), GDK_KEY_PRESS_MASK);
	gtk_widget_show(window);

	g_signal_connect(window, "key_press_event", G_CALLBACK(loginHandler), NULL); 
	gtk_main();
	return 0;
}
