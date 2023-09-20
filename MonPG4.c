#include <stdio.h>
#include <stdlib.h>

/* Ce programme est un juste prix. 
 * Il tire un nombre aleatoire entre 1 et 1000,
 * l'utilisateur doit le deviner.
 */
int main(){
    srand(time(0));
    
    int res;
    int justeAlea = (rand() % 1000) +1;
    int nbInput;
    int etat = 0;
    
    int cpt = 0;

    printf("Entrez une valeur entre 1 et 1000 : ");
    res = scanf("%d", &nbInput);
    
    if(res == 1){
        while(etat != 1){
            if(nbInput == justeAlea){
                printf("Bravo vous avez trouvé le juste prix en %d essais !\n", cpt);
                etat = 1;
            } else if(nbInput > justeAlea ){
                printf("C'est moins !\n");
                printf("Entrez une valeur entre 1 et 1000 : ");
                cpt++;
                res = scanf("%d", &nbInput);
            } else if(nbInput < justeAlea){
                printf("C'est plus !\n");
                printf("Entrez une valeur entre 1 et 1000 : ");
                cpt++;
                res = scanf("%d", &nbInput);
            }
        }
    }

    return EXIT_SUCCESS;
}
