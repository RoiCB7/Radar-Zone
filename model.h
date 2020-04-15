#ifndef MODEL_H
#define MODEL_H

#include <TYPES.H>

#define NUM_STATES 4
#define STATE_UP 0
#define STATE_DOWN 1
#define STATE_LEFT 2
#define STATE_RIGHT 3

#define X_LEFT 200
#define X_MID 300
#define X_RIGHT 400

#define Y_TOP 100
#define Y_MID 200
#define Y_BOT 300

/*
Class:Header class for model
Authors:Khris Bragas, Chris Botuli
Purpose:Creating the stuctures for both player and computer bot.
*/
typedef struct _Bitmap
{
    UINT16 *current_state;
    UINT16 *states[NUM_STATES];
} Bitmap;

typedef struct _PlayerBot
{
    Bitmap bm;
    int x_pos, y_pos, x_velocity, y_velocity;
} PlayerBot;

void change_velocity(PlayerBot *player, int x_vel, int y_vel);
void move_player(PlayerBot *player);
int player_collision(PlayerBot p1, PlayerBot p2);

#endif
