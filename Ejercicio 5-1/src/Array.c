#include "Array.h"
#include "ingreso.h"
void CargarVector(int vector[], int tam) {
	for (int i = 0; i < tam; i++) {
		vector[i] = IngresarEntero("Ingrese un numero: ", 1000, -1000,
				"Reingrese dato: ");
	}
}
void MostarVector(int vector[], int tam) {
	for (int i = 0; i < tam; i++) {
		printf("numero: %d\n", vector[i]);
	}
}
int AcumuladorVector(int vector[], int tam) {
	int resultado = 0;
	for (int i = 0; i < tam; i++) {
		resultado = resultado+vector[i];
	}
	return resultado;
}

