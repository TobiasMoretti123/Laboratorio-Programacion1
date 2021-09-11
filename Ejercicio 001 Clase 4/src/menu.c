#include "menu.h"
void MenuDeJuego(char mensaje[], char mensajePista1[], char mensajePista2[],
		char mensajePuntuacion[],int respuesta) {
	int numero;
	int puntuacion;
	int resta;
	puntuacion = 0;
	do {
		printf("%s", mensaje);
		scanf("%d", &numero);
		if (numero > respuesta && numero <= 100) {
			resta = numero - respuesta;
			printf("%s %d\n", mensajePista1, resta);
			puntuacion++;
		} else {
			if (numero < respuesta && numero > 0) {
				resta = respuesta - numero;
				printf("%s %d\n", mensajePista2, resta);
				puntuacion++;
			} else {
				if (numero == respuesta) {
					printf("Ganaste el juego!!! ");
					puntuacion = 10;
					break;
				}
			}
		}
	} while (numero > 0);
	printf("%s %d/10", mensajePuntuacion, puntuacion);
}
