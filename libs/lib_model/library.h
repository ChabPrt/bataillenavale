#ifndef LIB_MODEL_LIBRARY_H
#define LIB_MODEL_LIBRARY_H
#include <stdbool.h>

#define SIZE 10

struct __grid_case {
   bool is_fired;
   bool is_contain_ship;
};
typedef struct __grid_case grid_case;
struct ___hit {
    int column;
    int row;
};
typedef struct __hit hit;

void set_hit(int colonne, int row);
void set_ship(int colonne, int row);

/**
 * Used to init the grid. That allocate all memory needed for the game.
 * Don't forget to use the end() function to free the memory
 */
void init_grid();

/**
 * Used to free the memory of the data model
 */
void end();

#endif //LIB_MODEL_LIBRARY_H
