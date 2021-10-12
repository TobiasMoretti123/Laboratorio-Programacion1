#include "proyecto.h"
#include "utn.h"
#include "validaciones.h"

/// \fn void MenuDeOpciones(eProducto[], int, char[])
/// \brief Menu de n opciones con el proyecto de apple
/// \param lista La lista con los productos
/// \param tam El tamaño de la lista
/// \param mensaje Las distintas opciones del menu con la ultima siendo la de salida
/// \param opciones Cantidad de opciones del menu
void MenuDeOpciones(eProducto lista[], int tam, char mensaje[], int opciones) {
	int opcion;
	int respuestaFuncion;
	float maximo;
	do {
		printf("%s", mensaje);
		get_int(&opcion, 4, "Ingrese una opcion: ", "Opcion invalida ", 1,
				opciones, 4, 0);
		switch (opcion) {
		case 1:
			respuestaFuncion = AltaProducto(lista, tam);
			if (respuestaFuncion == -1) {
				printf("No hay espacio para otro producto\n");
			} else {
				printf("El producto ah sido ingresado!\n");
			}
			break;
		case 2:
			respuestaFuncion = BajaProducto(lista, tam);
			if (respuestaFuncion == 0) {
				printf("El producto no existe\n");
			} else {
				printf("El producto ah sido eliminado!\n");
			}
			break;
		case 3:
			respuestaFuncion = ModificarProducto(lista, tam);
			if (respuestaFuncion == 0) {
				printf("El producto no existe\n");
			} else {
				printf("El producto fue modificado correctamente!\n");
			}
			break;
		case 4:
			respuestaFuncion = ListadoProductos(lista, tam);
			if (respuestaFuncion == 0) {
				printf("No se ingresaron productos aun\n");
			}
			break;
		case 5:
			OrdenarProductosPorPrecio(lista, tam);
			printf("Ordenado por precio correctamente\n");
			break;
		case 6:
			OrdenarProductosPorDescripcion(lista, tam);
			printf("Ordenado por descripcion correctamente\n");
			break;
		case 7:
			respuestaFuncion = ListadoIphone(lista, tam);
			if (respuestaFuncion == 0) {
				printf("No se ingreso ningun iphone de EEUU\n");
			}
			break;
		case 8:
			BuscarPrecioMasAlto(lista, tam, &maximo);
			MostrarProductoPorPrecio(lista, tam, maximo);
			MostrarProductoPorPrecio(lista, tam, PRECIO);
			break;
		case 9:
			break;
		}
	} while (opcion != opciones);
}
/// \fn void MostrarProducto(eProducto)
/// \brief Muestra un producto
/// \param unProducto El producto a mostrar
void MostrarProducto(eProducto unProducto) {
	printf("%-4d %-20s %-4d %-4d %-4.2f\n", unProducto.idProducto,
			unProducto.descripcion, unProducto.nacionalidad, unProducto.tipo,
			unProducto.precio);
}
/// \fn int AltaProducto(eProducto[], int)
/// \brief Carga un producto siempre y cuando alla espacio
/// \param lista La lista a ser cargada
/// \param tam El tamaño de la lista
/// \return retorna la posicion donde se cargo la lista o -1 si la lista esta llena
int AltaProducto(eProducto lista[], int tam) {
	int index;
	index = BuscarEspacioVacio(lista, tam);
	if (index != -1) {
		lista[index] = IngresarUnProducto();
	}
	return index;
}
/// \fn int BuscarEspacioVacio(eProducto[], int)
/// \brief Busca si hay un espacio vacio en la lista
/// \param lista La lista a buscar el espacio
/// \param tam El tamaño de la lista
/// \return Retorna la posicion con el espacio vacio o -1 si esta lleno
int BuscarEspacioVacio(eProducto lista[], int tam) {
	int retorno;
	retorno = -1;
	for (int i = 0; i < tam; i++) {
		if (lista[i].isEmpty == EMPTY) {
			retorno = i;
			break;
		}
	}
	return retorno;
}
/// \fn int BajaProducto(eProducto[], int)
/// \brief Pide un ID de un producto y lo borra de la lista
/// \param lista La lista a ser leida
/// \param tam El tamaño de la lista
/// \return 1 en caso de que alla sido borrado o 0 si no existe ese producto
int BajaProducto(eProducto lista[], int tam) {
	int auxID;
	int flagDelete = 0;
	char respuesta;
	ListadoProductos(lista, tam);
	get_int(&auxID, 20, "Ingrese el ID que quiera eliminar: ", "ID invalido ",
			1, 1000, 4, 0);
	get_text(&respuesta, 2, "Desea borrar este ID(s para si)?: ",
			"Respuesta Invalido", 4);
	for (int i = 0; i < tam; i++) {
		if (BuscarEspacioVacio(lista, tam) == FULL) {
			if (lista[i].idProducto == auxID) {
				if (respuesta == 's') {
					lista[i].isEmpty = EMPTY;
					flagDelete = 1;
					break;
				}
			}
		}

	}
	return flagDelete;
}
/// \fn int ModificarProducto(eProducto[], int)
/// \brief Pide un ID de producto y modifica su tipo o precio
/// \param lista La lista a ser modificada
/// \param tam El tamaño de la lista
/// \return (1 si precio y tipo fue modificado 0 si no se encontro -1 solo el precio -2 solo el tipo)
int ModificarProducto(eProducto lista[], int tam) {
	int auxID;
	char respuesta;
	int respuestaTipoPrecio;
	int flagModify = 0;
	int auxTipo;
	ListadoProductos(lista, tam);
	get_int(&auxID, 20, "Ingrese ID que quiera modificar: ", "ID invalido ", 1,
			1000, 4, 0);
	get_text(&respuesta, 2, "Desea modificar este ID(s para si)?: ",
			"Respuesta Invalida ", 4);
	respuesta = tolower(respuesta);
	for (int i = 0; i < tam; i++) {
		if ((BuscarEspacioVacio(lista, tam) == FULL
				&& lista[i].idProducto == auxID) || respuesta == 's') {
			get_int(&respuestaTipoPrecio, 2,
					"Que desea modificar 1.Tipo 2.Precio 3.Precio y Tipo: ",
					"Opcion invalida ", 1, 3, 4, 0);

			break;
		}
	}
	if (respuestaTipoPrecio == 3) {
		get_int(&auxTipo, 20,
				"Ingrese nuevo tipo 1.IPHONE 2.MAC 3.IPAD 4.ACCESORIOS: ",
				"Tipo invalido ", 1, 4, 4, 0);
		get_text(&respuesta, 2,
				"Desea modificar el tipo de este producto(s para si)?: ",
				"Respuesta Invalida ", 4);
		for (int i = 0; i < tam; i++) {
			if (respuesta == 's') {
				lista[i].tipo = auxTipo;
				break;
			}
		}
		ModificarPrecio(lista, tam);
		flagModify = 1;
	} else {
		if (respuestaTipoPrecio == 2) {
			ModificarPrecio(lista, tam);
			flagModify = -1;
		} else {
			if (respuestaTipoPrecio == 1) {

				get_int(&auxTipo, 20,
						"Ingrese nuevo tipo 1.IPHONE 2.MAC 3.IPAD 4.ACCESORIOS: ",
						"Tipo invalido ", 1, 4, 4, 0);
				get_text(&respuesta, 2,
						"Desea modificar el tipo de este producto(s para si)?: ",
						"Respuesta Invalida ", 4);
				for (int i = 0; i < tam; i++) {
					if (respuesta == 's') {
						lista[i].tipo = auxTipo;
						break;
					}
				}
				flagModify = -2;
			}
		}
	}
	return flagModify;
}
/// \fn void ModificarPrecio(eProducto[], int)
/// \brief Modifica el precio de un producto
/// \param lista La lista a ser modificada
/// \param tam El tamaño de la lista
void ModificarPrecio(eProducto lista[], int tam) {
	float auxPrecio;
	char respuesta;
	get_float(&auxPrecio, 20, "Ingrese nuevo precio: ", "Precio invalido ", 1,
			200000, 4, 0);
	get_text(&respuesta, 2,
			"Desea modificar el precio de este producto(s para si)?: ",
			"Respuesta Invalida ", 4);
	for (int i = 0; i < tam; i++) {
		if (respuesta == 's') {
			lista[i].precio = auxPrecio;
			break;
		}
	}
}
/// \fn void InicialilarListaProducto(eProducto[], int)
/// \brief Inicializa la lista para que sea vacia
/// \param lista La lista a ser inicializada
/// \param tam El tamaño de la lista
void InicialilarListaProducto(eProducto lista[], int tam) {
	for (int i = 0; i < tam; i++) {
		lista[i].isEmpty = EMPTY;
	}
}
/// \fn eProducto IngresarUnProducto()
/// \brief Ingresa un producto con los parametros del struct
/// \return El producto ingresado
eProducto IngresarUnProducto() {
	eProducto producto;
	int auxID;
	char auxDes[20];
	int auxNac;
	int auxTipo;
	float auxPrecio;
	get_int(&auxID, 20, "Ingrese ID: ", "ID invalida ", 1, 1000, 4, 0);
	get_text(auxDes, 20, "Ingrese descripcion: ", "Descripcion invalida ", 4);
	get_int(&auxNac, 20, "Ingrese Nacionalidad 1.EEUU 2.CHINA  3.OTROS: ",
			"Nacionalidad invalida ", 1, 3, 4, 0);
	get_int(&auxTipo, 20, "Ingrese Tipo 1.IPHONE 2.MAC 3.IPAD 4.ACCESORIOS: ",
			"Tipo invalido ", 1, 4, 4, 0);
	get_float(&auxPrecio, 20, "Ingrese precio: ", "Precio invalido ", 1, 200000,
			4, 0);
	producto.idProducto = auxID;
	strncpy(producto.descripcion, auxDes, 20);
	producto.nacionalidad = auxNac;
	producto.tipo = auxTipo;
	producto.precio = auxPrecio;
	producto.isEmpty = FULL;

	return producto;
}
/// \fn int ListadoProductos(eProducto[], int)
/// \brief Muestra una lista de productos
/// \param lista La lista a mostrar
/// \param tam El tamaño de la lista
/// \return 1 en caso de que la lista este vacia 0 si no lo esta
int ListadoProductos(eProducto lista[], int tam) {
	int flagListaVacia = 0;
	printf("Id\tDescripcion\tNacionalidad\tTipo\tPrecio\n");
	for (int i = 0; i < tam; i++) {
		if (lista[i].isEmpty == FULL) {
			MostrarProducto(lista[i]);
			flagListaVacia = 1;
		}
	}
	return flagListaVacia;
}
/// \fn void OrdenarListaProductosPorPrecio(eProducto[], int)
/// \brief Ordena los productos por precio
/// \param lista La lista a ser ordenada
/// \param tam El tamaño de la lista
void OrdenarProductosPorPrecio(eProducto lista[], int tam) {
	eProducto auxiliarProducto;
	for (int i = 0; i < tam - 1; i++) {
		for (int j = i + 1; j < tam; j++) {
			if (lista[i].precio < lista[j].precio) {
				auxiliarProducto = lista[i];
				lista[i] = lista[j];
				lista[j] = auxiliarProducto;
			}
		}
	}
}
/// \fn void OrdenarListaProductosPorDesc(eProducto[], int)
/// \brief Ordena la lista por decripcion
/// \param lista La lista a ser ordenada
/// \param tam El tamaño de la lista
void OrdenarProductosPorDescripcion(eProducto lista[], int tam) {
	eProducto auxiliarProducto;
	for (int i = 0; i < tam - 1; i++) {
		for (int j = i + 1; j < tam; j++) {
			if (strncmp(lista[i].descripcion, lista[j].descripcion, tam) > 0) {
				auxiliarProducto = lista[i];
				lista[i] = lista[j];
				lista[j] = auxiliarProducto;
			}
		}
	}
}
/// \fn int ListadoIphone(eProducto[], int)
/// \brief Muestra una lista de todos los productos tipo iphone hechos en EEUU
/// \param lista La lista a mostrar
/// \param tam El tamaño de la lista a mostrar
/// \return 0 si no hay ningun producto en la lista 1 si lo hay
int ListadoIphone(eProducto lista[], int tam) {
	int flagListaVacia = 0;
	printf("Id\tDescripcion\tNacionalidad\tTipo\tPrecio\n");
	for (int i = 0; i < tam; i++) {
		if (lista[i].isEmpty == FULL && lista[i].nacionalidad == 1
				&& lista[i].tipo == 1) {
			MostrarProducto(lista[i]);
			flagListaVacia = 1;
		}
	}
	return flagListaVacia;
}

//Biblioteca de informes:
int BuscarPrecioMasAlto(eProducto lista[], int tam, float *maximo) {
	int retorno = 0;
	float max;
	int flagMax = 0;

	for (int i = 0; i < tam; i++) {
		if (lista[i].isEmpty == FULL) {
			if (flagMax == 0 || lista[i].precio > max) {
				max = lista[i].precio;
				flagMax = 1;
				retorno = 1;
			}
		}
	}
	*maximo = max;
	return retorno;
}
int MostrarProductoPorPrecio(eProducto lista[], int tam, float precioBuscado) {
	int retorno = 0;
	float max;
	BuscarPrecioMasAlto(lista, tam, &max);
	for (int i = 0; i < tam; i++) {
		if (lista[i].isEmpty == FULL && precioBuscado == lista[i].precio) {
			MostrarProducto(lista[i]);
			retorno = 1;
		}
	}
	return retorno;
}

