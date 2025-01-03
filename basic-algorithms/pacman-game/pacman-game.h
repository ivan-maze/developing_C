#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'

void hero_movement(char direction);
void phantom_movement();
int valid_direction(char direction);
int phantom_direction(int x_origin, int y_origin, int* x_destiny, int* y_destiny);
int game_over();

