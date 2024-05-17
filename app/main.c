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

    while(true){
        printGrids(gridPlayer, gridEnemy);

        int colSpan;
        printf("Sur quelle colonne portera votre tir ? ( A - J )");
        scanf("%s", &colSpan);

        printf("Lecture : %d\n",colSpan);

        if((65 <= colSpan && colSpan <= 74) || (97 <= colSpan && colSpan <= 106)){
            printf("non");
            break;
        }
        printf("oui");
        break;

        // 👌 Usefull for clear console ("On windows") => use "clear" instead for linux env
        system("cls");
        printGrids(gridPlayer, gridEnemy);
    }

    while(true);
    end();
}
