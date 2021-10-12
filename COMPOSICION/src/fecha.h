#include <stdio.h>
#include <stdlib.h>
typedef struct {
	int dia;
	int mes;
	int anio;
} eFecha;
#ifndef FECHA_H_
#define FECHA_H_

void MostrarFecha(eFecha unaFecha);
eFecha PedirFecha(char mensaje[]);

#endif /* FECHA_H_ */
