#include <stdio.h>
#include <stdlib.h>

char* inverter(char *str, int inicio, int fim) {
	if (inicio >= fim) {
		return str;
	}

  	char temp = str[inicio];
  	str[inicio] = str[fim];
  	str[fim] = temp;

  	return inverter(str, inicio + 1, fim - 1);
}

int main(int argc, char const *argv[]) {
	int tam;
	char *str;
	char *org_str;
	
	printf("Digite o tamanho da cadeia de caracteres: ");
	scanf("%d", &tam);
	
	str = (char *)malloc((tam + 1) * sizeof(char));
	org_str = (char *)malloc((tam + 1) * sizeof(char));
	
	if (str == NULL) {
		printf("Erro ao alocar memória.\n");
	    return 1;
	}
	
	printf("Digite uma cadeia de caracteres: ");
	scanf("%s", str);
	
	org_str = str;
		
	inverter(str, 0, tam - 1);
	
	printf("\n%s", str);
	printf("\n%s", org_str);
	
	if (org_str == str) {
		printf("Eh palindromo.");
	} else {
		printf("Nao eh palindromo.");
	}
		
	free(str);
	free(org_str);
	
	return EXIT_SUCCESS;
}
