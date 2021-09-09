#include "ingreso.h"
int IngresarEntero(char mensaje[], int max, int minimo, char mensajeError[]) {
	int numero;
	printf("%s", mensaje);
	scanf("%d", &numero);
	if (numero < minimo || numero > max) {
		printf("%s", mensajeError);
		scanf("%d", &numero);
	}
	return numero;
}

