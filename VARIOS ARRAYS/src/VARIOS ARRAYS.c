#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 5

void CargarAlumnos(int legajo[], char nombre[][50], float nota[], int edad[],
		int tam);
void MostarAlumnos(int legajo[], char nombre[][50], float nota[], int edad[],
		int tam);
void OrdenarAlumnosPorNombre(int legajo[], char nombre[][50], float nota[],
		int edad[], int tam);
int IngresarEntero(char mensaje[]);
float IngresarFlotante(char mensaje[]);
void getString(char cadena[], char mensaje[], int longitud);

int main(void) {
	setbuf(stdout, NULL);
	//Modelo de datos
	int legajo[TAM] = { 1000, 1001, 1002, 1003, 1004 };
	int edad[TAM] = { 22, 26, 35, 41, 25 };
	float nota[TAM] = { 9, 6, 4, 2, 7 };
	char nombre[TAM][50] = { "Maria", "Luis", "Juan Carlos", "Ana", "Martin" };
	//char email[][];

	//CargarAlumnos(legajo, nombre, nota, edad, TAM);
	OrdenarAlumnosPorNombre(legajo, nombre, nota, edad, TAM);
	MostarAlumnos(legajo, nombre, nota, edad, TAM);

	return EXIT_SUCCESS;
}

void CargarAlumnos(int legajo[], char nombre[][50], float nota[], int edad[],
		int tam) {
	for (int i = 0; i < tam; i++) {
		legajo[i] = IngresarEntero("Ingrese el legajo: ");
		edad[i] = IngresarEntero("Ingrese edad: ");
		nota[i] = IngresarFlotante("Ingrese la nota: ");
		getString(nombre[i], "Ingrese el nombre: ", 50);
	}
}
void MostarAlumnos(int legajo[], char nombre[][50], float nota[], int edad[],
		int tam) {
	for (int i = 0; i < tam; i++) {
		printf("%4d\t%-20s %4d\t%4.2f\n", legajo[i], nombre[i], edad[i],
				nota[i]);
	}
}
void OrdenarAlumnosPorNombre(int legajo[], char nombre[][50], float nota[],
		int edad[], int tam) {
	int auxiliarInt;
	float auxiliarFloat;
	char auxiliarString[50];
	for (int i = 0; i < tam - 1; i++) {
		for (int j = i + 1; j < tam; j++) {
			if (strcmp(nombre[i], nombre[j]) > 0) //Criterio de ordenamiento
					{
				auxiliarFloat = nota[i];
				nota[i] = nota[j];
				nota[j] = auxiliarFloat;

				auxiliarInt = edad[i];
				edad[i] = edad[j];
				edad[j] = auxiliarInt;

				auxiliarInt = legajo[i];
				legajo[i] = legajo[j];
				legajo[j] = auxiliarInt;

				strcpy(auxiliarString, nombre[i]);
				strcpy(nombre[i], nombre[j]);
				strcpy(nombre[j], auxiliarString);

			}
		}
	}
}
void OrdenarAlumnosPorNota(int legajo[], char nombre[][50], float nota[],
		int edad[], int tam) {
	int auxiliarInt;
	float auxiliarFloat;
	char auxiliarString[50];
	for (int i = 0; i < tam - 1; i++) {
		for (int j = i + 1; j < tam; j++) {
			if (nota[i] < nota[j]) //Criterio de ordenamiento
					{
				auxiliarFloat = nota[i];
				nota[i] = nota[j];
				nota[j] = auxiliarFloat;

				auxiliarInt = edad[i];
				edad[i] = edad[j];
				edad[j] = auxiliarInt;

				auxiliarInt = legajo[i];
				legajo[i] = legajo[j];
				legajo[j] = auxiliarInt;

				strcpy(auxiliarString, nombre[i]);
				strcpy(nombre[i], nombre[j]);
				strcpy(nombre[j], auxiliarString);

			}
		}
	}
}
int IngresarEntero(char mensaje[]) {
	int numero;
	printf("%s", mensaje);
	scanf("%d", &numero);

	return numero;
}
float IngresarFlotante(char mensaje[]) {
	float numero;
	printf("%s", mensaje);
	scanf("%f", &numero);
	return numero;
}
void getString(char cadena[], char mensaje[], int longitud) {
	printf("%s", mensaje);
	fflush(stdin);
	fgets(cadena, longitud, stdin);
}
