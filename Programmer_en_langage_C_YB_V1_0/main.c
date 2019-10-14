#include <stdio.h> /**< librairie de périphérique d'entrée/sortie */
#include <stdlib.h> /**< Bibliothèque de méthodes basiques (timer random ...) */
#include <math.h>

#define NFOIS 5

int main()
{
    int i;
    float x;
    float racx;

    printf("Hello world!\n");

    printf("je vais vous calculer %d racines carrées\n",NFOIS);

    for(i=0;i<NFOIS;i++){
        printf("donnez un nombre : ");
        scanf("%f",&x);
        if(x<0.0)
            printf("le nombre %f ne possède pas de racine carrée\n",x);
        else{
            racx=sqrt(x);
            printf("le nombre %f a pour racine carrée : %f\n",x,racx);
        }
    }

    printf("travail terminé - Au revoir");

    return 0;

}
