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
 7)LISTADO IPHONE de EEUU

 Biblioteca de informes:
 Agregar los siguientes informes:
 El/los  productos m�s caros.
 Los productos que cuestan 700
 Precio promedio por tipo de producto.
 De los Iphone el m�s barato
 Los productos "MADE IN CHINA"
 Las MAC que cuestan m�s de 700 USD
 El/Los Accesorios m�s caros
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "validaciones.h"
#include "proyecto.h"

int main(void) {
	setbuf(stdout, NULL);
	eProducto listaProductos[TAM];
	InicialilarListaProducto(listaProductos, TAM);
	MenuDeOpciones(listaProductos, TAM,
			"1.Alta\n2.Baja\n3.Modificar\n4.Listado Productos\n5.Ordenar lista por precio\n6.Ordenar lista por descripcion\n7.Lista Iphone\n8.Informar\n9.Salir\n",
			9);
	return 0;
}


