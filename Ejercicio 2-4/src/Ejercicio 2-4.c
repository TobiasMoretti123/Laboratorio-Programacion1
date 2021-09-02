/*
Tobias Moretti
Ejercicio 2-4:
Ingresar 5 caracteres e informar cuantas letras p (minúsculas) se ingresaron.
*/
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	setbuf(stdout,NULL);
	char letraIngresada;
	int cantidadDeMinuscula;

	cantidadDeMinuscula =0;

	for(int i = 0; i<5; i++)
	{
		printf("Ingrese un caracter: ");
		fflush(stdin);
		scanf("%c",&letraIngresada);

		if(letraIngresada == 'p')
		{
			cantidadDeMinuscula++;
		}
	}

	printf("La cantidad de p minuscula ingresada es de: %d",cantidadDeMinuscula);
	return 0;
}
