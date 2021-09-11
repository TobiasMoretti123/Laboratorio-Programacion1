/*
 Bibliotecas de ingreso de datos
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#define LONGITUD 64
int main(void) {
	setbuf(stdout, NULL);
	int numeroIngresado;
	float numeroDecimal;
	char texto[LONGITUD];
	utn_getNumero(&numeroIngresado, "Ingrese el numero entre 0 y 100: ",
			"Numero invalido o fuera de rango\n", 0, 100, 3);
	utn_getNumeroConDecimales(&numeroDecimal,
			"Ingrese numero decimal entre 0 y 100: ",
			"Numero invalido o fuera de rango\n", 0.0, 100.0, 3);
	utn_getTexto("Ingrese un texto: ", texto, 'z', 'A', "Reingrese texto\n",
			LONGITUD);
	printf("numero entero ingresado: %d\n", numeroIngresado);
	printf("numero decimal ingresado: %.2f\n", numeroDecimal);
	printf("El texto ingresado es: %s", texto);
	return 0;
	return EXIT_SUCCESS;
}

