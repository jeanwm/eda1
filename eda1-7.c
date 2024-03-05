#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n) {
    if (n == 0 || n == 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main(int argc, char const *argv[]) {
    int termo, resultado;

    printf("Informe o n-ésimo termo da sequência de Fibonacci: ");
    scanf("%d", &termo);

    if (termo < 0) {
        printf("Por favor, informe um número não negativo.\n");
        return 1;
    }

    resultado = fibonacci(termo);
    printf("O %d-ésimo termo da sequência de Fibonacci é: %d\n", termo, resultado);

  return EXIT_SUCCESS;
}