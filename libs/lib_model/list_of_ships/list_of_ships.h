//
// Created by vivie on 26/04/2024.
//

/**
 * File for list_of ship. Contained the method init to init list_oh_ship data model.
 */

#ifndef LIST_OF_SHIPS_H
#define LIST_OF_SHIPS_H
#include <stdbool.h>

#define SMALL_SHIP 2
#define MEDIUM_SHIP 3
#define LARGE_SHIP 4
#define XL_SHIP 5

struct __coordinate {
    int col;
    int row;
};

typedef struct __coordinate coordinate;

struct __ship {
    coordinate *coordinate;
    bool is_killed;
};

typedef struct __ship ship;

struct __list_of_ships {
    ship sm_ship;
    ship md_ship1;
    ship md_ship2;
    ship lg_ship;
    ship xl_ship;
};

typedef struct __list_of_ships list_of_ships;

/**
 * Allow to init a list of ship place in paramater
 * @param list List of ship
 */
void init_list_of_ships(list_of_ships *list);

#endif //LIST_OF_SHIPS_H
