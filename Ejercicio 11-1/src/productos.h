typedef struct {
	int idProducto;
	char descripcion[50];
	int tipo;
	int nacionalidad;
	float precio;
	int isEmpty;
} eProducto;

typedef struct {
	int idTipo;
	char descripcion[50];
} eTipo;

typedef struct {
	int idNacionalidad;
	char descripcion[50];
} eNacionalidad;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#ifndef PRODUCTOS_H_
#define PRODUCTOS_H_

void MenuDeOpciones(eProducto arrayProductos[], eTipo arrayTipo[],
		eNacionalidad arrayNacionalidad[], int tamProductos, int tamTipo,
		int tamNacionalidad);
void MenuInformes(eProducto arrayProductos[], eTipo arrayTipo[],
		eNacionalidad arrayNacionalidad[], int tamProductos, int tamTipo,
		int tamNacionalidad);
void MenuListados(eProducto arrayProductos[], eTipo arrayTipo[],
		eNacionalidad arrayNacionalidad[], int tamProductos, int tamTipo,
		int tamNacionalidad);
int InicializarProductos(eProducto arrayProductos[], int tamProductos);
int BuscarEspacioVacio(eProducto lista[], int tam);
int BuscarID(eProducto arrayProductos[], int tamProducto, int auxId);
int IngresarTipo(eTipo arrayTipo[], int tamTipo);
int IngresarNacionalidad(eNacionalidad arrayNacionalidad[], int tamNacionalidad);
eProducto IngresarProducto(eTipo arrayTipo[], eNacionalidad arrayNacionalidad[],
		int tamTipo, int tamNacionalidad);
int AltaProducto(eProducto arrayProductos[], eTipo arrayTipo[],
		eNacionalidad arrayNacionalidad[], int tamProductos, int tamTipo,
		int tamNacionalidad);
int BajaProducto(eProducto arrayProductos[], int tamProductos);
int ModificarProducto(eProducto arrayProductos[], eTipo arrayTipo[],
		int tamProductos, int tamTipo);
void MenuDeOpciones(eProducto arrayProductos[], eTipo arrayTipo[],
		eNacionalidad arrayNacionalidad[], int tamProductos, int tamTipo,
		int tamNacionalidad);
void OrdenarProductoPorPrecio(eProducto arrayProductos[], int tamProductos);
void OrdenarProductoPorDescripcion(eProducto arrayProductos[], int tamProductos);
int ListadoProductos(eProducto arrayProductos[], eTipo arrayTipo[],
		eNacionalidad arrayNacionalidad[], int tamProductos,
		int tamNacionalidad, int tamTipo);
void MostrarProducto(eProducto unProducto, eTipo unTipo,
		eNacionalidad unaNacionalidad);
int MostrarProductoPorPrecio(eProducto arrayProductos[], eTipo arrayTipo[],
		eNacionalidad arrayNacionalidad[], int tamProductos,
		int tamNacionalidad, int tamTipo);
int BuscarPrecioMasAlto(eProducto arrayProductos[], int tamProductos,
		float *maximo);
int ListarProductoTipo(eProducto arrayProductos[], eTipo arrayTipo[],
		int tamProductos, int tamTipo);
void MostrarProductoConTipo(eProducto unProducto, eTipo unTipo);
int ListarTipoProducto(eProducto arrayProductos[], eTipo arrayTipo[],
		int tamProductos, int tamTipo);
void MostrarTipoConProducto(eProducto unProducto, eTipo unTipo);
int PromedioPorTipo(eProducto arrayProductos[], eTipo unTipo, int tamProductos,
		float *promedio);
int MostrarPromedioPorTipo(eProducto arrayProductos[], eTipo arrayTipo[],
		int tamProductos, int tamTipo);
#endif /* PRODUCTOS_H_ */
