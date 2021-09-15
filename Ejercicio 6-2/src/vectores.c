#include "vectores.h"
#include "verificacion.h"
/// \fn void CargarVectorEnteros(int[], int)
/// \brief Pide valores para cargar un array de enteros
/// \param array El array a ser cargado con valores
/// \param sice El tamño del array a ser cargado
void CargarVectorEnteros(int array[], int sice) {
	for (int i = 0; i < sice; i++) {
		array[i] = IngresarEntero("Ingrese un entero: ", 1000, -1000,
				"Error reingrese dato: ");
	}
}
/// \fn void MostrarCantidadPostivosNegativos(int[], int)
/// \brief Muestra la cantidad de positivos y negativos dentro de un array
/// \param array El array a ser verificado
/// \param sice El tamaño del array
void MostrarCantidadPostivosNegativos(int array[], int sice) {
	int cantidadPostivos;
	int cantidadNegativos;
	cantidadNegativos = 0;
	cantidadPostivos = 0;
	for (int i = 0; i < sice; i++) {
		if (VerificarSigno(array[i]) == 1) {
			cantidadPostivos++;
		} else {
			if (VerificarSigno(array[i]) == -1) {
				cantidadNegativos++;
			}
		}
	}
	printf("a)La cantidad de negativos es: %d\n", cantidadNegativos);
	printf("a)La cantidad de positivos es: %d\n", cantidadPostivos);
}
/// \fn int BuscarMayorImpar(int[], int, int*)
/// \brief Busca el mayor numero impar
/// \param array El array a ser leido
/// \param sice El tamaño del array
/// \param maximo El puntero al numero maximo
/// \return 1 si se encontro impar o 0 si no
int BuscarMayorImpar(int array[], int sice, int *maximo) {
	int mayorImpar;
	int banderaImpar;
	banderaImpar = 0;
	for (int i = 0; i < sice; i++) {
		if (VerificarParidad(array[i]) == 0) {
			banderaImpar = 1;
			if (mayorImpar < array[i] || banderaImpar == 1) {
				mayorImpar = array[i];
			}
		}
	}

	*maximo = mayorImpar;

	return banderaImpar;
}
/// \fn void CargarVectorAleatorio(int[], int)
/// \brief Carga un vector de enteros de manera aleatoria
/// \param vector El vector a ser cargado
/// \param tam El tamaño del vector
void CargarVectorAleatorio(int vector[], int tam) {
	int index;
	char seguir;
	do {
		index = IngresarEntero("Ingrese una posicion: ", tam, 1,
				"Error reingrese dato: ");
		vector[index - 1] = IngresarEntero("Ingrese un numero: ", 1000, -1000,
				"Reingrese dato: ");
		printf("Desea ingresar otro?");
		fflush(stdin);
		scanf("%c", &seguir);
	} while (seguir == 's');
}
/// \fn void MostrarVectorAleatorio(int[], int, int)
/// \brief Muestra el vector en pantalla que fue cargado de manera aleatoria
/// \param vector El vector a ser mostrado
/// \param tam El tamaño del vector
/// \param valorInicial El valor inicial que se le aplico al vector
void MostrarVectorAleatorio(int vector[], int tam, int valorInicial) {
	for (int i = 0; i < tam; i++) {
		if (vector[i] != valorInicial) {
			printf("Valor %d: %d\n", i, vector[i]);
		}
	}
}
/// \fn int IngresarEntero(char[], int, int, char[])
/// \brief Pide un entero y lo verifica entre un maximo y minimo y lo devuelve
/// \param mensaje El mensaje de peticion de un entero
/// \param max El parametro maximo
/// \param minimo El parametro minimo
/// \param mensajeError El mensaje de error cuando el numero esta fuera de rango
/// \return El numero dentro del rango
int IngresarEntero(char mensaje[], int max, int minimo, char mensajeError[]) {
	int numero;
	printf("%s", mensaje);
	scanf("%d", &numero);
	while (numero < minimo || numero > max) {
		printf("%s", mensajeError);
		scanf("%d", &numero);
	}
	return numero;
}
/// \fn int MostrarArrayInt(int*, int)
/// \brief Imprime a mode DEBUG la informacion de un array de enteros
/// \param pArray Es el puntero al array a ser monstrado
/// \param limite Es la longitud del array
/// \return 0 si Ok o -1 para indicar un error
int MostrarArrayInt(int *pArray, int limite) {
	int retorno;
	retorno = -1;
	if (pArray != NULL && limite >= 0) {
		retorno = 0;
		for (int i = 0; i < limite; i++) {
			printf("Valor %d: %d\n", i, pArray[i]);
		}
	}
	return retorno;
}
/// \fn int ListadoPositivos(int[], int)
/// \brief Imprime una lista de los numeros positivos
/// \param array El array a ser listado
/// \param tam El limite del array
/// \return 1 en caso de haber positivos o 0 si no los hay
int ListadoPositivos(int array[], int tam) {
	int retorno;
	int i;
	retorno = 0;
	printf("Listado 1: ");
	for (i = 0; i < tam; i++) {
		if (VerificarSigno(array[i]) == 1) {
			retorno = 1;
			printf("%d ", array[i]);
		}
	}
	return retorno;
}
/// \fn int ListadoNegativos(int[], int)
/// \brief Imprime una lista de los numeros negativos
/// \param array El array a ser listado
/// \param tam El limite del array
/// \return 1 en caso de haber positivos o 0 si no los hay
int ListadoNegativos(int array[], int tam) {
	int retorno;
	int i;
	retorno = 0;
	printf("\nListado 2: ");
	for (i = 0; i < tam; i++) {
		if (VerificarSigno(array[i]) == -1) {
			retorno = 1;
			printf("%d ", array[i]);
		}
	}
	return retorno;
}

