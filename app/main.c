// main.c
#include <stdio.h>
#include <stdlib.h>
#include "../libs/lib_display/library.h"

void init() {
    init_model();
    //Mettre d'autres méthode d'init ici si besoin
}

void end() {
    end_model();
    //Mettre d'autres méthode de fin ici si besoin
}

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
    gridEnemy[2][3].is_sank = true;
    gridEnemy[2][4].is_sank = true;
    gridEnemy[2][5].is_sank = true;
    gridEnemy[5][4].is_fired = true;
    gridEnemy[5][6].is_fired = true;


    printGrids(gridPlayer, gridEnemy);

    //💩 useless code -- just for waiting time
    int num;
    float fnum;
    printf("Enter an integer and a floating-point number: ");
    scanf("%d %f", &num, &fnum);
    printf("You entered %d and %f\n", num, fnum);

    // 👌 Usefull for clear console ("On windows") => use "clear" instead for linux env
    system("cls");
    printGrids(gridPlayer, gridEnemy);

    //💩 useless code -- just for waiting time
    printf("Enter an integer and a floating-point number: ");
    scanf("%d %f", &num, &fnum);
    printf("You entered %d and %f\n", num, fnum);

    end();
    return 0;
}
