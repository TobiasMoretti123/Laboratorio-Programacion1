#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Validacion.h"
float ValidarTemperatura(float temperatura, float max, float min)
{
	float retorno;

	while (temperatura<min || temperatura>max)
	{
		printf("La temperatura es mayor al punto de ebullición o menor al de congelacion: ");
		scanf("%f", &temperatura);
		retorno = 1;
	}

	return retorno;
}
