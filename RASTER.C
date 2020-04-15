
#include <stdio.h>
#include <linea.h>
#include <osbind.h>
#include <raster.h>
#include <types.h>

#define alignto(p, bits) (((p) >> (bits)) << (bits))
#define aligntonext(p, bits) alignto(((p) + (1 << (bits)) - 1), (bits))

/*
Class:Raster
Authors:Khris Bragas, Chris Botuli
Purpose:Creating the basic image components of game.

*/


/*
plot_vert_line
Purpose:Creating a vertical line.
Input:Base,Int x, Int y, and int yf
*/
void plot_vert_line(const void *base, int x0, int y0, int yf)
{
	int i;
	yf = aligntonext(yf, 3);
	y0 = aligntonext(y0, 3);
	x0 = aligntonext(x0, 3);

	if (y0 == yf)
	{
		plot_point((unsigned char *)base, x0, y0);
		return;
	}

	if (y0 > yf)
	{
		y0 ^= yf;
		yf ^= y0;
		y0 ^= yf;
	}

	for (i = y0; i < yf; i += 8)
		plot_8_pixels((unsigned char *)base, x0, i);
}


/*
plot_horiz_line
Purpose:Creating a horizontal line.
Input:Base,Int y, Int x, and int xf
*/
void plot_horiz_line(const void *base, int y0, int x0, int xf)
{
	int i, offset;

	unsigned char *b8 = (unsigned char *)base;

	y0 = aligntonext(y0, 3);
	x0 = aligntonext(x0, 3);
	xf = aligntonext(xf, 3);

	if (x0 == xf)
	{
		plot_point((unsigned char *)base, x0, y0);
		return;
	}

	if (x0 > xf)
	{
		x0 ^= xf;
		xf ^= x0;
		x0 ^= xf;
	}

	for (i = x0; i < xf; i++)
	{
		offset = (y0 * 80) + (i >> 3);
		b8[offset] |= 0xff;
	}
}

/*
plot_point
Purpose:Creating a single plot point.
Input:Base,Int x, Int y. The x and y coordinates for the point.
*/
void plot_point(unsigned char *base, int x, int y)
{
	int offset = (y * 80) + (x >> 3);
	base[offset] |= 0x80;
}


/*
plot_8_pixels
Purpose:Plotting 8 pixels.
Input:Base,Int x, Int y. The x and y coordinates for the pixels.
*/
void plot_8_pixels(unsigned char *base, int x, int y)
{
	int i, offset;
	x >>= 3;

	for (i = 0; i < 8; i++)
	{
		offset = ((y + i) * 80) + (x);
		base[offset] |= 0x80;
	}
}


/*
print_bitmap
Purpose:Creating a bit map of unit size 16
Input:Base,Int x, Int y. The x and y coordinates for the bitmap
unsigned int height for the height of the bitmap.
*/
void print_bitmap(UINT16 *base, int x, int y, const void *bitmap, unsigned int height)
{
	int i, x_offset, y_offset;
	UINT16 *fb = base;
	UINT16 *bm = bitmap;

	x_offset = x >> 4;
	y_offset = (640 >> 4);

	for (i = 0; i < height; i++)
		base[((i + y) * y_offset) + x_offset] |= bm[i];
}

void fill_screen(void *base, unsigned long *bm)
{
	register int i;
	register unsigned long *loc = (UINT32 *)base;

	for (i = 0; i < 8000; i++)
		loc[i] = bm[i];
}
