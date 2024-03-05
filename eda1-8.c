#include <stdio.h>
#include <stdlib.h>

void inverter(char *str, int inicio, int fim) {
  if (inicio >= fim) {
    return;
  }

  char temp = str[inicio];
  str[inicio] = str[fim];
  str[fim] = temp;

  inverter(str, inicio + 1, fim - 1);
}

int main(int argc, char const *argv[]) {
  int tam;
  char *str;

  printf("Digite o tamanho da cadeia de caracteres: ");
  scanf("%d", &tam);

  str = (char *)malloc((tam + 1) * sizeof(char));

  if (str == NULL) {
    printf("Erro ao alocar memória.\n");
    return 1;
  }

  printf("Digite uma cadeia de caracteres: ");
  scanf("%s", str);

  inverter(str, 0, tam - 1);

  printf("A cadeia de caracteres invertida é: %s\n", str);

  free(str);

  return EXIT_SUCCESS;
}