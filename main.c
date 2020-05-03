#include <stdio.h>
#include <stdlib.h>
#include "drawing.h"
#include "pgm.h"
#include "constants.h"
int main() {
	int height, width;
	int choice;
	int x1, y1, x2, y2;
	int color;
	int radius;
	char* name;
	name = (char*)malloc(20 * sizeof(char));
	pgmt* imagem;
	do {
		do {
			printf("digite a largura da imagem que deseja criar: ");
			scanf("%d", &width);
			printf("digite a altura da imagem:");
			scanf("%d", &height);
			if (pgm_creat(&imagem, height, width) == -1) printf("ERRO! Digite os dados novamente\n");
			else printf("Imagem criada!!\n");
		} while (pgm_creat(&imagem, height, width) == -1);
		do {
			printf("---------------------------------------------------------\n1 - reta;\n2 - circulo;\n3 - disco;\n4 - retangulo;\n0 - se nao deseja criar.\n");
			printf("---------------------------------------------------------\n");
			printf("digite o numero do objeto que deseja incluir na sua imagem:\n");
			scanf("%d", &choice);
			switch (choice) {
			case 1:
				printf("digite o numero de tom de cinza da reta: ");
				scanf("%d", &color);
				printf("digite a coordenada x e y do primeiro ponto da reta: ");
				scanf("%d%d", &x1, &y1);
				printf("digite a coordenada x e y do segundo ponto da reta: ");
				scanf("%d%d", &x2, &y2);
				if (pgm_line(imagem, x1, y1, x2, y2, color) == -1) printf("Erro ao inserir reta\n");
				else printf("reta inserida com sucesso\n");
				break;
			case 2:
				printf("digite o numero do tom de cinza: ");
				scanf("%d", &color);
				printf("digite as coordenadas x e y do centro do circulo: ");
				scanf("%d%d", &x1, &y1);
				printf("digite o raio do circulo: ");
				scanf("%d", &radius);
				if (pgm_circle(imagem, x1, y1, radius, color) == -1) printf("nao foi possivel inserir circulo\n");
				else printf("ciruculo inserido com sucesso\n");
				break;
			case 3:
				printf("digite o numero do tom de cinza: ");
				scanf("%d", &color);
				printf("digite as coordenadas x e y do centro do disco:");
				scanf("%d%d", &x1, &y1);
				printf("digite o raio do disco: ");
				scanf("%d", &radius);
				if (pgm_disk(imagem, x1, y1, radius, color) == -1) printf("nao foi possivel inserir disco\n");
				else printf("disco inserido com sucesso\n");
				break;
			case 4:
				printf("digite o numero do tom de cinza: ");
				scanf("%d", &color);
				printf("digite as coordenadas x e y do centro do retangulo: ");
				scanf("%d%d", &x1, &y1);
				printf("digite a largura e depois altura do retangulo: ");
				scanf("%d%d", &width, &height);
				if (pgm_rect(imagem, x1, y1, width, height, color) == -1) printf("nao foi possivel inserir retangulo\n");
				else printf("retangulo inserido com sucesso\n");
				break;
			case 0:
				break;
			default:
				printf("\ndigito invalido!\n\n");
			}
		} while (choice != 0);
		printf("escreva o nome com que deseja salvar o artigo: ");
		scanf("%s", name);

		if (pgm_save(imagem, name) == -1)printf("erro ao salvar\n");
		else printf("arquivo salvo com sucesso!\n");
		free(name);
		printf("liberando memoria...\n");
		if (pgm_free(imagem) == -1)printf("erro ao liberar memoria\n");
		else printf("memoria liberada com sucesso!\n");
		printf("se deseja criar outra imagem digite 1, se deseja fechar o programa digite outro: ");
		scanf("%d", &choice);
	} while (choice == 1);
	

	

	return 0;
}
