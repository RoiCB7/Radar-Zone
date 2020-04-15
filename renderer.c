#include <renderer.h>
#include <raster.h>
#include <pbot.h>
#include <osbind.h>

/*
Class:renderer
Authors:Khris Bragas, Chris Botuli
Purpose:To render the compnents of our game
*/


/*
render_player
Purpose:Render the player bot
Input:PlayerBot *player, void *base.
Will take in the palyer and its base.
*/
void render_player(const PlayerBot *player, void *base)
{
    Vsync();
    print_bitmap((UINT16 *)base, player->x_pos, player->y_pos, player->bm.current_state, 16);
}

/*
render_computer_player
Purpose:Render the computer player bot
Input:PlayerBot *computer, void *base.
Will take in the computer player and its base.
*/
void render_computer_player(const PlayerBot *computer, void *base)
{
    Vsync();
    print_bitmap((UINT16 *)base, computer->x_pos, computer->y_pos, computer->bm.current_state, 16);
}


/*
render_rectangle
Purpose:Render a single rectagle
Input:Base,int length, int width, int x_pos, int y_pos.
Will take in the base length, width, and x and y coordinates of the rectanglr To
be rendered.
*/
void render_rectangle(const void *base, int length, int width, int x_pos, int y_pos)
{
    int x0 = x_pos;
    int xf = x0 + width;
    int y0 = y_pos;
    int yf = y_pos + length;

    plot_vert_line(base, x0, y0, yf);
    plot_vert_line(base, xf, y0, yf);
    plot_horiz_line(base, y0, x0, xf);
    plot_horiz_line(base, yf, x0, xf);
}

/*
render_screen
Purpose:Render the screen with the 2 players and the grid theyll be on.
Input:PlayerBot *player, PlayerBot *computer, void*base
Will take in the 2 players and the base.
*/
void render_screen(const PlayerBot *player, const PlayerBot *computer, void *base)
{
    Vsync();
    clear_screen(base);

    render_rectangle(base, 100, 100, 200, 100);
    render_rectangle(base, 100, 100, 200, 200);
    render_rectangle(base, 100, 100, 300, 100);
    render_rectangle(base, 100, 100, 300, 200);

    render_player(player, base);

    render_computer_player(computer, base);
}
