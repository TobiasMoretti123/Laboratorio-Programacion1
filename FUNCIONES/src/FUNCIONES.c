#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

//1. definir la funcion "prototipo-firma"
//que devuelve? ComoSeLlama (que recibe)

int main() {
	setbuf(stdout, NULL);
	int edad;

	//3.invocar a la funcion.
	PedirEntero("Ingrese edad: ");
	scanf("%d", &edad);

	return 0;
}
//2. Implementacion o desarrolo


