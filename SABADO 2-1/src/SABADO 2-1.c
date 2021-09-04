/*
 Ejercicio 2-1:
 Crear una función que reciba como parámetro un numero entero.
 La función retornara 1 en caso de que sea positivo, -1 en caso de que sea negativo y 0 en caso de que sea 0.
 Realizar la prueba lógica de la función en el main.
 */

#include <stdio.h>
#include <stdlib.h>

int PedirEntero(int numero);
int main(void) {
	setbuf(stdout, NULL);
	int numeroIngresado;

	printf("Ingrese un numero entero: ");
	scanf("%d", &numeroIngresado);

	if (PedirEntero(numeroIngresado) == 0) {
		printf("Es cero");
	} else {
		if (PedirEntero(numeroIngresado) == 1) {
			printf("Es positivo");
		} else {
			printf("Es negativo");
		}
	}

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

