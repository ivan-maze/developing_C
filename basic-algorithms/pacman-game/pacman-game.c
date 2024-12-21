#include <stdio.h>
#include <stdlib.h>
#include "pacmangame.h"

// matrix 5x10
char** map;
int lines;
int columns;

void readmap() {
    FILE* f = fopen("../map.txt", "r");
    if (f == 0) {
        printf("File not found\n");
        exit(1);
    }
    fscanf(f, "%d %d", &lines, &columns);
    allocatemap();
    for (int i = 0; i < 5; i++){
        fscanf(f, "%s", map[i]);
    }
    fclose(f);
}

void allocatemap() {
    map = malloc(sizeof(char*) * lines);
    for (int i = 0; i < lines; i++) {
        map[i] = malloc(sizeof(char) * (columns+1));
    }
}

void printmap() {
    for (int i = 0; i < 5; i++){
        printf("%s\n", map[i]);
    }
}

void movement(char direction) {
    int x;
    int y;

    for(int i = 0 ; i < lines; i++) {
        for(int j = 0; j < columns; j++) {
            if(map[i][j] == '@') {
                x = i;
                y = j;
                break;
            }
        }
    }

    switch (direction) {
        case 'a':
            map[x][y-1] = '@';
            break;
        case 'w':
            map[x-1][y] = '@';
            break;
        case 's':
            map[x+1][y] = '@';
            break;
        case 'd':
            map[x][y+1] = '@';
            break;
    }
    map [x][y] = '.';
}

void freemap() {
    for (int i = 0; i < lines; i++) {
        free(map[i]);
    }
    free(map);
}

int gameover() {
    return 0;
}

int main() {
    readmap();

    do {
        printmap();

        char command;
        scanf(" %c", &command);
        movement(command);

    } while(!gameover());
    
    
    freemap();
}
