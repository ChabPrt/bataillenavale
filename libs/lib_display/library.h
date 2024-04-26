// library.h

#ifndef LIBRARY_H
#define LIBRARY_H

#include <stdbool.h>

typedef struct {
    bool isContainsShip;
    bool hit;
} Cell;

void initGrid(Cell grid[][11]);
void printGrids(Cell gridPlayer[][11], Cell gridEnemy[][11]);

#endif
