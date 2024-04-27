//
// Created by vivie on 26/04/2024.
//

#ifndef GRID_CASE_H
#define GRID_CASE_H
#include <stdbool.h>

#define GRID_SIZE 10

struct __grid_case {
    bool is_fired;
    bool is_contain_ship;
    bool is_sank;
};

typedef struct __grid_case grid_case;

void init_grid(grid_case **grid);

#endif //GRID_CASE_H
