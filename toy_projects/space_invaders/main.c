#include "game.h"
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

#define WALL '#'
#define PLAYER '^'
#define INVADER '@'
#define BULLET '.'

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

    entity * bullets = malloc(sizeof(entity) * 10);
    int bulletCount  = 0;

    const int INVADERCOUNT = arena.width-3;
    entity invaders[INVADERCOUNT];

    for (int i = 0; i < INVADERCOUNT; i++) {
	invaders[i].pos.x    = arena.pos.x+2+i;
	invaders[i].pos.y    = arena.pos.y+2;
	invaders[i].velocity = 1;
	invaders[i].alive    = 1;
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

		if (invaders[0].pos.x == arena.pos.x+1 && invaderDirection == LEFT)
		    invaderDirection = DOWN;
		else if (invaders[0].pos.x == arena.pos.x+1 && invaderDirection == DOWN)
		    invaderDirection = RIGHT;
		else if (invaders[arena.width-4].pos.x == arena.pos.x+arena.width-1 && invaderDirection == RIGHT)
		    invaderDirection = DOWN;
		else if (invaders[arena.width-4].pos.x == arena.pos.x+arena.width-1 && invaderDirection == DOWN)
		    invaderDirection = LEFT;

		for (int i = 0; i < arena.width-3; i++)
		    move_entity(&invaders[i], arena, invaderDirection);
	    }

	    if (invaders[0].pos.y == player.pos.y)
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

	    bullet_hit_invader(bullets, &bulletCount, invaders, INVADERCOUNT);

	    bullet_hit_wall(bullets, &bulletCount, arena);

	    wave_cleared(invaders, INVADERCOUNT, &cleared);

	    clear();

	    draw_arena(arena, WALL);
	    mvprintw(arena.pos.y+2, arena.pos.x+arena.width+2, "Bullets: %d", bulletCount);
	    draw_entity(player, PLAYER);

	    for (int i = 0; i < arena.width-3; i++)
		draw_entity(invaders[i], INVADER);

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
