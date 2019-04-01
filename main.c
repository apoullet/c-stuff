#include <stdio.h>

#define false 0
#define true 1

#define up 2
#define right 3
#define down 4
#define left 5

typedef struct {
    int x;
    int y;
} point;

void move(point* p, int direction);

int main() {
    point p1;
    point p2;

    p1.x = 0;
    p1.y = 0;

    p2.x = 10;
    p2.y = 10;

    move(&p1, up);
    move(&p2, left);

    printf("p1's position is: %d, %d\n", p1.x, p1.y);
    printf("p2's position is: %d, %d\n", p2.x, p2.y);

    return 0;
}

void move(point* p, int direction) {
    if (direction == up)
	p->y--;
    else if (direction == right)
	p->x++;
    else if (direction == down)
	p->y++;
    else if (direction == left)
	p->x--;
}
