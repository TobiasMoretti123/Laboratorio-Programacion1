/*
Tobias Moretti
Ejercicio 1-2: ingresar 3 números y mostrar cuál de los tres es el mayor.
Ejemplo:
Si ingresamos 5, 9 y 3 el programa mostrará: “El mayor de los números es el segundo”
*/

#include <stdio.h>
#include <stdlib.h>

int main()
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

	if(primerNumero>segundoNumero && primerNumero>tercerNumero)
	{
		printf("El mayor de los numeros es el primero");
	}
	else
	{
		if(segundoNumero>primerNumero && segundoNumero>tercerNumero)
		{
			printf("El mayor de los numeros es el segundo");
		}
		else
		{
			printf("El mayor de los numero es el tercero");
		}
	}
	return 0;
}
