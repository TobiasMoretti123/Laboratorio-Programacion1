/*
 Tobias Moretti
 DIV 1E
 Ejercicio 1-1:
 Ingresar números enteros, hasta que el usuario lo decida. Calcular y mostrar:
 a) El promedio de los números positivos.
 b) El promedio de los números negativos.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);
	int numeroIngresado;
	int acumuladorNegativos;
	int acumuladorPositivos;
	int contadorPositivos;
	int contadorNegativos;
	float promedioNegativo;
	float promedioPositivo;
	char respuesta;

	acumuladorNegativos = 0;
	acumuladorPositivos = 0;
	contadorPositivos = 0;
	contadorNegativos = 0;
	respuesta = 's';

	do {
		printf("Ingrese un numero entero: ");
		scanf("%d", &numeroIngresado);

		if (numeroIngresado > 0) {
			acumuladorPositivos = acumuladorPositivos + numeroIngresado;
			contadorPositivos++;
		} else {
			acumuladorNegativos = acumuladorNegativos + numeroIngresado;
			contadorNegativos++;
		}
		printf("Desea agregar otro numero? (s para si): ");
		fflush(stdin);
		scanf("%c", &respuesta);

	} while (respuesta == 's');

	promedioNegativo = (float) acumuladorNegativos / contadorNegativos;
	promedioPositivo = (float) acumuladorPositivos / contadorPositivos;
	printf("a) El promedio de los positivos es: %.2f\n", promedioPositivo);
	printf("b) El promedio de los negativos es: %.2f\n", promedioNegativo);
	return 0;
}
