/*
 Ejercicio 7-1:
 Una empresa importadora que comercializa productos Apple, decide registrar de sus productos los siguientes datos:
 .idProducto (numerico)
 .descripcion (alfanumérico)
 .nacionalidad (numérico, por el momento utilizaremos un define: EEUU - CHINA - OTRO)
 .tipo (numérico, por el momento utilizaremos un define: IPHONE -MAC - IPAD - ACCESORIOS)
 .precio (numérico decimal)
 Realizar un programa que permita interactuar con un menú de usuarios con las siguientes opciones:
 i)ALTA Producto: Se ingresan los datos de UN solo producto. Siempre y cuando haya espacio disponible en el array.
 j)BAJA Producto: A partir del ingreso del ID. Si existe el producto desaparece de la lista, dejando espacio disponible para un nuevo producto.
 k)MODIFICACIÓN Producto: A partir del ingreso del ID. Si existe se podrá modificar el precio o el tipo.
 l)LISTADO Productos.
 m)LISTADO ordenado por precio.
 n)LISTADO ordenado por descripción.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "validaciones.h"
#include "productos.h"
#include "ordenamiento.h"
#include "listados.h"
#define TAM 4

int main(void) {
	setbuf(stdout, NULL);
	int idProducto[TAM] = { 0 };
	char descripcion[TAM][50] = { 0 };
	char nacionalidad[TAM][50] = { "EEUU", "CHINA", "ESPAÑA", "OTRO" };
	char tipo[TAM][50] = { "IPHONE", "MAC", "IPAD", "ACCESORIOS" };
	float precio[TAM] = { 0 };
	char opcion;
	do {
		printf("i.Alta Producto\n");
		printf("j.Baja Producto\n");
		printf("k.Modificar Producto\n");
		printf("l.Listado Productos\n");
		printf("m.Listado Ordenado por precio\n");
		printf("n.Listado Ordeando por descripcion\n");
		printf("o.Salir\n");
		printf("ingrese opcion(i-o): ");
		fflush(stdin);
		scanf("%c", &opcion);
		opcion = tolower(opcion);
		switch (opcion) {
		case 'i':
			AltaProducto(idProducto, descripcion, nacionalidad, tipo, precio,
			TAM);
			break;
		case 'j':
			BajaProducto(idProducto, descripcion, nacionalidad, tipo, precio,
			TAM);
			break;
		case 'k':
			ModificarProducto(idProducto, descripcion, nacionalidad, tipo,
					precio, TAM);
			break;
		case 'l':
			ListadoProductos(idProducto, descripcion, nacionalidad, tipo,
					precio, TAM);
			break;
		case 'm':
			if (OrdenarPrecio(idProducto, descripcion, nacionalidad, tipo,
					precio, TAM) == 0) {
				ListadoProductosPorPrecio(idProducto, descripcion, nacionalidad,
						tipo, precio, TAM);
			}
			break;
		case 'n':
			if (OrdenarDescripcion(idProducto, descripcion, nacionalidad, tipo,
					precio, TAM) == 0) {
				ListadoProductosPorDescripcion(idProducto, descripcion,
						nacionalidad, tipo, precio, TAM);
			}
			break;
		case 'o':
			printf("Gracias por usar nuestro servicio!");
			break;
		}

	} while (opcion >= 'i' && opcion <= 'n');

	return 0;
}

