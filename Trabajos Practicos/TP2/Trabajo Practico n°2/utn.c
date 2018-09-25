#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

/**
 *\brief Solicita un numero al usuario y devuelve el resultado.
 * \param mensaje Es el mensaje a ser mostrado
 * \return El numero ingresado por el usuario
 *
 */
float getFloat(char mensaje[])
{
    float auxiliar;
    printf("%s", mensaje);
    scanf("%f", &auxiliar);
    return auxiliar;
}

/**
 *\brief Solicita un numero al usuario y devuelve el resultado.
 * \param mensaje Es el mensaje a ser mostrado
 * \return El numero ingresado por el usuario
 *
 */
int getInt(char mensaje[])
{
    int auxiliar;
    printf("%s", mensaje);
    scanf("%d", &auxiliar);
    return auxiliar;
}

/**
*\brief Solicita un numero al usuario y devuelve el resultado.
* \param mensaje Es el mensaje a ser mostrado
* \return El numero ingresado por el usuario
*
*/
char getChar(char mensaje[])
{
    char auxiliar;
    printf("%s", mensaje);
    fflush(stdin);// Windows
    //fpurge(stdin);// Linux
    scanf("%c", &auxiliar);
    return auxiliar;
}

/**
*\brief Verifica si el valor recibido es numerico
* \param str Array con la cadena a ser analizada
* \return 1 si es numerico y 0 si no lo es
*
*/
int esNumerico(char str[])
{
    int i = 0;
    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9')
        {
            return 0;
        }
        i++;
    }
    return 1;
}

/**
*\brief Verifica si el valor recibido contiene solo letras
* \param str Array con la cadena a ser analizada
* \return 1 si es contiene solo ' ' y letras y 0 si no lo es
*
*/
int esSoloLetras(char str[])
{
    int i = 0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
        {
            return 0;
        }
        i++;
    }
    return 1;
}

/**
*\brief Verifica si el valor recibido contiene solo letras y numeros
* \param str Array con la cadena a ser analizada
* \return 1 si contiene solo espacio o letras y numeros y 0 si no lo es
*
*/
int AlfaNumerico(char str[])
{
    int i = 0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
        {
            return 0;
        }
        i++;
    }
    return 1;
}

/**
* \brief Solicita un texto al usuario y lo devuelve
* \param mensaje Es el mensaje a ser mostrado
* \param input Array donde se cargara el texto ingresado
* \return void
*
*/
void getString(char mensaje[], char input[])
{
    printf(mensaje);
    fflush(stdin);
    gets(input);
}

/**
* \brief Solicita un texto al usuario y lo devuelve
* \param mensaje Es el mensaje a ser mostrado
* \param input Array donde se cargara el texto ingresado
* \return 1 si el texto contiene solo letras
*
*/
int getStringLetras(char mensaje[], char input[])
{
    char aux[256];
    getString(mensaje, aux);
    fflush(stdin);
    if(esSoloLetras(aux))
    {
        strcpy(input, aux);
        return 1;
    }
    return 0;
}


/**
* \brief Solicita un texto al usuario y lo devuelve
* \param mensaje Es el mensaje a ser mostrado
* \param input Array donde se cargara el texto ingresado
* \param maximo cantidad maxima de caracteres permitidos
* \return 1 si el texto contiene solo letras
*
*/int getStringLetrasRango(char mensaje[], char input[], int maximo)
{
    char aux[256];
    getString(mensaje, aux);
    fflush(stdin);
    while(strlen(aux)>maximo){
        printf("\nSupero la cantidad de caracteres validos, reintente.\n");
        getString(mensaje, aux);
        fflush(stdin);

    }
    if(esSoloLetras(aux))
    {
        fflush(stdin);
        strcpy(input, aux);
        return 1;
    }
    return 0;
}

/**
* \brief Solicita un texto al usuario y lo devuelve
* \param mensaje Es el mensaje a ser mostrado
* \param input Array donde se cargara el texto ingresado
* \return 1 si el texto contiene solo numeros
*
*/
int getStringNumerosRango(char mensaje[], char input[], int minimo, int maximo)
{
    char aux[256];
    getString(mensaje, aux);
    if(esNumerico(aux) && (atoi(aux) >= minimo && atoi(aux) <= maximo))
    {
        strcpy(input, aux);
        return 1;
    }
    return 0;
}

int getStringNumeros(char mensaje[], char input[])
{
    char aux[256];
    getString(mensaje, aux);
    if(esNumerico(aux))
    {
        strcpy(input, aux);
        return 1;
    }
    return 0;
}

int esNumericoFlotante(char str[])
{
   int i=0;
   int cantidadPuntos=0;
   while(str[i] != '\0')
   {
       if (i == 0 && str[i] == '-')
       {
           i++;
           continue;

       }
       if (str[i] == '.' && cantidadPuntos == 0)
       {
           cantidadPuntos++;
           i++;
           continue;

       }
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}

int getStringNumerosFlotantes(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumericoFlotante(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}
