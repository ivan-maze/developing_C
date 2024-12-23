#include <stdio.h>
#include <stdlib.h>
#include "pacmangame.h"
#include "map.h"

MAP m;
POSITION hero;

void movement(char direction) {
    
    if (direction != 'a' &&
        direction != 'w' &&
        direction != 's' &&
        direction != 'd') {
        return;
    }
    
    int nextx = hero.x;
    int nexty = hero.y;

    switch (direction) {
        case 'a': nexty--; break;
        case 'w': nextx--; break;
        case 's': nextx++; break;
        case 'd': nexty++; break;
    }
    if (nextx >= m.lines) {
        return;
    }
    if (nexty >= m.columns) {
        return;
    }
    if (m.matrix[nextx][nexty] != '.') {
        return;
    }

    m.matrix[nextx][nexty] = '@';
    m.matrix[hero.x][hero.y] = '.';
    hero.x = nextx;
    hero.y = nexty;
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
