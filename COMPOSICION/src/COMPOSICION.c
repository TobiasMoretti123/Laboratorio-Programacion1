//Ejemplo de anidamiento o composicion
#include <stdio.h>
#include <stdlib.h>
#include "fecha.h"

typedef struct {
	int idCurso; //PK
	char descripcion[50];
	int duracionCurso;

} eCurso;
typedef struct {
	int legajo; //PK
	char nombre[50];
	float promedio;
	int idCurso; //FK

} eAlumno;

int main(void) {
	setbuf(stdout, NULL);
	eCurso listaCursos[4] = { { 100, "Java", 10 }, { 101, "VB", 20 }, { 102,
			"Phyton", 15 }, { 103, "Java Script", 30 } };
	eAlumno listaAlumnos[6] = { { 1, "Juan", 7, 101 }, { 2, "Ana", 9, 100 }, {
			3, "Luis", 4, 101 }, { 4, "Maria", 5, 102 },
			{ 5, "Alberto", 8, 103 }, { 6, "Juan Carlos", 8, 102 } };

	/*for (int i = 0; i < 6; i++) { //ALUMNOS
	 for (int j = 0; j < 4; j++) { //CURSOS
	 if(listaAlumnos[i].idCurso == listaCursos[j].idCurso)//FK
	 printf("%4d %20s %2.2f %20s\n", listaAlumnos[i].legajo,
	 listaAlumnos[i].nombre, listaAlumnos[i].promedio,
	 listaCursos[j].descripcion);
	 break;
	 }
	 }*/

	for (int i = 0; i < 4; i++) { //CURSOS
		printf("%s\n", listaCursos[i].descripcion);
		for (int j = 0; j < 6; j++) { //ALUMNOS
			if (listaCursos[i].idCurso == listaAlumnos[j].idCurso) //FK
				printf("\t%20s\n", listaAlumnos[j].nombre);
		}
	}

	return 0;
}
