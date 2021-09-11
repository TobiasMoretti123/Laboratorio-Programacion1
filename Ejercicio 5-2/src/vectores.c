#include "vectores.h"
void ListarVectorEnteros(int array[], int sice) {
	for (int i = 0; i < sice; i++) {
		printf("d)listado enteros: %d\n", array[i]);
	}
}
void ListarPares(int array[], int sice) {
	for (int i = 0; i < sice; i++) {
		if (VerificarParidad(array[i]) == 1) {
			printf("e)listado de pares: %d\n", array[i]);
		}
	}
}
void ListarNumerosEnPosicionImpar(int array[], int sice) {
	for (int i = 0; i < sice; i++) {
		if (VerificarParidad(i) == 0) {
			printf("f)El numero: %d esta en la posicion impar : %d\n", array[i],
					i);
		}
	}
}
void CargarVectorEnteros(int array[], int sice) {
	for (int i = 0; i < sice; i++) {
		array[i] = IngresarEntero("Ingrese un entero: ", 1000, -1000,
				"Reingrese dato: ");
	}
}
void MostrarCantidadPostivosNegativos(int array[], int sice) {
	int cantidadPostivos;
	int cantidadNegativos;
	cantidadNegativos = 0;
	cantidadPostivos = 0;
	for (int i = 0; i < sice; i++) {
		if (VerificarSigno(array[i]) == 1) {
			cantidadPostivos++;
		} else {
			if (VerificarSigno(array[i]) == -1) {
				cantidadNegativos++;
			}
		}
	}
	printf("a)La cantidad de negativos es: %d\n", cantidadNegativos);
	printf("a)La cantidad de positivos es: %d\n", cantidadPostivos);
}
int BuscarMayorImpar(int array[], int sice) {
	int mayorImpar;
	int contadorImpar;
	contadorImpar = 0;
	for (int i = 0; i < sice; i++) {
		if (VerificarParidad(array[i]) == 0) {
			contadorImpar++;
			if (mayorImpar < array[i] || contadorImpar == 1) {
				mayorImpar = array[i];
			}
		}
	}
	return mayorImpar;
}
