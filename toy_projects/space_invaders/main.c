#include "game.h"
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

#define PLAYER '^'
#define WALL '#'

int main() {
    int ch;
    srand(time(NULL));

    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
    timeout(100);

    int width = 30, height = 20;

    rect arena = { .pos.x = (COLS-width)/2, .pos.y = (LINES-height)/2, .width = width, .height = height };

    entity player = { .pos.x = arena.pos.x+arena.width/2, .pos.y = arena.pos.y+arena.height-1, .velocity = 1 };

    do {
	ch = getch();

	draw_arena(arena, WALL);
	draw_entity(player, PLAYER);
    } while (ch != 'q');

    endwin();

    return 0;
}
