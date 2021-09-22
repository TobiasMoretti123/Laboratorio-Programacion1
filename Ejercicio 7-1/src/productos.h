#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifndef PRODUCTOS_H_
#define PRODUCTOS_H_

void AltaProducto(int idProducto[], char descripcion[][50],
		char nacionalidad[][50], char tipo[][50], float precio[], int tam);
void BajaProducto(int idProducto[], char descripcion[][50],
		char nacionalidad[][50], char tipo[][50], float precio[], int tam);
void ModificarProducto(int idProducto[], char descripcion[][50],
		char nacionalidad[][50], char tipo[][50], float precio[], int tam);

#endif /* PRODUCTOS_H_ */
