/*
 Tobias Moretti
 Ejercicio 10-1:
 Dada la estructura eAlumno (legajo, nombre, nota1, nota2, promedio),
 de qué manera la podría relacionar con la estructura eCurso (idCurso, descripcion, duracion),
 teniendo en cuenta que un alumno puede cursar solo un curso
 */

#include <stdio.h>
#include <stdlib.h>
#define TAMCURSO 4
#define TAMALUMNOS 3
typedef struct {
	int legajo;
	char nombre[50];
	int nota1;
	int nota2;
	float promedio;
	int idCurso;
} eAlumno;
typedef struct {
	int idCurso;
	char descripcion[50];
	int duracion;
} eCurso;

void MostrarAlumnosConCurso(eAlumno alumno[], eCurso curso[], int tamAlumno,
		int tamCurso);
int main(void) {
	setbuf(stdout, NULL);
	eAlumno alumnos[TAMALUMNOS] = { { 1, "Juan Carlos", 4, 4, 4.0, 101 },
			{ 2, "Maria", 5, 6, 5.5, 103 }, { 3, "German", 2, 3,
					2.5, 102 } };
	eCurso cursos[TAMCURSO] = { { 100, "Ingles", 10 },
			{ 101, "Matematica", 10 }, { 102, "Programacion", 10 }, { 103,
					"Algebra", 10 } };
	MostrarAlumnosConCurso(alumnos, cursos, TAMALUMNOS, TAMCURSO);
	return 0;
}
void MostrarAlumnosConCurso(eAlumno alumno[], eCurso curso[], int tamAlumno,
		int tamCurso) {
	for (int i = 0; i < tamAlumno; i++) {
		for (int j = 0; j < tamCurso; j++) {
			if (alumno[i].idCurso == curso[j].idCurso) {
				printf("%20s %4d %4d %4.2f %20s %4d\n", alumno[i].nombre,
						alumno[i].nota1, alumno[i].nota2, alumno[i].promedio,
						curso[j].descripcion, curso[j].duracion);
			}
		}
	}

}
