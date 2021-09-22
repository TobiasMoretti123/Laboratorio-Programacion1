#include "ordenamiento.h"
/// \fn int OrdenarPrecio(int[], char[][], char[][], char[][], float[], int)
/// \brief Ordena los productos por precio
/// \param idProducto El puntero al id del producto
/// \param descripcion El puntero a la descripcion del producto
/// \param nacionalidad El puntero a la nacionalidad del producto
/// \param tipo El puntero al tipo de producto
/// \param precio El puntero al precio del producto
/// \param tam El tamaño del producto
/// \return 0 si fue ordenado 1 si no lo fue
int OrdenarPrecio(int idProducto[], char descripcion[][50],
		char nacionalidad[][50], char tipo[][50], float precio[], int tam) {
	int auxiliarInt;
	float auxiliarFloat;
	char auxiliarString[50];
	int ordenado = 1;
	for (int i = 0; i < tam - 1; i++) {
		for (int j = i + 1; j < tam; j++) {
			if (precio[i] < precio[j]) {
				auxiliarFloat = precio[i];
				precio[i] = precio[j];
				precio[j] = auxiliarFloat;

				auxiliarInt = idProducto[i];
				idProducto[i] = idProducto[j];
				idProducto[j] = auxiliarInt;

				strcpy(auxiliarString, descripcion[i]);
				strcpy(descripcion[i], descripcion[j]);
				strcpy(descripcion[j], auxiliarString);

				strcpy(auxiliarString, nacionalidad[i]);
				strcpy(nacionalidad[i], nacionalidad[j]);
				strcpy(nacionalidad[j], auxiliarString);

				strcpy(auxiliarString, tipo[i]);
				strcpy(tipo[i], tipo[j]);
				strcpy(tipo[j], auxiliarString);
				ordenado = 0;
			}
		}
	}
	return ordenado;
}

/// \fn int OrdenarDescripcion(int[], char[][], char[][], char[][], float[], int)
/// \brief Ordena los productos por descripcion
/// \param idProducto El puntero al id del producto
/// \param descripcion El puntero a la descripcion del producto
/// \param nacionalidad El puntero a la nacionalidad del producto
/// \param tipo El puntero al tipo de producto
/// \param precio El puntero al precio del producto
/// \param tam El tamaño del producto
/// \return 0 si fue ordenado 1 si no lo fue
int OrdenarDescripcion(int idProducto[], char descripcion[][50],
		char nacionalidad[][50], char tipo[][50], float precio[], int tam) {
	int auxiliarInt;
	float auxiliarFloat;
	char auxiliarString[50];
	int ordenado = 1;
	for (int i = 0; i < tam - 1; i++) {
		for (int j = i + 1; j < tam; j++) {
			if (strncmp(descripcion[i], descripcion[j], tam) > 0) {
				auxiliarFloat = precio[i];
				precio[i] = precio[j];
				precio[j] = auxiliarFloat;

				auxiliarInt = idProducto[i];
				idProducto[i] = idProducto[j];
				idProducto[j] = auxiliarInt;

				strcpy(auxiliarString, descripcion[i]);
				strcpy(descripcion[i], descripcion[j]);
				strcpy(descripcion[j], auxiliarString);

				strcpy(auxiliarString, nacionalidad[i]);
				strcpy(nacionalidad[i], nacionalidad[j]);
				strcpy(nacionalidad[j], auxiliarString);

				strcpy(auxiliarString, tipo[i]);
				strcpy(tipo[i], tipo[j]);
				strcpy(tipo[j], auxiliarString);
				ordenado = 0;
			}
		}
	}
	return ordenado;
}

