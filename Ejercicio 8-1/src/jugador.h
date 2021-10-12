typedef struct {
	char nombre[50];
	int goles;
	int partidos;
	float promedio;
} eJugador;
#include <stdio.h>
#include <stdlib.h>

#ifndef JUGADOR_H_
#define JUGADOR_H_

eJugador CargarJugador(char mensaje[]);
void MostrarJugador(eJugador jugador);
void PromedioGoles(eJugador jugador, float *promedio);

#endif /* JUGADOR_H_ */
