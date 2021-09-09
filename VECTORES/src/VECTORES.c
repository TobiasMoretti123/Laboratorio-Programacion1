#include <stdio.h>
#include <stdlib.h>
#define T 5

void CargarVector(int vector[], int tam);
int BuscarMaximo(int vector[], int tam);
void MostrarIndicesDelValor(int vector[], int tam, int valor);
void MostrarVector(int vector[], int tam);
int main(void) {
	setbuf(stdout, NULL);
	int listaNumeros[T]={};
	int maximo;
	int valorIngresado = 6;

	//CargarVector(listaNumeros, T);
	maximo = BuscarMaximo(listaNumeros, T);
	printf("El numero maximo es: %d\nPosiciones del maximo\n", maximo);
	MostrarIndicesDelValor(listaNumeros, T, maximo);
	MostrarVector(listaNumeros, T);
	MostrarIndicesDelValor(listaNumeros, T, valorIngresado);
	return 0;
}
void CargarVector(int vector[], int tam) {
	for (int i = 0; i < tam; i++) {
		printf("Ingrese un numero: ");
		scanf("%d", &vector[i]);
	}
}
int BuscarMaximo(int vector[], int tam) {
	int maximo;
	for (int i = 0; i < tam; i++) {
		if (vector[i] > maximo || i == 0) {
			maximo = vector[i];
		}
	}
	return maximo;
}
void MostrarIndicesDelValor(int vector[], int tam, int valor) {
	for (int i = 0; i < tam; i++) {
		if (vector[i] == valor) {
			printf("%d\n", i);
		}
	}
}
void MostrarVector(int vector[], int tam) {
	for (int i = 0; i < tam; i++) {
		printf("Valor %d: %d\n", i, vector[i]);
	}
}
