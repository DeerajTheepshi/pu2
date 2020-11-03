#include "handlers.h"

char password[25];

gboolean loginHandler(GtkWidget *window, GdkEventKey *event, gpointer data){
	guint keyVal = event->keyval;
	if(keyVal==GDK_KEY_Shift_L || keyVal==GDK_KEY_Shift_R ||
	keyVal==GDK_KEY_Control_L || keyVal==GDK_KEY_Control_R || 
	keyVal==GDK_KEY_Caps_Lock){
		return FALSE;
	} else if(keyVal!=GDK_KEY_Return){
		char key = (char)keyVal;
		strncat(password, &key, 1);
	} else if(keyVal==GDK_KEY_Return) {
		char *user = "diprivi";
		if(login(user, password))
			gtk_main_quit();
		return FALSE;
	}
	return TRUE;
}