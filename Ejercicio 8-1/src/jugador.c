#include "jugador.h"
#include "utn.h"
#include "validaciones.h"
/// \fn eJugador CargarJugador(char[])
/// \brief Carga un jugador
/// \param mensaje El mensaje a pedir el jugador
/// \return El jugador cargado
eJugador CargarJugador(char mensaje[]) {
	eJugador jugador;
	int auxGoles;
	int auxPartidos;
	printf("%s",mensaje);
	utn_getName(jugador.nombre, 20, "Ingrese nombre del jugador: ",
			"Nombre invalido ", 4);
	utn_getInt(&auxGoles, 20, "Ingrese cantidad de goles: ",
			"Cantidad invalida ", 0, 300, 4, 0);
	utn_getInt(&auxPartidos, 20, "Ingrese cantidad de partidos: ",
			"Cantidad invalida ", 1, 300, 4, 0);
	jugador.goles = auxGoles;
	jugador.partidos = auxPartidos;
	return jugador;
}
/// \fn void MostrarJugador(eJugador)
/// \brief Muestra el jugador ingresado
/// \param jugador El jugador a mostrar
void MostrarJugador(eJugador jugador) {
	float promedio;
	PromedioGoles(jugador, &promedio);
	jugador.promedio = promedio;
	printf("Nombre: %s\nGoles: %d\nPartidos: %d\nPromedio de goles: %.2f",
			jugador.nombre, jugador.goles, jugador.partidos, jugador.promedio);
}
/// \fn void PromedioGoles(eJugador, float*)
/// \brief Calcula el promedio de goles por partido
/// \param jugador El jugador a calcular
/// \param promedio Puntero a la posicion donde guardar el promedio
void PromedioGoles(eJugador jugador, float *promedio) {
	*promedio = jugador.goles / (float) jugador.partidos;
}

