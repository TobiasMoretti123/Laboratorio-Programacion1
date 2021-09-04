/*
Ejemplo de Menu
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);
	int opcion;
	do {
		printf("1.Alta\n");
		printf("2.Baja\n");
		printf("3.Modificar\n");
		printf("4.Salir\n");
		printf("Elija una opcion: ");
		scanf("%d", &opcion);
		switch (opcion) {
		case 1:
			printf("Estoy dando de alta\n");
			break;
		case 2:
			printf("Estoy dando de baja\n");
			break;
		case 3:
			printf("Estoy modificando\n");
			break;
		}

	} while (opcion != 4);
	return EXIT_SUCCESS;
}
