/*
Tobias Moretti
Crear un proyecto desde cero en Eclipse y modificar en el mensaje de "Hello world" por el de "Hola mundo".
*/
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	setbuf(stdout,NULL);
	puts("Hola Mundo");
	return 0;
}
