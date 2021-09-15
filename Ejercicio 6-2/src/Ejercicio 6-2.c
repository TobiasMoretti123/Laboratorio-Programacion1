/*
 Tobias Moretti
 Ejercicio 6-2:
 Realizar un programa que permita el ingreso de 10 números
 enteros (positivos y negativos).
 Necesito generar un listado
 de los números positivos de manera creciente
 y negativos de manera decreciente. (Como máximo 5 for)
 Ejemplo:
 Listado 1 : 4, 5, 6, 10, 18, 29
 Listado 2 : -1,-5,-9,-12
 */

#include <stdio.h>
#include <stdlib.h>
#include "vectores.h"
#include "ordenamiento.h"
#include "verificacion.h"
#define T 10

int main(void) {
	setbuf(stdout, NULL);
	int listaNumerosEnteros[T];
	CargarVectorEnteros(listaNumerosEnteros, T);
	OrdenarNumerosPositivos(listaNumerosEnteros, T);
	OrdenarNumerosNegativos(listaNumerosEnteros, T);
	if (ListadoPositivos(listaNumerosEnteros, T) != 1) {
		printf("No se ingresaron numeros positivos");
	}
	if (ListadoNegativos(listaNumerosEnteros, T) != 1) {
		printf("No se ingresaron numeros negativos");
	}

	return 0;
}

