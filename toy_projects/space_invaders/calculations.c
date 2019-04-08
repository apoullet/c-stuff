#include "game.h"

void move_entity(entity * e, rect arena, dir direction) {
    switch(direction) {
	case UP:
	    e->pos.y -= e->velocity;
	    break;

	case RIGHT:
	    e->pos.x += e->velocity;
	    break;
	
	case DOWN:
	    e->pos.y += e->velocity;
	    break;

	case LEFT:
	    e->pos.x -= e->velocity;
	    break;
    }

    if (e->pos.x < arena.pos.x+1)
	e->pos.x = arena.pos.x+1;
    if (e->pos.x > arena.pos.x+arena.width-1)
	e->pos.x = arena.pos.x+arena.width-1;
    if (e->pos.y < arena.pos.y+1)
	e->pos.y = arena.pos.y+1;
    if (e->pos.y > arena.pos.y+arena.height-1)
	e->pos.y = arena.pos.y+arena.height-1;
}

void shoot(entity * bullets, int * bulletCount, entity player) {
    entity bullet = { .pos.x = player.pos.x, .pos.y = player.pos.y, .velocity = 1, .alive = 1};   

    bullets[(*bulletCount)++] = bullet;
}

void bullet_hit_invader(entity * bullets, int * bulletCount, const int INVADERCOUNT, int waves, entity invaders[][INVADERCOUNT]) {
    for (int i = 0; i < *bulletCount; i++) {
	for (int j = 0; j < waves; j++) {
	    for (int k = 0; k < INVADERCOUNT; k++) {
		if (invaders[j][k].alive && bullets[i].pos.x == invaders[j][k].pos.x && bullets[i].pos.y == invaders[j][k].pos.y) {
		    for (int l = i+1; l < *bulletCount; l++)
			bullets[k-l] = bullets[l];

		    (*bulletCount)--;

		    invaders[j][k].alive = 0;
		}
	    }
	}
    }
}

void bullet_hit_wall(entity * bullets, int * bulletCount, rect arena) {
    for (int i = 0; i < *bulletCount; i++) {
	if (bullets[i].pos.y == arena.pos.y+1) {
	    for (int j = i+1; j < *bulletCount; j++)
		bullets[j-1] = bullets[j];

	    (*bulletCount)--;
	}
    }
}

void wave_cleared(const int INVADERCOUNT, int waves, entity invaders[][INVADERCOUNT], int * cleared) {
    for (int i = 0; i < waves; i++) {
	for (int j = 0; j < INVADERCOUNT; j++) {
	    if (invaders[i][j].alive) return;
	}
    }

    (*cleared)++;
}
