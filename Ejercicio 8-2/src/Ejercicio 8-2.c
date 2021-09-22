/*
 Ejercicio 8-2:
 Una empresa importadora que comercializa productos Apple, decide registrar de sus productos los siguientes datos:
 .idProducto (numerico)
 .descripcion (alfanumérico)
 .nacionalidad (numérico, por el momento utilizaremos un define: EEUU - CHINA - OTRO)
 .tipo (numérico, por el momento utilizaremos un define: IPHONE -MAC - IPAD - ACCESORIOS)
 .precio (numérico decimal)
 Realizar un programa que permita interactuar con un menú de usuarios con las siguientes opciones:
 1)ALTA Producto: Se ingresan los datos de UN solo producto. Siempre y cuando haya espacio disponible en el array.
 2)BAJA Producto: A partir del ingreso del ID. Si existe el producto desaparece de la lista, dejando espacio disponible para un nuevo producto.
 3)MODIFICACIÓN Producto: A partir del ingreso del ID. Si existe se podrá modificar el precio o el tipo.
 4)LISTADO Productos.
 5)LISTADO ordenado por precio.
 6)LISTADO ordenado por descripción.
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "validaciones.h"
#define TAM 5

typedef struct {
	int idProducto;
	char descripcion[100];
	int nacionalidad;
	int tipo;
	float precio;
} eProducto;

void CargarProductos(eProducto lista[], int tam);
void MostrarListadoProductos(eProducto lista[], int tam);
void MostrarProducto(eProducto unProducto);
void OrdenarListaProductosPorId(eProducto lista[], int tam);
int main(void) {
	setbuf(stdout, NULL);
	eProducto listaProductos[TAM] = { { 1000, "Iphone 12", 1, 1, 1000 }, { 2000,
			"Macbook Air", 3, 2, 1200 }, { 5000, "Macsafe", 3, 4, 50 }, { 2500,
			"Ipad 5", 3, 3, 750 }, { 4000, "Ipad 3", 2, 3, 400 } };

	//CargarProductos(listaProductos, TAM);
	MostrarListadoProductos(listaProductos, TAM);
	printf("Lista Ordenada\n");
	OrdenarListaProductosPorId(listaProductos, TAM);
	MostrarListadoProductos(listaProductos, TAM);

	return 0;
}
void MostrarProducto(eProducto unProducto) {
	printf("%4d %20s %4d %4d %4.2f\n", unProducto.idProducto,
			unProducto.descripcion, unProducto.nacionalidad, unProducto.tipo,
			unProducto.precio);
}
void CargarProductos(eProducto lista[], int tam) {
	int auxID;
	int auxNac;
	int auxTipo;
	float auxPrecio;
	for (int i = 0; i < tam; i++) {
		lista[i].idProducto = get_int(&auxID, 20, "Ingresa una ID: ",
				"ID invalida ", 1, 1000, 4, 0);
		get_text(lista[i].descripcion, 50, "Ingrese descripcion: ",
				"Descripcion invalida ", 4);
		lista[i].nacionalidad = get_int(&auxNac, 20,
				"Ingrese una nacionalidad 1.EEUU 2.CHINA 3.OTROS: ",
				"Nacionalidad invalida ", 1, 3, 4, 0);
		lista[i].tipo = get_int(&auxTipo, 20,
				"Ingrese un tipo 1.IPHONE 2.MAC 3.IPAD 4.Accesorios: ",
				"tipo invalido ", 1, 4, 4, 0);
		lista[i].precio = get_float(&auxPrecio, 20, "Ingrese precio: ",
				"Precio invalido ", 1, 200000, 4, 0);
		lista[i].idProducto = auxID;
		lista[i].nacionalidad = auxNac;
		lista[i].tipo = auxTipo;
		lista[i].precio = auxPrecio;
	}
}
void MostrarListadoProductos(eProducto lista[], int tam) {
	printf("Id\tDescripcion\tNacionalidad\tTipo\tPrecio\n");
	for (int i = 0; i < tam; i++) {
		MostrarProducto(lista[i]);
	}
}
void OrdenarListaProductosPorId(eProducto lista[], int tam) {
	eProducto auxiliarProducto;
	for (int i = 0; i < tam - 1; i++) {
		for (int j = i + 1; j < tam; j++) {
			if (lista[i].idProducto < lista[j].idProducto) {
				auxiliarProducto = lista[i];
				lista[i] = lista[j];
				lista[j] = auxiliarProducto;
			}
		}
	}
}

