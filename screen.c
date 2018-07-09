//
//  screen.c
//  snake-game
//
//  Created by POTADOS on 2018. 7. 9..
//  Copyright © 2018년 POTADOS. All rights reserved.
//

#include "screen.h"

void print_snake() {
    clear_console();

    int isBody = 0;
    
    List list = get_snake_body();
    for (register uint i = 0; i < MAP_SIZE; ++ i) {
        for (register uint j = 0; j < MAP_SIZE; ++ j) {
        
            for (register uint k = 0; k < list_get_length(list); ++ k) {
                int *point = list_get_value(list, k);
                if (point[0] == i && point[1] == j) {
                    printf("%d ", 1);
                    isBody = 1;
                    break;
                }
                else {
                    isBody = 0;
                }
            }
            
            if (isBody == 0) {
                printf("%d ", 0);

            }
        } printf("\n");
    }
    

}


void gotoxy(int x, int y) {
#if defined __WIN32__ || defined _MSC_VER
    
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    
#elif defined __APPLE__ || defined __unix__
    
    printf("\033[%d;%dH", y, x);
    
#endif
}

void movexy(int x, int y) {
#if defined __WIN32__ || defined _MSC_VER
    
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbiInfo);
    gotoxy(csbiInfo.dwCursorPosition.X + x, csbiInfo.dwCursorPosition.Y + y);
    
#elif defined __APPLE__ || defined __unix__
    
    if (x > 0) {
        printf("\033[%dC", x);
    }
    else if (x < 0) {
        printf("\033[%dD", x * -1);
    }
    
    if (y > 0) {
        printf("\033[%dB", y);
    }
    else if (y < 0) {
        printf("\033[%dA", y * -1);
    }
    
#endif
}

void clear_console() {
#if defined __WIN32__ || defined _MSC_VER
    system("cls");
#elif defined __APPLE__ || defined __unix__
    system("clear");
#endif
}
