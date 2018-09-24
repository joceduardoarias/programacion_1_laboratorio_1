#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int id;
    char descripcion[20];
    float importe;
    int stock;
}eproductos;
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
/** \brief verifica que el valor recibido sea numerico
 * \param valor es el vector con los datos ingresads que se va a analizar
 * \return devuel 1 si es numerico y 0 si no lo es.
 */
int esNumerico(char vec[]);
/** \brief verifica que el valor recibido sea una cadena de caracteres
 * \param valor es el vector con los datos ingresads que se va a analizar
 * \return devuelve 1 si contiene '' espacios y letras y 0 si no lo es
 */
int esSoloLetras(char vec[]);
/** \brief Solicita un texto al usuario y o devuelve
 * \param mensaje es el mensaje que se va a mostrar
 * \param input array donde se cargara el texto ingresado
 * \return 1 si solo contiene letras y 0 si no lo es
 */
void getsTring(char mensjase[], char input[]);
/** \brief Solicita un texto y lo devuelve
 * \param mensaje es el mensaje que se va a mostrar
 * \param input array donde se cargara el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int getStringLetras(char mensjase[], char input[]);
/** \brief Solicita un texto y lo devuelve
 * \param mensaje es el mensaje que se va a mostrar
 * \param input array donde se cargara el texto ingresado
 * \return 1 si el texto contiene solo letras y 0 si no lo es
 */
int getStringNumeros(char mensjase[], char input[]);
/** \brief iniciliza el array estructura con valor asignado
 * \param prod_array_struc es el array estructura que se va a manipular
 * \param longitud_array_struc es la longitud del array estructura
 * \param valor es el valor que cargara en el vector
 * \return devuelve 1 si son solo numero y 0 si o lo ess
 */

void inicialiarArrayStruc(eproductos prod_array_struc [], int longitud_array_struc,int valor);
/** \brief buscar la primera ocurrencia de lugar libre dentro de la estructura
 * \param prod_array_struc es el array estructura que se va a manipular
 * \param longitud_array_struc es la longitud del array estructura
 * \param valor es el valor a comparar dentro del vector
 * \return devuelve el indice del lugar libre o devuelve -1 si no hay lugar libre
 */
int buscarPrimeraOcurrencia(eproductos prod_array_struc [], int longitud_array_struc,int valor);
/** \brief buscar el valor minimo
 * \param prod_array_struc es el array estructura que se va a manipular
 * \param longitud_array_struc es la longitud del array estructura
 * \return devuelve el valor minimo y -1 si no hay datos cargados
 */
float buscarMinimo(eproductos prod_array_struc [], int longitud_array_struc);
/** \brief  busca el importe minimo en el array estructura
 * \param prod_array_struc es el array estructura que se va a manipular
 * \param longitud_array_struc es la longitud del array estructura
 * \param valor es el valor a analizar con el array estructura
 * \return
 */
void importeMinimo(eproductos prod_array_struc [], int longitud_array_struc);

#endif // FUNCIONES_H_INCLUDED
