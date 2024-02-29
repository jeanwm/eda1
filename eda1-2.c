#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  int n, k, total = 0;

  printf("Por favor, informe o tamanho do vetor: ");
  scanf("%i", &n);

  int *arr = (int *)malloc(n * sizeof(int));
  int *res_arr = (int *)malloc(n * sizeof(int));

  for (int i = 0; i < n; i++) {
    printf("Informe o valor da posicao %i do vetor: ", i + 1);
    scanf("%i", &arr[i]);
  }

  for (int x = 0; x < n; x++) {
    total = 1;
    for (int y = 0; y < n; y++) {
      if (y != x) {
        total = arr[y] * total;
      }
    }
    res_arr[x] = total;
  }

  for (int k = 0; k < n; k++) {
    printf("%i ", res_arr[k]);
  }

  free(arr);
  free(res_arr);

  return EXIT_SUCCESS;
}
