//
//  snake_control.c
//  snake-game
//
//  Created by POTADOS on 2018. 7. 9..
//  Copyright © 2018년 POTADOS. All rights reserved.
//

#include "snake_control.h"
#include "snake_data.h"

void change_snake_direction(Direction direction) {
    if (direction == get_snake_direction()) {
        return;
    }
    set_snake_direction(direction);
}

void move_snake() {
    List list = get_snake_body();
    Direction direction = get_snake_direction();
    int length = get_snake_length();
    
    switch (direction) {
        case UP:
            list_append(list, new_point(list->last->data[0], list->last->data[1] - 1));
            list_delete(list, 0);
            break;
        case LEFT:
            list_append(list, new_point(list->last->data[0] - 1, list->last->data[1]));
            list_delete(list, 0);
            break;
        case DOWN:
            list_append(list, new_point(list->last->data[0], list->last->data[1] + 1));
            list_delete(list, 0);
            break;
        case RIGHT:
            list_append(list, new_point(list->last->data[0] + 1, list->last->data[1]));
            list_delete(list, 0);
            break;
            
        default:
            break;
    }
    
    
}
