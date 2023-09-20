#include <gtk/gtk.h>
 
GtkWidget *window;
GtkWidget *selection;

 
/* Ce programme ouvre un affichage graphique qui permet à l'utilisateur
 * de choisir une couleur et de voir son code rgb sur des couleurs 
 * predefinies. 
 * En cliquant sur "+" on a acces a un stylo qui permet de selectionner
 * une couleur sur l'ecran et de recuperer son code rgb.
 */

void choixCouleur(GtkColorButton *selection, gpointer user_data)
{
    GdkRGBA couleur;
    gtk_color_chooser_get_rgba(GTK_COLOR_CHOOSER(selection), &couleur);
    gtk_widget_override_background_color(window,GTK_STATE_NORMAL,&couleur);
    const gchar *couleurString = gdk_rgba_to_string(&couleur);
    g_print("%s\n", couleurString);
}

 
int main (int argc, char *argv[])
{

    gtk_init (&argc, &argv);
 
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 400);       
    gtk_window_set_title(GTK_WINDOW(window), "Choix de couleur");
    gtk_container_set_border_width(GTK_CONTAINER(window),50);

    selection = gtk_color_button_new();
    gtk_color_chooser_set_use_alpha(GTK_COLOR_CHOOSER(selection), TRUE);
    g_signal_connect(GTK_COLOR_BUTTON(selection), "color-set",G_CALLBACK(choixCouleur), NULL);
    gtk_container_add(GTK_CONTAINER(window), selection);
 

    gtk_widget_show_all (window);

    gtk_main ();

    return EXIT_SUCCESS;
}
