//
// Created by vivie on 26/04/2024.
//

#include "list_of_ships.h"

#include <stdlib.h>

ship _init_ship(const int size) {
    ship ship;
    ship.is_killed = false;
    ship.coordinate = (coordinate *) malloc(size * sizeof(coordinate));
    return ship;
}

void init_list_of_ships(list_of_ships *list) {
    list->sm_ship = _init_ship(SMALL_SHIP);
    list->md_ship1 = _init_ship(MEDIUM_SHIP);
    list->md_ship2 = _init_ship(MEDIUM_SHIP);
    list->lg_ship = _init_ship(LARGE_SHIP);
    list->xl_ship = _init_ship(XL_SHIP);
}
