//
//  screen.h
//  snake-game
//
//  Created by POTADOS on 2018. 7. 9..
//  Copyright © 2018년 POTADOS. All rights reserved.
//

#ifndef screen_h
#define screen_h

#include <stdio.h>
#include "snake_data.h"
#include "snake_control.h"

void print_snake(void);

void gotoxy(int x, int y);
void movexy(int x, int y);

void clear_console();

#endif /* screen_h */
