// main.c
#include <stdio.h>
#include "../libs/lib_display/library.h"

int main() {
    init();

    grid_case **gridPlayer= get_grid_player();
    gridPlayer[4][4].is_fired = true;
    gridPlayer[5][5].is_fired = true;
    gridPlayer[5][5].is_contain_ship = true;
    gridPlayer[5][6].is_contain_ship = true;
    gridPlayer[5][7].is_contain_ship = true;
    gridPlayer[5][4].is_fired = true;
    gridPlayer[5][6].is_fired = true;

    grid_case **gridEnemy= get_grid_ordi();
    gridEnemy[4][4].is_fired = true;
    gridEnemy[5][5].is_fired = true;
    gridEnemy[5][5].is_contain_ship = true;
    gridEnemy[5][6].is_contain_ship = true;
    gridEnemy[5][7].is_contain_ship = true;
    gridEnemy[5][4].is_fired = true;
    gridEnemy[5][6].is_fired = true;

    printGrids(gridPlayer, gridEnemy);

    //💩 useless code -- just for waiting time
    int num;
    float fnum;
    printf("Enter an integer and a floating-point number: ");
    scanf("%d %f", &num, &fnum);
    printf("You entered %d and %f\n", num, fnum);

    end();
    return 0;
}
