#include <stdio.h>
#include <linea.h>
#include <osbind.h>

#include <raster.h>
#include <renderer.h>
#include <model.h>
#include <types.h>
#include <stdlib.h>
#include <unistd.h>

#include <UP.C>
#include <DOWN.C>
#include <LEFT.C>
#include <RIGHT.C>

#include <LOSE.C>
#include <UP2.C>
#include <DOWN2.C>
#include <LEFT2.C>
#include <RIGHT2.C>
#include <SPLASH.C>

#define P1_START_X_POS X_LEFT
#define P1_START_Y_POS Y_TOP

#define P2_START_X_POS X_RIGHT - 16
#define P2_START_Y_POS Y_BOT - 8

#define BYTES_PER_SCREEN 32000

#define BASE_HI 0xFF8201
#define BASE_MI 0xFF8203

#define SCREEN_SIZE 32000
#define NUM_FRAME_BUFFERS 2
#define FRAMEBUFFER_PADDING_LEN 0x100
#define addr_roundup(addr, padding) ((((UINT32)(addr) + (1 << padding) - 1) >> padding) << padding)

/*
Project:Radar Zone
Authors:Khris Bragas, Chris Botuli
Course:Comp2659
Professor:Tyson Kendon

This the main class of our game where we are calling our made functions and calling
our other classes to implement a working video game.

Purpose:this game will load 2 bots one being a player another being an cpu bot player
The game will load a four by four box where the 2 players will be loaded.The goal is
to avoid the computer bot player that will be chasing you the longer you survive the more
points you will gain, but if the computer bot cathes you its game over,

Controls:Movement W,A,S,D for up,left,down, and right. Q to quit the game.

*/


char g_framebuffers[NUM_FRAME_BUFFERS][SCREEN_SIZE + FRAMEBUFFER_PADDING_LEN];

typedef struct _Screen
{
	int current_fb_index;

	UINT8 *logbase;
	UINT8 *framebuffs[NUM_FRAME_BUFFERS];
	UINT8 *orig_framebuffer;

} Screen;

void init_scr(Screen *screen);
void flip_buffers(Screen *screen);
void clean_screen(Screen *screen);
UINT32 *get_video_base(void);
void set_video_base(UINT32 *base);

int main(int argc, char *argv[])
{
	PlayerBot player, computer_player;
	Screen sc;

	int game_flag;
	char player_input;

	init_scr(&sc);
	/*Loding title screen*/
	fill_screen(sc.logbase, splash);
	flip_buffers(&sc);
	sleep(5);

	/*Starting possition of each player*/
	player.x_pos = P1_START_X_POS;
	player.y_pos = P1_START_Y_POS;
	player.x_velocity = player.y_velocity = 0;

	computer_player.x_pos = P2_START_X_POS;
	computer_player.y_pos = P2_START_Y_POS;
	computer_player.x_velocity = computer_player.y_velocity = 0;

	/*Loading states of each player*/
	player.bm.states[STATE_UP] = bm_up;
	player.bm.states[STATE_DOWN] = bm_down;
	player.bm.states[STATE_LEFT] = bm_left;
	player.bm.current_state = player.bm.states[STATE_RIGHT] = bm_right;

	computer_player.bm.states[STATE_UP] = bm_up;
	computer_player.bm.states[STATE_DOWN] = bm_down;
	computer_player.bm.states[STATE_LEFT] = bm_left;
	computer_player.bm.current_state = computer_player.bm.states[STATE_RIGHT] = bm_right;

	render_screen(&player, &computer_player, sc.logbase);
	flip_buffers(&sc);

	/*Main gane loop*/
	game_flag = 1;
	while (game_flag != 0)
	{
		if (Cconis() < 0)
		{
			switch (player_input = Cnecin()) /* p1 */
			{
			case 'w':
				player.bm.current_state = player.bm.states[STATE_UP];
				change_velocity(&player, 0, -16);
				break;
			case 'a':
				player.bm.current_state = player.bm.states[STATE_LEFT];
				change_velocity(&player, -16, 0);
				break;
			case 's':
				player.bm.current_state = player.bm.states[STATE_DOWN];
				change_velocity(&player, 0, 16);
				break;
			case 'd':
				player.bm.current_state = player.bm.states[STATE_RIGHT];
				change_velocity(&player, 16, 0);
				break;
			case 'q':
				game_flag = 0;
				break;
			}
			move_player(&player);
		}

		switch (rand() % 50) /* comp */
		{
		case 1:
			computer_player.bm.current_state = computer_player.bm.states[STATE_UP];
			change_velocity(&computer_player, 0, -16);
			break;
		case 2:
			computer_player.bm.current_state = computer_player.bm.states[STATE_LEFT];
			change_velocity(&computer_player, -16, 0);
			break;
		case 3:
			computer_player.bm.current_state = computer_player.bm.states[STATE_DOWN];
			change_velocity(&computer_player, 0, 16);
			break;
		case 4:
			computer_player.bm.current_state = computer_player.bm.states[STATE_RIGHT];
			change_velocity(&computer_player, 16, 0);
			break;
		}
		move_player(&computer_player);
		render_screen(&player, &computer_player, sc.logbase);
		flip_buffers(&sc);

		if (player_collision(player, computer_player))
		{
			fill_screen(sc.logbase, lose);
			flip_buffers(&sc);
			sleep(3);

			player.x_pos = P1_START_X_POS;
			player.y_pos = P1_START_Y_POS;
			player.x_velocity = player.y_velocity = 0;

			computer_player.x_pos = P2_START_X_POS;
			computer_player.y_pos = P2_START_Y_POS;
			computer_player.x_velocity = computer_player.y_velocity = 0;
		}
	}

	clean_screen(&sc);

	return 0;
}

