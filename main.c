//
//  main.c
//  snake-game
//
//  Created by POTADOS on 2018. 7. 9..
//  Copyright © 2018년 POTADOS. All rights reserved.
//

#include <stdio.h>
#include "game_data.h"
#include "input.h"
#include "routines.h"
#include "snake_data.h"
#include "screen.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    init_snake();
    change_snake_direction(RIGHT);
    listen_input(5);
    //print_snake();
    return 0;
}
