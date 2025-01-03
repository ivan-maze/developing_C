#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
int phantom_direction(int x_origin, int y_origin, int* x_destiny, int* y_destiny) {
    int options[4][2] = {
        {x_origin, y_origin+1},
        {x_origin+1, y_origin},
        {x_origin, y_origin-1},
        {x_origin-1, y_origin}
    };
    srand(time(0));
    for (int i=0; i<10; i++) {
        int position = rand()%4;
        if (is_valid_path(&m, options[position][0], options[position][1]) &&
            !map_boundaries(&m, options[position][0], options[position][1])) {
            *x_destiny = options[position][0];
            *y_destiny = options[position][1];
            return 1;
        }
    }
    return 0;
}
void phantom_movement() {
    MAP copy;
    copy_map(&copy, &m);
    for (int i = 0; i < m.lines; i++) {
        for (int j = 0; j <= m.columns; j++) {
            if (copy.matrix[i][j] == PHANTOM) {
                int x_destiny;
                int y_destiny;
                int found = phantom_direction(i, j, &x_destiny, &y_destiny);
                if(found) {
                    walk_on_map(&m, i, j, x_destiny, y_destiny);
                }
            }
        }
    }
    free_map(&copy);
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
        phantom_movement();
    } while(!game_over());
    free_map(&m);
}
