#define CHAR_HERO '@'
#define EMPTY_POSITION '.'

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

void allocate_map(MAP* m);
void read_map(MAP* m);
void free_map(MAP* m);
void print_map(MAP* m);
void find_position(MAP* m, POSITION* p, char c);
int map_boundaries(MAP* m, int x, int y);
int is_valid_path(MAP* m, int x, int y);
void walk_on_map(MAP* m, int xorigin, int yorigin, int xdestiny, int ydestiny);
