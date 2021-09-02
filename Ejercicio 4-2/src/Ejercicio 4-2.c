/*
Tobias Moretti
Ejercicio 4-2:
Realizar un programa que permita la carga de temperaturas en celsius y fahrenheit ,
validando que las temperaturas ingresadas estén
entre el punto de congelación y ebullición del agua para cada tipo de escala.
Las validaciones se hacen en una biblioteca.
Las funciones de transformación de fahrenheit a celsius y de celsius a fahrenheit se hacen en otra biblioteca.
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Validacion.h"

int main(void)
{
	setbuf(stdout,NULL);
	float temperaturaIngresada;
	float temperaturaValida;
	char tipo;

	printf("Que tipo de temperatura desea?, c(celcius) f(farenheit): ");
	fflush(stdin);
	scanf("%c",&tipo);
	tipo = tolower(tipo);
	while(tipo!='c'&&tipo != 'f')
	{
		printf("Error ingrese c(celcius) o f(farenheit): ");
		fflush(stdin);
		scanf("%c",&tipo);
		tipo = tolower(tipo);
	}
	printf("Ingrese temperatura: ");
	scanf("%f", &temperaturaIngresada);

	switch (tipo)
	{
		case 'f':
			if(ValidarTemperatura(temperaturaIngresada, 212.0, 32.0)==1)
			{
				printf("La temperatura ingresada en farenheit es de: %.2f°f",temperaturaIngresada);
			}
			break;
		case 'c':
			if(ValidarTemperatura(temperaturaIngresada, 100.0, 0.0)==1)
			{
				printf("La temperatura ingresada en celcius es de: %.2f°c",temperaturaIngresada);
			}
			break;
	}
	return 0;
}

