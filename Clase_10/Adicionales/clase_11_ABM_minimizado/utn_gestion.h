#ifndef UTN_GESTION_H_INCLUDED
#define UTN_GESTION_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int id;
    char descripcion [20];
    float importe;
    int cantidad;

} eproductos;
/** \brief Se encarga de obtener un numero entero
 * \param mensaje es el mensaje a ser mostrado
 * \return devuelve un numero entero
 */
int getInt(char mensaje[]);
/** \brief Se encarga de obtener un numero decimal
 * \param mensaje es el mensaje a ser mostrado
 * \return devuelve un numero entero
 */
float getFloat(char mensaje[]);
/** \brief Se encarga de obtener un dato tipo char
 * \param mensaje es el mensaje a ser mostrado
 * \return devuelve un el caracter ingresado por el usuario
 */
char getChar(char mensaje[]);
/** \brief Inicializa el array estructura en el campo seleccionado con un valor determinado
 * \param prod es el array estructura con el que se va a manipular
 * \param cantidad_elementos_arrayStruct es la longitud de array estructura
 * \param valor el el valor definido para rellenar el campo seleccionado en array estructura
 * \return
 */
void inicializarArrayStruct(eproductos prod[],int cantidad_elementos_arrayStruct,int valor);
/** \brief busca un lugar libre en el campo seleccion del array estructura
 * \param prod es el array estructura a manipular
 * \param cantidad_elementos_arrayStruct es la longitud del array estructura
 * \param valor es el valor definido para hacer la comparacion
 * \return devuelve un entero que es el indice de un lugar libre de lo contrario devuelve -1
 */
int buscarPrimeraOcurrencia(eproductos prod[],int cantidad_elementos_arrayStruct,int valor);
/** \brief Esta funcion se encarga de dar de alta a los productos
 * \param prod es array estructura donde se va cargar los valores
 * \param cantidad_elementos_arrayStruct es la longitud del array estructura
 * \return
 */
void Alta(eproductos producto[],int cantidad_elementos_arrayStruct);
/** \brief esta funcion se encarga de hacer una baja logica de los productos
 * cargados al array estructura
 * \param prod es array estructura donde se va cargar los valores
 * \param cantidad_elementos_arrayStruct es la longitud del array estructura
 * \return
 */
 void baja(eproductos producto[],int cantidad_elementos_arrayStruct);
/** \brief Esta funcion se encarga de modificar los campos de cada producto
 *
 * \param prod es array estructura donde se va cargar los valores
 * \param cantidad_elementos_arrayStruct es la longitud del array estructura
 * \return
 *
 */
void modificaion(eproductos producto[],int cantidad_elementos_arrayStruct);
/** \brief Esta funcion se encarga de mostrar por consola todo los
 * valores cargados en array estructura
 * \param prod es array estructura donde se va cargar los valores
 * \param cantidad_elementos_arrayStruct es la longitud del array estructura
 * \return
 *
 */
void listar(eproductos producto[],int cantidad_elementos_arrayStruct);
/** \brief esta funcion se encarga de ordenar el array estructura
 *
 * \param prod es array estructura donde se va cargar los valores
 * \param cantidad_elementos_arrayStruct es la longitud del array estructura
 * \return
 *
 */
void ordenar(eproductos producto[],int cantidad_elementos_arrayStruct);
/** \brief buscar el valor minimo en el array estructura
 * \param producto es array estructura donde se va cargar los valores
 * \param cantidad_elementos_arrayStruct es la longitud del array estructura
 * \return devuelve el valor minimo en el array estructura o devuelve (-1) si no hay valores cargados
 */
float buscarValorMinimo(eproductos producto[],int cantidad_elementos_arrayStruct);
/** \brief buscar el producto de menor importe dentro de array estructura
 * \param  producto es array estructura donde se va cargar los valores
 * \param cantidad_elementos_arrayStruct es la longitud del array estructura
 * \return
 */
void productoMasBarato(eproductos producto[],int cantidad_elementos_arrayStruct);
/** \brief  Calcular el precio promedio dentro del campo importe del array estructura
 * \param  producto es array estructura donde se va cargar los valores
 * \param cantidad_elementos_arrayStruct es la longitud del array estructura
 * \return devuelve el precio promedio o (-1) si no hay datos cargados
 */
float promdeioImporte(eproductos producto[],int cantidad_elementos_arrayStruct);
/** \brief busca los productos con importe mayor al promedio de importes
 * \param  producto es array estructura donde se va cargar los valores
 * \param cantidad_elementos_arrayStruct es la longitud del array estructura
 * \return
 */
void productosMayorPromedioImporte(eproductos producto[],int cantidad_elementos_arrayStruct);
#endif // UTN_GESTION_H_INCLUDED
