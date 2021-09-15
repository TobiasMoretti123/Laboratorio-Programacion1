/*
 ============================================================================
 Name        : BURBUJEO.c
 Author      : Tobias
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "ordenamiento.h"
#define QTY_EMPLEADOS 9

int MostrarArrayInt(int *pArray, int limite);

int main(void) {
	int arrayEdades[QTY_EMPLEADOS] = { 54, 26, 93, 17, 77, 31, 44, 55, 27 };
	int respuesta;
	MostrarArrayInt(arrayEdades, QTY_EMPLEADOS);
	respuesta = OrdenarArrayInt(arrayEdades, QTY_EMPLEADOS);
	if (respuesta > 0) {
		printf("\n\nIteraciones: %d\n", respuesta);
	}
	MostrarArrayInt(arrayEdades, QTY_EMPLEADOS);
	respuesta = OrdenarArrayInt(arrayEdades, QTY_EMPLEADOS);
	if (respuesta > 0) {
		printf("\n\nIteraciones: %d\n", respuesta);
	}
	return 0;
}
/// \fn int MostrarArrayInt(int*, int)
/// \brief Imprime a mode DEBUG la informacion de un array de enteros
/// \param pArray Es el puntero al array a ser monstrado
/// \param limite Es la longitud del array
/// \return 0 si Ok o -1 para indicar un error
int MostrarArrayInt(int *pArray, int limite) {
	int retorno;
	retorno = -1;
	if (pArray != NULL && limite >= 0) {
		retorno = 0;
		for (int i = 0; i < limite; i++) {
			printf("\n[DEBUG]  Indice: %d - Valor:%d", i, pArray[i]);
		}
	}
	return retorno;
}

