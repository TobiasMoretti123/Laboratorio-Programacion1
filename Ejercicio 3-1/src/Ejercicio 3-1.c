/*
Tobias Moretti
Ejercicio 3-1:
Crear una función que muestre por pantalla el número flotante  que recibe como parámetro.
*/

#include <stdio.h>
#include <stdlib.h>

float MostrarFlotante(float numero);
int main(void)
{
	setbuf(stdout,NULL);
	float numeroFlotante;

	printf("Ingrese un numero con coma: ");
	scanf("%f", &numeroFlotante);
	MostrarFlotante(numeroFlotante);

	return 0;
}
float MostrarFlotante(float numero)
{
	float resultado;
	resultado = numero;

	printf("El numero con coma es: %.2f",resultado);

	return resultado;
}
