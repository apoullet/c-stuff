typedef enum {
    UP,
    RIGHT,
    DOWN,
    LEFT,
    NONE
} direction;

typedef struct {
    int x;
    int y;
} vec2d;

typedef struct {
    int body[600][2];
    int limb_count;
    int growing;
    direction move;
} snake;

typedef struct {
    vec2d pos;
    int width;
    int height;
} rect;

void draw_arena(rect arena);
void draw_snake(snake player);
void draw_cherry(vec2d goal);

snake * init_snake(snake * player, rect arena);
void move_snake(snake * player);
void grow_snake(snake * player);
void hit_wall(snake * player, rect arena);
int collision(snake player);
void move_cherry(vec2d * goal, rect arena);
void init_rect(rect * rectangle, int x, int y, int width, int height);
