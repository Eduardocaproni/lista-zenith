#ifndef _IMAGEM_PGM
#define _IMAGEM_PGM
struct PGM {
	char magic_number[3];
	int width, height;
	int max_ton;
	int** pixels;
	
};
typedef struct PGM pgmt;
int pgm_creat(pgmt** imagem, int height, int width);
int pgm_free(pgmt* imagem);
int pgm_save(pgmt* imagem, char*);
int pgm_set_pixel(pgmt* imagem, int height, int width, int color);

#endif 
