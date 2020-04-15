#include <stdio.h>
#include <linea.h>
#include <osbind.h>

#include <model.h>

/*
Class:PlayerBot header file.
Authors:Khris Bragas, Chris Botuli
Purpose:Creating the bitmap for the pplayer bot in base 16.
*/



void move_player(PlayerBot *player)
{
	int temp_x, temp_y;

	/* x pos first */

	if (player->x_pos + player->x_velocity >= X_LEFT && player->x_pos + player->x_velocity <= X_RIGHT &&
		((player->y_pos == Y_TOP) ||
		 (player->y_pos >= Y_MID - 16 && player->y_pos <= Y_MID) ||
		 (player->y_pos >= Y_BOT - 16 && player->y_pos <= Y_BOT + 16)))
		player->x_pos += player->x_velocity;

	/* y pos next */
	if (player->y_pos + player->y_velocity >= Y_TOP && player->y_pos + player->y_velocity <= Y_BOT &&
		((player->x_pos == X_LEFT) ||
		 (player->x_pos >= X_MID - 16 && player->x_pos <= X_MID + 16) ||
		 (player->x_pos >= X_RIGHT - 16 && player->x_pos <= X_RIGHT + 16)))
		player->y_pos += player->y_velocity;
}

void change_velocity(PlayerBot *player, int x_vel, int y_vel)
{
	player->x_velocity = x_vel;
	player->y_velocity = y_vel;
}

int player_collision(PlayerBot p1, PlayerBot p2)
{
	return (p1.x_pos > p2.x_pos && p1.x_pos <= p2.x_pos + 16 && p1.y_pos == p2.y_pos);
}