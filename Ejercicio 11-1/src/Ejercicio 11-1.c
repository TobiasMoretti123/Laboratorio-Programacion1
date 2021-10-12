/*
 Ejercicio 11-1
 Tobias Moretti
 1.ALTA Producto: Se ingresan los datos de UN solo producto. Siempre y cuando haya espacio disponible en el array.
 Al momento de dar de alta el producto, el usuario podrá elegir el tipo de producto,
 de una lista que se le desplegará en pantalla.
 2.BAJA Producto: A partir del ingreso del ID. Si existe el producto desaparece de la lista,
 dejando espacio disponible para un nuevo producto.
 3.MODIFICACIÓN Producto: A partir del ingreso del ID. Si existe se podrá modificar el precio o el tipo.
 Si modifica el tipo de producto, se utilizará el mismo criterio que para dar de alta.
 4.LISTADO Productos.
 5.LISTADO ordenado por precio.
 6.LISTADO ordenado por descripción.
 Agregar los siguientes informes:
 7.El/los  productos más caros.
 8.Precio promedio por tipo de producto. Se deberá mostrar la descripción del tipo y a continuación el precio promedio.
 9.El listado de todos los productos con la descripción del tipo.
 10.Por cada tipo la lista de productos.
 11.El/los tipos de productos con mas productos elaborados.
 */
//Biblioteca intermedia funciones que compartan estructuras

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "validaciones.h"
#include "productos.h"

#define TAMPRODUCTO 5
#define TAMTIPO 4
#define TAMNACIONALIDAD 3

int main(void) {
	setbuf(stdout, NULL);
	eProducto listaProductos[TAMPRODUCTO];
	eTipo listaTipo[TAMTIPO] = { { 1000, "Iphone" }, { 1001, "Ipad" }, { 1002,
			"Mac" }, { 1003, "Accesorios" } };
	eNacionalidad listaNacionalidad[TAMNACIONALIDAD] = { { 1, "EEUU" }, { 2,
			"CHINA" }, { 3, "OTRO" } };
	InicializarProductos(listaProductos, TAMPRODUCTO);
	MenuDeOpciones(listaProductos, listaTipo, listaNacionalidad, TAMPRODUCTO,
	TAMTIPO, TAMNACIONALIDAD);
	return 0;
}


