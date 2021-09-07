#include "validacion.h"
/// \fn float ValidarTemperatura(char[], float, float, char[])
/// \brief Pide un float y lo valida entre un maximo y un minimo
/// \param mensaje El mensaje que se va a mostrar al pedir un float
/// \param min El parametro minimo
/// \param max El parametro maximo
/// \param mensajeError El mensaje que se va a mostrar cuando lo ingresado esta fuera de rango
/// \return El float validado entre los parametros inpuestos
float ValidarTemperatura(char mensaje[], float min, float max,
		char mensajeError[]) {
	float retorno;
	float temperatura;

	printf("%s", mensaje);
	scanf("%f", &temperatura);
	while (temperatura < min || temperatura > max) {
		printf("%s", mensajeError);
		scanf("%f", &temperatura);
		retorno = temperatura;
	}
	retorno = temperatura;
	return retorno;
}

