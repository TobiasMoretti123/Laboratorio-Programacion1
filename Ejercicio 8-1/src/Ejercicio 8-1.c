/*
 ============================================================================
 Name        : Ejercicio.c
 Author      : Tobias
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define TAM 5

typedef struct {
	int idProducto;
	char descripcion[100];
	int nacionalidad;
	int tipo;
	float precio;
} eProducto;

void MostrarProducto(eProducto unProducto);
int main(void) {
	setbuf(stdout, NULL);
	eProducto miProducto = { 1000, "Iphone 12", 1, 1, 1000 };
	eProducto listaProductos[TAM];

	MostrarProducto(miProducto);

	return 0;
}
void MostrarProducto(eProducto unProducto) {
	printf("%d %s %d %d %.2f\n", unProducto.idProducto, unProducto.descripcion,
			unProducto.nacionalidad, unProducto.tipo, unProducto.precio);
}
