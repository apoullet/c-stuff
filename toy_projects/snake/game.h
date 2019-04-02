typedef enum {
    UP,
    RIGHT,
    DOWN,
    LEFT,
    NONE
} direction;

typedef struct {
    int body[10][2];
    int limb_count;
    int growing;
    direction move;
} snake;

typedef struct {
    int x;
    int y;
} cherry;

void draw_arena(int width, int height);
void draw_snake(snake * player);
void move_snake(snake * player);
void grow_snake(snake * player);
void draw_cherry(cherry * goal);
void move_cherry(cherry * goal);
