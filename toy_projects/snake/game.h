typedef struct {
    int x;
    int y;
} vec2d;

typedef struct {
    vec2d pos;
    int width;
    int height;
} rect;

typedef enum {
    UP,
    RIGHT,
    DOWN,
    LEFT,
    NONE
} direction;

typedef struct {
    int limb_count;
    int growing;
    direction move;
    vec2d * body;
} snake;

void draw_arena(rect arena);
void draw_snake(snake player);
void draw_cherry(vec2d goal);

void move_snake(snake * player);
void hit_wall(snake * player, rect arena);
int collision(snake player);
void move_cherry(vec2d * goal, rect arena);
