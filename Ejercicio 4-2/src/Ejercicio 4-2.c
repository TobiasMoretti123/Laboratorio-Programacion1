/*
 Tobias Moretti
 Ejercicio 4-2:
 Realizar un programa que permita la carga de temperaturas en celsius y fahrenheit ,
 validando que las temperaturas ingresadas estén entre el punto de congelación y ebullición del agua
 para cada tipo de escala.
 Las validaciones se hacen en una biblioteca.
 Las funciones de transformación de fahrenheit a celsius y de celsius a fahrenheit se hacen en otra biblioteca.
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Convertor.h"
#include "validacion.h"

int main(void) {
	setbuf(stdout, NULL);
	float resultado;
	float temperaturaValida;
	char tipoTemperatura;

	printf("Presiona c para convertir temperatura de farenheit a celcius");
	printf("\nPresiona f para convertir temperatura de celcius a farenheit");
	printf("\nElija una opcion (c o f): ");
	fflush(stdin);
	scanf("%c", &tipoTemperatura);
	tipoTemperatura = tolower(tipoTemperatura);
	while (tipoTemperatura != 'c' && tipoTemperatura != 'f') {
		printf("Error por favor ingrese f o c: ");
		fflush(stdin);
		scanf("%c", &tipoTemperatura);
		tipoTemperatura = tolower(tipoTemperatura);
	}
	switch (tipoTemperatura) {
	case 'c':
		temperaturaValida = ValidarTemperatura(
				"Ingrese temperatura en farenheit: ", 32.0, 212.0,
				"Reingrese dato: ");
		resultado = DeCelciusAFarenheit(temperaturaValida);
		printf("La temperatura en celcius es de: %.2f°c", resultado);
		break;
	case 'f':
		temperaturaValida = ValidarTemperatura(
				"Ingrese temperatura en celcius: ", 0.0, 100.0,
				"Reingrese dato: ");
		resultado = DeFarenheitACelsius(temperaturaValida);
		printf("La temperatura en farenheit es de: %.2f°f", resultado);
		break;
	}

	return 0;
}

