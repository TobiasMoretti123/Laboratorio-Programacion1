#include "Convertor.h"
float DeFarenheitACelsius(float temperatura) {
	float resultado;

	resultado = (temperatura * 1.8) + 32;

	return resultado;
}
float DeCelciusAFarenheit(float temperatura) {
	float resultado;

	resultado = (temperatura - 32) / 1.8;

	return resultado;
}
