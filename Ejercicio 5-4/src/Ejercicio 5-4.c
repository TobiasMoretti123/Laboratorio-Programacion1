/*
 ANEXO 5-3:
 Crear un Array de 5 elementos de tipo num�rico donde se cargar�n edades.
 Agregar la funcionalidad para la opci�n 1 del Men� del ejercicio anterior
 utilizando funciones, es decir una funci�n que inicialice el Array.
 Agregar la funcionalidad para la opci�n 2 del Men� utilizando funciones,
 es decir una funci�n que le pida los n�meros o edades al usuario para cargar el Array de forma secuencial.
 */

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "ingreso.h"
#define T 5

int main(void) {
	setbuf(stdout, NULL);
	int listaEdades[T];
	MenuDeOpciones("1.Inicializar", "2.Cargar", "3-Mostrar",
			"4-Calcular Promedio", "5-Ordenar",
			"Ud. ha seleccionado la opci�n 1-Inicializar",
			"Ud. ha seleccionado la opci�n 2-Cargar",
			"Ud. ha seleccionado la opci�n 3-Mostrar",
			"Ud. ha seleccionado la opci�n 4-Cacular Promedio",
			"Ud. ha seleccionado la opci�n 5-Ordenar",listaEdades,T);
	return 0;
}
