#include "game.h"
#include <ncurses.h>

#define LIMB '*'
#define CHERRY '$'
#define WALL '#'

void draw_arena(rect arena) {
    mvhline(arena.pos.y, arena.pos.x, WALL, arena.width);

    mvhline(arena.pos.y+arena.height-1, arena.pos.x, WALL, arena.width);

    mvvline(arena.pos.y, arena.pos.x, WALL, arena.height);

    mvvline(arena.pos.y, arena.pos.x+arena.width-1, WALL, arena.height);
}

void draw_snake(snake player) {
    for (int i = 0; i < player.limb_count; i++)
	mvaddch(player.body[i].y, player.body[i].x, LIMB);
}

void draw_cherry(vec2d goal) {
    mvaddch(goal.y, goal.x, CHERRY);
}
