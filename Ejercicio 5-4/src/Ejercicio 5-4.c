/*
 ANEXO 5-3:
 Crear un Array de 5 elementos de tipo numérico donde se cargarán edades.
 Agregar la funcionalidad para la opción 1 del Menú del ejercicio anterior
 utilizando funciones, es decir una función que inicialice el Array.
 Agregar la funcionalidad para la opción 2 del Menú utilizando funciones,
 es decir una función que le pida los números o edades al usuario para cargar el Array de forma secuencial.
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
			"Ud. ha seleccionado la opción 1-Inicializar",
			"Ud. ha seleccionado la opción 2-Cargar",
			"Ud. ha seleccionado la opción 3-Mostrar",
			"Ud. ha seleccionado la opción 4-Cacular Promedio",
			"Ud. ha seleccionado la opción 5-Ordenar",listaEdades,T);
	return 0;
}
