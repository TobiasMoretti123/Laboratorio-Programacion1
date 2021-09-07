/*
Crear una función que permita ingresar un numero al usuario y lo retorne.
Crear una función que reciba el radio de un círculo y retorne su área.
Utilizar las funciones para hacer un programa que calcule el área de un círculo
cuyo radio es ingresado por el usuario. Documentar las funciones al estilo Doxygen.
*/
#include <stdio.h>
#include <stdlib.h>
//A = pi * r²

int PedirNumero (char mensaje[]);
float CalcularArea (float radio);
int main(void) {
	setbuf(stdout, NULL);
	float numeroIngresado;
	float area;

	numeroIngresado = PedirNumero("Ingrese el radio del circulo: ");
	area = CalcularArea(numeroIngresado);

	printf("El area del circulo es: %.2f centimetros cuadrados",area );
	return 0;
}
/// \fn int PedirNumero(char[])
/// \brief Pide un numero y lo retorna
/// \param mensaje El mensaje para pedir el numero
/// \return El numero ingresado
int PedirNumero (char mensaje[])
{
	setbuf(stdout, NULL);
	int numero;

	printf("%s", mensaje);
	scanf("%d", &numero);

	return numero;
}
/// \fn float CalcularArea(float)
/// \brief Recibe un float y calcula el area de un circulo
/// \param radio El float a calcular para el area
/// \return El area de un circulo
float CalcularArea (float radio)
{
	float resultado;

	resultado = (radio*radio)*3.14;

	return resultado;
}
