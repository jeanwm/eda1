#include <stdio.h>
#include <stdlib.h>

int produto(int x, int y) {
  if (x == 0 || y == 0) {
    return 0;
  } else if (x == 1) {
    return y;
  } else if (y == 1) {
    return x;
  } else {
    return x + produto(x, y - 1);
  }
}

int main(int argc, char const *argv[]) {
  int x = 0, y = 0;

  printf("Digite o primeiro número positivo: ");
  scanf("%d", &x);
  printf("Digite o segundo número positivo: ");
  scanf("%d", &y);

  if (x < 0 || y < 0) {
    printf("Por favor, digite números positivos.\n");
    return 1;
  }

  printf("O produto de %d e %d é: %d\n", x, y, produto(x, y));

  return EXIT_SUCCESS;
}