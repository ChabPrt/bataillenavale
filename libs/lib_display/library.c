// library.c
#include "library.h"
#include <stdio.h>

void initGrid(Cell grid[][11]) {
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 11; j++) {
            grid[i][j].isContainsShip = false;
            grid[i][j].hit = false;
        }
    }
}

void printGrids(Cell gridPlayer[][11], Cell gridEnemy[][11]) {
    printf("  1 2 3 4 5 6 7 8 9 10     1 2 3 4 5 6 7 8 9 10\n");
    char row = 'A';
    for (int i = 1; i < 11; i++) {
        printf("%c ", row++);
        for (int j = 1; j < 11; j++) {
            if (gridPlayer[i][j].hit) {
                if (gridPlayer[i][j].isContainsShip) {
                    printf("\033[33m"); // Jaune
                } else {
                    printf("\033[34m"); // Bleu
                }
            } else {
                if (gridPlayer[i][j].isContainsShip) {
                    printf("\033[32m"); // Vert
                } else {
                    printf("\033[37m"); // Blanc
                }
            }
            printf("%s ", gridPlayer[i][j].isContainsShip ? "#" : ".");
        }
        printf("    "); // Ecart entre grilles
        printf("%c ", 'A' + i - 1); // Colonne de lettres de grille tirs
        for (int j = 1; j < 11; j++) {
            if (gridEnemy[i][j].hit) {
                if (gridEnemy[i][j].isContainsShip) {
                    printf("\033[33m"); // Jaune
                } else {
                    printf("\033[34m"); // Bleu
                }
            } else {
                printf("\033[37m"); // Blanc
            }
            printf("%s ", (gridEnemy[i][j].hit && gridEnemy[i][j].isContainsShip) ? "#" : ".");
        }
        printf("\n");
    }
}
