// main.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../libs/lib_display/library.h"


void init() {
    // Initialisation du générateur de nombres aléatoires
    srand(time(NULL));
    init_model();
    //Mettre d'autres méthode d'init ici si besoin
}

void end() {
    end_model();
    //Mettre d'autres méthode de fin ici si besoin
}

int main() {
    init();

    grid_case **gridPlayer= get_grid_player();
    grid_case **gridEnemy= get_grid_ordi();

    int nbRound = 1;
    bool partyFinished = false;
    while(!partyFinished){
        //Permet de clear la console
        //system("cls");

        printf(nbRound == 1 ? "Tour %d\n" : "Tours %d\n", nbRound);
        printGrids(gridPlayer, gridEnemy);

        //Logique du joueur
        //On demande la colonne
        int colSpan = 1;
        printf("Sur quelle ligne portera votre tir ? ( 1 - 10 )");
        scanf("%d", &colSpan);

        if(!(1 <= colSpan && colSpan <= GRID_SIZE)) continue;

        //On demande la ligne
        int rowSpan = 0;
        printf("Sur quelle colonne portera votre tir ? ( A - J )");
        scanf("%s", &rowSpan);


        //Vérification si caractère n'est pas entre A et J ou a et j;
        if(!(( (int) 'A' <= rowSpan && rowSpan <= (int) 'J') || ((int) 'a' <= rowSpan && rowSpan <= (int) 'j'))) continue;

        //Correction des positions
        if( (int) 'A' <= rowSpan && rowSpan <= (int) 'J'){
            rowSpan -= (int) 'A';
        }else{
            rowSpan -= (int) 'a';
        }
        colSpan--;

        //Methode permettant d'effectuer le tir du joueur
        coordinate playerShoot;
        playerShoot.row = rowSpan;
        playerShoot.col = colSpan;

        printf("Coord: Col: %d Row:%d\n",playerShoot.col,playerShoot.row);

        set_hit_player(playerShoot);

        if(is_player_has_won()){
            printf("Victoire !");
            break;
        }

        //Logique de l'odinateur
        if(is_ordi_has_won()){
            printf("Perdu !");
            break;
        }

        nbRound++;
    }

    //while(1);
    end();
}
