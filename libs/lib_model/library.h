/**
 * The main file for data model. Used to store data and provide the init and end methods for data model.
 */

#ifndef LIB_MODEL_LIBRARY_H
#define LIB_MODEL_LIBRARY_H
#include <stdbool.h>
#include "./list_of_ships/list_of_ships.h"
#include "./grid_case/grid_case.h"

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
void set_hit_ordi(coordinate coordinate);

/**
 * Allow to know if the ordi has won
 * @return true if the ordi has won, false otherwise
 */
bool is_ordi_has_won();

/**
 * Allow to know if the player has won
 * @return true if the ordi has won, false otherwise
 */
bool is_player_has_won();

/**
 * Used to init the grid. That allocate all memory needed for the game.
 * Don't forget to use the end() function to free the memory
 */
void init_model();

/**
 * Used to free the memory of the data model
 */
void end_model();

#endif //LIB_MODEL_LIBRARY_H
