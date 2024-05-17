#include "library.h"

#include <stdio.h>
#include <stdlib.h>

grid_case **grid_player;
grid_case **grid_ordi;

list_of_ships ships_player;
list_of_ships ships_ordi;

grid_case **get_grid_player() {
    return grid_player;
}

grid_case **get_grid_ordi() {
    return grid_ordi;
}

list_of_ships get_ships_player() {
    return ships_player;
}

list_of_ships get_ships_ordi() {
    return ships_ordi;
}

void set_hit_player(coordinate coordinate) {
    //todo : à implémenter. Peut être créé une autre lib pour ça.
}

void set_hit_ennemy(coordinate coordinate) {
    //todo : à implémenter. Peut être créé une autre lib pour ça.
}

void set_ship_player(coordinate coordinate) {
    //todo : à implémenter. Peut être créé une autre lib pour ça.
}

void set_ship_ennemy(coordinate coordinate) {
    //todo : à implémenter. Peut être créé une autre lib pour ça.
}

bool is_killed_player(coordinate coordinate) {
    return grid_player[coordinate.row][coordinate.col].is_sank;
}

bool is_killed_ennemy(coordinate coordinate) {
    return grid_ordi[coordinate.row][coordinate.col].is_sank;
}

/**
 * La méthode doit positionner les bateaux dans la grille
 * Attention, la méthode ne vérifie pas que toute la grille est vide
 *
 * @param grid Grillé cible
 * @param list_of_ships Liste des bateaux
 */
void place_ship_on_grid(grid_case **grid, list_of_ships *list_of_ships) {
    const int ships_amount = 5;
    ship ships_s[ships_amount] = {
            list_of_ships->sm_ship,
            list_of_ships->md_ship1,
            list_of_ships->md_ship2,
            list_of_ships->lg_ship,
            list_of_ships->xl_ship,
    };

    //Je boucle sur tous les bateaux
    for (int ship_index_i = 0; ship_index_i < ships_amount; ship_index_i++) {
        ship curr_ship = ships_s[ship_index_i];

        //On détermine si on le place à la vertical(0) ou à l'horizontal(1)
        int isHorizontal = (rand() % 2) & 0x3;

        int next = 0;
        do {
            //On utilise les coordonnées aléatoires
            int y_max = isHorizontal == 1 ? GRID_SIZE : GRID_SIZE - curr_ship.size;
            int x_max = isHorizontal == 1 ? GRID_SIZE - curr_ship.size : GRID_SIZE;
            int y = rand() % y_max;
            int x = rand() % x_max;

            //Si on est en dehors, on recommence
            if (y < 0 || x < 0 || y >= y_max || x >= x_max) continue;
            bool alreadyHasShipAtCoord = false;

            //On regarde si les cases sont libres
            for (int i = 0; i < curr_ship.size; ++i) {

                int local_x = isHorizontal == 1 ? x + i : x;
                int local_y = isHorizontal == 1 ? y : y + i;

                //On recommence, un bateau est déjà présent ici
                if (grid[local_y][local_x].is_contain_ship) {
                    alreadyHasShipAtCoord = true;
                    break;
                };
            }
            if (alreadyHasShipAtCoord == true) continue;

            //On peut placer un bateau ici
            for (int i = 0; i < curr_ship.size; ++i) {
                int local_x = isHorizontal == 1 ? x + i : x;
                int local_y = isHorizontal == 1 ? y : y + i;

                // Accéder à la case [x][y+i] dans la grille
                curr_ship.coordinate[i].col = local_y;
                curr_ship.coordinate[i].row = local_x;

                grid_case *target_case = &grid[local_y][local_x];
                target_case->is_contain_ship = true;
            }

            break;
        } while (next == 0);

    }
}

void init_model() {
    grid_player = (grid_case **) malloc(GRID_SIZE * sizeof(grid_case *));
    if (grid_player == NULL) { exit(1); }
    init_grid(grid_player);
    grid_ordi = (grid_case **) malloc(GRID_SIZE * sizeof(grid_case *));
    if (grid_ordi == NULL) { exit(1); }
    init_grid(grid_ordi);

    init_list_of_ships(&ships_ordi);
    init_list_of_ships(&ships_player);

    //placement des bateaux sur la grilles
    place_ship_on_grid(grid_player, &ships_player);
    place_ship_on_grid(grid_ordi, &ships_ordi);

}

void end_model() {
    for (int i = 0; i < GRID_SIZE; ++i) {
        free(grid_player[i]);
        free(grid_ordi[i]);
    }
    free(grid_player);
    free(grid_ordi);

    free(ships_ordi.sm_ship.coordinate);
    free(ships_ordi.md_ship1.coordinate);
    free(ships_ordi.md_ship2.coordinate);
    free(ships_ordi.lg_ship.coordinate);
    free(ships_ordi.xl_ship.coordinate);

    free(ships_player.sm_ship.coordinate);
    free(ships_player.md_ship1.coordinate);
    free(ships_player.md_ship2.coordinate);
    free(ships_player.lg_ship.coordinate);
    free(ships_player.xl_ship.coordinate);
}
