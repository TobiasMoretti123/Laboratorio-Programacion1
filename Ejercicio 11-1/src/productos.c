#include "productos.h"
#include "utn.h"
#include "validaciones.h"
#define EMPTY 0
#define FULL 1
/// \fn int InicializarProductos(eProducto[], int)
/// \brief Inicializa la lista con el valor isEmpy en true
/// \param arrayProductos La lista de productos a ser inicializada
/// \param tamProductos El tamaño de la lista
/// \return -1 en caso de haber un erro 0 si sale bien
int InicializarProductos(eProducto arrayProductos[], int tamProductos) {
	int retorno;
	retorno = -1;
	if (tamProductos > 0) {
		for (int i = 0; i < tamProductos; i++) {
			arrayProductos[i].isEmpty = EMPTY;
			retorno = 0;
		}
	}
	return retorno;
}
/// \fn int BuscarEspacioVacio(eProducto[], int)
/// \brief Busca un espacio vacio en la lista utilizando el valor isEmpty
/// \param lista La lista a ser buscada
/// \param tam El tamaño de la lista
/// \return -1 Si hubo un error o no encontro lugar vacio o la posicion donde fue encontrado
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
/// \fn int AltaProducto(eProducto[], eTipo[], eNacionalidad[], int, int, int)
/// \brief Ingresa un producto siempre y cuando alla espacio en la lista
/// \param arrayProductos El array con los productos
/// \param arrayTipo El array con los tipos
/// \param arrayNacionalidad El array con las nacionalidades
/// \param tamProductos El tamaño de la lista de productos
/// \param tamTipo El tamaño de la lista de tipos
/// \param tamNacionalidad El tamaño de la lista de nacionalidades
/// \return -1 si no encontro espacio vacio 0 si lo encontro y se ingreso correctamente
int AltaProducto(eProducto arrayProductos[], eTipo arrayTipo[],
		eNacionalidad arrayNacionalidad[], int tamProductos, int tamTipo,
		int tamNacionalidad) {
	int retorno;
	int index;
	retorno = -1;
	index = BuscarEspacioVacio(arrayProductos, tamProductos);
	if (index != -1) {
		arrayProductos[index] = IngresarProducto(arrayTipo, arrayNacionalidad,
				tamTipo, tamNacionalidad);
		retorno = 0;
	}

	return retorno;
}
/// \fn int BuscarID(eProducto[], int, int)
/// \brief Busca una id en toda la lista de productos y devuelve su posicion
/// \param arrayProductos La lista a ser buscada
/// \param tamProducto El tamaño de la lista
/// \param auxId La id a ser buscado en la lista
/// \return -1 en caso de no encontrarla o la posicion en caso de que si
int BuscarID(eProducto arrayProductos[], int tamProducto, int auxId) {
	int index;
	index = -1;
	for (int i = 0; i < tamProducto; i++) {
		if (arrayProductos[i].idProducto == auxId) {
			index = i;
		}
	}
	return index;
}
/// \fn int BajaProducto(eProducto[], int)
/// \brief Pide una id al usuario para que borre el producto de la lista
/// \param arrayProductos La lista a ser leida
/// \param tamProductos El tamaño de la lista
/// \return -1 si no se encontro el producto 0 si se dio de baja
int BajaProducto(eProducto arrayProductos[], int tamProductos) {
	int retorno;
	int index;
	int auxId;
	retorno = -1;
	utn_getInt(&auxId, 20, "Ingrese ID de producto que quiera dar de baja: ",
			"ID invalido ", 0, 1000, 4, 0);
	index = BuscarID(arrayProductos, tamProductos, auxId);
	if (index != -1) {
		arrayProductos[index].isEmpty = EMPTY;
		retorno = 0;
	}
	return retorno;
}
/// \fn int ModificarProducto(eProducto[], eTipo[], int, int)
/// \brief Modifica un producto por tipo o precio pidiendole el ID al usuario
/// \param arrayProductos La lista de productos a ser modificada
/// \param arrayTipo La lista de tipos a ser mostrada
/// \param tamProductos El tamaño de la lista de productos
/// \param tamTipo El tamaño de la lista de tipos
/// \return -1 si hubo algun error o no se encontro el id, 0 si se modifico correctamente
int ModificarProducto(eProducto arrayProductos[], eTipo arrayTipo[],
		int tamProductos, int tamTipo) {
	int retorno;
	int index;
	int respuesta;
	int auxId;
	float auxPrecio;
	int auxTipo;
	retorno = -1;
	utn_getInt(&auxId, 20, "Ingrese ID de producto que quiera modificar: ",
			"ID invalido ", 0, 1000, 4, 0);
	index = BuscarID(arrayProductos, tamProductos, auxId);
	if (index != -1) {
		utn_getInt(&respuesta, 20,
				"Que desea modificar 1.Tipo 2.Precio 3.Ambos?: ",
				"Respuesta invalida ", 1, 3, 4, 0);
	}
	switch (respuesta) {
	case 1:
		auxTipo = IngresarTipo(arrayTipo, tamTipo);
		arrayProductos[index].tipo = auxTipo;
		retorno = 0;
		break;
	case 2:
		utn_getFloat(&auxPrecio, 20, "Ingrese precio: ", "Precio invalido ", 1,
				20000, 4, 0);
		arrayProductos[index].precio = auxPrecio;
		retorno = 0;
		break;
	case 3:
		auxTipo = IngresarTipo(arrayTipo, tamTipo);
		arrayProductos[index].tipo = auxTipo;
		retorno = 0;
		utn_getFloat(&auxPrecio, 20, "Ingrese precio: ", "Precio invalido ", 1,
				20000, 4, 0);
		arrayProductos[index].precio = auxPrecio;
		retorno = 0;
		break;
	}

	return retorno;
}
/// \fn eProducto IngresarProducto(eTipo[], eNacionalidad[], int, int)
/// \brief Ingresa un producto
/// \param arrayTipo La lista de tipos a mostrar
/// \param arrayNacionalidad La lista de nacionalidades a mostrar
/// \param tamTipo El tamaño de la lista de tipos
/// \param tamNacionalidad El tamaño de la lista de nacionalidades
/// \return El producto ingresado
eProducto IngresarProducto(eTipo arrayTipo[], eNacionalidad arrayNacionalidad[],
		int tamTipo, int tamNacionalidad) {
	eProducto producto;
	int auxId;
	char auxDes[50];
	int auxTipo;
	int auxNacionalidad;
	float auxPrecio;
	utn_getInt(&auxId, 20, "Ingrese ID de producto: ", "ID invalido ", 0, 1000,
			4, 0);
	utn_getText(auxDes, 20, "Ingrese descripcion de producto: ",
			"Descripcion invalida ", 4);
	auxTipo = IngresarTipo(arrayTipo, tamTipo);
	auxNacionalidad = IngresarNacionalidad(arrayNacionalidad, tamNacionalidad);
	utn_getFloat(&auxPrecio, 20, "Ingrese precio: ", "Precio invalido ", 1,
			20000, 4, 0);
	producto.idProducto = auxId;
	strncpy(producto.descripcion, auxDes, 50);
	producto.tipo = auxTipo;
	producto.nacionalidad = auxNacionalidad;
	producto.precio = auxPrecio;
	producto.isEmpty = FULL;
	return producto;
}
/// \fn int IngresarTipo(eTipo[], int)
/// \brief Muestra una lista de los tipos para que sea ingresado
/// \param arrayTipo La lista de tipos a mostrar
/// \param tamTipo El tamaño de la lista de tipos
/// \return El tipo ingresado
int IngresarTipo(eTipo arrayTipo[], int tamTipo) {
	int auxTipo;
	for (int i = 0; i < tamTipo; i++) {
		printf("%-5d %20s\n", arrayTipo[i].idTipo, arrayTipo[i].descripcion);
	}
	utn_getInt(&auxTipo, 20, "De la lista de tipos ingrese el ID deseado: ",
			"ID de tipo invalido ", 1000, 1003, 4, 0);
	return auxTipo;
}
/// \fn int IngresarNacionalidad(eNacionalidad[], int)
/// \brief Muestra una lista de nacionalidades para que sea ingresada
/// \param arrayNacionalidad La lista de nacionalidades a ser mostrada
/// \param tamNacionalidad El tamaño de la lista de nacionalidades
/// \return La nacionalidad ingresada
int IngresarNacionalidad(eNacionalidad arrayNacionalidad[], int tamNacionalidad) {
	int auxNacionalidad;
	for (int i = 0; i < tamNacionalidad; i++) {
		printf("%-5d %20s\n", arrayNacionalidad[i].idNacionalidad,
				arrayNacionalidad[i].descripcion);
	}
	utn_getInt(&auxNacionalidad, 20,
			"De la lista de nacionalidades ingrese el ID deseado: ",
			"ID de nacionalidad invalido ", 1, 3, 4, 0);
	return auxNacionalidad;
}
/// \fn void OrdenarProductoPorPrecio(eProducto[], int)
/// \brief Ordena los productos por precio de mayor a menor
/// \param arrayProductos La lista de productos a ser ordenada
/// \param tamProductos El tamaño de la lista a ser ordenada
void OrdenarProductoPorPrecio(eProducto arrayProductos[], int tamProductos) {
	int flagSwap;
	int i;
	eProducto buffer[tamProductos];
	int nuevoLimite;
	do {
		flagSwap = 0;
		for (i = 0; i < nuevoLimite; i++) {
			if (arrayProductos[i].precio < arrayProductos[i + 1].precio) {
				flagSwap = 1;
				buffer[i] = arrayProductos[i];
				arrayProductos[i] = arrayProductos[i + 1];
				arrayProductos[i + 1] = buffer[i];
			}
			nuevoLimite--;
		}
	} while (flagSwap == 1);
}
/// \fn void OrdenarProductoPorDescripcion(eProducto[], int)
/// \brief Ordena la lista de productos por descripcion alfabeticamente
/// \param arrayProductos La lista a ser ordenada
/// \param tamProductos El tamaño de la lista
void OrdenarProductoPorDescripcion(eProducto arrayProductos[], int tamProductos) {
	int flagSwap;
	int i;
	eProducto buffer[tamProductos];
	int nuevoLimite;
	do {
		flagSwap = 0;
		for (i = 0; i < nuevoLimite; i++) {
			if (strncmp(arrayProductos[i].descripcion,
					arrayProductos[i + 1].descripcion, tamProductos) < 0) {
				flagSwap = 1;
				buffer[i] = arrayProductos[i];
				arrayProductos[i] = arrayProductos[i + 1];
				arrayProductos[i + 1] = buffer[i];
			}
			nuevoLimite--;
		}
	} while (flagSwap == 1);
}
/// \fn int ListadoProductos(eProducto[], eTipo[], eNacionalidad[], int, int, int)
/// \brief Muestra un listado con todos los productos
/// \param arrayProductos La lista de productos a ser mostrada
/// \param arrayTipo La lista de tipos a ser mostrada
/// \param arrayNacionalidad La lista de nacionalidades a ser mostrada
/// \param tamProductos El tamaño de la lista de productos
/// \param tamNacionalidad El tamaño de la lista de nacionalidades
/// \param tamTipo El tamaño de la lista de tipos
/// \return 0 en caso de que la lista este vacia 1 si no lo esta
int ListadoProductos(eProducto arrayProductos[], eTipo arrayTipo[],
		eNacionalidad arrayNacionalidad[], int tamProductos,
		int tamNacionalidad, int tamTipo) {
	int flagListaVacia;
	flagListaVacia = 0;
	printf("ID    DESCRIPCION     TIPO\t      NACIONALIDAD    PRECIO\n");
	for (int i = 0; i < tamProductos; i++) {
		for (int j = 0; j < tamTipo; j++) {
			for (int k = 0; k < tamNacionalidad; k++) {
				if (arrayProductos[i].isEmpty == FULL) {
					MostrarProducto(arrayProductos[i], arrayTipo[j],
							arrayNacionalidad[k]);
					flagListaVacia = 1;
				}
			}
		}

	}
	return flagListaVacia;
}
/// \fn void MostrarProducto(eProducto, eTipo, eNacionalidad)
/// \brief Muestra un producto con su tipo y nacionalidad
/// \param unProducto El producto a ser mostrado
/// \param unTipo El tipo a ser mostrado
/// \param unaNacionalidad La nacionalidad a ser mostrada
void MostrarProducto(eProducto unProducto, eTipo unTipo,
		eNacionalidad unaNacionalidad) {
	if (unProducto.tipo == unTipo.idTipo
			&& unProducto.nacionalidad == unaNacionalidad.idNacionalidad) {
		printf("%-5d %-15s %-15s %-15s %-7.2f\n", unProducto.idProducto,
				unProducto.descripcion, unTipo.descripcion,
				unaNacionalidad.descripcion, unProducto.precio);
	}
}
/// \fn int BuscarPrecioMasAlto(eProducto[], int, float*)
/// \brief Busca el precio mas alto en la lista y lo devuelve a modo de puntero
/// \param arrayProductos La lista a ser leida
/// \param tamProductos El tamaño de la lista
/// \param maximo El maximo a ser comparado
/// \return 0 en caso de no encontrar el maximo 1 si lo encontro
int BuscarPrecioMasAlto(eProducto arrayProductos[], int tamProductos,
		float *maximo) {
	int retorno = 0;
	float max;
	int flagMax = 0;
	for (int i = 0; i < tamProductos; i++) {
		if (arrayProductos[i].isEmpty == FULL) {
			if (flagMax == 0 || arrayProductos[i].precio > max) {
				max = arrayProductos[i].precio;
				flagMax = 1;
				retorno = 1;
			}
		}
	}
	*maximo = max;
	return retorno;
}
/// \fn int MostrarProductoPorPrecio(eProducto[], eTipo[], eNacionalidad[], int, int, int)
/// \brief Muestra el/los productos por precio mas alto
/// \param arrayProductos La lista de productos a ser mostrada
/// \param arrayTipo La lista de tipos a ser mostrada
/// \param arrayNacionalidad La lista de nacionalidades a ser mostrada
/// \param tamProductos El tamaño de la lista de productos
/// \param tamNacionalidad El tamaño de la lista de nacionalidades
/// \param tamTipo El tamaño de la lista de tipos
/// \return 0 si la lista esta vacia 1 si no
int MostrarProductoPorPrecio(eProducto arrayProductos[], eTipo arrayTipo[],
		eNacionalidad arrayNacionalidad[], int tamProductos,
		int tamNacionalidad, int tamTipo) {
	float max;
	int flagListaVacia = 0;
	BuscarPrecioMasAlto(arrayProductos, tamProductos, &max);
	printf("ID    DESCRIPCION     TIPO\t      NACIONALIDAD    PRECIO\n");
	for (int i = 0; i < tamProductos; i++) {
		for (int j = 0; j < tamTipo; j++) {
			for (int k = 0; k < tamNacionalidad; k++) {
				if (arrayProductos[i].isEmpty == FULL
						&& max == arrayProductos[i].precio) {
					MostrarProducto(arrayProductos[i], arrayTipo[j],
							arrayNacionalidad[k]);
					flagListaVacia = 1;
				}
			}
		}
	}
	return flagListaVacia;
}
/// \fn int ListarProductoTipo(eProducto[], eTipo[], int, int)
/// \brief Muestra una lista de los productos con el tipo
/// \param arrayProductos La lista de productos a ser mostrada
/// \param arrayTipo la lista de tipos a ser mostrada
/// \param tamProductos El tamaño de la lista de productos
/// \param tamTipo El tamaño de la lista de tipos
/// \return 0 si la lista esta vacia 1 si no lo esta
int ListarProductoTipo(eProducto arrayProductos[], eTipo arrayTipo[],
		int tamProductos, int tamTipo) {
	int flagListaVacia = 0;
	printf("ID    DESCRIPCION     TIPO\t      PRECIO\n");
	for (int i = 0; i < tamProductos; i++) {
		for (int j = 0; j < tamTipo; j++) {
			if (arrayProductos[i].isEmpty == FULL) {
				MostrarProductoConTipo(arrayProductos[i], arrayTipo[j]);
				flagListaVacia = 1;
			}
		}
	}
	return flagListaVacia;
}
/// \fn void MostrarProductoConTipo(eProducto, eTipo)
/// \brief Muestra un producto con el tipo
/// \param unProducto El producto a ser mostrado
/// \param unTipo El tipo a ser mostrado
void MostrarProductoConTipo(eProducto unProducto, eTipo unTipo) {
	if (unProducto.tipo == unTipo.idTipo) {
		printf("%-5d %-15s %-15s %-7.2f\n", unProducto.idProducto,
				unProducto.descripcion, unTipo.descripcion, unProducto.precio);
	}
}
/// \fn int ListarTipoProducto(eProducto[], eTipo[], int, int)
/// \brief Muestra una lista de tipos con el producto
/// \param arrayProductos La lista de productos a ser mostrada
/// \param arrayTipo la lista de tipos a ser mostrada
/// \param tamProductos El tamaño de la lista de productos
/// \param tamTipo El tamaño de la lista de tipos
/// \return 0 si la lista esta vacia 1 si no lo esta
int ListarTipoProducto(eProducto arrayProductos[], eTipo arrayTipo[],
		int tamProductos, int tamTipo) {
	int flagListaVacia = 0;
	printf("DESCRIPCION     PRODUCTO        PRECIO\n");
	for (int i = 0; i < tamTipo; i++) {
		printf("%-15s\n", arrayTipo[i].descripcion);
		for (int j = 0; j < tamProductos; j++) {
			if (arrayProductos[j].isEmpty == FULL) {
				MostrarTipoConProducto(arrayProductos[j], arrayTipo[i]);
				flagListaVacia = 1;
			}
		}
	}
	return flagListaVacia;
}
/// \fn void MostrarTipoConProducto(eProducto, eTipo)
/// \brief Muestra un tipo con su producto
/// \param unProducto El producto a ser mostrado
/// \param unTipo El tipo a ser mostrado
void MostrarTipoConProducto(eProducto unProducto, eTipo unTipo) {
	if (unProducto.tipo == unTipo.idTipo) {
		printf("\t\t%-15s %-7.2f\n", unProducto.descripcion, unProducto.precio);
	}
}
/// \fn int PromedioPorTipo(eProducto[], eTipo, int, float*)
/// \brief Calcula el promedio por tipo de producto
/// \param arrayProductos La lista de productos a ser calculada
/// \param unTipo El tipo a ser promediado
/// \param tamProductos El tamaño de la lista de productos
/// \param promedio El puntero a donde se guarde el promedio
/// \return -1 si hubo algun error 0 si pudo calcular el promedio
int PromedioPorTipo(eProducto arrayProductos[], eTipo unTipo, int tamProductos,
		float *promedio) {
	int retorno;
	int contador;
	float auxPrecio;
	int acumulador;
	contador = 0;
	acumulador = 0;
	retorno = -1;
	for (int i = 0; i < tamProductos; i++) {
		if (arrayProductos[i].tipo == unTipo.idTipo) {
			auxPrecio = arrayProductos[i].precio;
			contador++;
			acumulador += auxPrecio;
			if (contador != 0) {
				*promedio = (float) acumulador / contador;
				retorno = 0;
			}
		}
	}
	return retorno;
}
/// \fn int MostrarPromedioPorTipo(eProducto[], eTipo[], int, int)
/// \brief Muestra el tipo de producto con su precio promedio
/// \param arrayProductos La lista de productos a ser mostrada
/// \param arrayTipo La lista de tipos a ser mostrada
/// \param tamProductos El tamaño de la lista de productos
/// \param tamTipo El tamaño de la lista de tipos
/// \return 0 si la lista esta vacia 1 si no lo esta
int MostrarPromedioPorTipo(eProducto arrayProductos[], eTipo arrayTipo[],
		int tamProductos, int tamTipo) {
	int respuestaFuncion;
	float promedio;
	int j;
	int i;
	int flagListaVacia = 0;
	printf("DESCRIPCION     PRECIO PROMEDIO\n");
	for (i = 0; i < tamTipo; i++) {
		printf("%-15s\n", arrayTipo[i].descripcion);
		for (j = 0; j < tamProductos; j++) {
			respuestaFuncion = PromedioPorTipo(arrayProductos, arrayTipo[i],
					tamProductos, &promedio);
			if (respuestaFuncion == 0 && arrayProductos[j].isEmpty == FULL) {
				printf("\t\t%7.2f\n", promedio);
				flagListaVacia = 1;
				break;
			}
		}
	}
	return flagListaVacia;
}
void MenuDeOpciones(eProducto arrayProductos[], eTipo arrayTipo[],
		eNacionalidad arrayNacionalidad[], int tamProductos, int tamTipo,
		int tamNacionalidad) {
	int opcion;
	int flagAdedd = 0;
	int respuestaFuncion;
	do {
		utn_getInt(&opcion, 3,
				"1.Dar de alta un producto\n2.Dar de baja un producto\n3.Modificar un producto\n4.Listados de productos\n5.Informes de productos\n6.Salir\nIngrese una opcion: ",
				"Opcion invalida", 1, 6, 4, 0);
		switch (opcion) {
		case 1:
			respuestaFuncion = AltaProducto(arrayProductos, arrayTipo,
					arrayNacionalidad, tamProductos, tamTipo, tamNacionalidad);
			if (respuestaFuncion == 0) {
				printf("Producto dado de alta correctamente!\n");
				flagAdedd = 1;
			}
			break;
		case 2:
			if (flagAdedd == 1) {
				ListadoProductos(arrayProductos, arrayTipo, arrayNacionalidad,
						tamProductos, tamNacionalidad, tamTipo);
				respuestaFuncion = BajaProducto(arrayProductos, tamProductos);
				if (respuestaFuncion == 0) {
					printf("Producto dado de baja correctamente!\n");
				}
			} else {
				printf("No puede dar de baja un productos si no se ingreso ninguno\n");
			}
			break;
		case 3:
			if (flagAdedd == 1) {
				ListadoProductos(arrayProductos, arrayTipo, arrayNacionalidad,
						tamProductos, tamNacionalidad, tamTipo);
				respuestaFuncion = ModificarProducto(arrayProductos, arrayTipo,
						tamProductos, tamTipo);
				if (respuestaFuncion == 0) {
					printf("Producto modificado correctamente!\n");
				}
			} else {
				printf("No puede modificar un producto si no se ingrese ninguno\n");
			}
			break;
		case 4:
			if (flagAdedd == 1) {
				MenuListados(arrayProductos, arrayTipo, arrayNacionalidad,
						tamProductos, tamTipo, tamNacionalidad);
			} else {
				printf("No se pueden ver listados si no se ingreso ningun producto\n");
			}
			break;
		case 5:
			if (flagAdedd == 1) {
				MenuInformes(arrayProductos, arrayTipo, arrayNacionalidad,
						tamProductos, tamTipo, tamNacionalidad);
			} else {
				printf("No se pueden ver informes si aun no se ingresaron productos\n");
			}
			break;
		case 6:
			printf("Gracias por usar nuestro servicio!\n");
			break;
		}

	} while (opcion != 6);
}
void MenuInformes(eProducto arrayProductos[], eTipo arrayTipo[],
		eNacionalidad arrayNacionalidad[], int tamProductos, int tamTipo,
		int tamNacionalidad) {
	int opcion;
	int respuestaFuncion;
	printf("Menu de informes\n");
	utn_getInt(&opcion, 2,
			"1.El/los productos mas caros\n2.Precio promedio por tipo de producto\n3.Listado con la descripcion del tipo\n4.Listado por tipo\n5.El/los tipos con mas productos\n6.Salir\nIngrese una opcion: ",
			"Opcion invalida ", 1, 6, 4, 0);
	switch (opcion) {
	case 1:
		respuestaFuncion = MostrarProductoPorPrecio(arrayProductos, arrayTipo,
				arrayNacionalidad, tamProductos, tamNacionalidad, tamTipo);
		if (respuestaFuncion == 0) {
			printf("Lista de productos vacia\n");
		}
		break;
	case 2:
		respuestaFuncion = MostrarPromedioPorTipo(arrayProductos, arrayTipo,
				tamProductos, tamTipo);
		if (respuestaFuncion == 0) {
			printf("Lista de productos vacia\n");
		}
		break;
	case 3:
		respuestaFuncion = ListarProductoTipo(arrayProductos, arrayTipo,
				tamProductos, tamTipo);
		if (respuestaFuncion == 0) {
			printf("Lista de productos vacia\n");
		}
		break;
	case 4:
		respuestaFuncion = ListarTipoProducto(arrayProductos, arrayTipo,
				tamProductos, tamTipo);
		if (respuestaFuncion == 0) {
			printf("Lista de productos vacia\n");
		}
		break;
	case 5:
		printf("Muestro tipo con mas productos");
		break;
	}
}
void MenuListados(eProducto arrayProductos[], eTipo arrayTipo[],
		eNacionalidad arrayNacionalidad[], int tamProductos, int tamTipo,
		int tamNacionalidad) {
	int opcion;
	int respuestaFuncion;
	printf("Menu de Listados\n");
	utn_getInt(&opcion, 3,
			"1.LISTADO productos\n2.LISTADO ordenado por precio\n3.LISTADO ordenado por descripcion\n4.Salir de menu listados\nIngrese una opcion: ",
			"Opcion invalida", 1, 4, 4, 0);
	switch (opcion) {
	case 1:
		respuestaFuncion = ListadoProductos(arrayProductos, arrayTipo,
				arrayNacionalidad, tamProductos, tamNacionalidad, tamTipo);
		if (respuestaFuncion == 0) {
			printf("Lista de productos vacia\n");
		}
		break;
	case 2:
		OrdenarProductoPorPrecio(arrayProductos, tamProductos);
		respuestaFuncion = ListadoProductos(arrayProductos, arrayTipo,
				arrayNacionalidad, tamProductos, tamNacionalidad, tamTipo);
		if (respuestaFuncion == 0) {
			printf("Lista de productos vacia\n");
		}
		break;
	case 3:
		OrdenarProductoPorDescripcion(arrayProductos, tamProductos);
		respuestaFuncion = ListadoProductos(arrayProductos, arrayTipo,
				arrayNacionalidad, tamProductos, tamNacionalidad, tamTipo);
		if (respuestaFuncion == 0) {
			printf("Lista de productos vacia\n");
		}
		break;
	}
}
/*
 11.El/los tipos de productos con mas productos elaborados.
 */

