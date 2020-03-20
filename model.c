#include <stdio.h>
#include <linea.h>
#include <osbind.h>
#include "model.h"

void move_player(PlayerBot *player)
{
player->x += player->delta_x;
player->y += player->delta_y;

} 