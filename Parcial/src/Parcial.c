/******************************************************************************
 1. Realizar un párrafo en donde se pueda observar
 la/s relacion/es entre los siguientes términos: vector, función, dirección de memoria,
 pasaje por valor, pasaje por referencia.
 No esta permitido realizar definiciones de manual,
 es necesario que el párrafo demuestre las relaciones entre los términos.
 2. Realizar una función que reciba como parámetro una cadena de caracteres.
 La misma permitirá intercambiar las vocales por un carácter
 comodín que también será recibido como parámetro.
 La función retornará la cantidad de reemplazos que se llevaron a cabo.
 3. Realizar una función que reciba como parámetro el importe de un producto
 y un porcentaje de descuento.
 La función retornará el importe con el descuento aplicado.

 *******************************************************************************/
/*
 1.Un vector,puede ser utilizado en una función, utilizando su direccion de memoria dirección de memoria,
 si es un pasaje por valor se debera especificar en que lugar del vector, si es pasaje por referencia se debera pasar completamente sin &.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

float ImporteConDescuento(int importe, int descuento);
int IntercambiarVocales(char cadena[], char caracterComodin);
int main() {
	setbuf(stdout, NULL);
	char cadena[50] = { "Yolanda" };
	int importe = 25;
	int descuento = 5;
	float importeConDescuento;
	int cantidadVocales;
	char caracterComodin = '*';
	cantidadVocales = IntercambiarVocales(cadena, caracterComodin);
	importeConDescuento = ImporteConDescuento(importe, descuento);
	printf("Importe con descuento: %.2f\n", importeConDescuento);
	printf("Cantidad de vocales cambiadas: %d\nPalabra cambiada: %s",
			cantidadVocales, cadena);

	return 0;
}
float ImporteConDescuento(int importe, int descuento) {
	float importeConDescuento;
	float total;
	importeConDescuento = (float) importe * descuento / 100;
	total = importe - importeConDescuento;
	return total;
}
int IntercambiarVocales(char cadena[], char caracterComodin) {
	int i;
	int cantidadVocales;
	int tamCadena;
	cantidadVocales = 0;
	tamCadena = strnlen(cadena, 50);
	for (i = 0; i < tamCadena; i++) {
		strlwr(cadena);
		if (cadena[i] == 'a' || cadena[i] == 'e' || cadena[i] == 'i'
				|| cadena[i] == 'o' || cadena[i] == 'u') {
			cadena[i] = caracterComodin;
			cantidadVocales++;
		}
	}
	return cantidadVocales;
}

