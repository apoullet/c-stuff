typedef enum {
    UP,
    RIGHT,
    DOWN,
    LEFT
} dir;

typedef struct {
    float x, y;
} vec2d;

typedef struct {
    vec2d pos;
    int width, height;
} rect;

typedef struct {
    vec2d pos;
    float velocity;
} entity;

typedef struct {
    entity * invaders;
} invaderRow;

void move_entity(entity * e, rect arena, dir direction);

void draw_arena(rect arena, unsigned char appearance);
void draw_entity(entity e, unsigned char appearance);
