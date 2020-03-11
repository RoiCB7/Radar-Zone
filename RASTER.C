 #include "raster.h"
#include <stdio.h>
#include <linea.h>
#include <osbind.h>

#define SOLID 0xFFFF
#define XOR		2


void plot_something_1(UINT16 *base, int x, int y, ...)
{
	/* [TO DO] delete this example function */
}

void plot_line(unsigned short x1, unsigned short y1,
			   unsigned short x2, unsigned short y2,
			   short style, short mode)
			   {
X1 = x1;
Y1 = y1;
X2 = x2;
Y2 = y2;
LNMASK =style;
WMODE = mode;
LSTLIN =0;
linea3();			   			   	   
}

void print_bitmap(UINT16 *base, int x, int y, const UINT16 *bitmap,
unsigned int height)
{
int i;
int offset;

offset = (x>>4) + (y*40);
for(i=0; i < height; i++)*(base + offset + (40*i)) |= bitmap[i];

return;

}

void fill_screen(long *base, char pattern){
	register int i =0;
	register long *loc = base;

	while(i++ < 32000)
		*(loc++) = pattern;
}
