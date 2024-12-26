struct map {
    char** matrix;
    int lines;
    int columns;
};
typedef struct map MAP;

struct position {
    int x;
    int y;
};
typedef struct position POSITION;

void readmap(MAP* m);
void allocatemap(MAP* m);
void freemap(MAP* m);
void printmap(MAP* m);
void findposition(MAP* m, POSITION* p, char c);
int mapboundaries(MAP* m, int x, int y);
int isvalidpath(MAP* m, int x, int y);
void walkonmap(MAP* m, int xorigin, int yorigin, int xdestiny, int ydestiny);
