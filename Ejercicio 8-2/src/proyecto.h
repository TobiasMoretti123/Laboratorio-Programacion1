#define TAM 5
#define EMPTY 0
#define FULL 1
#define PRECIO 700
#define LENTIPO 4
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct{
	int idTipo;
	char descripcionTipo[30];
	int isEmpty;
}eTipoProducto;
typedef struct {
	int idProducto;
	char descripcion[100];
	int nacionalidad;
	int tipo;
	float precio;
	int isEmpty;
} eProducto;

#ifndef PROYECTO_H_
#define PROYECTO_H_

int AltaProducto(eProducto lista[], int tam);
int BajaProducto(eProducto lista[], int tam);
int ModificarProducto(eProducto lista[], int tam);
void ModificarPrecio(eProducto lista[], int tam);
int ListadoProductos(eProducto lista[], int tam);
int ListadoIphone(eProducto lista[], int tam);
void OrdenarProductosPorPrecio(eProducto lista[], int tam);
void OrdenarProductosPorDescripcion(eProducto lista[], int tam);
void InicialilarListaProducto(eProducto lista[], int tam);
void MostrarProducto(eProducto unProducto);
void MenuDeOpciones(eProducto lista[], int tam, char mensaje[], int opciones);
int BuscarEspacioVacio(eProducto lista[], int tam);
eProducto IngresarUnProducto();

//Biblioteca informes:
int BuscarPrecioMasAlto(eProducto lista[], int tam, float *maximo);
int MostrarProductoPorPrecio(eProducto lista[], int tam, float precioBuscado);

#endif /* PROYECTO_H_ */
