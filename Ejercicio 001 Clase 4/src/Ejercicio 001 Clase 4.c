/*
 Dise�ar un programa para jugar a adivinar un n�mero entre 0 y 100.
 El juego tiene que dar pistas de si el n�mero introducido por el jugador est� por encima o por debajo.
 El juego termina cuando se adivina el n�mero o se decide terminar de jugar ingresando un n�mero negativo.
 Permitir jugar tantas veces como lo desee el jugador y al salir mostrar su mejor puntuaci�n.
 */

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#define NUMERO 70

int main(void) {
	setbuf(stdout, NULL);
	MenuDeJuego(
			"Adivine el numero entre 0 y 100 o escriba un negativo para salir: ",
			"Lo ingresado esta por debajo del numero por diferecia de",
			"Lo ingresado esta por arriba del numero por diferencia de",
			"Su puntuacion es:",NUMERO);
	return 0;
}

