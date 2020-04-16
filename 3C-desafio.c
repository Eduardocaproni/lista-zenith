#include <stdio.h>
#include <stdlib.h>


int main() {
	/*struct stdados {
		int dados[3];
	};
	struct stdados teste;*/
	int teste[3];
	int x = 0;
	teste[1] = 0;
	teste[2] = 0;
	teste[0] = 0;
	FILE* arq_bin;
	arq_bin = fopen("dados3.bin", "rb");
	if (!arq_bin)
		printf("ERRO");

	x=fread(teste, sizeof(int), 3, arq_bin);
	printf("%d %d %d %d\n", teste[0], teste[1], teste[2],x);
	
	fclose(arq_bin);
	
	return 0;
}