#include <stdio.h>
#include<stdlib.h>
#include "pgm.h"
#include "constants.h"

int pgm_creat(pgmt** imagem, int height, int width) {
	int i;
	if (!imagem)
		return ERROR;
	if (width<0 || width>MAX_SIZE_IMAGE)
		return ERROR;
	if (height<0 || height>MAX_SIZE_IMAGE)
		return ERROR;
	(*imagem) = (pgmt*)calloc(1, sizeof(pgmt));
	(*imagem)->magic_number[0] = 'P';
	(*imagem)->magic_number[1] = '2';
	(*imagem)->magic_number[2] = '\0';
	(*imagem)->width = width;
	(*imagem)->height = height;
	(*imagem)->max_ton = 255;
	(*imagem)->pixels = (int**)calloc(height, sizeof(int*));
	for (i = 0; i < height; i++)
		(*imagem)->pixels[i] = (int*)calloc(width, sizeof(int));
	return SUCCESS;

}
int pgm_free(pgmt* imagem) {
	int i;
	if (!imagem)
		return ERROR;
	for (i = 0; i < imagem->height; i++)
		free(imagem->pixels[i]);
	free(imagem->pixels);
	free(imagem);
	return SUCCESS;
}
int pgm_save(pgmt* imagem, char* name) {
	if (!imagem)
		return ERROR;
	if (!name)
		return ERROR;
	int i, j;
	FILE* arquivo;
	arquivo = fopen(name, "w");
	fprintf(arquivo, "%s\n", imagem->magic_number);
	fprintf(arquivo, "%d %d\n", imagem->width, imagem->height);
	fprintf(arquivo, "%d\n", imagem->max_ton);
	for (i = 0; i < imagem->height; i++) {
		for (j = 0; j < imagem->width - 1; j++) {
			fprintf(arquivo, "%d ", imagem->pixels[i][j]);
		}
		if (i == imagem->height - 1)
			fprintf(arquivo, "%d", imagem->pixels[i][j]);
		else
			fprintf(arquivo, "%d\n", imagem->pixels[i][j]);
	}
	fclose(arquivo);
	return SUCCESS;
}

int pgm_set_pixel(pgmt* imagem, int height, int width, int color) {
	if (!imagem) return ERROR;
	if (color < 0 || color>255) return ERROR;
	if (height<0 || height> MAX_SIZE_IMAGE) return ERROR;
	if (width<0 || width>MAX_SIZE_IMAGE) return ERROR;
	if (height >= imagem->height) return ERROR;
	if (width >= imagem->width) return ERROR;
	imagem->pixels[height][width] = color;
	return SUCCESS;
}
