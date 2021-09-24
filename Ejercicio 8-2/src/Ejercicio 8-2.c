/*
 Ejercicio 8-2:
 Una empresa importadora que comercializa productos Apple, decide registrar de sus productos los siguientes datos:
 .idProducto (numerico)
 .descripcion (alfanum�rico)
 .nacionalidad (num�rico, por el momento utilizaremos un define: EEUU - CHINA - OTRO)
 .tipo (num�rico, por el momento utilizaremos un define: IPHONE -MAC - IPAD - ACCESORIOS)
 .precio (num�rico decimal)
 Realizar un programa que permita interactuar con un men� de usuarios con las siguientes opciones:
 1)ALTA Producto: Se ingresan los datos de UN solo producto. Siempre y cuando haya espacio disponible en el array.
 2)BAJA Producto: A partir del ingreso del ID. Si existe el producto desaparece de la lista, dejando espacio disponible para un nuevo producto.
 3)MODIFICACI�N Producto: A partir del ingreso del ID. Si existe se podr� modificar el precio o el tipo.
 4)LISTADO Productos.
 5)LISTADO ordenado por precio.
 6)LISTADO ordenado por descripci�n.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "validaciones.h"
#include "proyecto.h"
#define TAM 2

int main(void) {
	setbuf(stdout, NULL);
	eProducto listaProductos[TAM];

	InicialilarListaProducto(listaProductos, TAM);
	MenuDeOpciones(listaProductos, TAM,
			"1.Alta\n2.Baja\n3.Modificar\n4.Listado Productos\n5.Listado Ordenado por ID\n6.Listado Ordenado por precio\n7.Salir\n");

	return 0;
}

