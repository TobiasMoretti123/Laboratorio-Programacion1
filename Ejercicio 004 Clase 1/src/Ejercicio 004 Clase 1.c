/*
Tobias Moretti
Escribir un programa que realice las siguientes acciones:

- Solicite al usuario 10 n?meros
- Calcule cu?ntos son negativos y cuantos son positivos
- Muestre por pantalla la cantidad de negativos y la cantidad de positivos
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	setbuf(stdout,NULL);
	int numeroIngresado;
	int cantidadNegativos;
	int cantidadPositivos;

	cantidadNegativos = 0;
	cantidadPositivos = 0;

	for(int i=0;i<10;i++)
	{
		printf("Ingrese un numero: ");
		scanf("%d", &numeroIngresado);

		if(numeroIngresado<0)
		{
			cantidadNegativos++;
		}
		else
		{
			cantidadPositivos++;
		}
	}
	printf("La cantidad de numeros positivos es de %d y la cantidad de negativos es de %d",cantidadPositivos,cantidadNegativos);

	return 0;
}
