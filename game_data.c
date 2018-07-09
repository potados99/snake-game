//
//  game_data.c
//  snake-game
//
//  Created by POTADOS on 2018. 7. 9..
//  Copyright © 2018년 POTADOS. All rights reserved.
//

#include "game_data.h"

static int map[MAP_SIZE][MAP_SIZE];

void init_map(void) {
    for (register uint row = 0; row < MAP_SIZE; ++ row) {
        for (register uint column = 0; column < MAP_SIZE; ++ column) {
            map[row][column] = EMPTY;
        }
    }
}

int (*get_map(void))[] {
    return map;
}

void set_map(int value[][MAP_SIZE]) {
    for (register uint row = 0; row < MAP_SIZE; ++ row) {
        for (register uint column = 0; column < MAP_SIZE; ++ column) {
            map[row][column] = value[row][column];
        }
    }
}

void set_map_element(int row, int column, Block block) {
    map[row][column] = block;
}
