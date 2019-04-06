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

    rect arena;

    init_rect(&arena, COLS/2, LINES/2, 60, 40);

    snake player;

    init_snake(&player, arena.pos.x+arena.width/2, arena.pos.y+arena.height/2);

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
	
	if (player.body[player.limb_count-1][1] == goal.y && player.body[player.limb_count-1][0] == goal.x) {
	    grow_snake(&player);
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
    } while (ch != 'q' && player.limb_count < 600 && !collision(player));

    endwin();

    return 0;
}
