#include <stdio.h>
#include <stdlib.h>
#include "map.h"

void allocate_map(MAP* m) {
    m->matrix = malloc(sizeof(char*) * m->lines);
    for (int i = 0; i < m->lines; i++) {
        m->matrix[i] = malloc(sizeof(char) * (m->columns+1));
    }
}

void read_map(MAP* m) {
    FILE* f = fopen("map.txt", "r");
    if (f == 0) {
        printf("File not found\n");
        exit(1);
    }
    fscanf(f, "%d %d", &(m->lines), &(m->columns));
    allocate_map(m);
    for (int i = 0; i < m->lines; i++){
        fscanf(f, "%s", m->matrix[i]);
    }
    fclose(f);
}

void print_map(MAP* m) {
    for (int i = 0; i < m->lines; i++){
        printf("%s\n", m->matrix[i]);
    }
}

void find_position(MAP* m, POSITION* p, char c) {
    for (int i = 0 ; i < m->lines; i++) {
        for (int j = 0; j < m->columns; j++) {
            if (m->matrix[i][j] == c) {
                p->x = i;
                p->y = j;
                break;
            }
        }
    }
}

int map_boundaries(MAP* m, int x, int y) {
    if (x >= m->lines) {
        return 1;
    }
    if (y >= m->columns) {
        return 1;
    }
    return 0;
}

int is_valid_path(MAP* m, int x, int y) {
    return m->matrix[x][y] == EMPTY_POSITION;
        
}

void walk_on_map(MAP* m, int xorigin, int yorigin, int xdestiny, int ydestiny) {
    char hero_position = m->matrix[xorigin][yorigin];
    m->matrix[xdestiny][ydestiny] = hero_position;
    m->matrix[xorigin][yorigin] = EMPTY_POSITION;
}

void free_map(MAP* m) {
    for (int i = 0; i < m->lines; i++) {
        free(m->matrix[i]);
    }
    free(m->matrix);
}
