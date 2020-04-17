#include <stdio.h>
#include <stdlib.h>
int divisao(int* numeros, float *resultados);

int main() {
	int numeros[3];
	int verificar;
	float resultados[2];
	FILE* arq_dados;
	FILE* arq_result;
	arq_dados = fopen("dados2.csv", "r");
	arq_result = fopen("resultados.csv", "w");
	if (!arq_dados) {
		printf("ERRO,ARQUIVO NAO ENCONTRADO!");
		return 0;
	}
	while (fscanf(arq_dados, "%d,%d,%d", &numeros[0], &numeros[1], &numeros[2])!=EOF) {
		verificar = divisao(numeros, resultados);
		if (verificar == -1) {
			printf("ERRO NA DIVISAO!");
			return 0;
		}
		else {
			fprintf(arq_result,"%.2f, %.2f\n",resultados[0],resultados[1]);
		}
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