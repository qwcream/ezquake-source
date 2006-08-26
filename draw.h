/*
Copyright (C) 1996-1997 Id Software, Inc.

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  

See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

*/

// draw.h -- these are the only functions outside the refresh allowed
// to touch the vid buffer

#include "wad.h"

#ifdef GLQUAKE
typedef struct
{
	int			width, height;
	int			texnum;
	float		sl, tl, sh, th;
} mpic_t;
#else
typedef struct
{
	int			width;
	short		height;
	byte		alpha;
	byte		pad;
	byte		data[4];	// variable sized
} mpic_t;
#endif

extern	mpic_t		*draw_disc;	// also used on sbar

void Draw_Init (void);
void Draw_Character (int x, int y, int num);
void Draw_SubPic(int x, int y, mpic_t *pic, int srcx, int srcy, int width, int height);
void Draw_Pic (int x, int y, mpic_t *pic);
void Draw_TransPic (int x, int y, mpic_t *pic);
void Draw_TransSubPic (int x, int y, mpic_t *pic, int srcx, int srcy, int width, int height);
void Draw_TransPicTranslate (int x, int y, mpic_t *pic, byte *translation);
void Draw_ConsoleBackground (int lines);
void Draw_BeginDisc (void);
void Draw_EndDisc (void);
void Draw_TileClear (int x, int y, int w, int h);
void Draw_Fill (int x, int y, int w, int h, int c);
void Draw_FadeBox (int x, int y, int width, int height, float r, float g, float b, float a); // HUD -> hexum
void Draw_FadeScreen (void);
void Draw_String (int x, int y, char *str);
void Draw_Alt_String (int x, int y, char *str);
void Draw_ColoredString (int x, int y, char *str, int red);
mpic_t *Draw_CachePicSafe (char *path, qbool true);
mpic_t *Draw_CachePic (char *path);
mpic_t *Draw_CacheWadPic (char *name);
void Draw_Crosshair(void);
void Draw_TextBox (int x, int y, int width, int lines);

// HUD -> hexum
void Draw_SCharacter (int x, int y, int num, float scale);
void Draw_SString (int x, int y, char *str, float scale);
void Draw_SAlt_String (int x, int y, char *str, float scale);
void Draw_SPic (int x, int y, mpic_t *, float scale);
void Draw_SAlphaPic (int x, int y, mpic_t *, float alpha, float scale);
void Draw_SSubPic(int x, int y, mpic_t *, int srcx, int srcy, int width, int height, float scale);
void Draw_STransPic (int x, int y, mpic_t *, float scale);
void Draw_SFill (int x, int y, int w, int h, int c, float scale);

// HUD -> Cokeman
void Draw_AlphaPieSlice (int x, int y, float radius, float startangle, float endangle, float thickness, qbool fill, int c, float alpha);
void Draw_AlphaFill (int x, int y, int w, int h, int c, float alpha);
void Draw_AlphaCircle (int x, int y, float radius, float thickness, qbool fill, int c, float alpha);
void Draw_AlphaCircleOutline (int x, int y, float radius, float thickness, int color, float alpha);
void Draw_AlphaCircleFill (int x, int y, float radius, int color, float alpha);
void Draw_CircleOutline (int x, int y, float radius, float thickness, int color);
void Draw_CircleFill (int x, int y, float radius, int color);
void Draw_AlphaLine (int x_start, int y_start, int x_end, int y_end, float thickness, int c, float alpha);
void Draw_Line (int x_start, int y_start, int x_end, int y_end, float thickness, int c);
void Draw_AlphaOutline (int x, int y, int w, int h, int c, float thickness, float alpha);
void Draw_Outline (int x, int y, int w, int h, int c, float thickness);
void Draw_AlphaSubPic (int x, int y, mpic_t *pic, int srcx, int srcy, int width, int height, float alpha);
void Draw_SAlphaSubPic (int x, int y, mpic_t *gl, int srcx, int srcy, int width, int height, float scale, float alpha);
void Draw_SAlphaSubPic2 (int x, int y, mpic_t *gl, int srcx, int srcy, int width, int height, float scale_x, float scale_y, float alpha);
void Draw_AlphaPic (int x, int y, mpic_t *pic, float alpha);
