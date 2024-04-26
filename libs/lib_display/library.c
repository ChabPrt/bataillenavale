// library.c
#include "library.h"
#include "../lib_model/library.h"
#include <stdio.h>

void printGrids(grid_case **gridPlayer, grid_case **gridEnemy) {
    printf("  1 2 3 4 5 6 7 8 9 10     1 2 3 4 5 6 7 8 9 10\n");
    char row = 'A';
    for (int i = 0; i < GRID_SIZE; i++) {
        printf("%c ", row++);
        for (int j = 0; j < GRID_SIZE; j++) {
            if (gridPlayer[i][j].is_fired) {
                if (gridPlayer[i][j].is_contain_ship) {
                    printf("\033[33m"); // Jaune
                } else {
                    printf("\033[34m"); // Bleu
                }
            } else {
                if (gridPlayer[i][j].is_contain_ship) {
                    printf("\033[32m"); // Vert
                } else {
                    printf("\033[37m"); // Blanc
                }
            }
            printf("%s ", gridPlayer[i][j].is_contain_ship ? "#" : ".");
        }
        printf("    "); // Ecart entre grilles
        printf("%c ", 'A' + i); // Colonne de lettres de grille tirs
        for (int j = 0; j < GRID_SIZE; j++) {
            if (gridEnemy[i][j].is_fired) {
                if (gridEnemy[i][j].is_contain_ship) {
                    printf("\033[33m"); // Jaune
                } else {
                    printf("\033[34m"); // Bleu
                }
            } else {
                printf("\033[37m"); // Blanc
            }
            printf("%s ", (gridEnemy[i][j].is_fired && gridEnemy[i][j].is_contain_ship) ? "#" : ".");
        }
        printf("\n");
    }
}
