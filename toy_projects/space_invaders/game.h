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
    int alive;
} entity;

void move_entity(entity * e, rect arena, dir direction);
void shoot(entity * bullets, int * bulletCount, entity player);
void bullet_hit_invader(entity * bullets, int * bulletCount, const int INVADERCOUNT, int waves, entity (*invaders)[INVADERCOUNT]);
void bullet_hit_wall(entity * bullets, int * bulletCount, rect arena);
void wave_cleared(const int INVADERCOUNT, int waves, entity (*invaders)[INVADERCOUNT], int * cleared);

void draw_arena(rect arena, unsigned char appearance);
void draw_entity(entity e, unsigned char appearance);
