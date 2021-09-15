#include <stdio.h>
#include <stdlib.h>

#ifndef VECTORES_H_
#define VECTORES_H_

void CargarVectorEnteros(int array[], int sice);
void CargarVectorAleatorio(int vector[], int tam);
void MostrarCantidadPostivosNegativos(int array[], int sice);
int BuscarMayorImpar(int array[], int sice, int *maximo);
void MostrarVectorAleatorio(int vector[], int tam, int valorInicial);
int IngresarEntero(char mensaje[], int max, int minimo, char mensajeError[]);
int MostrarArrayInt(int *pArray, int limite);
int ListadoPositivos(int array[], int tam);
int ListadoNegativos(int array[], int tam);

#endif /* VECTORES_H_ */
