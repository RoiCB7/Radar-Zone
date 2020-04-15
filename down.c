/*
Class: down.C
Authors: Khris Bragas, Chris Botuli
Purpose: Bitmap for the bot facing down.
*/
int g_down_height = 16; /* height in bits */
int g_down_width = 16;	/* width in bits */
int g_down_size = 64;	/* total bytes */

const UINT16 bm_down[] = {
	0x03c0,
	0x07e0,
	0x0ff0,
	0x1ff8,
	0xffff,
	0xfe7f,
	0xfe7f,
	0xfe7f,
	0x7e7e,
	0x3e7c,
	0x3e7c,
	0x3ffc,
	0x1ff8,
	0x0ff0,
	0x07e0,
	0x03c0,
};
