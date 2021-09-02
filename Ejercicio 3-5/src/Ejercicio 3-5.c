/*
Tobias Moretti
Ejercicio 3-5:
Realizar un programa en donde se puedan utilizar los prototipos de la función Sumar en sus 4 combinaciones.
int Sumar1(int, int);
int Sumar2(void);
void  Sumar3(int, int);
void Sumar4(void);
*/

#include <stdio.h>
#include <stdlib.h>
int Sumar1(int, int);
int Sumar2(void);
void Sumar3(int, int);
void Sumar4(void);
int main(void)
{
	setbuf(stdout,NULL);
	int primerNumero;
	int segundoNumero;
	int suma1;
	int suma2;

	printf("Ingrese primer numero de la primer suma y tercera: ");
	scanf("%d", &primerNumero);
	printf("Ingrese segundo numero de la primer suma y tercera: ");
	scanf("%d", &segundoNumero);
	suma1 = Sumar1(primerNumero,segundoNumero);
	suma2 = Sumar2();
	Sumar3(primerNumero, segundoNumero);
	Sumar4();

	printf("El resultado de la primer suma es: %d\n",suma1);
	printf("El resultado de la segunda suma es: %d\n",suma2);

	return 0;
}
int Sumar1(int numero1, int numero2)
{
	int resultado;

	resultado = numero1 + numero2;

	return resultado;
}
int Sumar2(void)
{
	int resultado;
	int numero1;
	int numero2;

	printf("Ingrese un numero de la segunda suma: ");
	scanf("%d", &numero1);
	printf("Ingrese otro numero de la segunda suma: ");
	scanf("%d", &numero2);

	resultado = numero1 + numero2;

	return resultado;
}
void Sumar3(int numero1, int numero2)
{
	int resultado;

	resultado = numero1 + numero2;

	printf("El resultado de la tercer suma es: %d\n",resultado);

}
void Sumar4(void)
{
	int resultado;
	int numero1;
	int numero2;

	printf("Ingrese un numero de la cuarta suma: ");
	scanf("%d", &numero1);
	printf("Ingrese otro numero de la cuarta suma: ");
	scanf("%d", &numero2);

	resultado = numero1 + numero2;

	printf("El resultado de la cuarta suma es: %d\n", resultado);
}
