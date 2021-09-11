#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// void IngresarCadena (char mensaje[];char cadena[];int tam);
int main(void) {
	setbuf(stdout, NULL);
	char cadena[21] = "Perro";
	char cadena2[21] = " Feo";
	int comp;

	/*
	 * tolower
	 * touper
	 * isdigit (es numero)
	 * isalpha (es alphabetico)
	 * isspace (es un espacio)
	 *
	 * atoi (parse int)
	 * atof (parse float)
	 */
	//strncat(cadena,cadena2,21);concatenar
	//strlwr(cadena);//tolower de cadena
	//strupr(cadena2);//tupper de cadena
	//comp = strcmpi(cadena, cadena2); //stricmp ignora minuscula o mayuscula
	//printf("%d", comp);
	//strncpy(cadena,"hola",21);
	//puts(cadena);
	/*printf("Ingrese una palabra: ");
	 fflush(stdin);
	 fgets(cadena, 21, stdin);
	 largo = strlen(cadena);
	 cadena[largo-1]='\0';
	 printf("la cadena es %s y el largo es: %d", cadena, largo);*/
	return 0;
}

