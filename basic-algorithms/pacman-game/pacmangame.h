void readmap();
void allocatemap();
void freemap();
void printmap();
void movement(char direction);
int gameover();
struct map {
    char** matrix;
    int lines;
    int columns;
};