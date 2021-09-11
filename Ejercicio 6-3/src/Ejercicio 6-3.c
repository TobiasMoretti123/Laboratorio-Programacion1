/*
 Tobias Moretti
 Ejercicio 6-3:
 Pedirle al usuario su nombre y apellido
 (en variables separadas, una para el nombre y otra para el apellido).
 Ninguna de las dos variables se puede modificar.
 Debemos lograr guardar en una tercer variable el apellido y el nombre con el siguiente formato:
 Por ejemplo:
 Si el nombre es juan ignacio y el apellido es gOmEz, la salida deber�a ser:
 Gomez, Juan Ignacio
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define T 21

void IngresoCadena(char mensaje[], char cadena[], int tam);
void CadenaAMinuscula(char cadena[], int tam);
void SacarEnter(char cadena[], int tam);
void PonerComa(char cadena[], int tam);
void PrimerMayuscula(char cadena[], int tam);

int main(void) {
	setbuf(stdout, NULL);
	char nombre[T];
	char apellido[T];
	char persona[T];
	IngresoCadena("Ingrese su nombre: ", nombre, T);
	IngresoCadena("Ingrese su apellido: ", apellido, T);
	PonerComa(apellido, T);
	strncat(apellido, " ", T);
	strncat(apellido, nombre, T);
	strncpy(persona, apellido, T);
	CadenaAMinuscula(persona, T);
	SacarEnter(persona, T);
	PrimerMayuscula(persona, T);


	printf("%s", persona);

	return 0;
}
void IngresoCadena(char mensaje[], char cadena[], int tam) {
	printf("%s", mensaje);
	fflush(stdin);
	fgets(cadena, tam, stdin);
}
void CadenaAMinuscula(char cadena[], int tam) {
	for (int i = 0; i < tam; i++) {
		if (cadena[i] > 'Z') {
			strlwr(cadena);
		}
	}
}
void SacarEnter(char cadena[], int tam) {
	for (int i = 0; i < tam; i++) {
		if (cadena[i] == '\n') {
			cadena[i] = ' ';
		}
	}
}
void PonerComa(char cadena[], int tam) {
	for (int i = 0; i < tam; i++) {
		if (cadena[i] == ' ' || cadena[i] == '\n') {
			cadena[i] = ',';
		}
	}
}
void PrimerMayuscula(char cadena[], int tam) {
	int i = 0;
	while (cadena[i] != '\0') {
		if (cadena[i] >= 'a' && cadena[i] <= 'z') {
			cadena[0] = toupper(cadena[0]);
		}
		else
		{
			if(cadena[i]==' ')
			{
				cadena[i+1]=toupper(cadena[i+1]);
			}
		}
		i++;
	}
}

