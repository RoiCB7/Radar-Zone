#include <stdio.h>
#include <linea.h>
#include <osbind.h>

#include "renderer.h"
#include "model.h"
#include "raster.h"



void render_player(const PlayerBot *player, UINT16 *base){
    print_bitmap(base, player->x, player->y, playerBot, 16);

}