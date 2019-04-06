typedef enum {
    UP,
    RIGHT,
    DOWN,
    LEFT,
    NONE
} direction;

typedef struct {
    int body[600][2];
    int limb_count;
    int growing;
    direction move;
} snake;

typedef struct {
    int x;
    int y;
} vec2d;

void draw_arena(vec2d arena);
void draw_snake(snake player);
void draw_cherry(vec2d goal);

void init_snake(snake * player, int x, int y);
void move_snake(snake * player);
void grow_snake(snake * player);
void hit_wall(snake * player, vec2d arena);
int collision(snake player);
void move_cherry(vec2d * goal, vec2d arena);
