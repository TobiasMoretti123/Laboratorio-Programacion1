/*
 ============================================================================
 Name        : Prueba.c
 Author      : Tobias
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int generarNumero(int numeroAnterior);
int main(void) {
	int numero = 2;
	int nuevoNumero;

	printf("%d\n",numero);
	nuevoNumero = generarNumero(numero);
	printf("%d",nuevoNumero);
	return 0;
}
int generarNumero(int numeroAnterior){
	int numero;
	if(numeroAnterior>=1)
	{
		numero = numeroAnterior+1;
	}

	return numero;
}

