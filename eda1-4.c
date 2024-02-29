#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  int n = 0, sum_main = 0, sum_sec = 0;

  printf("Por favor, informe o tamanho da matriz quadrada: ");
  scanf("%i", &n);

  int *m = (int *)malloc((n * n) * sizeof(int));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("Informe o valor da posição [%i][%i]: ", i + 1, j + 1);
      scanf("%i", &m[n * i + j]);
    }
  }

  for (int x = 0; x < n; x++) {
    for (int y = 0; y < n; y++) {
      if (x == y) {
        sum_main += m[n * x + y];
      }
      if (x + y == n - 1) {
        sum_sec += m[n * x + y];
      }
    }
  }

  printf("A soma da diagonal principal é: %i\n", sum_main);
  printf("A soma da diagonal secundária é: %i\n", sum_sec);

  free(m);

  return EXIT_SUCCESS;
}