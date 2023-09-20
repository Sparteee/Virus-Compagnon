#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Ce programme demande un nombre a l'utilisateur
 * et lui retourne tous les nombres premiers entre
 * 2 et son nombre.
 */
int estPremier(int n) {
    if (n < 2) {
        return 0;
    }
    
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    
    return 1;
}

int main() {
    int valeur;
    printf("Entrez une valeur superieure a 2 : ");
    scanf("%d", &valeur);

    printf("-- Les nombres premiers entre 2 et %d sont : -- \n", valeur);
    
    for (int i = 2; i <= valeur; i++) {
        if (estPremier(i)) {
            printf("%d\n ", i);
        }
    }

    return 0;
}

