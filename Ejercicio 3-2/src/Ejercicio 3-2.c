/*
Tobias Moretti
Ejercicio 3-2:
Crear una función que permita determinar si un número es par o no. La función retorna 1 en caso afirmativo y 0 en caso contrario. Probar en el main.
*/
#include <stdio.h>
#include <stdlib.h>

int EsPar (int numero);
int main(void)
{
	setbuf(stdout,NULL);
	int numeroIngresado;

	printf("ingrese un numero: ");
	scanf("%d", &numeroIngresado);
	if(EsPar(numeroIngresado)==1)
	{
		printf("Es par");
	}
	else
	{
		printf("No es par");
	}

	return 0;
}
int EsPar (int numero)
{
	int resultado;

	if(numero % 2 == 0)
	{
		resultado = 1;
	}
	else
	{
		resultado = 0;
	}

	return resultado;
}
