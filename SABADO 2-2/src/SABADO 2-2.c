/*
Ejercicio 2-2:
Realizar un programa que permita el ingreso de 10 números enteros.
Determinar el promedio de los positivos, la cantidad de ceros y
del menor de los negativos la suma de los antecesores.
Nota:
Utilizar la función del punto anterior y
desarrollar funciones para resolver los procesos que están resaltados.
*/

#include <stdio.h>
#include <stdlib.h>
int PedirEntero(int numero);
int SumaAntecesores(int numero, int cantidad);
float PromedioPositivos(int numero, int cantidad);
int main(void) {
	setbuf(stdout, NULL);
	int numeroIngresado;
	int cantidadCeros;
	float promedio;
	int elMenorNumero;
	int suma;
	cantidadCeros = 0;
	for(int i=0;i<10;i++)
	{
		printf("Ingrese un numero entero: ");
		scanf("%d", &numeroIngresado);
		if(PedirEntero(numeroIngresado)==0)
		{
			cantidadCeros++;
		}
		else
		{
			if(PedirEntero(numeroIngresado)==1)
			{
				promedio = PromedioPositivos(numeroIngresado, i);
			}
			else
			{
				if(i==1)
				{
					elMenorNumero = numeroIngresado;
					suma = SumaAntecesores(numeroIngresado, i);
				}
			}
		}
		if(elMenorNumero>numeroIngresado)
		{
			elMenorNumero = numeroIngresado;
		}
	}
	printf("El promedio de los positivos es: %.2f\n",promedio);
	printf("La cantidad de ceros es: %d\n", cantidadCeros);
	printf("El menor numero negativo es: %d y la suma de sus antecesores es: %d",elMenorNumero,suma);
	return 0;
}
int PedirEntero(int numero) {
	int retorno;
	if (numero == 0) {
		retorno = 0;
	} else {
		if (numero > 0) {
			retorno = 1;
		} else {
			retorno = -1;
		}
	}
	return retorno;
}
float PromedioPositivos(int numero, int cantidad)
{
	float resultado;
	int acumulador;
	acumulador = 0;

	for(int i;i<cantidad;i++)
	{
		acumulador = acumulador + numero;
	}
	resultado = (float)acumulador/cantidad;

	return resultado;
}
int SumaAntecesores(int numero, int cantidad)
{
	int resultado;
	int acumulador;
	acumulador = 0;
	for(int i;i<cantidad;i++)
	{
		acumulador = acumulador + numero;
	}
	resultado = acumulador;
	return resultado;
}
