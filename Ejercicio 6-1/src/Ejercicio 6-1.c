/*
 Tobias Moretti
 Ejercicio 6-1:
 Disponemos de dos variables numéricas (a y b).
 Realizar un algoritmo que permita el intercambio de valores de dichas variables.
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

void IntercambioDeNumeros(int *numero1, int *numero2, char mensaje[]);
int main(void) {
	setbuf(stdout, NULL);
	int numeroA;
	int numeroB;

	utn_getNumero(&numeroA, "Ingrese primer numero: ", "Error ", -1000, 1000,
			3);
	utn_getNumero(&numeroB, "Ingrese segundo numero: ", "Error ", -1000, 1000,
			3);

	printf("Antes de intercambio de numero a: %d\n", numeroA);
	printf("Antes de intercambio numero b: %d\n", numeroB);

	IntercambioDeNumeros(&numeroA, &numeroB,
			"Desea intercambiar la posicion del numero(s para si)?: ");

	printf("Despues de intercambio de numero a: %d\n", numeroA);
	printf("Despues de intercambio numero b: %d\n", numeroB);
	return 0;
}
/// \fn void IntercambioDeNumeros(int*, int*, char[])
/// \brief Ingresa dos numberos y los intercambia de lugar
/// \param numero1 El primer numero a ingresar
/// \param numero2 El segundo numero a ingresar
/// \param mensaje El mensaje para el cambio de parametro
void IntercambioDeNumeros(int *numero1, int *numero2, char mensaje[]) {
	char respuesta;
	int valorAnterior;
	printf("%s", mensaje);
	fflush(stdin);
	scanf("%c", &respuesta);
	if (respuesta == 's') {
		valorAnterior = *numero1;
		*numero1 = *numero2;
		*numero2 = valorAnterior;
	}
}
