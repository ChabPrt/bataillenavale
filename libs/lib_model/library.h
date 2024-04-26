#ifndef LIB_MODEL_LIBRARY_H
#define LIB_MODEL_LIBRARY_H
#include <stdbool.h>

#define GRID_SIZE 10
#define SMALL_SHIP 2
#define MEDIUM_SHIP 3
#define LARGE_SHIP 4
#define XL_SHIP 5

struct __grid_case {
    bool is_fired;
    bool is_contain_ship;
};

typedef struct __grid_case grid_case;

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
 * Allow to get the player's list of ships
 * @return The player's list of ships
 */
list_of_ships get_ships_player();

/**
 * Allow to get the ordi's list of ships
 * @return The ordi's list of ships
 */
list_of_ships get_ships_ordi();

/**
 * Allow to get the player's grid
 * @return The player's grid
 */
grid_case **get_grid_player();

/**
 * Allow to get the ordi's grid
 * @return The ordi's grid
 */
grid_case **get_grid_ordi();

/**
 * Allow to set hit in the grille player
 * @param coordinate Coordinate of the hit
 */
void set_hit_player(coordinate coordinate);

/**
 * Allow to set hit to the grille ordi
 * @param coordinate Coordinate of the hit
 */
void set_hit_ennemy(coordinate coordinate);

/**
 * Allow to set ship to the grille player
 * @param coordinate Coordinate of the ship
 */
void set_ship_player(coordinate coordinate);

/**
 * Allow to set ship to the grille ordi
 * @param coordinate Coordinate of the ship
 */
void set_ship_ennemy(coordinate coordinate);

/**
 * Allow to know if a coordinate point is a killed ship to the player grid
 * @param coordinate Coordinate to test
 */
bool is_killed_player(coordinate coordinate);

/**
 * Allow to know if a coordinate point is a killed ship to the ordi grid
 * @param coordinate Coordinate to test
 */
bool is_killed_ennemy(coordinate coordinate);

/**
 * Used to init the grid. That allocate all memory needed for the game.
 * Don't forget to use the end() function to free the memory
 */
void init();

/**
 * Used to free the memory of the data model
 */
void end();

#endif //LIB_MODEL_LIBRARY_H
