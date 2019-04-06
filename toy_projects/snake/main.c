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

    vec2d arena;

    arena.x = 30;
    arena.y = 20;

    snake player;

    init_snake(&player, arena.x/2, arena.y/2);

    vec2d goal;

    move_cherry(&goal, arena);

    int score = 0;

    do {
	clear();

	draw_arena(arena);
	mvprintw(2, arena.x+1, "SCORE: %d", score);
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
