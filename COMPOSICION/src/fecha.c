#include "fecha.h"
#include "utn.h"
void MostrarFecha(eFecha unaFecha) {
	printf("%d/%d/%d", unaFecha.dia, unaFecha.mes, unaFecha.mes);
}
eFecha PedirFecha(char mensaje[]) {
	eFecha miFecha;
	printf("%s", mensaje);
	int auxDia;
	int auxMes;
	int auxAnio;
	utn_getInt(&auxDia, 2, "Ingrese dia: ", "Dia invalido ", 1, 31, 4, 0);
	utn_getInt(&auxMes, 2, "Ingrese mes: ", "Mes invalido ", 1, 12, 4, 0);
	utn_getInt(&auxAnio, 2, "Ingrese Año: ", "Año invalido ", 1900, 3000, 4, 0);
	miFecha.dia = auxDia;
	miFecha.mes = auxMes;
	miFecha.anio = auxAnio;

	return miFecha;
}
