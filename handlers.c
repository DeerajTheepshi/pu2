#include "handlers.h"
#include <stdio.h>
char password[25];

void handleInput(guint keyVal){
	char key = (char)keyVal;
	strncat(password, &key, 1);
}

void handleBackspace(){
	password[strlen(password)-1] = '\0';
}

gboolean loginHandler(GtkWidget *window, GdkEventKey *event, gpointer data){
	guint keyVal = event->keyval;
	if(keyVal==GDK_KEY_Shift_L || keyVal==GDK_KEY_Shift_R ||
	keyVal==GDK_KEY_Control_L || keyVal==GDK_KEY_Control_R || 
	keyVal==GDK_KEY_Caps_Lock){
		return FALSE;
	} else if(keyVal==GDK_KEY_BackSpace){
		handleBackspace();
	} else if(keyVal!=GDK_KEY_Return){
		handleInput(keyVal);
	} else if(keyVal==GDK_KEY_Return) {
		char *user = "diprivi";
		if(login(user, password))
			gtk_main_quit();
		return FALSE;
	}
	return TRUE;
}