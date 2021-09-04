/*
 Tobias Moretti
 DIV 1E
 Ejercicio 1-3:
 Realizar el algoritmo que permita ingresar los datos de los alumnos de una división de la UTN FRA, los datos solicitados son:
 Legajo
 Tipo cursada(L: "libre" - P: "presencial" – R: "remota")
 Cantidad de materias( mas de cero y menos de 8)
 Sexo (F: “femenino” – M: “masculino” , O: “no binario”)
 Nota promedio (entre 0 y 10)
 Edad (validar)
 Se debe informar de existir, o informar que no existe , en el caso que corresponda.
 a) El Legajo del mejor promedio femenino.
 b) El legajo del más joven de los alumnos masculinos entre los que dan libre.
 c) El promedio de nota por sexo.
 d) La edad y legajo del que cursa más materias. (Sin importar su género)
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void) {
	setbuf(stdout, NULL);
	int legajo;
	char tipoCursada;
	int cantidadMaterias;
	char genero;
	int notaPromedio;
	int edad;
	char respuesta;
	int legajoMejorPromedio;
	int laDeMejorPromedio;
	int cantidadAlumnos;
	int elMasJoven;
	int legajoMasJoven;
	int cantidadMasculino;
	int cantidadFemenino;
	int cantidadNoBinario;
	int acumuladorMasculino;
	int acumuladorFemenino;
	int acumuladorNoBinario;
	float promedioMasculino;
	float promedioFemenino;
	float promedioNobinario;
	int edadMasMaterias;
	int legajoMasMaterias;
	int masMaterias;

	respuesta = 's';
	cantidadAlumnos = 0;
	cantidadMasculino = 0;
	cantidadFemenino = 0;
	cantidadNoBinario = 0;
	acumuladorMasculino = 0;
	acumuladorFemenino = 0;
	acumuladorNoBinario = 0;

	do {
		printf("Ingrese legajo: ");
		scanf("%d", &legajo);
		printf("Ingrese tipo de cursada l: libre - p: presencial – r: remota: ");
		fflush(stdin);
		scanf("%c", &tipoCursada);
		tipoCursada = tolower(tipoCursada);
		while (tipoCursada != 'l' && tipoCursada != 'p' && tipoCursada != 'r') {
			printf("Error ingrese l: libre - p: presencial – r: remota: ");
			fflush(stdin);
			scanf("%c", &tipoCursada);
			tipoCursada = tolower(tipoCursada);
		}
		printf("Ingrese la cantidad de materias: ");
		scanf("%d", &cantidadMaterias);
		while (cantidadMaterias < 1 || cantidadMaterias > 8) {
			printf("Error la cantidad de materias debe ser entre 1 y 8: ");
			scanf("%d", &cantidadMaterias);
		}
		printf(
				"ingrese genero f: “femenino” – m: “masculino” , o: “no binario: ");
		fflush(stdin);
		scanf("%c", &genero);
		genero = tolower(genero);
		while (genero != 'f' && genero != 'm' && genero != 'o') {
			printf("Error f: “femenino” – m: “masculino” , o: “no binario: ");
			fflush(stdin);
			scanf("%c", &genero);
			genero = tolower(genero);
		}
		printf("Ingrese el promedio de notas: ");
		scanf("%d", &notaPromedio);
		while (notaPromedio < 0 || notaPromedio > 10) {
			printf("Error el promedio debe ser entre 0 y 10: ");
			scanf("%d", &notaPromedio);
		}
		printf("Ingrese la edad: ");
		scanf("%d", &edad);
		while (edad < 18 || edad > 120) {
			printf("Error ingrese una edad valida +18: ");
			scanf("%d", &edad);
		}
		printf("Desea agregar otro alumno (s para continuar): ");
		fflush(stdin);
		scanf("%c", &respuesta);
		respuesta = tolower(respuesta);
		cantidadAlumnos++;
		if (cantidadAlumnos == 1) {
			switch (genero) {
			case 'f':
				legajoMejorPromedio = legajo;
				laDeMejorPromedio = notaPromedio;
				cantidadFemenino++;
				acumuladorFemenino = acumuladorFemenino + notaPromedio;
				break;
			case 'm':
				if (tipoCursada == 'l') {
					legajoMasJoven = legajo;
					elMasJoven = edad;
				}
				cantidadMasculino++;
				acumuladorMasculino = acumuladorMasculino + notaPromedio;
				break;
			case 'o':
				cantidadNoBinario++;
				acumuladorNoBinario = acumuladorNoBinario + notaPromedio;
				break;
			}
		}
		if (laDeMejorPromedio < notaPromedio) {
			legajoMejorPromedio = legajo;
			laDeMejorPromedio = notaPromedio;
		}
		if (elMasJoven > edad) {
			legajoMasJoven = legajo;
			elMasJoven = edad;
		}
		if(cantidadAlumnos == 1)
		{
			edadMasMaterias = edad;
			legajoMasMaterias = legajo;
			masMaterias = cantidadMaterias;
		}
		if(masMaterias<cantidadMaterias)
		{
			edadMasMaterias = edad;
			legajoMasMaterias = legajo;
			masMaterias = cantidadMaterias;
		}
	} while (respuesta == 's');

	promedioMasculino = (float)acumuladorMasculino/cantidadMasculino;
	promedioFemenino = (float)acumuladorFemenino/cantidadFemenino;
	promedioNobinario = (float)acumuladorNoBinario/cantidadNoBinario;

	printf("a) El Legajo del mejor promedio femenino es : %d\n",
			legajoMejorPromedio);
	printf("b) El legajo del más joven de los alumnos masculinos entre los que dan libre es: %d\n",
			legajoMasJoven);
	printf("c) El promedio de los masculinos es: %.2f, el promedio de los femeninos es: %.2f y el promedio de los no binarios es: %.2f"
			,promedioMasculino, promedioFemenino, promedioNobinario);
	printf("d) La edad del que cursa mas materias es de %d, y su legajo es: %d",edadMasMaterias,legajoMasMaterias);

	return 0;
}
