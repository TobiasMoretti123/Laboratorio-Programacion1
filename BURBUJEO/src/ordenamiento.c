#include "ordenamiento.h"
/// \fn int OrdenarArrayInt(int*, int)
/// \brief Ordena un array de enteros DESC
/// \param pArray Es el puntero al array a ser monstrado
/// \param limite Es la longitud del array
/// \return Cantidad de iteraciones necesarias para ordenar si Ok o -1 si error
int OrdenarArrayInt(int *pArray, int limite) {
	int flagSwap;
	int i;
	int contador;
	int retorno;
	int buffer;
	int nuevoLimite;
	retorno = -1;
	contador = 0;
	if (pArray != NULL && limite >= 0) {
		nuevoLimite = limite - 1;
		do {
			flagSwap = 0;
			for (i = 0; i < nuevoLimite; i++) {
				contador++;
				if (pArray[i] > pArray[i + 1]) {
					flagSwap = 1;
					buffer = pArray[i];
					pArray[i] = pArray[i + 1];
					pArray[i + 1] = buffer;
				}
				nuevoLimite--;
			}
		} while (flagSwap == 1);
		retorno = contador;
	}

	return retorno;
}
