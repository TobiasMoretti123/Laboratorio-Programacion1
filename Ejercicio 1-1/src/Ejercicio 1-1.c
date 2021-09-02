/*
Tobias Moretti
Ejercicio 1-1: Ingresar dos números enteros, sumarlos y mostrar el resultado.
Ejemplo:
Si ingresamos 3 y 2 el programa mostrará: “La suma entre 3 y 2 da como resultado 5”
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	setbuf(stdout,NULL);
	int primerNumero;
	int segundoNumero;
	int suma;

	printf("Ingrese primer numero: ");
	scanf("%d",&primerNumero);
	printf("Ingrese segundo numero: ");
	scanf("%d",&segundoNumero);

	suma = primerNumero + segundoNumero;

	printf("La suma es: %d",suma);


	return 0;
}
