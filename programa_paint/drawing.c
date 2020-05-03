#include <stdio.h>
#include "pgm.h"
#include "constants.h"
#include "drawing.h"
#include <math.h>

int pgm_line(pgmt* imagem,int x1, int y1, int x2, int y2, int color) {
	if (!imagem) return ERROR;
	int i, teste;
	int x_1, x_2, y_1, y_2;
	int delta_y = y2 - y1;
	int delta_x = x2 - x1;
	float tg;
	if (modulo(delta_x) > modulo(delta_y)) {
		if (x1 < x2) {
			tg = (float)delta_y / delta_x;
			for (i = x1; i < x2; i++) {
				pgm_set_pixel(imagem, i, y1 + (i-x1) * tg, color);
			}
		}
		else {
			x_1 = x2;
			x_2 = x1;
			y_1 = y2;
			y_2 = y1;
			tg = (float)(y_2 - y_1) / (x_2 - x_1);
			for (i = x_1; i < x_2; i++) {
				pgm_set_pixel(imagem, i,(int)y_1 +(i-x_1) * tg, color);
			}
		}
	}
	else{
		if (y1 < y2) {
			tg = (float)delta_x / delta_y;
			for (i = y1; i < y2; i++) {
				pgm_set_pixel(imagem,(int)x1 + (i-y1) * tg, i, color);
			}
		}
		else {
			x_1 = x2;
			x_2 = x1;
			y_1 = y2;
			y_2 = y1;
			tg = (float)(x_2 - x_1) / (y_2 - y_1);
			for (i = y_1; i < y_2; i++) {
				pgm_set_pixel(imagem, x_1  + (i-y_1) * tg , i, color);
			}
		}
	}
	return SUCCESS;
}

int pgm_circle(pgmt* imagem, int xc, int yc, int radius, int color) {
	if (radius < 0) return ERROR;
	if (!imagem) return ERROR;
	int x, y;
	for (x =xc - radius; x < xc + radius; x++) {
		pgm_set_pixel(imagem, x, yc + sqrt(pow(radius, 2) - pow(x - xc, 2)), color);
		pgm_set_pixel(imagem, x, yc - sqrt(pow(radius, 2) - pow(x - xc, 2)), color);
	}
	for (y = yc - radius; y < yc + radius; y++) {
		pgm_set_pixel(imagem, xc + sqrt(pow(radius, 2) - pow(y - yc, 2)), y, color);
		pgm_set_pixel(imagem, xc - sqrt(pow(radius, 2) - pow(y - yc, 2)), y, color);
	}
	return SUCCESS;
}
int pgm_disk(pgmt* imagem, int xc, int yc, int radius, int color) {
	if (!imagem) return ERROR;
	if (radius < 0) return ERROR;
	int x, y;
	for (x = xc - radius; x < xc + radius; x++) {
		for (y = yc - radius; y < yc + radius; y++) {
			if(pow(x-xc,2)+pow(y-yc,2)<pow(radius, 2)){
				pgm_set_pixel(imagem, x, y, color);
			}
		}
	}

	return SUCCESS;
}
int pgm_rect(pgmt* imagem, int x, int y, int width, int height, int color) {
	if (!imagem) return ERROR;
	if (height < 0) return ERROR;
	if (width < 0) return ERROR;
	int i;
	for (i = y - width / 2; i < y + width / 2; i++) {
		pgm_set_pixel(imagem, x + height / 2, i, color);
		pgm_set_pixel(imagem, x - height / 2, i, color);
	}
	for (i = x - height / 2; i < x + height / 2; i++) {
		pgm_set_pixel(imagem, i, y + width / 2, color);
		pgm_set_pixel(imagem, i, y - width / 2, color);
	}


	return SUCCESS;
}

int modulo(int x) {
	if (x < 0) return -x;
	return x;
}