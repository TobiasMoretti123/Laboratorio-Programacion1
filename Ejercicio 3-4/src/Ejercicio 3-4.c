/*
Ejercicio 3-4:
Especializar la función anterior para que permita validar el entero ingresado en un rango determinado.
*/

#include <stdio.h>
#include <stdlib.h>

int PedirUnEntero ();
int main(void)
{
	setbuf(stdout,NULL);
	int numeroIngresado;

	numeroIngresado = PedirUnEntero();

	printf("El entero ingresado es: %d",numeroIngresado);
}
int PedirUnEntero ()
{
	int retorno;

	printf("Ingrese un numero entero: ");
	scanf("%d",&retorno);
	while(retorno<0 || retorno>120)
	{
		printf("El valor debe ser entre 0 y 120: ");
		scanf("%d",&retorno);
	}

	return retorno;
}