/*
int_Scr
Purpose:Creates a second bufffer and will load in the image into buffer.
Input:The screen it will be doing this on.
*/
void init_scr(Screen *screen)
{
	int i;

	screen->current_fb_index = 0;
	screen->orig_framebuffer = (UINT8 *)get_video_base();

	for (i = 0; i != NUM_FRAME_BUFFERS; i++)
	{
		screen->framebuffs[i] = (UINT8 *)addr_roundup(g_framebuffers[i], 8);
		clear_screen(screen->framebuffs[i]);
	}

	screen->logbase = screen->framebuffs[screen->current_fb_index];
	flip_buffers(screen);
}

/*
flip_buffers
Purpose:Wil flip between old to the new buffers
Input:The screen that it will be doing this on.

*/
void flip_buffers(Screen *screen)
{
	set_video_base((UINT32 *)screen->logbase);
	screen->current_fb_index = (screen->current_fb_index + 1) % NUM_FRAME_BUFFERS;
	screen->logbase = screen->framebuffs[screen->current_fb_index];
}



/*
clean_screen
Purpose:Wil clear the screen.
Input:The screen that it will be doing this on.

*/
void clean_screen(Screen *screen)
{
	set_video_base((UINT32 *)screen->orig_framebuffer);
}


/*
*get_video_base
Purpose:Method to calculate the base of the screen.


*/
UINT32 *get_video_base(void)
{
	UINT32 base;
	UINT8 *mi;
	UINT8 *hi;

	long old_ssp = Super(0);

	mi = (UINT8 *)BASE_MI;
	hi = (UINT8 *)BASE_HI;
	base = (UINT32)*hi << 16 | (UINT32)*mi << 8;

	Super(old_ssp);

	return (UINT32 *)base;
}

/*
set_video_base
Purpose:Wil set the videos base.
Input:The base in unit32.

*/
void set_video_base(UINT32 *base)
{
	UINT8 mi;
	UINT8 hi;
	UINT8 *p_mi;
	UINT8 *p_hi;

	long old_ssp = Super(0);

	mi = (UINT8)((UINT32)base >> 8);
	hi = (UINT8)((UINT32)base >> 16);

	p_hi = (UINT8 *)BASE_HI;
	p_mi = (UINT8 *)BASE_MI;
	*p_hi = hi;
	*p_mi = mi;

	Super(old_ssp);
}
