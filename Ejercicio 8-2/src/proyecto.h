#define EMPTY 0
#define FULL 1
typedef struct {
	int idProducto;
	char descripcion[100];
	int nacionalidad;
	int tipo;
	float precio;
	int isEmpty;
} eProducto;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifndef PROYECTO_H_
#define PROYECTO_H_

int AltaProducto(eProducto lista[], int tam);
int BajaProducto(eProducto lista[], int tam);
int ModificarProducto(eProducto lista[], int tam);
int ListadoProductos(eProducto lista[], int tam);
int ListadoOrdenadoPorPrecio(eProducto lista[], int tam);
int ListadoOrdenadoPorDesc(eProducto lista[], int tam);
void OrdenarListaProductosPorPrecio(eProducto lista[], int tam);
void OrdenarListaProductosPorDesc(eProducto lista[], int tam);
void InicialilarListaProducto(eProducto lista[], int tam);
void MostrarProducto(eProducto unProducto);
void MenuDeOpciones(eProducto lista[], int tam, char mensaje[]);
int BuscarEspacioVacio(eProducto lista[], int tam);
eProducto IngresarUnProducto();

#endif /* PROYECTO_H_ */
