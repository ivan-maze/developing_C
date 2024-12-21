#include <stdio.h>
#include <stdlib.h>
#include "pacmangame.h"

struct map m;

void readmap() {
    FILE* f = fopen("../map.txt", "r");
    if (f == 0) {
        printf("File not found\n");
        exit(1);
    }
    fscanf(f, "%d %d", &(m.lines), &(m.columns));
    allocatemap();
    for (int i = 0; i < m.lines; i++){
        fscanf(f, "%s", m.matrix[i]);
    }
    fclose(f);
}

void allocatemap() {
    m.matrix = malloc(sizeof(char*) * m.lines);
    for (int i = 0; i < m.lines; i++) {
        m.matrix[i] = malloc(sizeof(char) * (m.columns+1));
    }
}

void printmap() {
    for (int i = 0; i < m.lines; i++){
        printf("%s\n", m.matrix[i]);
    }
}

void movement(char direction) {
    int x;
    int y;

    for(int i = 0 ; i < m.lines; i++) {
        for(int j = 0; j < m.columns; j++) {
            if(m.matrix[i][j] == '@') {
                x = i;
                y = j;
                break;
            }
        }
    }

    switch (direction) {
        case 'a':
            m.matrix[x][y-1] = '@';
            break;
        case 'w':
            m.matrix[x-1][y] = '@';
            break;
        case 's':
            m.matrix[x+1][y] = '@';
            break;
        case 'd':
            m.matrix[x][y+1] = '@';
            break;
    }
    m.matrix [x][y] = '.';
}

void freemap() {
    for (int i = 0; i < m.lines; i++) {
        free(m.matrix[i]);
    }
    free(m.matrix);
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
