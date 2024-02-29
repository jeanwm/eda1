#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  int n, count = 0;

  printf("Por favor, informe o valor de n: ");
  scanf("%i", &n);

  for (int i = 1; i <= n; i++) {
    if (n % i == 0) {
      count++;
    }
  }

  if (count > 2) {
    printf("%i não é um número primo", n);
  } else {
    printf("%i é um número primo", n);
  }

  return EXIT_SUCCESS;
}