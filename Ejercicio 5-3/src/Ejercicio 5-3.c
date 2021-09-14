/*
 Tobias Moretti
 Ejercicio 5-3:
 Realizar un programa que permita el ingreso de 10 números enteros distintos de cero.
 La carga deberá ser aleatoria (todos los elementos se inicializan en cero por default).
 Determinar el promedio de los positivos, y del menor de los negativos la suma de los antecesores
 (Según la recta numérica de los reales, hasta llegar a cero).
 Utilizar funciones y vectores.
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "vectores.h"
#include "verificacion.h"
#define T 10

int PromedioPositivos(int vector[], int tam, float *promedio, int valorInicial);
int BuscarMenorNegativo(int array[], int sice, int *minimo, int valorIncial);
int SumaAntecesores(int array[], int sice, int *minimo, int valorIncial);
int main(void) {
	setbuf(stdout, NULL);
	int listaNumeros[T] = { 0 };
	float promedioPositivos;
	int respuestaPositivos;
	int respuestaNegativos;
	int menorNegativo;
	int sumaAntecesores;
	CargarVectorAleatorio(listaNumeros, T);
	MostrarVector(listaNumeros, T, 0);
	respuestaPositivos = PromedioPositivos(listaNumeros, T, &promedioPositivos,
			0);
	respuestaNegativos = BuscarMenorNegativo(listaNumeros, T, &menorNegativo,
			0);
	if (respuestaPositivos == 1) {
		printf("El promedio de los positivos es: %.2f\n", promedioPositivos);
	} else {
		printf("No se ingreso numero positivo\n");
	}
	if (respuestaNegativos == 1) {
		printf("El menor de los negativos es: %d\n", menorNegativo);
		sumaAntecesores = SumaAntecesores(listaNumeros, T, &menorNegativo, 0);
		printf("La suma de los antecesores hasta 0 es: %d\n", sumaAntecesores);
	} else {
		printf("No se ingreso numero negativo\n");
	}

	return 0;
}
int PromedioPositivos(int vector[], int tam, float *promedio, int valorInicial) {
	int retorno;
	float promedioPostivos;
	int acumulador;
	int cantidad;
	retorno = 0;
	cantidad = 0;
	acumulador = 0;
	for (int i = 0; i < tam; i++) {
		if (vector[i] != valorInicial) {
			if (VerificarSigno(vector[i]) == 1) {
				cantidad++;
				acumulador = acumulador + vector[i];
				promedioPostivos = (float) acumulador / cantidad;
				retorno = 1;
			}
		}
	}
	*promedio = promedioPostivos;
	return retorno;
}
int BuscarMenorNegativo(int array[], int sice, int *minimo, int valorInicial) {
	int menorNegativo;
	int banderaNegativa;
	banderaNegativa = 0;
	for (int i = 0; i < sice; i++) {
		if (VerificarSigno(array[i]) == -1) {
			banderaNegativa = 1;
			if (menorNegativo > array[i] || banderaNegativa == 1) {
				menorNegativo = array[i];
			}
		}
	}
	*minimo = menorNegativo;
	return banderaNegativa;
}
int SumaAntecesores(int array[], int sice, int *minimo, int valorIncial) {
	int retorno;
	int respuesta;
	int suma;
	respuesta = BuscarMenorNegativo(array, sice, minimo, valorIncial);
	if (respuesta == 1) {
		for (int i = *minimo; i < 0; i++) {
			suma = *minimo + (*minimo + 1);
		}
	}
	retorno = suma;
	return retorno;
}

