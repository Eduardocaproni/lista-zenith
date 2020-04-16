#include <stdio.h>
#include <stdlib.h>
int divisao(int* numeros, float *resultados);

int main() {
	int numeros[3];
	int verificar;
	float resultados[2];
	printf("digite os 3 inteiros: ");
	scanf("%d %d %d", &numeros[0], &numeros[1], &numeros[2]);
	verificar = divisao(numeros, resultados);
	if (verificar == -1) {
		printf("ERRO NA DIVISAO!");
		return 0;
	}
	else{
		printf("divisao 1 = %.2lf\ndivisao 2 = %.2lf\n", resultados[0], resultados[1]);
		}
	return 0;
}

int divisao(int* numeros, float* resultados) {
	if (numeros[2] == 0)
		return -1;
	
	resultados[0] =(float) numeros[0] / numeros[2];
	resultados[1] = (float)numeros[1] / numeros[2];
	return 0;
}