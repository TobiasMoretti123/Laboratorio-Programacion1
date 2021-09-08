/*
 Tobias Moretti
 Ejercicio 2-2:
 Realizar un programa que permita el ingreso de 10 números enteros.
 Determinar el promedio de los positivos, la cantidad de ceros y
 del menor de los negativos la suma de los antecesores.
 Nota:
 Utilizar la función del punto anterior y
 desarrollar funciones para resolver los procesos que están resaltados.
 */

#include <stdio.h>
#include <stdlib.h>
int PedirEntero(int numero);
float PromedioPositivos(int acumulador, int cantidad);
int SumaAntecesores(int numero);
int main(void) {
	setbuf(stdout, NULL);
	int numeroIngresado;
	int cantidadCeros;
	int cantidadPositivos;
	int cantidadNegativos;
	int acumuladorPositivos;
	int elMenorNegativo;
	int sumaAntecesores;
	float promedio;

	cantidadCeros = 0;
	cantidadPositivos = 0;
	cantidadNegativos = 0;
	acumuladorPositivos = 0;

	for (int i = 0; i < 10; i++) {
		printf("Ingrese un numero entero: ");
		scanf("%d", &numeroIngresado);
		if (PedirEntero(numeroIngresado) == 0) {
			cantidadCeros++;
		} else {
			if (PedirEntero(numeroIngresado) == 1) {
				cantidadPositivos++;
				acumuladorPositivos = acumuladorPositivos + numeroIngresado;
			} else {
				cantidadNegativos++;
				if (cantidadNegativos == 1) {
					elMenorNegativo = numeroIngresado;
				}
				if (elMenorNegativo > numeroIngresado) {
					elMenorNegativo = numeroIngresado;
					sumaAntecesores = SumaAntecesores(elMenorNegativo);
				}
			}
		}
	}
	promedio = PromedioPositivos(acumuladorPositivos, cantidadPositivos);
	printf("El promedio de los positivos es: %.2f\n", promedio);
	printf("La cantidad de ceros es: %d\n", cantidadCeros);
	printf("El menor numero es: %d y la sumatoria de sus antecesores es: %d",
			elMenorNegativo, sumaAntecesores);
	return 0;
}
int PedirEntero(int numero) {
	int retorno;
	if (numero == 0) {
		retorno = 0;
	} else {
		if (numero > 0) {
			retorno = 1;
		} else {
			retorno = -1;
		}
	}
	return retorno;
}
float PromedioPositivos(int acumulador, int cantidad) {
	float resultado;
	resultado = (float) acumulador / cantidad;
	return resultado;
}
int SumaAntecesores(int numero) {
	int resultado;
	resultado = 0;
	resultado = resultado + numero;
	return resultado;
}

