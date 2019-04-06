#include "game.h"
#include <stdlib.h>
#include <time.h>

void move_snake(snake * player) {
    vec2d new_limb;

    switch (player->move) {
	case UP:
	    new_limb.x = player->body[player->limb_count-1].x;    
	    new_limb.y = player->body[player->limb_count-1].y-1;    
	    break;
	
	case RIGHT:
	    new_limb.x = player->body[player->limb_count-1].x+1;    
	    new_limb.y = player->body[player->limb_count-1].y;    
	    break;
	
	case DOWN:
	    new_limb.x = player->body[player->limb_count-1].x;    
	    new_limb.y = player->body[player->limb_count-1].y+1;    
	    break;

	case LEFT:
	    new_limb.x = player->body[player->limb_count-1].x-1;    
	    new_limb.y = player->body[player->limb_count-1].y;    
	    break;

	default:
	    new_limb.x = player->body[player->limb_count-1].x;    
	    new_limb.y = player->body[player->limb_count-1].y;    
	    break;
    }

    if (player->growing) {
	player->growing = 0;
	player->limb_count++;
    } else {
	for (int i = 1; i < player->limb_count; i++) {
	    player->body[i-1].x = player->body[i].x;
	    player->body[i-1].y = player->body[i].y;
	}
    }

    player->body[player->limb_count-1].x = new_limb.x;
    player->body[player->limb_count-1].y = new_limb.y;
}

void hit_wall(snake * player, rect arena) {
    for (int i = 0; i < player->limb_count; i++) {
	if (player->body[i].x < arena.pos.x+1)
	    player->body[i].x = arena.pos.x+arena.width-2;
	if (player->body[i].x > arena.pos.x+arena.width-2)
	    player->body[i].x = arena.pos.x+1;
	if (player->body[i].y < arena.pos.y+1)
	    player->body[i].y = arena.pos.y+arena.height-2;
	if (player->body[i].y > arena.pos.y+arena.height-2)
	    player->body[i].y = arena.pos.y+1;
    }
}

int collision(snake player) {
    vec2d head = player.body[player.limb_count-1];

    for (int i = 0; i < player.limb_count-1; i++)
	if (head.x == player.body[i].x && head.y == player.body[i].y) return 1;

    return 0;
}

void move_cherry(vec2d * goal, rect arena) {
    srand(time(NULL));

    goal->x = arena.pos.x+1 + rand() % (arena.width-2);
    goal->y = arena.pos.y+1 + rand() % (arena.height-2);
}
