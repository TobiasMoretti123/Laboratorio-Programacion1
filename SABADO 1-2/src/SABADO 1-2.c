/*
 Tobias Moretti
 DIV 1E
 Ejercicio 1-2:
 Ingresar 5 números. Determinar cuál es el máximo y el mínimo e indicar en qué orden fue ingresado.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);
	int numeroIngresado;
	int numeroMaximo;
	int numeroMinimo;

	for (int i = 0; i < 5; i++) {
		printf("Ingrese un numero: ");
		scanf("%d", &numeroIngresado);

		if (i == 1) {
			numeroMaximo = numeroIngresado;
			numeroMinimo = numeroIngresado;
		}

		if (numeroMaximo < numeroIngresado) {
			numeroMaximo = numeroIngresado;
		} else {
			if (numeroMinimo > numeroIngresado) {
				numeroMinimo = numeroIngresado;
			}
		}
		printf("Orden: %d\n", numeroIngresado);
	}
	printf("El numero maximo es: %d\n", numeroMaximo);
	printf("El numero minimo es: %d\n", numeroMinimo);

	return 0;
}
