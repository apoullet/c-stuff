#include "game.h"
#include <ncurses.h>

#define LIMB '*'
#define CHERRY '$'
#define WALL '#'

void draw_arena(int width, int height) {
    mvhline(0, 0, WALL, width);

    mvhline(height-1, 0, WALL, width);

    mvvline(0, 0, WALL, height);

    mvvline(0, width-1, WALL, height);
}

void draw_snake(snake * player) {
    for (int i = 0; i < player->limb_count; i++)
	mvaddch(player->body[i][0], player->body[i][1], LIMB);
}

void draw_cherry(cherry * goal) {
    mvaddch(goal->y, goal->x, CHERRY);
}
