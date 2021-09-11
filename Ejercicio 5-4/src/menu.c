#include "menu.h"
#include "ingreso.h"
#include "arrays.h"
void MenuDeOpciones(char opcion1[], char opcion2[], char opcion3[],
		char opcion4[], char opcion5[], char respuesta1[], char respuesta2[],
		char respuesta3[], char respuesta4[], char respuesta5[], int array[],
		int tam) {
	int opcion;
	do {
		printf("%s\n", opcion1);
		printf("%s\n", opcion2);
		printf("%s\n", opcion3);
		printf("%s\n", opcion4);
		printf("%s\n", opcion5);
		printf("Elija una opcion: ");
		scanf("%d", &opcion);
		if (opcion < 1 || opcion > 6) {
			printf("Error ingrese una opcion valida entre(1y5): ");
			scanf("%d", &opcion);
		}
		switch (opcion) {
		case 1:
			InicializarArray(array, tam);
			break;
		case 2:
			CargarVectorEnteros(array, tam);
			break;
		case 3:
			printf("%s\n", respuesta3);
			break;
		case 4:
			printf("%s\n", respuesta4);
			break;
		case 5:
			printf("%s\n", respuesta5);
			break;
		}

	} while (opcion != 6);
}

