/*
 Tobias Moretti
 Ejercicio 8-1:
 Crear la estructura Jugador (nombre, goles metidos, partidos jugados, promedio de goles).
 Crear una función que permita cargar los datos de un jugador y otra que los muestre.
 Una tercera función calculará el promedio de goles.
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "validaciones.h"
#include "jugador.h"
int main(void) {
	setbuf(stdout, NULL);
	eJugador unJugador;
	unJugador = CargarJugador("Ingrese un jugador\n");
	MostrarJugador(unJugador);
	return 0;
}


