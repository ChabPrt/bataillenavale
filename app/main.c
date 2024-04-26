// main.c
#include <stdio.h>
#include "../libs/lib_display/library.h"

int main() {
    Cell gridPlayer[11][11];
    initGrid(gridPlayer);
    gridPlayer[4][4].hit = true;
    gridPlayer[5][5].hit = true;
    gridPlayer[5][5].isContainsShip = true;
    gridPlayer[5][6].isContainsShip = true;
    gridPlayer[5][7].isContainsShip = true;
    gridPlayer[5][4].hit = true;
    gridPlayer[5][6].hit = true;

    Cell gridEnemy[11][11];
    initGrid(gridEnemy);
    gridEnemy[4][4].hit = true;
    gridEnemy[5][5].hit = true;
    gridEnemy[5][5].isContainsShip = true;
    gridEnemy[5][6].isContainsShip = true;
    gridEnemy[5][7].isContainsShip = true;
    gridEnemy[5][4].hit = true;
    gridEnemy[5][6].hit = true;

    printGrids(gridPlayer, gridEnemy);

    //useless code -- just for waiting time
    int num;
    float fnum;
    printf("Enter an integer and a floating-point number: ");
    scanf("%d %f", &num, &fnum);
    printf("You entered %d and %f\n", num, fnum);

    return 0;
}
