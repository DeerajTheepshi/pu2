#include <gtk/gtk.h>
#include <gdk/gdkkeysyms.h>

char password[20];

gboolean onTextInput(GtkWidget *window, GdkEventKey *event, gpointer data){
	guint keyVal = event->keyval;
	if(keyVal==GDK_KEY_Shift_L || keyVal==GDK_KEY_Shift_R ||
	keyVal==GDK_KEY_Control_L || keyVal==GDK_KEY_Control_R || 
	keyVal==GDK_KEY_Caps_Lock){
		return FALSE;
	} else if(keyVal!=GDK_KEY_Return){
		char key = (char)keyVal;
		strncat(password, &key, 1);
	} else if(keyVal==GDK_KEY_Return) {
		printf("Hey %s", password);
		gtk_main_quit();
		return FALSE;
	}
	return TRUE;
}

int main(int argc, char *argv[]) {
	GtkWidget *window;
	gtk_init(&argc, &argv);
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "D-LOCK");
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_window_fullscreen(GTK_WINDOW(window));
	gtk_widget_add_events(GTK_WINDOW(window), GDK_KEY_PRESS_MASK);
	gtk_widget_show(window);

	g_signal_connect(window, "key_press_event", G_CALLBACK(onTextInput), NULL);
	g_signal_connect(window, "destroy",
			G_CALLBACK(gtk_main_quit), NULL);  
	gtk_main();
	return 0;
}
