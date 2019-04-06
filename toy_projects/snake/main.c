#include "game.h"
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

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

    int space = arena.width*arena.height - 2*(arena.width+arena.height);

    vec2d body[space];

    body[0].x = arena.pos.x+arena.width/2;
    body[0].y = arena.pos.y+arena.height/2;

    snake player = { .limb_count = 1, .move = NONE, .body = body };

    vec2d goal;

    move_cherry(&goal, arena);

    int score = 0;

    do {
	clear();

	draw_arena(arena);
	mvprintw(arena.pos.y+2, arena.pos.x+arena.width+1, "SCORE: %d", score);
	move_snake(&player);
	draw_snake(player);
	hit_wall(&player, arena);
	
	if (player.body[player.limb_count-1].y == goal.y && player.body[player.limb_count-1].x == goal.x) {
	    player.growing = 1;
	    move_cherry(&goal, arena);
	    score++;
	}

	draw_cherry(goal);
	refresh();

	ch = getch();

	switch (ch) {
	    case KEY_UP:
		player.move = UP;
		break;
	    case KEY_RIGHT:
		player.move = RIGHT;
		break;
	    case KEY_DOWN:
		player.move = DOWN;
		break;
	    case KEY_LEFT:
		player.move = LEFT;
		break;
	}
    } while (ch != 'q' && player.limb_count < space && !collision(player));

    endwin();

    return 0;
}
