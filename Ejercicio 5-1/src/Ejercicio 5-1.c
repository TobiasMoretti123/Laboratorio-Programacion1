/*
 Tobias Moretti
 Ejercicio 5-1:
 Pedir el ingreso de 5 números. Mostrarlos y calcular la sumatoria de los mismos.
 */

#include <stdio.h>
#include <stdlib.h>
#include "ingreso.h"
#include "Array.h"
#define T 5

int main(void) {
	setbuf(stdout, NULL);
	int listaNumeros[T];
	int sumatoria;
	CargarVector(listaNumeros, T);
	MostarVector(listaNumeros, T);
	sumatoria= AcumuladorVector(listaNumeros, T);

	printf("La sumatoria es: %d",sumatoria);
	return 0;
}

