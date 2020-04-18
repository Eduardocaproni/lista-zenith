#include <stdio.h>
#include <math.h>
#include "biblioteca.h"



float fmedia(int* vetor) {
	float media = 0;
	int i;
	for (i = 0; i < 3; i++) {
		media += vetor[i];
	}
	return media / 3;
}

float fsoma(int* vetor) {
	int soma = 0;
	int i;
	for (i = 0; i < 3; i++) {
		soma += vetor[i];
	}
	return soma;
}

float fdesviop(int* vetor, float media) {
	int desviop = 0;
	int i;
	for (i = 0; i < 3; i++) {
		desviop += pow((vetor[i] - media), 2);
	}
	desviop = sqrt((desviop / 2), 2);

	return desviop;
}