/*
Ejercicio:
Realizar un programa que solicite cinco n�meros e imprima por pantalla el promedio, el m�ximo y el m�nimo.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	setbuf(stdout,NULL);
	int numeroIngresado;
	int acumulador;
	float promedio;
	int numeroMaximo;
	int numeroMinimo;

	acumulador = 0;

	for(int i = 0; i<5;i++)
	{
		printf("Ingrese un numero: ");
		scanf("%d",&numeroIngresado);

		acumulador = acumulador + numeroIngresado;

		if(i==0)
		{
			numeroMaximo = numeroIngresado;
			numeroMinimo = numeroIngresado;
		}

		if(numeroMaximo<numeroIngresado)
		{
			numeroMaximo = numeroIngresado;
		}
		else
		{
			if(numeroMinimo>numeroIngresado)
			{
				numeroMinimo = numeroIngresado;
			}
		}
	}
	promedio = (float)acumulador / 5;

	printf("El promedio de los numeros es de: %.2f\n", promedio);
	printf("El numero maximo es %d y el minimo es %d", numeroMaximo, numeroMinimo);
	return 0;
}
