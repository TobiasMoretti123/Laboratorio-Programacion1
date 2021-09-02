#include <stdio.h>
#include <stdlib.h>

//1. definir la funcion "prototipo-firma"
//que devuelve? ComoSeLlama (que recibe)

int SumarNumeros (int primerNumero, int segundoNumero);
void MostrarUnEntero(int valor);

int main()
{
	setbuf(stdout,NULL);
	int suma;

	//3.invocar a la funcion.
	suma = SumarNumeros(4, 9);//parametros actuales.
	MostrarUnEntero(suma);

	return 0;
}
//2. Implementacion o desarrolo
int SumarNumeros (int primerNumero, int segundoNumero)//parametro formales
{//scope de la funcion
	int resultado;

	resultado = primerNumero + segundoNumero;

	return resultado;
}
void MostrarUnEntero(int valor)
{
	printf("el valor es:  %d",valor);
}
