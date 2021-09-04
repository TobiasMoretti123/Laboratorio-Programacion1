#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"
void PedirEntero(char mensaje[]) {
	int numeroIngresado;

	printf("%s", mensaje);
	scanf("%d", &numeroIngresado);
}

