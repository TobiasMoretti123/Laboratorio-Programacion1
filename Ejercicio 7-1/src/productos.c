#include "utn.h"
#include "validaciones.h"
#include "productos.h"

/// \fn void AltaProducto(int[], char[][], char[][], char[][], float[], int)
/// \brief Ingresa un producto si hay espacio
/// \param idProducto El puntero al ID del producto
/// \param descripcion El puntero a la descripcion del producto
/// \param nacionalidad El puntero a la nacionalidad del producto
/// \param tipo El puntero al tipo de producto
/// \param precio El puntero al precio del producto
/// \param tam El tamao del array de productos
void AltaProducto(int idProducto[], char descripcion[][50],
		char nacionalidad[][50], char tipo[][50], float precio[], int tam) {
	int posicion;
	int auxID;
	float auxPrecio;

	do {
		get_int(&posicion, 50, "Ingrese posicion (1-4): ", "Posicion invalida ",
				1, tam, 4, 0);

		get_int(&auxID, 50, "Ingrese ID: ", "ID invalido", 1, 1000, 4, 0);
		get_text(descripcion[posicion - 1], 50, "Ingrese descripcion: ",
				"Descripcion invalida ", 4);
		get_float(&auxPrecio, 50, "Ingrese precio: ", "Precio invalido ", 1,
				200000, 4, 0);
		idProducto[posicion - 1] = auxID;
		precio[posicion - 1] = auxPrecio;

	} while (idProducto[posicion - 1] == 0 && descripcion[posicion - 1] == 0
			&& precio[posicion - 1] == 0);

}
/// \fn void BajaProducto(int[], char[][], char[][], char[][], float[], int)
/// \brief Pide el ID del producto y si lo encuentra lo borra de la lista
/// \param idProducto El puntero al ID del producto
/// \param descripcion El puntero a la descripcion del producto
/// \param nacionalidad El puntero a la nacionalidad del producto
/// \param tipo El puntero al tipo de producto
/// \param precio El puntero al precio del producto
/// \param tam El tamaño del array de productos
void BajaProducto(int idProducto[], char descripcion[][50],
		char nacionalidad[][50], char tipo[][50], float precio[], int tam) {
	int auxID;
	char auxDescripcion[tam];
	int i;
	int posicion = 0;
	int banderaIgualdad = 0;

	get_int(&auxID, tam, "Ingrese el ID que desee borrar: ", "ID no valido ", 1,
			1000, 4, 0);
	for (i = 0; i < tam; i++) {
		if (idProducto[i] != 0 && descripcion[i] != 0 && precio[i] != 0) {
			if (idProducto[i] == auxID) {
				posicion = i;
				banderaIgualdad = 1;
				strncpy(auxDescripcion, descripcion[i], tam);
			}
		}

	}
	if (banderaIgualdad == 1) {
		idProducto[posicion] = 0;
		precio[posicion] = 0;
		auxDescripcion[posicion] = 0;
	}

}
/// \fn void ModificarProducto(int[], char[][], char[][], char[][], float[], int)
/// \brief Pide un ID y si lo encuentra pide modificar la descripcion y precio del producto
/// \param idProducto El puntero al ID del producto
/// \param descripcion El puntero a la descripcion del producto
/// \param nacionalidad El puntero a la nacionalidad del producto
/// \param tipo El puntero al tipo de producto
/// \param precio El puntero al precio del producto
/// \param tam El tamaño del producto
void ModificarProducto(int idProducto[], char descripcion[][50],
		char nacionalidad[][50], char tipo[][50], float precio[], int tam) {
	int auxID;
	float auxPrecio;
	int i;
	int posicion = 0;
	int banderaIgualdad = 0;

	get_int(&auxID, tam, "Ingrese el ID que desee modificar: ", "ID no valido ",
			1, 1000, 4, 0);
	for (i = 0; i < tam; i++) {
		if (idProducto[i] != 0 && descripcion[i] != 0 && precio[i] != 0) {
			if (idProducto[i] == auxID) {
				posicion = i;
				banderaIgualdad = 1;
			}
		}

	}
	if (banderaIgualdad == 1) {
		get_float(&auxPrecio, 50, "Ingrese nuevo precio: ", "Precio invalido ",
				1, 200000, 4, 0);
		get_text(descripcion[posicion], 50, "Ingrese nueva descripcion: ",
				"Descripcion invalida ", 4);
		precio[posicion] = auxPrecio;
	}
}

