#include <stdio.h>
#include <linea.h>
#include <osbind.h>
#include "raster.h"

#define SOLID 0xFFFF
#define XOR		2
#define HEIGHT 16
#define BYTES_PER_SCREEN 32000

const UINT16 playerBot [HEIGHT] = {
	0x0000,
	0x0000,
	0x0000,
	0x0810,
	0x0420,
	0x0FF0,
	0x1998,
	0x3FFC,
	0x2FF4,
	0x2FF4,
	0x2814,
	0x0420,
	0x0000,
	0x0000,
	0x0000,
	0x0000	
};

const UINT16 enemyBot [HEIGHT] = {
	0x0000,
	0x0000,
	0x0000,
	0x0380,
	0x0100,
	0x27C8,
	0x2FE8,
	0x3C78,
	0x0820,
	0x3C78,
	0x2FE8,
	0x27C8,
	0x0440,
	0X06C0,
	0x0000,
	0x0000
};


int main()
{
	int y =0;
	int x =0;
	UINT16 *base = Physbase();
	long *base2 = Physbase(); 

	
	printf("\033E\033f\n"); /*delete this and the next line and make our own fill screen*/
	/*fill_screen(base2, 0);*/
	linea0();				/*delete this too*/
	
	/*make our own fill screen*/
	
			plot_line(100, 50, 500, 50, SOLID, XOR);	/*Horizontal*/
			Vsync();
			plot_line(300, 50, 300, 250, SOLID, XOR); 	/*Vertical*/
			Vsync();
			plot_line(100, 250, 500, 250, SOLID, XOR); 	/*bottom horizontal*/
			Vsync();
			plot_line(100, 50, 100, 250, SOLID, XOR); 	/*left vertical*/
			plot_line(500, 50, 500, 250, SOLID, XOR); 	/*right vertical*/
				
		print_bitmap(base, 303, 250, playerBot, 16);	/*player bot*/
		print_bitmap(base, 303, 35, enemyBot, 16);		/*enemy bot*/

	Cnecin();
	return 0;
}