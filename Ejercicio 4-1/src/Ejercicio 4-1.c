/*
 Tobias Moretti
 Ejercicio 4-1:
 Realizar un programa EN EL MAIN que permita calcular y mostrar el factorial de un número.
 Por ejemplo:
 5! = 5*4*3*2*1 = 120
*/

#include <stdio.h>
#include <stdlib.h>

int PedirUnEntero(char mensaje[]);
int main(void) {
	setbuf(stdout, NULL);
	int resultado;
	int factorial;

	factorial = PedirUnEntero("Ingrese numero que quiera factoriar: ");
	resultado = 1;
	while (factorial > 1) {
		resultado *= factorial;
		printf("%d x", factorial);
		factorial--;
	}

	printf("1 = %d\n\n", resultado);
	return 0;
}
int PedirUnEntero(char mensaje[]) {
	int retorno;
	printf("%s", mensaje);
	scanf("%d", &retorno);
	return retorno;
}
