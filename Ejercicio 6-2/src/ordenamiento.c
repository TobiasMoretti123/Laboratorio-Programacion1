#include "ordenamiento.h"
#include "verificacion.h"
/// \fn int OrdenarNumerosNegativos(int[], int)
/// \brief Ordena de manera descendente los numeros negativos
/// \param array Puntero al array a ser ordenado
/// \param tam El limite del array
/// \return 1 en caso de Ok o -1 en caso de no haber negativos
int OrdenarNumerosNegativos(int array[], int tam) {
	int flagSwap;
	int i;
	int retorno;
	int buffer;
	int nuevoLimite;
	retorno = -1;
	nuevoLimite = tam - 1;
	do {
		flagSwap = 0;
		for (i = 0; i < tam - 1; i++) {
			if (VerificarSigno(array[i]) == -1) {
				retorno = 1;
				if (array[i] < array[i + 1]) {
					flagSwap = 1;
					buffer = array[i];
					array[i] = array[i + 1];
					array[i + 1] = buffer;
				}
				nuevoLimite--;
			}
		}
	} while (flagSwap == 1);
	return retorno;
}
/// \fn int OrdenarNumerosPositivos(int[], int)
/// \brief Ordena de manera ascendente los numeros positivos
/// \param array El array a ser ordenado
/// \param tam El limite del array
/// \return 1 en caso de Ok o -1 en caso de no haber positivos
int OrdenarNumerosPositivos(int array[], int tam) {
	int flagSwap;
	int i;
	int retorno;
	int buffer;
	int nuevoLimite;
	retorno = -1;
	nuevoLimite = tam - 1;
	do {
		flagSwap = 0;
		for (i = 0; i < tam - 1; i++) {
			if (VerificarSigno(array[i]) == 1) {
				retorno = 1;
				if (array[i] > array[i + 1]) {
					flagSwap = 1;
					buffer = array[i];
					array[i] = array[i + 1];
					array[i + 1] = buffer;
				}
				nuevoLimite--;
			}
		}
	} while (flagSwap == 1);
	return retorno;
}

