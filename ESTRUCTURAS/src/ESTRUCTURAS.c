/*
	Estructuras:
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char nombre[20];
	char apellido[20];
	char calle[20];
	int numero;
}datosPersonales;

int IngresarEntero(char mensaje[]);
float IngresarFlotante(char mensaje[]);
void getString(char cadena[], char mensaje[], int longitud);
int main(void) {
	datosPersonales agenda;

	agenda.numero = IngresarEntero("Ingrese un entero: ");
	strcpy(agenda.calle,"Av.Siempreviva");

	return 0;
}
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
