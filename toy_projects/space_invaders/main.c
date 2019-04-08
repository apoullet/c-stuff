#include "game.h"
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

#define WALL '#'
#define PLAYER '^'
#define INVADER '@'
#define BULLET '.'

// TODO: Program the fact that if a wave is completely killed off it's not counting any more in the losing condition.
int main() {
    int ch;
    srand(time(NULL));

    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
    timeout(100);

    int gameOver = 0;
    int cleared  = 0;

    int width = 30, height = 20;

    rect arena = { .pos.x = (COLS-width)/2, .pos.y = (LINES-height)/2, .width = width, .height = height };

    entity player = { .pos.x = arena.pos.x+arena.width/2, .pos.y = arena.pos.y+arena.height-1, .velocity = 1, .alive = 1 };

    entity * bullets = malloc(sizeof(entity) * 32);
    int bulletCount  = 0;

    const int INVADERCOUNT = arena.width-3;

    int waves = 2;

    entity invaderBlock[waves][INVADERCOUNT];

    for (int i = 0; i < waves; i++) {
	for (int j = 0; j < INVADERCOUNT; j++) {
	    invaderBlock[i][j].pos.x    = arena.pos.x+2+j;
	    invaderBlock[i][j].pos.y    = arena.pos.y+2+i;
	    invaderBlock[i][j].velocity = 1;
	    invaderBlock[i][j].alive    = 1;
	}
    }

    dir invaderDirection = LEFT;

    int loop = 0;

    do {
	ch = getch();

	if (cleared) {
	    clear();

	    mvprintw(LINES/2, (COLS-8)/2, "YOU WIN!");
	} else if (!gameOver) {
	    if (++loop == 7) {
		loop = 0;

		if (invaderBlock[waves-1][0].pos.x == arena.pos.x+1 && invaderDirection == LEFT)
		    invaderDirection = DOWN;
		else if (invaderBlock[waves-1][0].pos.x == arena.pos.x+1 && invaderDirection == DOWN)
		    invaderDirection = RIGHT;
		else if (invaderBlock[waves-1][INVADERCOUNT-1].pos.x == arena.pos.x+arena.width-1 && invaderDirection == RIGHT)
		    invaderDirection = DOWN;
		else if (invaderBlock[waves-1][INVADERCOUNT-1].pos.x == arena.pos.x+arena.width-1 && invaderDirection == DOWN)
		    invaderDirection = LEFT;

		for (int i = 0; i < waves; i++) {
		    for (int j = 0; j < INVADERCOUNT; j++) {
			move_entity(&invaderBlock[i][j], arena, invaderDirection);
		    }
		}
	    }

	    if (invaderBlock[waves-1][0].pos.y == player.pos.y)
		gameOver = 1;

	    switch(ch) {
		case KEY_LEFT:
		    move_entity(&player, arena, LEFT);
		    break;

		case KEY_RIGHT:
		    move_entity(&player, arena, RIGHT);
		    break;

		case ' ':
		    shoot(bullets, &bulletCount, player);
	    }

	    for (int i = 0; i < bulletCount; i++)
		move_entity(&bullets[i], arena, UP);

	    bullet_hit_invader(bullets, &bulletCount, INVADERCOUNT, waves, invaderBlock);

	    bullet_hit_wall(bullets, &bulletCount, arena);

	    wave_cleared(INVADERCOUNT, waves, invaderBlock, &cleared);

	    clear();

	    draw_arena(arena, WALL);
	    draw_entity(player, PLAYER);

	    for (int i = 0; i < waves; i++) {
		for (int j = 0; j < INVADERCOUNT; j++) {
		    draw_entity(invaderBlock[i][j], INVADER);
		}
	    }

	    for (int i = 0; i < bulletCount; i++)
		draw_entity(bullets[i], BULLET);
	} else {
	    clear();

	    mvprintw(LINES/2, (COLS-10)/2, "GAME OVER!");
	}
    } while (ch != 'q');

    endwin();

    return 0;
}
