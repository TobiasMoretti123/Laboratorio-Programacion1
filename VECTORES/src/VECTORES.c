#include <stdio.h>
#include <stdlib.h>
#define T 5

void CargarVector(int vector[], int tam);
int main(void) {
	setbuf(stdout, NULL);
	int listaNumeros[T];
	int i;
	int acumulador;
	int maximo;
	acumulador = 0;

	CargarVector(listaNumeros,T);
	for (i = 0; i < T; i++) {
		acumulador = acumulador + listaNumeros[i];
	}
	printf("El total acumulado es: %d\n", acumulador);
	for (i = 0; i < T; i++) {
		if (listaNumeros[i] > maximo || i == 0) {
			maximo = listaNumeros[i];
		}
	}
	printf("El numero maximo es: %d\n", maximo);
	for (i = 0; i < T; i++) {
		printf("Valor %d: %d\n", i, listaNumeros[i]);
	}
	return 0;
}
void CargarVector(int vector[], int tam) { // param por referencia
	for (int i = 0; i < tam; i++) {
		printf("Ingrese un numero: ");
		scanf("%d", &vector[i]);
	}
}
