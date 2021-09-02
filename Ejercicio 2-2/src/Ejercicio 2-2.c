/*
Tobias Moretti
Ingresar 10 números enteros, distintos de cero. Mostrar:
a.Cantidad de pares e impares.
b.El menor número ingresado.
c.De los pares el mayor número ingresado.
d.Suma de los positivos.
e.Producto de los negativos.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	setbuf(stdout,NULL);
	int numeroIngresado;
	int cantidadPares;
	int cantidadImpares;
	int elMenorNumero;
	int elMayorPar;
	int sumaPositivos;
	int productoNegativos;

	cantidadPares = 0;
	cantidadImpares = 0;
	sumaPositivos = 0;
	productoNegativos = 1;

	for(int i=0;i<10;i++)
	{
		printf("Ingrese un numero: ");
		scanf("%d",&numeroIngresado);

		if(numeroIngresado % 2 == 0)
		{
			cantidadPares++;
		}
		else
		{
			cantidadImpares++;
		}
		if(i==1)
		{
			elMenorNumero = numeroIngresado;
		}
		else
		{
			if(cantidadPares == 1)
			{
				elMayorPar = numeroIngresado;
			}
		}
		if(elMenorNumero>numeroIngresado)
		{
			elMenorNumero = numeroIngresado;
		}
		else
		{
			if(elMayorPar<numeroIngresado)
			{
				elMayorPar = numeroIngresado;
			}
		}
		if(numeroIngresado<0)
		{
			productoNegativos = productoNegativos*numeroIngresado;
		}
		else
		{
			sumaPositivos = sumaPositivos + numeroIngresado;
		}
	}

	printf("a.La cantidad de pares es de %d y la cantidad de impares es de %d\n", cantidadPares,cantidadImpares);
	printf("b.El menor número ingresado es: %d\n",elMenorNumero);
	printf("c.De los pares el mayor número ingresado es: %d\n",elMayorPar);
	printf("d.La suma de los positivos es de: %d\n",sumaPositivos);
	printf("e.El producto de los negativos es de: %d\n",productoNegativos);

	return 0;
}
