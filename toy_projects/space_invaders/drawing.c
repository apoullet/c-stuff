#include "game.h"
#include <ncurses.h>

void draw_arena(rect arena, unsigned char appearance) {
    mvhline(arena.pos.y, arena.pos.x, appearance, arena.width+1);
    mvvline(arena.pos.y, arena.pos.x, appearance, arena.height+1);
    mvhline(arena.pos.y+arena.height, arena.pos.x, appearance, arena.width+1);
    mvvline(arena.pos.y, arena.pos.x+arena.width, appearance, arena.height+1);
}

void draw_entity(entity e, unsigned char appearance) {
    if (e.alive)
	mvaddch(e.pos.y, e.pos.x, appearance);
    else
	mvaddch(e.pos.y, e.pos.x, ' ');
}
