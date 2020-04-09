#include <stdio.h>
#include <math.h>
int main() {
	int i, vetor[3];
	float media=0, soma=0, desviop=0;
	for (i = 0; i < 3; i++) {
		scanf_s("%d", &vetor[i]);
		soma += vetor[i];
		media += vetor[i];

	}
	media = media / 3;
	for (i = 0; i < 3; i++) {
		desviop += pow((vetor[i] - media), 2);
	}
	desviop = sqrt(desviop / 2);
	printf("soma:%.2f media:%.2f desviop:%.2f", soma, media, desviop);


		return 0;
}