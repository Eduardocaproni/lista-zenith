#ifndef _DRAW_H
#define _DRAW_H
#include "pgm.h"
int pgm_line(pgmt * imagem, int x1, int y1, int x2, int y2, int color);
int pgm_circle(pgmt* imagem, int x, int y,int radius, int color);
int pgm_disk(pgmt* imagem, int xc, int yc, int radius, int color);
int pgm_rect(pgmt* imagem, int x, int y, int width, int height, int color);


int modulo(int x);

#endif
