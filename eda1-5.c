#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  int n = 0;

  printf("Por favor, informe o tamanho da string: ");
  scanf("%i", &n);

  char *str = malloc((n + 1) * sizeof(char));
  char *res_str = malloc((n + 1) * sizeof(char));

  for (int i = 0; i < n; i++) {
    printf("Informe o valor da posição [%i] da string: ", i + 1);
    scanf(" %c", &str[i]);
  }

  for (int x = 1; x <= n; x++) {
    int count = 1;

    if (str[x] == str[x - 1]) {
      count++;
    } else {
      res_str[x] = count;
      res_str[x + 1] = str[x];
    }
  }

  for (int y = 1; y <= n; y++) {
    printf("%char", res_str[y]);
  }

  free(str);
  free(res_str);

  return EXIT_SUCCESS;
}

// int main(int argc, char const *argv[]) {
//   int n = 0;

//   printf("Por favor, informe o tamanho da string: ");
//   scanf("%i", &n);

//   char *str = malloc((n + 1) * sizeof(char));
//   char *res_str = malloc((2 * n + 1) * sizeof(char)); // Tamanho máximo para o resultado compactado

//   printf("Informe a string: ");
//   scanf("%s", str);

//   int res_index = 0; // Índice para o resultado compactado

//   for (int x = 0; x < n; x++) {
//     int count = 1;

//     // Verifica se o caractere atual é igual ao próximo
//     while (x + 1 < n && str[x] == str[x + 1]) {
//       count++;
//       x++;
//     }

//     // Insere o contador e o caractere no resultado compactado
//     res_str[res_index++] = count + '0'; // Converte o contador para caractere
//     res_str[res_index++] = str[x];
//   }

//   // Adiciona terminador de string
//   res_str[res_index] = '\0';

//   printf("Resultado compactado: %s\n", res_str);

//   free(str);
//   free(res_str);

//   return EXIT_SUCCESS;
// }