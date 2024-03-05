#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  int n = 0;

  printf("Por favor, informe o tamanho da string: ");
  scanf("%i", &n);

  char *str = malloc((n + 1) * sizeof(char));
  char *res_str = malloc((2 * n + 1) * sizeof(char));

  printf("Informe a string: ");
  scanf("%s", str);

  int res_index = 0;
  for (int x = 0; x < n; x++) {
    int count = 1;

    while (x + 1 < n && str[x] == str[x + 1]) {
      count++;
      x++;
    }

    res_str[res_index++] = count + '0';
    res_str[res_index++] = str[x];
  }

  res_str[res_index] = '\0';

  printf("Resultado compactado: %s\n", res_str);

  free(str);
  free(res_str);

  return EXIT_SUCCESS;
}