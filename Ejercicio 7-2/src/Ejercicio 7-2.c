/*
 Tobias Moretti
 Ejercicio 7-2:
 Dados 3 vectores paralelos de tipo entero:
 Cargar el vector A y B de manera secuencial.
 El tercer vector C, deberá cargarse con el mayor
 de los elementos del mismo componente.
 Mostrar los 3 vectores, ordenados de menor a mayor
 por el vector C
 */

#include <stdio.h>
#include <stdlib.h>
#include "ingreso.h"
#include "vectores.h"
#define T 3

int main(void) {
	setbuf(stdout, NULL);
	int vectorEnterosA[T];
	int vectorEnterosB[T];
	int vectorEnterosC[T];

	CargarVectorSecuencial(vectorEnterosA, vectorEnterosB, vectorEnterosC, T);
	OrdernarVectores(vectorEnterosA, vectorEnterosB, vectorEnterosC, T);
	MostrarVectores(vectorEnterosA, vectorEnterosB, vectorEnterosC, T);
	return 0;
}


