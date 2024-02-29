#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int n, k = 0;
	
	printf("Por favor, informe o tamanho do vetor: ");
	scanf("%i", &n);
	
	int *arr = (int*)malloc(n * sizeof(int));
	
	for (int i = 0; i < n; i++) {
		printf("Informe o valor da posicao %i do vetor: ", i + 1);
		scanf("%i", &arr[i]);
	}
	
	printf("Por favor, informe o valor independente: ");
	scanf("%i", &k);
	
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			if (k == arr[x] + arr[y]) {
				free(arr);
				return EXIT_SUCCESS;
			}
		}
	}

	free(arr);
	return EXIT_FAILURE;
}
