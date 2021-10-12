/*Ejercicio 10-3:
Una empresa importadora que comercializa productos Apple, decide registrar de sus productos los siguientes datos:
idProducto (numerico)
descripcion (alfanumérico)
nacionalidad (numérico, por el momento utilizaremos un define: EEUU - CHINA - OTRO)
tipo (numérico)
precio (numérico decimal)
Agregar la estructura etipoProducto, que definirá los siguientes campos:

idTipo (numérico)
descripcionTipo(alfanumérico)

Para esta estructura en principio trabajaremos con datos hardcodeados:

idTipo  descripcionTipo
1000    Iphone
1001    Ipad
1002    Mac
1003    Accesorios



Realizar un programa que permita interactuar con un menú de usuarios con las siguientes opciones:
ALTA Producto: Se ingresan los datos de UN solo producto. Siempre y cuando haya espacio disponible en el array. Al momento de dar de alta el producto, el usuario podrá elegir el tipo de producto, de una lista que se le desplegará en pantalla.
BAJA Producto: A partir del ingreso del ID. Si existe el producto desaparece de la lista, dejando espacio disponible para un nuevo producto.
MODIFICACIÓN Producto: A partir del ingreso del ID. Si existe se podrá modificar el precio o el tipo. Si modifica el tipo de producto, se utilizara el mismo criterio que para dar de alta.
LISTADO Productos.
LISTADO ordenado por precio.
LISTADO ordenado por descripción.
Agregar los siguientes informes:
El/los  productos más caros.
Precio promedio por tipo de producto. Se deberá mostrar la descripción del tipo y a continuación el precio promedio.
Agregar los siguientes informes:
El/los  productos más caros.
Los productos que cuestan 700
Precio promedio por tipo de producto.
De los Iphone el más barato
Los productos "MADE IN CHINA"
Las MAC que cuestan más de 700 USD
El/Los Accesorios más caros

Se agregan los siguientes listados:
El listado de todos los productos con la descripción del tipo.
Por cada tipo la lista de productos.


*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "input.h"

#define TAM 5
#define EMPTY 0
#define FULL 1
#define IPHONE 1
#define MAC 2
#define IPAD 3
#define ACCESORIOS 4
#define EEUU 1
#define CHINA 2
#define OTRO 3
#define TAMAL 0
#define TABIEN 1
#define LENTIPO 4


typedef struct
{
  int idProducto;//PK
  char descripcion[100];
  int nacionalidad;
  int tipo;//FK
  float precio;
  int isEmpty;
//  eTipoProducto tipo; <--- Esto no

} eProducto;//Lo' producto'


typedef struct
{
    int idTipo;//PK Tatuatelo
    char descripcionTipo[30];
    int isEmpty;// Este tambien

} eTipoProducto;//Tipos de productos

int CargarProducto (eProducto lista[], int tam);
void MostrarListadoProductos (eProducto lista[], int tam);
void OrdenarListaProductosPorId (eProducto lista[], int tam);
void MostrarProducto (eProducto unProducto);
eProducto IngresarUnProducto ();
void InicializarListaProducto (eProducto lista[], int tam);
int BuscarPrimerEspacioLibre (eProducto lista[], int tam);
//int BuscarProductoPorId(int idProducto, eProducto lista[], int tam);
int BorrarProductoGuardado (eProducto lista[], int tam);
int ModificarProductoGuardado (eProducto lista[], int tam);
void OrdenarProductoPorPrecio (eProducto lista[], int tam);
void OrdenarListaProductosPorDescripcion (eProducto lista[], int tam);
int ListadoProductosIphone (eProducto lista[], int tam);
float BuscarPrecioMasAlto (eProducto lista[], int tam);
void InformarProductoPorPrecio (eProducto lista[], int tam,	float precioBuscado);
int MostrarPrecioPromedioPorTipoDeProducto (eProducto lista[], int tam, int tipo,float *pPromedio);
void ListadoProductosConTipo (eProducto productos[], eTipoProducto tipos[], int tamProductos, int tamTipo);

int
main (void)
{
  int opcion;
  int retornoFuncion;
  setbuf (stdout, NULL);
  float precioPromedioPorIphone;
  float precioPromedioPorMac;
  float precioPromedioPorIpad;
  float precioPromedioPorAccesorios;

  eTipoProducto listaTipoProductos[LENTIPO] =
  {
      {1000, "Iphone", FULL},
      {1001, "Ipad", FULL},
      {1002, "Mac", FULL},
      {1003, "Accesorios", FULL}
  };

  eProducto listaProductos[TAM] =
    { {1000, "Iphone 12", 1, 1000, 700, FULL}, {2000, "Macbook Air", 1, 1002, 1200,FULL}, {5000, "MagSafe", 1, 1003,50, FULL}, {2500,"Ipad 5", 3,1001, 750, FULL}, {4000,"Ipad 3",2, 1001,400, FULL}};
  //eProducto listaProductos[TAM];
  //InicializarListaProducto(listaProductos,TAM);


do{

    printf("1. Alta\n");
    printf("2. Mostrar\n");
    printf("3. Borrar producto\n");
    printf("4. Modificar Producto\n");
    printf("5. Ordenado Por Precio\n");
    printf("6. Ordenado Por Descripcion\n");
    printf("7. Listado de Iphone de EEUU\n");

    opcion = IngresarEntero("Elija una opcion ewe\n");

    switch(opcion){
        case 1:
        retornoFuncion = CargarProducto(listaProductos, TAM);
        if(retornoFuncion != -1){
        	puts("El producto se cargo exitosamente\n");
        }else{
        	puts("El producto no pudo cargarse\n");
        }
        break;
        case 2:
        MostrarListadoProductos(listaProductos, TAM);
        break;
        case 3:
        retornoFuncion=BorrarProductoGuardado(listaProductos, TAM);
        if(retornoFuncion==1)
        {
            printf("El producto se borro exitosamente.\n");
        }
        else
        {
            printf("no se pudo borrar el producto.\n");
        }

        break;

        case 4:
        retornoFuncion = ModificarProductoGuardado(listaProductos,TAM);

        if(retornoFuncion==1)
        {
            printf("El producto se modifico Correctamente.\n");
        }
        else
        {
            printf("No se pudo modificar el producto con exito.\n");
        }

        break;

        case 5:
               OrdenarProductoPorPrecio(listaProductos,TAM);
               printf("Se ordeno Correctamente\n");

        break;
         case 6:
               OrdenarListaProductosPorDescripcion(listaProductos,TAM);
               printf("Se ordeno Correctamente\n");

        break;
        case 7:
               retornoFuncion = ListadoProductosIphone(listaProductos, TAM);
               if(retornoFuncion == TAMAL)
               {
                   printf("No se encontraron Iphone de EEUU\n");
               }
        break;
        case 28:

            ListadoProductosConTipo(listaProductos, listaTipoProductos, TAM, LENTIPO);

        break;
    }

}while(opcion!=10);
/*
  InformarProductoPorPrecio (listaProductos, TAM, 700);

  if (MostrarPrecioPromedioPorTipoDeProducto(listaProductos, TAM, 1, &precioPromedioPorIphone) == 0)
      {
          printf ("el promedio de precios para Iphone es igual a %.2f", precioPromedioPorIphone);
      }
  if (MostrarPrecioPromedioPorTipoDeProducto (listaProductos, TAM, 2, &precioPromedioPorMac) == 0)
      {
          printf ("el promedio de precios para Mac es igual a %.2f",precioPromedioPorMac);
      }
  if (MostrarPrecioPromedioPorTipoDeProducto(listaProductos, TAM, 3, &precioPromedioPorIpad) == 0)
      {
        printf ("el promedio de precios para Ipad es igual a %.2f",precioPromedioPorIpad);
       }
  if (MostrarPrecioPromedioPorTipoDeProducto (listaProductos, TAM, 4, &precioPromedioPorAccesorios) == 0)
    {
        printf ("el promedio de precios para Accesorios es igual a %.2f", precioPromedioPorAccesorios);
    }
*/
  //CargarProductos(listaProductos, TAM);
  /*
     InformarProductoMasCaro(listaProductos, TAM);
     MostrarListadoProductos(listaProductos, TAM);
     printf("Lista Ordenada\n");
     OrdenarListaProductosPorId(listaProductos, TAM);
     MostrarListadoProductos(listaProductos, TAM);

   */




  return EXIT_SUCCESS;
}

