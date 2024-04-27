#include "library.h"

#include <stdlib.h>

grid_case **grid_player;
grid_case **grid_ordi;

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

void set_hit_player(coordinate coordinate) {
    //todo : à implémenter. Peut être créé une autre lib pour ça.
}

void set_hit_ennemy(coordinate coordinate) {
    //todo : à implémenter. Peut être créé une autre lib pour ça.
}

void set_ship_player(coordinate coordinate) {
    //todo : à implémenter. Peut être créé une autre lib pour ça.
}

void set_ship_ennemy(coordinate coordinate) {
    //todo : à implémenter. Peut être créé une autre lib pour ça.
}

bool is_killed_player(coordinate coordinate) {
    return grid_player[coordinate.row][coordinate.col].is_sank;
}

bool is_killed_ennemy(coordinate coordinate) {
    return grid_ordi[coordinate.row][coordinate.col].is_sank;
}

void init_model() {
    grid_player = (grid_case **) malloc(GRID_SIZE * sizeof(grid_case *));
    if (grid_player == NULL) { exit(1); }
    init_grid(grid_player);
    grid_ordi = (grid_case **) malloc(GRID_SIZE * sizeof(grid_case *));
    if (grid_ordi == NULL) { exit(1); }
    init_grid(grid_ordi);
    init_list_of_ships(&ships_ordi);
    init_list_of_ships(&ships_player);
}

void end_model() {
    for (int i = 0; i < GRID_SIZE; ++i) {
        free(grid_player[i]);
        free(grid_ordi[i]);
    }
    free(grid_player);
    free(grid_ordi);

    free(ships_ordi.sm_ship.coordinate);
    free(ships_ordi.md_ship1.coordinate);
    free(ships_ordi.md_ship2.coordinate);
    free(ships_ordi.lg_ship.coordinate);
    free(ships_ordi.xl_ship.coordinate);

    free(ships_player.sm_ship.coordinate);
    free(ships_player.md_ship1.coordinate);
    free(ships_player.md_ship2.coordinate);
    free(ships_player.lg_ship.coordinate);
    free(ships_player.xl_ship.coordinate);
}
