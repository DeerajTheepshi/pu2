#include "auth.h"
#include "handlers.h"

int main(int argc, char *argv[]) {
    GtkWidget *window, *label, *grid;

    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "pu2");
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_fullscreen(GTK_WINDOW(window));
    gtk_window_set_deletable(GTK_WINDOW(window), FALSE);

    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    label = gtk_label_new("Enter Your Password");
    gtk_grid_attach(GTK_GRID(grid), label, 0, 0, 1, 1);

    gtk_widget_set_vexpand(label, TRUE);
    gtk_widget_set_hexpand(label, TRUE);

    gtk_widget_add_events(GTK_WINDOW(window), GDK_KEY_PRESS_MASK);
    gtk_widget_show_all(window);

    g_signal_connect(window, "key_press_event", G_CALLBACK(loginHandler),
                     label);
    gtk_main();
    return 0;
}
