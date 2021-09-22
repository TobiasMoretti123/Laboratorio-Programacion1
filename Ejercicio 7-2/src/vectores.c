#include "vectores.h"
#include "ingreso.h"
void CargarVectorSecuencial(int arrayA[], int arrayB[], int arrayC[], int tam) {
	int i;

	for (i = 0; i < tam; i++) {
		arrayA[i] = IngresarEntero("Ingrese un entero en array A: ");
		arrayB[i] = IngresarEntero("Ingrese un entero en array B: ");

		if (arrayA[i] > arrayB[i]) {
			arrayC[i] = arrayA[i];
		} else {
			arrayC[i] = arrayB[i];
		}
	}
}
void OrdernarVectores(int arrayA[], int arrayB[], int arrayC[], int tam) {
	int i;
	int j;
	int auxiliarArrayA;
	int auxiliarArrayB;
	int auxiliarArrayC;

	for (i = 0; i < tam; i++) {
		for (j = i + 1; j < tam; j++) {
			if (arrayC[i] > arrayC[j]) {
				auxiliarArrayC = arrayC[i];
				arrayC[i] = arrayC[j];
				arrayC[j] = auxiliarArrayC;

				auxiliarArrayA = arrayA[i];
				arrayA[i] = arrayA[j];
				arrayA[j] = auxiliarArrayA;

				auxiliarArrayB = arrayB[i];
				arrayB[i] = arrayB[j];
				arrayB[j] = auxiliarArrayB;
			}
		}
	}
}
void MostrarVectores(int arrayA[], int arrayB[], int arrayC[], int tam) {

	int i;

	printf("\nVectores A, B, C: ");
	for(i =0;i<tam;i++)
	{
		printf("\n%d\t%d\t%d",arrayA[i],arrayB[i],arrayC[i]);
	}
}

