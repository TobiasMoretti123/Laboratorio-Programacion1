#include <stdio.h>
#include <stdlib.h>

#ifndef VECTORES_H_
#define VECTORES_H_

void CargarVectorEnteros(int array[], int sice);
void CargarVectorAleatorio(int vector[], int tam);
void ListarVectorEnteros(int array[], int sice);
void ListarPares(int array[], int sice);
void ListarNumerosEnPosicionImpar(int array[], int sice);
void MostrarCantidadPostivosNegativos(int array[], int sice);
int BuscarMayorImpar(int array[], int sice, int *maximo);
void MostrarVector(int vector[], int tam, int valorInicial);
int IngresarEntero(char mensaje[], int max, int minimo, char mensajeError[]);

#endif /* VECTORES_H_ */
