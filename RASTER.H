#ifndef RASTER_H
#define RASTER_H

#include "types.h"

/* [TO DO] the functions below are examples. Replace them! */

void plot_something_1(UINT16 *base, int x, int y, ...);
void plot_something_2(UINT32 *base, int x, int y, ...);
void plot_line(unsigned short x1, unsigned short y1, unsigned short x2, unsigned short y2, 
               short style, short mode);
void print_bitmap(UINT16 *base, int x, int y, const UINT16 *bitmap,
unsigned int height);
void fill_screen(long *base, char pattern);


               
#endif
