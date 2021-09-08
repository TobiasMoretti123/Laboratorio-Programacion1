/*
 Diseñar un programa para jugar a adivinar un número entre 0 y 100.
 El juego tiene que dar pistas de si el número introducido por el jugador está por encima o por debajo.
 El juego termina cuando se adivina el número o se decide terminar de jugar ingresando un número negativo.
 Permitir jugar tantas veces como lo desee el jugador y al salir mostrar su mejor puntuación.
 */

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

int main(void) {
	setbuf(stdout, NULL);
	MenuDeJuego(
			"Adivine el numero entre 0 y 100 o escriba un negativo para salir: ",
			"Esta por encima del numero por diferecia de",
			"Esta por debajo del numero por diferencia de",
			"Su puntuacion es:");
	return 0;
}

