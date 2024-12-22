#include <stdio.h>
#include <stdlib.h>
#include "map.h"

void findposition(MAP* m, POSITION* p, char c) {
    for(int i = 0 ; i < m->lines; i++) {
        for(int j = 0; j < m->columns; j++) {
            if(m->matrix[i][j] == c) {
                p->x = i;
                p->y = j;
                break;
            }
        }
    }
}

void readmap(MAP* m) {
    FILE* f = fopen("map.txt", "r");
    if (f == 0) {
        printf("File not found\n");
        exit(1);
    }
    fscanf(f, "%d %d", &(m->lines), &(m->columns));
    allocatemap(m);
    for (int i = 0; i < m->lines; i++){
        fscanf(f, "%s", m->matrix[i]);
    }
    fclose(f);
}

void allocatemap(MAP* m) {
    m->matrix = malloc(sizeof(char*) * m->lines);
    for (int i = 0; i < m->lines; i++) {
        m->matrix[i] = malloc(sizeof(char) * (m->columns+1));
    }
}

void printmap(MAP* m) {
    for (int i = 0; i < m->lines; i++){
        printf("%s\n", m->matrix[i]);
    }
}

void freemap(MAP* m) {
    for (int i = 0; i < m->lines; i++) {
        free(m->matrix[i]);
    }
    free(m->matrix);
}
