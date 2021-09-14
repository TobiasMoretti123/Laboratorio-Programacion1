#include "vectores.h"
#include "verificacion.h"
#include "utn.h"
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
		if (VerificarParidad(array[i]) == 0) {
			printf("f)El numero: %d esta en la posicion impar : %d\n", array[i],
					i);
		}
	}
}
void CargarVectorEnteros(int array[], int sice) {
	for (int i = 0; i < sice; i++) {
		array[i] = utn_getNumero(array, "Ingrese un entero: ", "Reingrese dato",
				-1000, 1000, 3);
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
void CargarVectorAleatorio(int vector[], int tam) {
	int index;
	char seguir;
	do {
		index = IngresarEntero("Ingrese una posicion: ",tam, 1, "Error reingrese dato: ");
		vector[index - 1] = IngresarEntero("Ingrese un numero: ", 1000, -1000, "Reingrese dato: ");
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
int IngresarEntero(char mensaje[], int max, int minimo, char mensajeError[]) {
	int numero;
	printf("%s", mensaje);
	scanf("%d", &numero);
	while (numero < minimo || numero > max) {
		printf("%s", mensajeError);
		scanf("%d", &numero);
	}
	return numero;
}
