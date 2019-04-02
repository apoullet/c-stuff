#include "game.h"
#include <stdlib.h>
#include <time.h>

void move_snake(snake * player) {
    int new_limb[2];

    switch (player->move) {
	case UP:
	    new_limb[0] = player->body[player->limb_count-1][0]-1;    
	    new_limb[1] = player->body[player->limb_count-1][1];    
	    break;
	
	case RIGHT:
	    new_limb[0] = player->body[player->limb_count-1][0];    
	    new_limb[1] = player->body[player->limb_count-1][1]+1;    
	    break;
	
	case DOWN:
	    new_limb[0] = player->body[player->limb_count-1][0]+1;    
	    new_limb[1] = player->body[player->limb_count-1][1];    
	    break;

	case LEFT:
	    new_limb[0] = player->body[player->limb_count-1][0];    
	    new_limb[1] = player->body[player->limb_count-1][1]-1;    
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

void move_cherry(cherry * goal) {
    srand(time(NULL));

    goal->x = 1 + rand() % 28;
    goal->y = 1 + rand() % 18;
}
