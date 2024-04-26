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

void init_grid(grid_case **grid) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; ++j) {
            grid[i][j].is_contain_ship = false;
            grid[i][j].is_fired = false;
            grid[i][j].is_sank = false;
        }
    }
}

void set_hit_player(coordinate coordinate) {
    //todo : à implémenter, à voir pour mettre dans une autre lib
}

void set_hit_ennemy(coordinate coordinate) {
    //todo : à implémenter, à voir pour mettre dans une autre lib
}

void set_ship_player(coordinate coordinate) {
    //todo : à implémenter, à voir pour mettre dans une autre lib
}

void set_ship_ennemy(coordinate coordinate) {
    //todo : à implémenter, à voir pour mettre dans une autre lib
}

ship init_ship(const int size) {
    ship ship;
    ship.is_killed = false;
    ship.coordinate = (coordinate *) malloc(size * sizeof(coordinate));
    return ship;
}

void init_list_of_ships(list_of_ships *list) {
    list->sm_ship = init_ship(SMALL_SHIP);
    list->md_ship1 = init_ship(MEDIUM_SHIP);
    list->md_ship2 = init_ship(MEDIUM_SHIP);
    list->lg_ship = init_ship(LARGE_SHIP);
    list->xl_ship = init_ship(XL_SHIP);
}

void init() {
    grid_player = (grid_case **) malloc(GRID_SIZE * sizeof(grid_case *));
    if (grid_player == NULL) { exit(1); }
    grid_ordi = (grid_case **) malloc(GRID_SIZE * sizeof(grid_case *));
    if (grid_ordi == NULL) { exit(1); }
    for (int i = 0; i < GRID_SIZE; ++i) {
        grid_player[i] = (grid_case *) malloc(GRID_SIZE * sizeof(grid_case));
        if (grid_ordi[i] == NULL) { exit(1); }
    }
    init_grid(grid_player);
    init_grid(grid_ordi);
    init_list_of_ships(&ships_ordi);
    init_list_of_ships(&ships_player);
}

void end() {
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
