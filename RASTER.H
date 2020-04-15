#ifndef RASTER_H
#define RASTER_H

#include <types.h>

/*
Class:Header class for RASTER
Authors:Khris Bragas, Chris Botuli
Purpose:Header for all the methods in RASTER.C
*/

void print_bitmap(UINT16 *base, int x, int y, const void *bitmap, unsigned int height);
void plot_vert_line(const void *base, int x0, int y0, int yf);
void plot_horiz_line(const void *base, int y0, int x0, int xf);
void plot_8_pixels(unsigned char *base, int x, int y);
void fill_screen(void *base, unsigned long *bm);
void plot_point(unsigned char *base, int x, int y);
extern void clear_screen(void *fb);

#endif
