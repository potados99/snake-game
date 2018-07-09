//
//  types.h
//  snake-game
//
//  Created by POTADOS on 2018. 7. 9..
//  Copyright © 2018년 POTADOS. All rights reserved.
//

#ifndef types_h
#define types_h

#include <stdio.h>
#include "linked_list.h"

typedef unsigned int uint;

typedef enum {
    true = 1,
    false = 0
} bool;

typedef enum {
    UP,
    LEFT,
    DOWN,
    RIGHT
} Direction;

typedef enum {
    HEAD_FORWARD,
    HEAD_LEFT,
    HEAD_RIGHT
} HeadDirection;

typedef enum {
    EMPTY = 0,
    BODY = 1,
    TARGET = 2
} Block;

#endif /* types_h */
