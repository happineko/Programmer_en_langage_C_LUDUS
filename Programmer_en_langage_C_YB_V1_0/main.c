#include <stdio.h> /**< librairie de p�riph�rique d'entr�e/sortie */
#include <stdlib.h> /**< Biblioth�que de m�thodes basiques (timer random ...) */
#include <math.h>

#define NFOIS 5

int main()
{
    int i;
    float x;
    float racx;

    printf("Hello world!\n");

    printf("je vais vous calculer %d racines carr�es\n",NFOIS);

    for(i=0;i<NFOIS;i++){
        printf("donnez un nombre : ");
        scanf("%f",&x);
        if(x<0.0)
            printf("le nombre %f ne poss�de pas de racine carr�e\n",x);
        else{
            racx=sqrt(x);
            printf("le nombre %f a pour racine carr�e : %f\n",x,racx);
        }
    }

    printf("travail termin� - Au revoir");

    return 0;

}
