#include <stdio.h> /**< librairie de p�riph�rique d'entr�e/sortie */
#include <stdlib.h> /**< Biblioth�que de m�thodes basiques (timer random ...) */
#include <math.h>

#define NFOIS 5 //constante
#define PI 3.14
#define Nom "moi"
#define CAR 'B'

#define TAILLE 10

/* int main() //Calcul racine carrees
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

    //Op�rateurs
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

    //Factorisation op�rateur
    // +=
    // -=
    // *=
    // /=
    // %=

    //boucle pour, tant que, faire tant que
    // operateur ternaire

    //Structures conditions et boucles
    int a=0,b=0,c=0,d=0;

    //condition
    if(a==b){
        printf("ils sont egaux \n");
    }else{
        printf("ils sont differents \n");
    }

    //conditions avec operateurs logiques

    if((a==b)&&(a==c)){
        printf("ils sont tous egaux\n");
    }else{
        printf("ils sont differents\n");
    }
    if((a==b)||(a==c)){
        printf("ils sont tous egaux\n");
    }else if((a==c)&&(a!=d)){
        printf("blabla...\n");
    }

    //Boucle
    int i=0;

    for(i=0;i<TAILLE;i++){
        printf("Hello World\n");
    }

    //tant que

    while(i<TAILLE){
        printf("Hello World\n");
        i++;
    }

    //Faire tant que
    i=0;
    do{
        printf("hello world\n");
        i++;
    }while(i<TAILLE);

    //Cas alternatif de la condition
    int choix=-1;

    printf("Choisissez\n");
    scanf("%d",&choix);
    switch(choix){
        case 0:printf("Quitter\n");break;
        case 1:printf("Calculer\n");break;
        case 2:printf("Jouer\n");break;
        default:printf("Default\n");break;
    }

    //Test ? instruction 1:Instruction 2

    (a==b)? printf("Egaux"):printf("different");
}
