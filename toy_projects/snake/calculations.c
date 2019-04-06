#include "game.h"
#include <stdlib.h>
#include <time.h>

snake * init_snake(snake * player, rect arena) {
    player = malloc(sizeof(*player));

    player->body[0][0] = arena.pos.x+arena.width;
    player->body[0][1] = arena.pos.y+arena.height;
    player->limb_count = 1;
    player->growing    = 0;
    player->move       = NONE;

    return player;
}

void move_snake(snake * player) {
    int new_limb[2];

    switch (player->move) {
	case UP:
	    new_limb[0] = player->body[player->limb_count-1][0];    
	    new_limb[1] = player->body[player->limb_count-1][1]-1;    
	    break;
	
	case RIGHT:
	    new_limb[0] = player->body[player->limb_count-1][0]+1;    
	    new_limb[1] = player->body[player->limb_count-1][1];    
	    break;
	
	case DOWN:
	    new_limb[0] = player->body[player->limb_count-1][0];    
	    new_limb[1] = player->body[player->limb_count-1][1]+1;    
	    break;

	case LEFT:
	    new_limb[0] = player->body[player->limb_count-1][0]-1;    
	    new_limb[1] = player->body[player->limb_count-1][1];    
	    break;

	default:
	    new_limb[0] = player->body[player->limb_count-1][0];    
	    new_limb[1] = player->body[player->limb_count-1][1];    
	    break;
    }

    if (player->growing) {
	player->growing = 0;
	player->limb_count++;
    } else {
	for (int i = 1; i < player->limb_count; i++) {
	    player->body[i-1][0] = player->body[i][0];
	    player->body[i-1][1] = player->body[i][1];
	}
    }

    player->body[player->limb_count-1][0] = new_limb[0];
    player->body[player->limb_count-1][1] = new_limb[1];
}

void grow_snake(snake * player) {
    player->growing = 1;
}

void hit_wall(snake * player, rect arena) {
    for (int i = 0; i < player->limb_count; i++) {
	if (player->body[i][0] < arena.pos.x+1)
	    player->body[i][0] = arena.pos.x+arena.width-2;
	if (player->body[i][0] > arena.pos.x+arena.width-2)
	    player->body[i][0] = arena.pos.x+1;
	if (player->body[i][1] < arena.pos.y+1)
	    player->body[i][1] = arena.pos.y+arena.height-2;
	if (player->body[i][1] > arena.pos.y+arena.height-2)
	    player->body[i][1] = arena.pos.y+1;
    }
}

int collision(snake player) {
    int * head = player.body[player.limb_count-1];

    for (int i = 0; i < player.limb_count-1; i++)
	if (head[0] == player.body[i][0] && head[1] == player.body[i][1]) return 1;

    return 0;
}

void move_cherry(vec2d * goal, rect arena) {
    srand(time(NULL));

    goal->x = arena.pos.x+1 + rand() % (arena.width-2);
    goal->y = arena.pos.y+1 + rand() % (arena.height-2);
}

void init_rect(rect * rectangle, int x, int y, int width, int height) {
    rectangle->pos.x  = x-width/2;
    rectangle->pos.y  = y-height/2;
    rectangle->width  = width;
    rectangle->height = height;
}