/* recorre el array para encontrar el tipo indicado
** devuelve -1 si no consiguiC3 hacer la tarea y 0 si pudo hacer su tarea
*/
int MostrarPrecioPromedioPorTipoDeProducto (eProducto lista[], int tam, int tipo,float *pPromedio)
{
  int i;
  int contador;
  float acumuladorPrecio;
  float promedio;
  int retorno;

  retorno = -1;
  contador = 0;
  acumuladorPrecio = 0;

  for (i = 0; i < tam; i++)
    {
      if (lista[i].isEmpty == FULL && lista[i].tipo == tipo)
	{
	  contador++;
	  acumuladorPrecio += lista[i].precio;
	}
    }
  if (contador != 0)
    {
      *pPromedio = acumuladorPrecio / contador;
      retorno = 0;
    }
  return retorno;
}




float
BuscarPrecioMasAlto (eProducto lista[], int tam)
{

  int flagMax = 0;
  float auxiliarPrecioMax;
  for (int i = 0; i < tam; i++)
    {
      if (lista[i].isEmpty == FULL)
	{
	  if (flagMax == 0 || lista[i].precio > auxiliarPrecioMax)
	    {
	      auxiliarPrecioMax = lista[i].precio;
	      flagMax = 1;
	    }
	}
    }
  return auxiliarPrecioMax;
}

