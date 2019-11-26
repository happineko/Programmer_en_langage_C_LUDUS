#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define ESSAISMAX 12
#define CODELENGTH 4


void genereCode(int *n_code);
void affichCode(int *n_code);
void genereGrid(int n_grid[CODELENGTH][ESSAISMAX]);
void affichGrid(int n_grid[CODELENGTH][ESSAISMAX],int n_code[CODELENGTH]);
void color(int t, int f);
int verifVictoire(int n_rep[4] ,int n_code[4]);
void doublon(int n_code[CODELENGTH]);

int main()
{
    int n_rep[4]; //Tableau d'entier qui va contenir la proposition de l'utilisateur
    int n_essai = 1; //Variable du nombre d'essai
    int i;
    srand(time(NULL)); //Va generer un nombre aléatoire
    int n_code[CODELENGTH]; //Tableau d'entier qui va contenir le code a trouver
    int n_grid[CODELENGTH][ESSAISMAX]; //Tableau d'entier representant le tableau des reponses
    genereCode(n_code); //Genere le code a trouver
    doublon(n_code);
    genereGrid(n_grid); //Genere la grille
    while(verifVictoire(n_rep,n_code)==0 && n_essai <= ESSAISMAX) //On verifie si la reponse a ete trouve ou si le nombre d'essai max a ete depasse
    {
        system("cls"); //On efface l'ecran
        //affichCode(n_code); //va afficher le mot de passe (debug)
        //printf("\n");
        affichGrid(n_grid,n_code); //fonction d'affichage de la grille
        printf("\n");
        for(i=0;i<CODELENGTH;i++) //On prend le nombre saisi par l'utilisateur chiffre par chiffre
        {
            color(15,0); //Texte en blanc
            printf("je pense a un nombre a 4 chiffres devine lequel : \n");
            printf("chiffre %d (entre 1 et 9) : ",i+1);
            scanf("%d",&n_rep[i]);
            fflush(stdin);
            while(n_rep[i] < 0 || n_rep[i] > 10) //on verifie que le chiffre est compris entre 1 et 9
            {
                printf("Un chiffre entre 1 et 9 : \n");
                scanf("%d",&n_rep[i]);
                fflush(stdin);
            }
            n_grid[i][ESSAISMAX-n_essai]=n_rep[i]; //On met la reponse de l'utilisateur dans la grille
        }
        n_essai ++; //Tour suivant

    }
    system("cls");
    affichGrid(n_grid,n_code); //on affiche une derniere fois la grille
    printf("\n");
    color(15,0);
    printf("GAME OVER\n"); //Si on sort de la boucle principale le jeu est terminé
    if(verifVictoire(n_rep,n_code)==1) //Si la victoire est confirme c'est gagne autrement c'est perdu
    {
        printf("VOUS AVEZ GAGNE");
    }else{
        printf("VOUS AVEZ PERDU\n");
        printf("La reponse etait : "); // on affiche la reponse
        for(i=0;i<CODELENGTH;i++)
        {
            printf("%d",n_code[i]);
        }
    }
    return 0;
}

void genereCode(int *n_code)// Generation du code a trouver (formalisme pointeur) prend en parametre le tableau du code
{
    int i;

    for(i=0;i<CODELENGTH;i++)
    {
        *(n_code+i) = rand() % 10;
    }

}

void affichCode(int *n_code)//Affichage du code en debug (formalisme pointeur) prend en parametre le tableau du code
{
    int i;
    for(i=0;i<CODELENGTH;i++)
    {
        printf("%d",*(n_code+i));
    }
    printf("\n");
}

void genereGrid(int n_grid[CODELENGTH][ESSAISMAX]) //Genere la grille des reponses prend en parametre le tableau des reponses
{
    int i,j;
    for(j=0;j<ESSAISMAX;j++)
    {
        for(i=0;i<CODELENGTH;i++)
        {
            n_grid[i][j]=0;
        }
    }
}

void affichGrid(int n_grid[CODELENGTH][ESSAISMAX],int n_code[CODELENGTH])//Affiche la grille des reponses prend en parametre le tableau des reponses et le tableau du code
{
    int i,j;
    for(j=0;j<ESSAISMAX;j++)
    {
        for(i=0;i<CODELENGTH;i++)
        {
            color(15,0); //On met le texte en blanc de base
            if((n_grid[i][j]==n_code[0])||(n_grid[i][j]==n_code[1])||(n_grid[i][j]==n_code[2])||(n_grid[i][j]==n_code[3]))
            {
                color(14,0); //Si le chiffre saisi par l'utilisateur est compris dans le code a trouver mais pas a la bonne place alors le chiffre sera en jaune
            }
            if(n_grid[i][j]==n_code[i])
            {
                color(2,0); //Si le chiffre saisi par l'utilisateur est compris dans le code a trouver et a la bonne place le chiffre sera en vert
            }
            if(n_grid[0][j]==0&&n_grid[1][j]==0&&n_grid[2][j]==0&&n_grid[3][j]==0)
            {
                color(15,0); //si les 4 chiffres d'une ligne sont egal a 0 on met le texte en blanc (car 0 chiffre d'initialisation et peut etre affecté par les couleurs)
            }
            printf("%d",n_grid[i][j]);
        }
        printf("\n");
    }
}

void color(int t, int f) //Permet de changer la couleur du texte et la couleur de fond du texte
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole,f*16+t);
}

int verifVictoire(int n_rep[4] ,int n_code[4]) //Verification de la victoire
{
    int n_finish;
    if(n_rep[0]==n_code[0]&&n_rep[1]==n_code[1]&&n_rep[2]==n_code[2]&&n_rep[3]==n_code[3])
    {
        n_finish = 1;
    }else{
        n_finish = 0;
    }

    return n_finish;


}

void doublon(int n_code[CODELENGTH]) //Verifie si un doublon est present dans le code a trouver
{
    int i,j;
    for(j=0;j<CODELENGTH;j++)
    {
        for(i=0;i<CODELENGTH;i++)
        {
            if(i==j) //si on verifie la meme position on passe a la prochaine position
            {
                break;
            }
            do
            {

                n_code[i] += 1;
                if (n_code[i]>9)
                {
                    n_code[i]=0;
                }
            }while(n_code[i]==n_code[j]); //Si il y a un doublon on ajoute 1, si ca depasse 9 on retourne a 0
        }
    }
}
