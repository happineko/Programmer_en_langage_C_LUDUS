#include <stdio.h> /**< librairie de p�riph�rique d'entr�e/sortie */
#include <stdlib.h> /**< Biblioth�que de m�thodes basiques (timer random ...) */
#include <math.h>

#define TAILLE 10
#define MOT "HELLO"

//Les entrees sorties conversationnels

int main()
{
    //Affichage
    printf("%d\n",TAILLE);
    printf("%s\n",MOT);

    //Saisie

    int val;
    scanf("%d",&val);
    fflush(stdin);
    char car;
    scanf("%c\n",&car);
    fflush(stdin);
    char tabCar[TAILLE];
    scanf("%s",tabCar);

    return 0;

}
