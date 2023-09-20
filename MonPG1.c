#include <gtk/gtk.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

GtkWidget *input;

/* Ce programme affiche une calculatrice
 * simple.
 */
 
double calcul(char signe, double a, double b)
{
    switch (signe)
    {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        default:
            return 0;
    }
}

void recupClick(GtkWidget *widget, gpointer data)
{
    const gchar *textBouton = gtk_button_get_label(GTK_BUTTON(widget));
    const gchar *textInput = gtk_entry_get_text(GTK_ENTRY(input));

    char memoire[100];
    strcpy(memoire, textInput);
    strcat(memoire, textBouton);

    gtk_entry_set_text(GTK_ENTRY(input), memoire);
}

void clear(GtkWidget *widget, gpointer data)
{
    gtk_entry_set_text(GTK_ENTRY(input), "");
}

void egal(GtkWidget *widget, gpointer data)
{
    const gchar *textInput = gtk_entry_get_text(GTK_ENTRY(input));

    int i;
    double nb1, nb2;
    char signe;

    for (i = 0; i < strlen(textInput); i++)
    {
        if (textInput[i] == '+' || textInput[i] == '-' || textInput[i] == '*' || textInput[i] == '/')
        {
            signe = textInput[i];
            break;
        }
    }

    nb1 = atof(strtok(textInput, &signe));
    nb2 = atof(strtok(NULL, &signe));

    double result = calcul(signe, nb1, nb2);

    char memoire[100];
    sprintf(memoire, "%.2f", result);

    gtk_entry_set_text(GTK_ENTRY(input), memoire);
}


int main(int argc, char *argv[]) 
{
    GtkWidget *window;
    GtkWidget *grid;
    GtkWidget *button[16];

    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);
    gtk_window_set_title(GTK_WINDOW(window),"Calculatrice");
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 200);
    gtk_container_set_border_width(GTK_CONTAINER(window),10);

    grid = gtk_grid_new();

    input = gtk_entry_new();
    gtk_editable_set_editable(GTK_EDITABLE(input), FALSE);

    
    button[0] = gtk_button_new_with_label("0");
    button[1] = gtk_button_new_with_label("1");
    button[2] = gtk_button_new_with_label("2");
    button[3] = gtk_button_new_with_label("3");
    button[4] = gtk_button_new_with_label("4");
    button[5] = gtk_button_new_with_label("5");
    button[6] = gtk_button_new_with_label("6");
    button[7] = gtk_button_new_with_label("7");
    button[8] = gtk_button_new_with_label("8");
    button[9] = gtk_button_new_with_label("9");
    button[10] = gtk_button_new_with_label("+");
    button[11] = gtk_button_new_with_label("-");
    button[12] = gtk_button_new_with_label("*");
    button[13] = gtk_button_new_with_label("/");
    button[14] = gtk_button_new_with_label("C");
    button[15] = gtk_button_new_with_label("=");
    

    gtk_grid_set_row_spacing(GTK_GRID(grid), 5);
    gtk_grid_set_column_spacing(GTK_GRID(grid), 5);

    gtk_grid_attach(GTK_GRID(grid), button[13], 3, 3, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), button[7], 0, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), button[8], 1, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), button[9], 2, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), button[11], 3, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), button[4], 0, 3, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), button[5], 1, 3, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), button[6], 2, 3, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), button[12], 3, 4, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), button[1], 0, 4, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), button[2], 1, 4, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), button[3], 2, 4, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), button[10], 3, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), button[0], 0, 5, 3, 1);
    gtk_grid_attach(GTK_GRID(grid), button[14], 0, 1, 3, 1);
    gtk_grid_attach(GTK_GRID(grid), button[15], 3, 5, 1, 1);
    

    g_signal_connect(button[0],"clicked",G_CALLBACK(recupClick), NULL);
    g_signal_connect(button[1],"clicked",G_CALLBACK(recupClick), NULL);
    g_signal_connect(button[2],"clicked",G_CALLBACK(recupClick), NULL);
    g_signal_connect(button[3],"clicked",G_CALLBACK(recupClick), NULL);
    g_signal_connect(button[4],"clicked",G_CALLBACK(recupClick), NULL);
    g_signal_connect(button[5],"clicked",G_CALLBACK(recupClick), NULL);
    g_signal_connect(button[6],"clicked",G_CALLBACK(recupClick), NULL);
    g_signal_connect(button[7],"clicked",G_CALLBACK(recupClick), NULL);
    g_signal_connect(button[8],"clicked",G_CALLBACK(recupClick), NULL);
    g_signal_connect(button[9],"clicked",G_CALLBACK(recupClick), NULL);
    g_signal_connect(button[10],"clicked",G_CALLBACK(recupClick), NULL);
    g_signal_connect(button[11],"clicked",G_CALLBACK(recupClick), NULL);
    g_signal_connect(button[12],"clicked",G_CALLBACK(recupClick), NULL);
    g_signal_connect(button[13],"clicked",G_CALLBACK(recupClick), NULL);
    g_signal_connect(button[14],"clicked",G_CALLBACK(clear), NULL);
    g_signal_connect(button[15],"clicked",G_CALLBACK(egal), NULL);


    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_box_pack_start(GTK_BOX(vbox), input, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), grid, TRUE, TRUE, 0);


    gtk_container_add(GTK_CONTAINER(window), vbox);
    gtk_widget_show_all(window);

    gtk_main();

    return EXIT_SUCCESS;
}

