#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifndef ORDENAMIENTO_H_
#define ORDENAMIENTO_H_

int OrdenarPrecio(int idProducto[], char descripcion[][50],
		char nacionalidad[][50], char tipo[][50], float precio[], int tam);
int OrdenarDescripcion(int idProducto[], char descripcion[][50],
		char nacionalidad[][50], char tipo[][50], float precio[], int tam);

#endif /* ORDENAMIENTO_H_ */
