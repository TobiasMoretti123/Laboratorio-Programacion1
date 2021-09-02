#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Convertor.h"

float CelsiusAFahrenheit(float celsius)
{
	float resultado;
	resultado = (celsius*1.8) + 32;
	return resultado;
}
float FarenheitACelcius(float farenheit)
{
	float resultado;
	resultado = (farenheit-32)/1.8;
	return resultado;
}


