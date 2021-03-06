/*
Tobias Moretti
Ejercicio 2-3:
Debemos alquilar el servicio de transporte para llegar a Mar del Plata con un grupo de personas,
de cada persona debemos obtener los siguientes datos:
n?mero de cliente,
estado civil ('s' para soltero, 'c' para casado o 'v' viudo),
edad( solo mayores de edad, m?s de 17),
temperatura corporal (validar por favor)
y genero('f' para femenino, 'm' para masculino, 'o' para no binario).
NOTA: El precio por pasajero es de $600.
Se debe informar (solo si corresponde):
a) La cantidad de personas con estado "viudo" de m?s de 60 a?os.
b) el n?mero de cliente y edad de la mujer soltera m?s joven.
c) cu?nto sale el viaje total sin descuento.
d) si hay m?s del 50% de los pasajeros que tiene m?s de 60 a?os ,
el precio final tiene un descuento del 25%, que solo mostramos si corresponde.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define PASAJE 600
#define DESCUENTO 25

int main(void)
{
	setbuf(stdout,NULL);
	int numeroCliente;
	char estadoCivil;
	int edad;
	float temperaturaCorporal;
	char genero;
	char respuesta;
	int numeroDeLaMasJoven;
	int laMasJoven;
	int cantidadViudos;
	int cantidadPersonas;
	int cantidadMayoresDeSesenta;
	int precioViaje;
	int precioConDescuento;

	respuesta = 's';
	cantidadViudos = 0;
	cantidadPersonas = 0;
	cantidadMayoresDeSesenta = 0;

	do
	{
		printf("Ingrese numero de cliente: ");
		scanf("%d",&numeroCliente);
		printf("Ingrese estado civil 's' para soltero, 'c' para casado o 'v' viudo: ");
		fflush(stdin);
		scanf("%c",&estadoCivil);
		estadoCivil = tolower(estadoCivil);
		while(estadoCivil!='s'&&estadoCivil!='c'&&estadoCivil!='v')
		{
			printf("Error reingrese dato 's' para soltero, 'c' para casado o 'v' viudo: ");
			fflush(stdin);
			scanf("%c",&estadoCivil);
			estadoCivil = tolower(estadoCivil);
		}
		printf("Ingrese edad mayor de 17 a?os: ");
		scanf("%d",&edad);
		while(edad<17||edad>120)
		{
			printf("Error ingrese edad valida: ");
			scanf("%d",&edad);
		}
		printf("Ingrese temperatura corporal: ");
		scanf("%f", &temperaturaCorporal);
		while(temperaturaCorporal<35.0 || temperaturaCorporal>41.0)
		{
			printf("Ingrese temperatura corporal valida(entre 35 y 41: ");
			scanf("%f",&temperaturaCorporal);
		}
		printf("Ingrese genero 'f' para femenino, 'm' para masculino, 'o' para no binario: ");
		fflush(stdin);
		scanf("%c",&genero);
		genero = tolower(genero);
		while(genero!='f'&&genero!='m'&&genero!='o')
		{
			printf("Error reingrese dato 'f' para femenino, 'm' para masculino, 'o' para no binario: ");
			fflush(stdin);
			scanf("%c",&genero);
			genero = tolower(genero);
		}
		if(estadoCivil=='v' && edad>60)
		{
			cantidadViudos++;
		}
		if(edad>60)
		{
			cantidadMayoresDeSesenta++;
		}
		cantidadPersonas++;

		if(cantidadPersonas==1 && estadoCivil =='s' && genero == 'f')
		{
			laMasJoven = edad;
			numeroDeLaMasJoven = numeroCliente;
		}

		if(laMasJoven>edad)
		{
			laMasJoven = edad;
			numeroDeLaMasJoven = numeroCliente;
		}

		printf("Desea continuar? (s para si): ");
		fflush(stdin);
		scanf("%c",&respuesta);
		respuesta=tolower(respuesta);

	}while(respuesta == 's');

	precioViaje = PASAJE*cantidadPersonas;
	printf("a) La cantidad de personas con estado viudo de m?s de 60 a?os es de: %d\n",cantidadViudos);
	printf("b) el n?mero de cliente de la mujer mas joven es %d y su edad es de %d\n",numeroDeLaMasJoven,laMasJoven);
	printf("c) El viaje sin descuento es de: %d\n",precioViaje);

	if(cantidadPersonas % 2 == 0)
	{
		if(cantidadPersonas/2 <= cantidadMayoresDeSesenta)
		{
			precioConDescuento = (float)precioViaje*DESCUENTO/100;
			printf("d) El precio final con descuento es de: %d",precioConDescuento);
		}
	}

	if(cantidadPersonas/2 <= cantidadMayoresDeSesenta*0.5)
	{
		precioConDescuento = (float)precioViaje*DESCUENTO/100;
		printf("d) El precio final con descuento es de: %d",precioConDescuento);
	}
	return 0;
}
