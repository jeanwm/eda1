#include <stdio.h>
#include <stdlib.h>

char* inverter(char *str, int inicio, int fim) {
    while (inicio < fim) {
        char temp = str[inicio];
        str[inicio] = str[fim];
        str[fim] = temp;
        inicio++;
        fim--;
    }
    return str;
}

int comparaStrings(char *str1, char *str2) {
    while (*str1 && *str2) {
        if (*str1 != *str2)
            return 0; 
        str1++;
        str2++;
    }

    if (*str1 == '\0' && *str2 == '\0')
        return 1; 
    else
        return 0;
}

int main(int argc, char const *argv[]) {
    int tam;
    char *str;
    char *org_str;

    printf("Digite o tamanho da cadeia de caracteres: ");
    scanf("%d", &tam);

    str = (char *)malloc((tam + 1) * sizeof(char));
    org_str = (char *)malloc((tam + 1) * sizeof(char));

    if (str == NULL || org_str == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    printf("Digite uma cadeia de caracteres: ");
    scanf("%s", str);

    int i = 0;
    while (str[i] != '\0') {
        org_str[i] = str[i];
        i++;
    }
    org_str[i] = '\0';

    inverter(str, 0, tam - 1);

    if (comparaStrings(org_str, str)) {
        printf("\nEh palindromo.\n");
    } else {
        printf("\nNao eh palindromo.\n");
    }

    free(str);
    free(org_str);

    return EXIT_SUCCESS;
}