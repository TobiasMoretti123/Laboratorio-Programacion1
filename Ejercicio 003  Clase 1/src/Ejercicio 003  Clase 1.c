/*
Tobias Moretti
Agregar al programa adjunto la funcionalidad resaltada con un (*)

- Limpie la pantalla
- Solicite dos valores numéricos al usuario distintos de cero *
- Asigne a las variables numero1 y numero2 los valores obtenidos
- Realice la resta de dichas variables
- Muestre el resultado por pantalla
- Muestre por pantalla la leyenda "Resultado positivo" en caso de ser mayor *
- Muestre por pantalla la leyenda "Resultado negativo" si es menor que cero *
*/

#include <stdio.h>
#include <stdlib.h>


int main()
{
	setbuf(stdout,NULL);
	int a;
	int b;
	int numero1;
	int numero2;
	int resultado;

	printf("Ingrese 1 numero: ");
	scanf("%d",&a);
	while(a==0)
	{
		printf("Error ingrese numero distinto de 0: ");
		scanf("%d",&a);
	}
	printf("Ingrese 2 numero: ");
	scanf("%d",&b);
	while(b==0)
	{
		printf("Error ingrese numero distinto de 0: ");
		scanf("%d",&b);
	}
	numero1=a;
	numero2=b;
	resultado=numero1-numero2;

	printf("El resultado es: %d \n",resultado);
	if(resultado>0)
	{
        printf("Resultado positivo \n");
	}
	if(resultado<0)
	{
        printf("Resultado negativo \n");
	}

	return 0;
}
