#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
	int n, i, total;
	
	printf("Por favor, informe o tamanho do vetor: ");
	scanf("%d", &n);
	
	int *arr     = (int *)malloc(n * sizeof(int));
	int *res_arr = (int *)malloc(n * sizeof(int));
	
	for (i = 0; i < n; i++) {
	    printf("Informe o valor da posicao %i do vetor: ", i + 1);
	    scanf("%d", &arr[i]);
	}
	
	total = 1;
	for (i = 0; i < n; i++) {
		total = total * arr[i];
	}
	
	for (i = 0; i < n; i++) {
		res_arr[i] = total / arr[i];
	}
	
	
	for (i = 0; i < n; i++) {
	    printf("%d ", res_arr[i]);
	}
	
	free(arr);
	free(res_arr);
	
	return EXIT_SUCCESS;
}
