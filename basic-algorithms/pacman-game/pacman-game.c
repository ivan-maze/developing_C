#include <stdio.h>
#include <stdlib.h>
#include "pacman-game.h"
#include "map.h"

MAP m;
POSITION hero;

int validdirection(char direction) {
    return 
        direction == 'a' ||
        direction == 'w' ||
        direction == 's' ||
        direction == 'd';
}

void movement(char direction) {
    
    if (!validdirection(direction)) {
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
    
    if (mapboundaries(&m, nextx, nexty)) {
        return;
    }

    if (!isvalidpath(&m, nextx, nexty)) {
        return;
    }
    
    walkonmap(&m, hero.x, hero.y, nextx, nexty);
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
