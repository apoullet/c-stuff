#include "game.h"
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

#define WALL '#'
#define PLAYER '^'
#define INVADER '@'

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

    entity invaders[arena.width-3];

    invaderRow firstRow = { .invaders = invaders };

    for (int i = 0; i < arena.width-3; i++) {
	firstRow.invaders[i].pos.x    = arena.pos.x+2+i;
	firstRow.invaders[i].pos.y    = arena.pos.y+2;
	firstRow.invaders[i].velocity = 1;
    }

    dir invaderDirection = LEFT;

    do {
	ch = getch();
	
	if (firstRow.invaders[0].pos.x == arena.pos.x+1 && invaderDirection == LEFT)
	    invaderDirection = DOWN;
	else if (firstRow.invaders[0].pos.x == arena.pos.x+1 && invaderDirection == DOWN)
	    invaderDirection = RIGHT;
	else if (firstRow.invaders[arena.width-4].pos.x == arena.pos.x+arena.width-1 && invaderDirection == RIGHT)
	    invaderDirection = DOWN;
	else if (firstRow.invaders[arena.width-4].pos.x == arena.pos.x+arena.width-1 && invaderDirection == DOWN)
	    invaderDirection = LEFT;

	for (int i = 0; i < arena.width-3; i++)
	    move_entity(&firstRow.invaders[i], arena, invaderDirection);

	switch(ch) {
	    case KEY_LEFT:
		move_entity(&player, arena, LEFT);
		break;

	    case KEY_RIGHT:
		move_entity(&player, arena, RIGHT);
		break;
	}

	clear();

	draw_arena(arena, WALL);
	draw_entity(player, PLAYER);

	for (int i = 0; i < arena.width-3; i++)
	    draw_entity(firstRow.invaders[i], INVADER);
    } while (ch != 'q');

    endwin();

    return 0;
}
