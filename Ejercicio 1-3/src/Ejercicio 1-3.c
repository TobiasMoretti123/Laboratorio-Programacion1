/*
Tobias Moretti
Ejercicio 1-3: ingresar 3 n�meros y mostrar el n�mero del medio,
s�lo si existe. En caso de que no exista tambi�n informarlo.
Ejemplo:
1   5   3    el 3 es del medio
5   1   5    no hay numero del medio
3  	5   1    el 3 es del medio
3   1   5    el 3 es del medio
5   3   1    el 3 es del medio

 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	setbuf(stdout,NULL);
	int primerNumero;
	int segundoNumero;
	int tercerNumero;

	printf("Ingrese primer numero: ");
	scanf("%d",&primerNumero);
	printf("Ingrese segundo numero: ");
	scanf("%d",&segundoNumero);
	printf("Ingrese tercer numero: ");
	scanf("%d",&tercerNumero);

	if((primerNumero<segundoNumero && primerNumero>tercerNumero)||(primerNumero>segundoNumero && primerNumero<tercerNumero))
	{
		printf("El %d es el del medio",primerNumero);
	}
	else
	{
		if((segundoNumero<primerNumero && segundoNumero>tercerNumero)||(segundoNumero>primerNumero && segundoNumero<tercerNumero))
		{
			printf("El %d es el del medio",segundoNumero);
		}
		else
		{
			if((tercerNumero<segundoNumero && tercerNumero>primerNumero)||(tercerNumero>segundoNumero && tercerNumero<primerNumero))
			{
				printf("El %d es el del medio",tercerNumero);
			}
			else
			{
				printf("No hay numero del medio");
			}
		}
	}
	return 0;
}
