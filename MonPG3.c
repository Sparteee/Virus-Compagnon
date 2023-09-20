#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Ce programme demande a l'utilisateur s'il souhaite
 * faire le theoreme de Pythagore ou sa reciproque
 * et lui calcule.
 */
int main() {
    int choix;
    double cote1, cote2, hypo;
    
    printf("Voulez-vous faire le theoreme de Pythagore ou la reciproque ?\n");
    
    printf("1. Theoreme de Pythagore\n");
    printf("2. Reciproque du theoreme de Pythagore\n");
    
    scanf("%d", &choix);
    
    switch(choix) {
    	// Theoreme
        case 1:
            printf("Entrez la longueur du premier cote: ");
            scanf("%lf", &cote1);

            printf("Entrez la longueur du deuxieme cote: ");
            scanf("%lf", &cote2);

            hypo = sqrt(pow(cote1, 2) + pow(cote2, 2));

            printf("La longueur de l'hypotenuse est: %.2f\n", hypo);
            break;
        // Reciproque
        case 2:
            printf("Entrez la longueur de l'hypotenuse: ");
            scanf("%lf", &hypo);

            printf("Entrez la longueur d'un des cotes: ");
            scanf("%lf", &cote1);

            cote2 = sqrt(pow(hypo, 2) - pow(cote1, 2));

            printf("La longueur du deuxieme cote est: %.2f\n", cote2);
            break;
        // Cas ou l'utilisateur a rentre autre chose que 1 ou 2
        default:
            printf("Choix invalide. Veuillez choisir 1 ou 2.\n");
    }
    
    return EXIT_SUCCESS;
}

