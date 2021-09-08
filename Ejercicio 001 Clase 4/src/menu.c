#include "menu.h"
void MenuDeJuego(char mensaje[], char mensajePista1[], char mensajePista2[],
		char mensajePuntuacion[]) {
	int numero;
	int puntuacion;
	int resta;
	puntuacion = 0;
	do {
		printf("%s", mensaje);
		scanf("%d", &numero);
		if (numero > NUMERO && numero <= 100) {
			resta = numero - NUMERO;
			printf("%s %d\n", mensajePista1, resta);
			puntuacion++;
		} else {
			if (numero < NUMERO && numero >= 0) {
				resta = NUMERO - numero;
				printf("%s %d\n", mensajePista2, resta);
				puntuacion++;
			} else {
				if (numero == NUMERO) {
					printf("Ganaste el juego!!! ");
					puntuacion = 10;
					break;
				}
			}
		}
	} while (numero > 0);
	printf("%s %d/10", mensajePuntuacion, puntuacion);
}
