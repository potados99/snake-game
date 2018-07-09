//
//  game_data.h
//  snake-game
//
//  Created by POTADOS on 2018. 7. 9..
//  Copyright © 2018년 POTADOS. All rights reserved.
//

#ifndef game_data_h
#define game_data_h

#define MAP_SIZE 20

#include "types.h"

void init_map(void);
int (*get_map(void))[];
void set_map(int value[][MAP_SIZE]);
void set_map_element(int row, int column, Block block);

#endif /* game_data_h */
