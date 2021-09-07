/*
 Dise�ar un programa para jugar a adivinar un n�mero entre 0 y 100.
 El juego tiene que dar pistas de si el n�mero introducido por el jugador est� por encima o por debajo.
 El juego termina cuando se adivina el n�mero o se decide terminar de jugar ingresando un n�mero negativo.
 Permitir jugar tantas veces como lo desee el jugador y al salir mostrar su mejor puntuaci�n.
 */

#include <stdio.h>
#include <stdlib.h>

void MenuDeJuego(char mensaje[], char mensajePista1[], char mensajePista2[],
		char mensajePuntuacion[]);
int main(void) {
	setbuf(stdout, NULL);
	MenuDeJuego(
			"Adivine el numero entre 0 y 100 o escriba un negativo para salir: ",
			"Esta por encima del numero: ", "Esta por debajo del numero: ",
			" Su puntuacion es: ");
	return 0;
}
void MenuDeJuego(char mensaje[], char mensajePista1[], char mensajePista2[],
		char mensajePuntuacion[]) {
	int numero;
	int puntuacion;
	printf("%s", mensaje);
	scanf("%d", &numero);
	puntuacion = 10;
	do {
		if (numero > 37 && numero <= 100) {
			printf("%s", mensajePista1);
			scanf("%d", &numero);
			puntuacion--;
		} else {
			if (numero < 37 && numero >= 0) {
				printf("%s", mensajePista2);
				scanf("%d", &numero);
				puntuacion--;
			} else {
				if (numero == 37) {
					printf("Ganaste el juego!!!");
					break;
				}
			}
		}
	} while (numero > 0);
	printf("%s %d/100", mensajePuntuacion, puntuacion);
}
