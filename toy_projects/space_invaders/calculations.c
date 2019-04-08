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
