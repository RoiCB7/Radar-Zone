/*
Class: up.C
Authors: Khris Bragas, Chris Botuli
Purpose: Bitmap for the bot facing up.
*/
int g_up_height = 16; /* height in bits */
int g_up_width = 16;  /* width in bits */
int g_up_size = 64;	  /* total bytes */

const UINT16 bm_up[] = {
	0x03c0,
	0x07e0,
	0x0ff0,
	0x1ff8,
	0x3ffc,
	0x3e7c,
	0x3e7c,
	0x7e7e,
	0xfe7f,
	0xfe7f,
	0xfe7f,
	0xffff,
	0x1ff8,
	0x0ff0,
	0x07e0,
	0x03c0,
};
