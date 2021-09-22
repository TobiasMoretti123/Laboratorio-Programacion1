#include "listados.h"
/// \fn void ListadoProductos(int[], char[][], char[][], char[][], float[], int)
/// \brief Lista el array de productos con todos sus valores
/// \param idProducto El puntero al id del producto
/// \param descripcion El puntero a la descripcion del producto
/// \param nacionalidad El puntero a la nacionalidad del producto
/// \param tipo El puntero al tipo de producto
/// \param precio El puntero al precio del producto
/// \param tam El tamaño del producto
void ListadoProductos(int idProducto[], char descripcion[][50],
		char nacionalidad[][50], char tipo[][50], float precio[], int tam) {
	int i;
	printf("--------------LISTADO PRODUCTOS---------------\n");
	for (i = 0; i < tam; i++) {
		if (idProducto[i] != 0 && descripcion[i] != 0 && precio[i] != 0) {
			printf(
					"Producto: %d ID: %4d Descripcion: %s\t Nacionalidad: %s\t Tipo: %s\t Precio: %4.2f\n",
					i + 1, idProducto[i], descripcion[i], nacionalidad[i],
					tipo[i], precio[i]);
		}

	}
}
/// \fn void ListadoProductosPorPrecio(int[], char[][], char[][], char[][], float[], int)
/// \brief Lista el array de productos ordenado por precio
/// \param idProducto El puntero al id del producto
/// \param descripcion El puntero a la descripcion del producto
/// \param nacionalidad El puntero a la nacionalidad del producto
/// \param tipo El puntero al tipo de producto
/// \param precio El puntero al precio del producto
/// \param tam El tamaño del producto
void ListadoProductosPorPrecio(int idProducto[], char descripcion[][50],
		char nacionalidad[][50], char tipo[][50], float precio[], int tam) {
	int i;
	printf(
			"--------------LISTADO PRODUCTOS ORDENADOS POR PRECIO---------------\n");
	for (i = 0; i < tam; i++) {
		if (idProducto[i] != 0 && descripcion[i] != 0 && precio[i] != 0) {
			printf(
					"Producto: %d ID: %4d Descripcion: %s\t Nacionalidad: %s\t Tipo: %s\t Precio: %4.2f\n",
					i + 1, idProducto[i], descripcion[i], nacionalidad[i],
					tipo[i], precio[i]);
		}
	}
}
/// \fn void ListadoProductosPorDescripcion(int[], char[][], char[][], char[][], float[], int)
/// \brief Lista el array de productos ordenado por descripcion
/// \param idProducto El puntero al id del producto
/// \param descripcion El puntero a la descripcion del producto
/// \param nacionalidad El puntero a la nacionalidad del producto
/// \param tipo El puntero al tipo de producto
/// \param precio El puntero al precio del producto
/// \param tam El tamaño del producto
void ListadoProductosPorDescripcion(int idProducto[], char descripcion[][50],
		char nacionalidad[][50], char tipo[][50], float precio[], int tam) {
	int i;
	printf(
			"--------------LISTADO PRODUCTOS ORDENADOS POR DESCRIPCION---------------\n");
	for (i = 0; i < tam; i++) {
		if (idProducto[i] != 0 && descripcion[i] != 0 && precio[i] != 0) {
			printf(
					"Producto: %d ID: %4d Descripcion: %s\t Nacionalidad: %s\t Tipo: %s\t Precio: %4.2f\n",
					i + 1, idProducto[i], descripcion[i], nacionalidad[i],
					tipo[i], precio[i]);
		}
	}
}
