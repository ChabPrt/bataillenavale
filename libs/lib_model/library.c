#include "library.h"

#include <stdlib.h>

grid_case** grid_player;
grid_case** grid_ordi;

list_of_ships ships_player;
list_of_ships ships_ordi;

grid_case **get_grid_player() {
    return grid_player;
}

grid_case **get_grid_ordi() {
    return grid_ordi;
}

list_of_ships get_ships_player() {
    return ships_player;
}

list_of_ships get_ships_ordi() {
    return ships_ordi;
}


void set_hit(int colonne, int row) {
    //todo : à implémenter
}

void set_ship(int colonne, int row) {
    //todo : à implémenter
}

void init_grid() {
    grid_player = (grid_case**) malloc(GRID_SIZE*sizeof(grid_case));
    if (grid_player==NULL){ exit(1); }
    for (int i = 0; i < GRID_SIZE; ++i) {
        grid_player[i] = (grid_case*) malloc(GRID_SIZE*sizeof(grid_case));
        if (grid_player[i]==NULL){ exit(1); }
    }
    grid_ordi = (grid_case**) malloc(GRID_SIZE*sizeof(grid_case));
    if (grid_ordi==NULL){ exit(1); }
    for (int i = 0; i < GRID_SIZE; ++i) {
        grid_ordi[i] = (grid_case*) malloc(GRID_SIZE*sizeof(grid_case));
        if (grid_ordi[i]==NULL){ exit(1); }
    }
}

void end() {
    free(grid_player);
    free(grid_ordi);
}
