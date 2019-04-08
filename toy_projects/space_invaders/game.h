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

void draw_arena(rect arena, unsigned char appearance);
void draw_entity(entity e, unsigned char appearance);
