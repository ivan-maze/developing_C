#include <stdio.h>
#include <stdlib.h>
#include "pacmangame.h"
#include "map.h"

MAP m;
POSITION hero;

void movement(char direction) {
 
    m.matrix [hero.x][hero.y] = '.';

    switch (direction) {
        case 'a': m.matrix[hero.x][hero.y-1] = '@'; hero.y--; break;
        case 'w': m.matrix[hero.x-1][hero.y] = '@'; hero.x--; break;
        case 's': m.matrix[hero.x+1][hero.y] = '@'; hero.x++; break;
        case 'd': m.matrix[hero.x][hero.y+1] = '@'; hero.y++; break;
    }
}

int gameover() {
    return 0;
}

int main() {
    readmap(&m);
    findposition(&m, &hero, '@');

    do {
        printmap(&m);

        char command;
        scanf(" %c", &command);
        movement(command);

    } while(!gameover());
    
    
    freemap(&m);
}
