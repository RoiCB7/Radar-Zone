#include <stdio.h>
#include <linea.h>
#include <osbind.h>
#include "raster.h"
#include "model.h"
#include "renderer.h"

#define SOLID 0xFFFF
#define XOR		2
#define BYTES_PER_SCREEN 32000


int main()
{
	int i =0;
	UINT16 *base = Physbase();
	long *base2 = Physbase(); 

	PlayerBot player;

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
		print_bitmap(base, 303, 35, enemyBot, 16);		/*enemy bot*/

	player.x = 303;
	player.y = 250;

	player.delta_x = 0;
	player.delta_y = 0; /*was -1*/


	render_player(&player, base);

	for (i =0; i <= 10; i++){
		player.delta_x += i;
		move_player(&player);
	}
	
	render_player(&player, base);

	Cnecin();
	return 0;
}
	




/*
	player.delta_x = 100;
	move_player(&player);
	print_bitmap(base, player.x, player.y, playerBot, 16);*/



/*
	for(i = player.x; i <= 304; i++)
	{
		player.delta_x = i;
		move_player(&player);
		print_bitmap(base, player.x, player.y, playerBot, 16);

	}*/