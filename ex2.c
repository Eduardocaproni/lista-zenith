#include <stdio.h>
#include <math.h>

float fmedia(int* vetor, int N);
float fsoma(int* vetor, int N);
float fdesviop(int* vetor, int N, float media);

int main() {
	int N, i, *vetor ;
	float media, soma, desviop ;
	printf("digite o numero de dados:");
	scanf_s("%d", &N);
	vetor = (int*)malloc(N * sizeof(int));
	
	printf("digite os dados:");
	for (i = 0; i < N; i++) {
		scanf_s("%d", &vetor[i]);
	}
	
	soma=fsoma(vetor, N);
	
	media = fmedia(vetor, N);
	desviop = fdesviop(vetor, N, media);
	printf("soma: %f\nmedia: %f\ndesvio padrao: %f\n ", soma, media, desviop);
	
	return 0;
}
float fmedia(int* vetor,int N) {
	float media=0;
	int i;
	for (i = 0; i < N; i++) {
		media += vetor[i];
	}
	return media / 3;
}


float fsoma(int* vetor, int N) {
	int soma = 0;
	int i;
	for (i = 0; i < N; i++) {
		soma += vetor[i];
	}
	return soma;
}


float fdesviop(int *vetor, int N ,float media) {
	int desviop = 0;
	int i;
	for (i = 0; i < N; i++) {
		desviop += pow((vetor[i] - media), 2);
	}
	N--;
	desviop = sqrt((desviop / N), 2);

	return desviop;
}
