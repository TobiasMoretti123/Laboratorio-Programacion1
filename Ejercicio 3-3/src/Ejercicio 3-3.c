/*
Tobias Moretti
Ejercicio 3-3:
Crear una función que pida el ingreso de un entero y lo retorne.
*/

#include <stdio.h>
#include <stdlib.h>

int PedirUnEntero (char mensaje[]);
int main(void)
{
	setbuf(stdout,NULL);
	int numeroIngresado;

	numeroIngresado = PedirUnEntero("Igrese un numero: ");

	printf("El entero ingresado es: %d",numeroIngresado);
}
int PedirUnEntero (char mensaje[],)
{
	int numeroIngresado;

	printf("%s",mensaje);
	scanf("%d",&numeroIngresado);

	return numeroIngresado;
}
