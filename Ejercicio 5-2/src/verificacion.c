#include "verificacion.h"
int VerificarSigno(int numero) {
	int retorno;
	if (numero < 0) {
		retorno = 1;
	} else {
		if (numero > 0) {
			retorno = -1;
		}
	}
	return retorno;
}
int VerificarParidad(int numero) {
	int retorno;
	if (numero % 2 == 0) {
		retorno = 1;
	} else {
		retorno = 0;
	}
	return retorno;
}

int SumarPares(int array[], int sice) {
	int resultado;
	resultado =0;
	for (int i = 0; i < sice; i++) {
		if (VerificarParidad(array[i]) == 1) {
			resultado = resultado + array[i];
		}
	}
	return resultado;
}