void
InformarProductoPorPrecio (eProducto lista[], int tam, float precioBuscado)
{


  for (int i = 0; i < tam; i++)
    {
      if (lista[i].isEmpty == FULL && precioBuscado == lista[i].precio)
	{
	  MostrarProducto (lista[i]);
	}
    }

}

int
CargarProducto (eProducto lista[], int tam)
{
  int index = BuscarPrimerEspacioLibre (lista, tam);
  if (index != -1)
    {
      lista[index] = IngresarUnProducto ();
    }
  return index;
}

void
OrdenarListaProductosPorId (eProducto lista[], int tam)
{
  eProducto auxiliarProducto;
  for (int i = 0; i < tam - 1; i++)
    {
      for (int j = i + 1; j < tam; j++)
	{
	  if (lista[i].idProducto < lista[j].idProducto)
	    {
	      auxiliarProducto = lista[i];
	      lista[i] = lista[j];
	      lista[j] = auxiliarProducto;
	    }
	}
    }
}

void
OrdenarProductoPorPrecio (eProducto lista[], int tam)
{
  eProducto auxiliarProducto;
  for (int i = 0; i < tam - 1; i++)
    {
      for (int j = i + 1; j < tam; j++)
	{
	  if (lista[i].precio > lista[j].precio)
	    {
	      auxiliarProducto = lista[i];
	      lista[i] = lista[j];
	      lista[j] = auxiliarProducto;
	    }
	}
    }
}

void
OrdenarListaProductosPorDescripcion (eProducto lista[], int tam)
{
  eProducto auxiliarProducto;
  for (int i = 0; i < tam - 1; i++)
    {
      for (int j = i + 1; j < tam; j++)
	{
	  if (strcmp (lista[i].descripcion, lista[j].descripcion) > 0)
	    {
	      auxiliarProducto = lista[i];
	      lista[i] = lista[j];
	      lista[j] = auxiliarProducto;
	    }
	}
    }
}

void
MostrarListadoProductos (eProducto lista[], int tam)
{
  int flagListaVacia = 0;
  printf ("Id\tDescripcion\tNacionalidad\tTipo\tPrecio\n");
  for (int i = 0; i < tam; i++)
    {
      if (lista[i].isEmpty == FULL)
	{
	  MostrarProducto (lista[i]);
	}
      else
	{
	  if (flagListaVacia == 0)
	    {
	      puts ("Listado de productos vacia.\n");
	      flagListaVacia = 1;
	    }

	}
    }
}

