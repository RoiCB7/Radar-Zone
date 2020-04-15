/*
Class: right.C
Authors: Khris Bragas, Chris Botuli
Purpose: Bitmap for the bot facing right.
*/
int g_right_height = 16; /* height in bits */
int g_right_width = 16;	 /* width in bits */
int g_right_size = 64;	 /* total bytes */

const UINT16 bm_right[] = {
	0x0f00,
	0x0f80,
	0x0ff0,
	0x1ff8,
	0x3ffc,
	0x7ffe,
	0xffff,
	0xf81f,
	0xf81f,
	0xffff,
	0x7ffe,
	0x3ffc,
	0x1ff8,
	0x0ff0,
	0x0f80,
	0x0f00,
}; 
