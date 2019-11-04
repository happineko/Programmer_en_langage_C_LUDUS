#include <stdio.h>
#include <stdlib.h>

#define TAILLE 4

void initTab(char grille[TAILLE][TAILLE]);
void affTab(char grille[TAILLE][TAILLE]);
int verifWTL(char grille[TAILLE][TAILLE]);
int verifOOBX(int newX);
int verifOOBY(int newY);


int main()
{
    int newX=1, newY=1;
    char grille[TAILLE][TAILLE];
    int joueur = 1;
    int tour = 0;
    initTab(grille);
    affTab(grille);
    while((verifWTL(grille)== 0)&&(tour<=9)){
        if(joueur == 1){
            tour += 1;
            do{
                printf("Ou voulez-vous placer le X ?\n");
                printf("X : ");
                scanf("%d",&newX);
                newX = verifOOBX(newX);
                fflush(stdin);
                printf("Y : ");
                scanf("%d",&newY);
                fflush(stdin);
                newY = verifOOBY(newY);
            }while(grille[newY][newX] != '_');
            grille[newY][newX]='X';
            joueur = 2;
        }else{
            tour += 1;
            do{
                printf("Ou voulez-vous placer le O ?\n");
                printf("X : ");
                scanf("%d",&newX);
                fflush(stdin);
                newX = verifOOBX(newX);
                printf("Y : ");
                scanf("%d",&newY);
                fflush(stdin);
                newY = verifOOBY(newY);
            }while(grille[newY][newX] != '_');
            grille[newY][newX]='O';
            joueur = 1;
        }
        system("cls");
        affTab(grille);
    }
    printf("GAME OVER");
    return 0;
}

//Procedure d'initialisation de la grillenewY = verifOOBY(newY);
void initTab(char grille[TAILLE][TAILLE]){
    int i,j;
    for(i=1;i<=TAILLE;i++){
        for(j=1;j<=TAILLE;j++){
            grille[i][j]='_';
        }
    }
}

//Procedure d'affichage de la grille
void affTab(char grille[TAILLE][TAILLE]){
    int i,j;
    for(i=1;i<=3;i++){
        for(j=1;j<=3;j++){
            printf("%c",grille[i][j]);
        }
        printf("\n");
    }
}

//Verification condition win/tie/lose
int verifWTL(char grille[TAILLE][TAILLE]){
    int i,j;
    int finish = 0;
    int comptX, comptO;

    //Verification pour le caractere x et o en ligne
    if(finish == 0){
        for(i=1;i<=TAILLE;i++){
            comptX = 0;
            comptO = 0;
            for(j=1;j<=TAILLE;j++){
                if(grille[i][j]=='X'){
                    comptX += 1;
                }
                if(grille[i][j]=='O'){
                    comptO += 1;
                }
            }
            if ((comptX == 3)||(comptO == 3)){
                finish = 1;
                break;
            }
        }
    }

    //Verification pour le caractere x et o en colonne
    if(finish == 0){
        for(j=1;j<=TAILLE;j++){
            comptX = 0;
            comptO = 0;
            for(i=1;i<=TAILLE;i++){
                if(grille[i][j]=='X'){
                    comptX += 1;
                }
                if(grille[i][j]=='O'){
                    comptO += 1;
                }
            }
            if ((comptX == 3)||(comptO == 3)){
                finish = 1;
                break;
            }
        }
    }

    //Verification des diagonales
    if((grille[1][1]=='X')&&(grille[2][2]=='X')&&(grille[3][3]=='X')&&(finish == 0)){
        finish = 1;
    }
    if((grille[1][1]=='O')&&(grille[2][2]=='O')&&(grille[3][3]=='O')&&(finish == 0)){
        finish = 1;
    }
    if((grille[1][3]=='X')&&(grille[2][2]=='X')&&(grille[3][1]=='X')&&(finish == 0)){
        finish = 1;
    }
    if((grille[1][3]=='O')&&(grille[2][2]=='O')&&(grille[3][1]=='O')&&(finish == 0)){
        finish = 1;
    }

    //Verification de l'egalité


    return finish;
}

//Verification OOB de la coordonée X
int verifOOBX(int newX){
    while((newX <1)||(newX > 3)){
        printf("Donner une valeur de X dans le tableau(1-3)\n");
        printf("X : ");
        scanf("%d",&newX);
        fflush(stdin);
    }
    return newX;
}

//Verification OOB de la coordonée Y
int verifOOBY(int newY){
    while((newY <1)||(newY > 3)){
        printf("Donner une valeur de Y dans le tableau(1-3)\n");
        printf("Y : ");
        scanf("%d",&newY);
        fflush(stdin);
    }
    return newY;
}



