#include <stdio.h>
#include <math.h>
#include <inttypes.h>

float fmedia(uint8_t* vetor);
float fsoma(uint8_t* vetor);
float fdesviop(uint8_t* vetor, float media);

int main() {
	uint8_t dados[3];
	float soma=0, media=0, desviop=0;
	FILE* arq_bin;
	arq_bin = fopen("dados3.bin", "rb");
	if (!arq_bin) {
		printf("ERRO!");
		return -1;
	}
	fread(&dados, sizeof(uint8_t), 3, arq_bin);
	printf("%" PRIu8 "\n", dados[0]);
	printf("%" PRIu8 "\n", dados[1]);
	printf("%" PRIu8 "\n",dados[2]);

	soma = fsoma(dados);
	media = fmedia(dados);
	desviop = fdesviop(dados, media);
	printf("soma= %.2lf, media= %.2lf, desvio padrao: %.2lf\n", soma, media, desviop);
	
	fclose(arq_bin);
	
	return 0;
}


float fmedia(uint8_t* vetor) {
	float media = 0;
	int i;
	for (i = 0; i < 3; i++) {
		media += vetor[i];
	}
	return media / 3;
}


float fsoma(uint8_t* vetor) {
	int soma = 0;
	int i;
	for (i = 0; i < 3; i++) {
		soma += vetor[i];
	}
	return soma;
}


float fdesviop(uint8_t* vetor, float media) {
	int desviop = 0;
	int i;
	for (i = 0; i < 3; i++) {
		desviop += pow((vetor[i] - media), 2);
	}
	desviop = sqrt((desviop / 2), 2);

	return desviop;
}