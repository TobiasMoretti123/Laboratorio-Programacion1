#include <stdio.h>
#include <stdlib.h>
#include "ingreso.h"
#define T 5
#define INICIAL -1001

void CargarVector(int vector[], int tam);
void MostrarVector(int vector[], int tam, int valorInicial);
void InicializarVector(int vector[], int tam, int valorInicial);
int BuscarMayorImpar(int array[], int sice, int *maximo);
int VerificarParidad(int numero);
int main(void) {
	setbuf(stdout, NULL);
	int listaNumeros[T];
	int maximoImpar;
	int respuesta;

	InicializarVector(listaNumeros, T, INICIAL);
	CargarVector(listaNumeros, T);
	MostrarVector(listaNumeros, T, INICIAL);
	respuesta = BuscarMayorImpar(listaNumeros, T, &maximoImpar);

	if (respuesta == 1) {
		printf("El maximo impar es: %d", maximoImpar);
	}
	else
	{
		printf("No se ingreso ningun numero impar");
	}

	return 0;
}
void CargarVector(int vector[], int tam) {
	int index;
	int auxiliar;
	char seguir;
	do {
		auxiliar = IngresarEntero("Ingrese un numero: ", 1000, -1000, "error");
		index = IngresarEntero("Ingrese una posicion: ", tam, 1, "error");
		vector[index - 1] = auxiliar;
		printf("Desea ingresar otro?");
		fflush(stdin);
		scanf("%c", &seguir);
	} while (seguir == 's');
}
void MostrarVector(int vector[], int tam, int valorInicial) {
	for (int i = 0; i < tam; i++) {
		if (vector[i] != valorInicial) {
			printf("Valor %d: %d\n", i, vector[i]);
		}
	}
}
void InicializarVector(int vector[], int tam, int valorInicial) {
	for (int i = 0; i < tam; i++) {
		vector[i] = valorInicial;
	}
}
int BuscarMayorImpar(int array[], int sice, int *maximo) {
	int mayorImpar;
	int banderaImpar;
	banderaImpar = 0;
	for (int i = 0; i < sice; i++) {
		if (VerificarParidad(array[i]) == 0) {
			banderaImpar = 1;
			if (mayorImpar < array[i] || banderaImpar == 1) {
				mayorImpar = array[i];
			}
		}
	}

	*maximo = mayorImpar;

	return banderaImpar;
}
int VerificarParidad(int numero) {
	int retorno;
	if (numero % 2 == 0) {
		retorno = 1;
	} else {
		retorno = 0;
	}
	return retorno;
}
