#include <stdio.h>
#include <stdlib.h>
#include "pacman-game.h"
#include "map.h"

MAP m;
POSITION hero;

int valid_direction(char direction) {
    return 
        direction == LEFT ||
        direction == UP ||
        direction == DOWN ||
        direction == RIGHT;
}

void hero_movement(char direction) {
    
    if (!valid_direction(direction)) {
        return;
    }
    
    int next_x = hero.x;
    int next_y = hero.y;

    switch (direction) {
        case LEFT: next_y--; break;
        case UP: next_x--; break;
        case DOWN: next_x++; break;
        case RIGHT: next_y++; break;
    }
    
    if (map_boundaries(&m, next_x, next_y)) {
        return;
    }

    if (!is_valid_path(&m, next_x, next_y)) {
        return;
    }
    
    walk_on_map(&m, hero.x, hero.y, next_x, next_y);
    hero.x = next_x;
    hero.y = next_y;
}

int game_over() {
    return 0;
}

int main() {
    read_map(&m);
    find_position(&m, &hero, CHAR_HERO);

    do {
        print_map(&m);

        char command;
        scanf(" %c", &command);
        hero_movement(command);

    } while(!game_over());
    
    free_map(&m);
}
