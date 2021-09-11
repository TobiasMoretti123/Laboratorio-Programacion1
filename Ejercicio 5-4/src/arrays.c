#include "arrays.h"
#include "ingreso.h"
void InicializarArray(int cadena[], int tam) {
	for (int i = 0; i < tam; i++) {
		cadena[i] = -1;
	}
}
void CargarVectorEnteros(int array[], int sice) {
	for (int i = 0; i < sice; i++) {
		array[i] = IngresarEntero("Ingrese una edad: ", 120, 0,
				"Reingrese dato: ");
	}
}
