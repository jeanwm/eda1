#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int compare(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

float mediana(int vetor[], int tamanho) {
  if (tamanho % 2 == 0) {
    return (vetor[tamanho / 2 - 1] + vetor[tamanho / 2]) / 2.0;
  } else {
    return vetor[tamanho / 2];
  }
}

int moda(int vetor[], int tamanho) {
  int frequencia[MAX_SIZE] = {0};
  int moda = -1, maxFrequencia = 0;

  for (int i = 0; i < tamanho; i++) {
    frequencia[vetor[i]]++;
    if (frequencia[vetor[i]] > maxFrequencia) {
      maxFrequencia = frequencia[vetor[i]];
      moda = vetor[i];
    }
  }

  return moda;
}

float zScore(int valor, float media, float desvioPadrao) {
  return (valor - media) / desvioPadrao;
}

int main(int argc, char const *argv[]) {
  int vetor[MAX_SIZE];
  int tamanho;
  float soma = 0, desvioPadrao = 0;

  printf("Digite o tamanho do conjunto de numeros (maximo %d): ", MAX_SIZE);
  scanf("%d", &tamanho);

  printf("Digite os numeros:\n");
  for (int i = 0; i < tamanho; i++) {
    scanf("%d", &vetor[i]);
    soma += vetor[i];
  }

  qsort(vetor, tamanho, sizeof(int), compare);

  float medianaValor = mediana(vetor, tamanho);

  int modaValor = moda(vetor, tamanho);

  float media = soma / tamanho;

  for (int i = 0; i < tamanho; i++) {
    desvioPadrao += pow(vetor[i] - media, 2);
  }
  desvioPadrao = sqrt(desvioPadrao / tamanho);

  printf("\nMediana: %.2f\n", medianaValor);
  printf("Moda: %d\n", modaValor);

  printf("Outliers: ");
  for (int i = 0; i < tamanho; i++) {
    float z = zScore(vetor[i], media, desvioPadrao);
    if (z > 3 || z < -3) {
      printf("%d ", vetor[i]);
    }
  }
  printf("\n");

  printf("Quartis:\n");
  printf("Primeiro quartil: %.2f\n", mediana(vetor, tamanho / 2));
  printf("Segundo quartil (Mediana): %.2f\n", medianaValor);
  if (tamanho % 2 == 0) {
    printf("Terceiro quartil: %.2f\n",
           mediana(vetor + tamanho / 2, tamanho / 2));
  } else {
    printf("Terceiro quartil: %.2f\n",
           mediana(vetor + tamanho / 2 + 1, tamanho / 2));
  }

  return EXIT_SUCCESS;
}