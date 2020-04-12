#include <stdio.h>
#include <math.h>
float fmedia(int* vetor);
float fsoma(int* vetor);
float fdesviop(int* vetor, float media);

	int main() {
		FILE* arq_dados;
		float media, soma, desviop;
		FILE* arq_resultados;
		int dados[3];
		arq_resultados = fopen("resultados2.csv", "w");
		arq_dados = fopen("dados2.csv","r");
		if (arq_dados == NULL) {
			printf("ERRO! Arquivo nao encontrado");
		}
		while (fscanf(arq_dados, "%d,%d,%d", &dados[0], &dados[1], &dados[2]) != EOF) {
			soma = fsoma(dados);
			media = fmedia(dados);
			desviop = fdesviop(dados,media);
			fprintf(arq_resultados, "%.2f, %.2f, %.2f\n", soma, media, desviop);
		}

		fclose(arq_dados);
		fclose(arq_resultados);


		return 0;
	}
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