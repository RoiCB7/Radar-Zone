#ifndef RENDERER_H
#define RENDERER_H

#include <model.h>

/*
Class:Header class for renderer
Authors:Khris Bragas, Chris Botuli
Purpose:Header for all the methods in renderer.c
*/

void render_rectangle(const void *base, int length, int width, int x_pos, int y_pos);
void render_screen(const PlayerBot *player, const PlayerBot *computer, void *base);
void render_computer_player(const PlayerBot *computer, void *base);
void render_player(const PlayerBot *player, void *base);

#endif