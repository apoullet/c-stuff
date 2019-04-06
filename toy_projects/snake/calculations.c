#include "game.h"
#include <stdlib.h>
#include <time.h>

void init_snake(snake * player, int x, int y) {
    player->body[0][0] = x;
    player->body[0][1] = y;
    player->limb_count = 1;
    player->growing    = 0;
    player->move       = NONE;
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

void hit_wall(snake * player, vec2d arena) {
    int width = arena.x, height = arena.y;

    for (int i = 0; i < player->limb_count; i++) {
	if (player->body[i][0] < 1)
	    player->body[i][0] = width-2;
	if (player->body[i][0] > width-2)
	    player->body[i][0] = 1;
	if (player->body[i][1] < 1)
	    player->body[i][1] = height-2;
	if (player->body[i][1] > height-2)
	    player->body[i][1] = 1;
    }
}

int collision(snake player) {
    int * head = player.body[player.limb_count-1];

    for (int i = 0; i < player.limb_count-1; i++)
	if (head[0] == player.body[i][0] && head[1] == player.body[i][1]) return 1;

    return 0;
}

void move_cherry(vec2d * goal, vec2d arena) {
    srand(time(NULL));

    goal->x = 1 + rand() % (arena.x-2);
    goal->y = 1 + rand() % (arena.y-2);
}
