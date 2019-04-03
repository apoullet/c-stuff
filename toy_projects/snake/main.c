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

    snake player;

    player.body[0][0] = 10; 
    player.body[0][1] = 15; 

    player.limb_count = 1;

    player.growing = 0;

    player.move = NONE;

    cherry goal;

    goal.x = 1 + rand() % 28;
    goal.y = 1 + rand() % 18;

    int score = 0;

    do {
	clear();

	draw_arena(30, 20);
	mvprintw(1, 32, "SCORE: %d", score);
	move_snake(&player);
	draw_snake(&player);
	
	if (player.body[player.limb_count-1][1] == goal.x && player.body[player.limb_count-1][0] == goal.y) {
	    grow_snake(&player);
	    move_cherry(&goal);
	    score++;
	}

	draw_cherry(&goal);
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
    } while (ch != 'q' && player.limb_count < 600);

    endwin();

    return 0;
}
