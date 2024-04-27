//
// Created by vivie on 26/04/2024.
//

#include "grid_case.h"

#include <stdlib.h>

void init_grid(grid_case **grid) {
    for (int i = 0; i < GRID_SIZE; i++) {
        grid[i] = (grid_case *) malloc(GRID_SIZE * sizeof(grid_case));
        if (grid[i] == NULL) { exit(1); }
        for (int j = 0; j < GRID_SIZE; ++j) {
            grid[i][j].is_contain_ship = false;
            grid[i][j].is_fired = false;
            grid[i][j].is_sank = false;
        }
    }
}
