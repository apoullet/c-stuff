#include "game.h"
#include <ncurses.h>

#define LIMB '*'
#define CHERRY '$'
#define WALL '#'

void draw_arena(vec2d arena) {
    mvhline(0, 0, WALL, arena.x);

    mvhline(arena.y-1, 0, WALL, arena.x);

    mvvline(0, 0, WALL, arena.y);

    mvvline(0, arena.x-1, WALL, arena.y);
}

void draw_snake(snake player) {
    for (int i = 0; i < player.limb_count; i++)
	mvaddch(player.body[i][1], player.body[i][0], LIMB);
}

void draw_cherry(vec2d goal) {
    mvaddch(goal.y, goal.x, CHERRY);
}
