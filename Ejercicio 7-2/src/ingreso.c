#include "ingreso.h"
int IngresarEntero(char mensaje[]) {
	int numero;
	printf("%s", mensaje);
	scanf("%d", &numero);

	return numero;
}
float IngresarFlotante(char mensaje[]) {
	float numero;
	printf("%s", mensaje);
	scanf("%f", &numero);
	return numero;
}
void getString(char cadena[], char mensaje[], int longitud) {
	printf("%s", mensaje);
	fflush(stdin);
	fgets(cadena, longitud, stdin);
}