void
MostrarProducto (eProducto unProducto)
{
  printf ("%4d %20s %4d %4d %4.2f\n", unProducto.idProducto,
	  unProducto.descripcion, unProducto.nacionalidad, unProducto.tipo,
	  unProducto.precio);
}

eProducto
IngresarUnProducto ()
{
  eProducto producto;
  producto.idProducto = IngresarEntero ("Ingresa el id del producto");
  getString (producto.descripcion, "Ingresar la descripcion del producto",
	     100);
  producto.nacionalidad =
    IngresarEntero
    ("Ingresa la nacionalidad del producto, 1.EEUU, 2.China, 3.Otro: ");
  producto.tipo =
    IngresarEntero
    ("Ingresa el tipo del producto, 1.Iphone, 2.Mac, 3.Ipad, 4.Accesorios: ");
  producto.precio = IngresarFlotante ("Ingresa el precio del producto");
  producto.isEmpty = FULL;

  return producto;
}

void
InicializarListaProducto (eProducto lista[], int tam)
{
  for (int i = 0; i < tam; i++)
    {
      lista[i].isEmpty = EMPTY;
    }
}

int
BuscarPrimerEspacioLibre (eProducto lista[], int tam)
{
  int i;
  int index;

  index = -1;
  for (i = 0; i < tam; i++)
    {
      if (lista[i].isEmpty == EMPTY)
	{
	  index = i;
	  break;
	}
    }
  return index;
}

/*int BuscarProductoPorId(int idProducto,eProducto lista[], int tam){

}
*/
int
BorrarProductoGuardado (eProducto lista[], int tam)
{
  int i;
  int auxiliarProductoGuardado = 0;
  int productoSeleccionado;
  MostrarListadoProductos (lista, tam);

  productoSeleccionado = IngresarEntero ("Ingrese el producto a borrar");

  for (i = 0; i < tam; i++)
    {
      if (lista[i].isEmpty == FULL
	  && lista[i].idProducto == productoSeleccionado)
	{
	  lista[i].isEmpty = EMPTY;
	  auxiliarProductoGuardado = 1;
	  break;
	}
    }
  return auxiliarProductoGuardado;
}


int
ModificarProductoGuardado (eProducto lista[], int tam)
{
  int i;
  int productoSeleccionado;
  float precioAcambiar;
  int retorno;
  retorno = 0;

  productoSeleccionado =
    IngresarEntero ("Ingrese el producto por ID a modificar");

  for (i = 0; i < tam; i++)
    {
      if (lista[i].isEmpty == FULL
	  && lista[i].idProducto == productoSeleccionado)
	{
	  precioAcambiar = IngresarFlotante ("Ingrese nuevo precio.");
	  lista[i].precio = precioAcambiar;
	  retorno = 1;
	  break;
	}
    }

  return retorno;


}


int
ListadoProductosIphone (eProducto lista[], int tam)
{
  int retorno = TAMAL /*0 */ ;
  int flagListaVacia = 0;
  printf ("Id\tDescripcion\tNacionalidad\tTipo\tPrecio\n");
  for (int i = 0; i < tam; i++)
    {
      if (lista[i].isEmpty == FULL && lista[i].tipo == IPHONE /*1 */
	  && lista[i].nacionalidad == EEUU /*1 */ )
	{
	  MostrarProducto (lista[i]);
	  retorno = TABIEN /*1 */ ;
	}

    }


  return retorno;
}


void ListadoProductosConTipo (eProducto productos[], eTipoProducto tipos[], int tamProductos, int tamTipo)
{
    int i;
    int j;

    for(i = 0; i < tamProductos; i++)
    {

        for(j = 0; j < tamTipo; j++)
        {

            if(productos[i].isEmpty == FULL && productos[i].tipo == tipos[j].idTipo)
            {
                printf("%20s %10s\n",productos[i].descripcion,tipos[j].descripcionTipo);
                break;
            }
        }
    }
}

