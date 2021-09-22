#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#ifndef LISTADOS_H_
#define LISTADOS_H_

void ListadoProductos(int idProducto[], char descripcion[][50],
		char nacionalidad[][50], char tipo[][50], float precio[], int tam);
void ListadoProductosPorPrecio(int idProducto[], char descripcion[][50],
		char nacionalidad[][50], char tipo[][50], float precio[], int tam);
void ListadoProductosPorDescripcion(int idProducto[], char descripcion[][50],
		char nacionalidad[][50], char tipo[][50], float precio[], int tam);

#endif /* LISTADOS_H_ */
