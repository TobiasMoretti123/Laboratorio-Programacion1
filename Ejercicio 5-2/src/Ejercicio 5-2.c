/*
 Tobias Moretti
 Ejercicio 5-2:
 Pedir el ingreso de 10 números enteros entre -1000 y 1000. Determinar:
 a Cantidad de positivos y negativos.
 b Sumatoria de los pares.
 c El mayor de los impares.
 d Listado de los números ingresados.
 e Listado de los números pares.
 f Listado de los números de las posiciones impares.
 Se deberán utilizar funciones y vectores.
 */

#include <stdio.h>
#include <stdlib.h>
#include "vectores.h"
#include "ingreso.h"
#include "verificacion.h"

#define SICE 10
int main(void) {
	setbuf(stdout, NULL);
	int listaNumeros[SICE];
	int suma;
	int mayorImpar;

	CargarVectorEnteros(listaNumeros, SICE);
	MostrarCantidadPostivosNegativos(listaNumeros, SICE);
	suma = SumarPares(listaNumeros, SICE);
	mayorImpar = BuscarMayorImpar(listaNumeros, SICE);
	printf("b)La suma de pares es igual a: %d\n", suma);
	printf("c)El mayor impar es: %d\n", mayorImpar);
	ListarVectorEnteros(listaNumeros, SICE);
	ListarPares(listaNumeros, SICE);
	ListarNumerosEnPosicionImpar(listaNumeros, SICE);

	return 0;
}

