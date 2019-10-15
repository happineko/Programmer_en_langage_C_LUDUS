#include <stdio.h> /**< librairie de périphérique d'entrée/sortie */
#include <stdlib.h> /**< Bibliothèque de méthodes basiques (timer random ...) */
#include <math.h>

#define NFOIS 5 //constante
#define PI 3.14
#define Nom "moi"
#define CAR 'B'

/* int main() //Calcul racine carrees
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

} */

int main() //Programme sur les types
{
    //Integer
    short int nA;
    int nB;
    long int nC;

    printf("taille de a : %d octet(s)\n", sizeof(nA));
    printf("taille de b : %d octet(s)\n", sizeof(nB));
    printf("taille de c : %d octet(s)\n", sizeof(nC));

    //Reel
    float fltReelSimple;
    double dblReelDouble;

    printf("taille de fltReelSimple : %d octet(s)\n",sizeof(fltReelSimple));
    printf("taille de dblReelDouble : %d octet(s)\n",sizeof(dblReelDouble));

    //Caractere
    char cCaractere;
    printf("taille de cCaractere : %d octet(s)\n",sizeof(cCaractere));

    //Test Define
    printf("affichage de PI : %f\n",PI);
    printf("affichage de nom : %s\n",Nom);
    printf("affichage de caractere : %c\n",CAR);

    //Opérateurs
    int nI=0;
    ++nI; //pre-incrementation
    nI++; //post-incrementation
    //% modulo
    // / division (attention aux types)

    //Cast
    long double ldblLongDouble=105.55519841119745121284;
    printf("valeur du long double : %lf\n",(double)ldblLongDouble);

    //Operateurs relationnels
    // >
    // <
    // >=
    // <=
    // ==
    // !=

    //operateurs logiques
    // & AND
    // &&
    // | OR
    // ||
    // ! NOT

    //Factorisation opérateur
    // +=
    // -=
    // *=
    // /=
    // %=

    //boucle pour, tant que, faire tant que
    // operateur ternaire


}
