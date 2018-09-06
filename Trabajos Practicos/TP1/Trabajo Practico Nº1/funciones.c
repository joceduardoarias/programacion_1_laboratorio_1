#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

/** \brief Suma dos numeros.
 *
 * \param a es el primer numero a sumar.
 * \param b es el segundo numero a sumar.
 * \return el valor de dicha suma
 *
 */
float suma(float a, float b)
{
    float resultado;
    resultado = a + b;
    return resultado;
}

/** \brief Resta dos numeros.
 *
 * \param a es el primer numero a sumar.
 * \param b es el segundo numero a sumar.
 * \return el valor de dicha resta
 *
 */
float resta(float a, float b)
{
    float resultado;
    resultado = a - b;
    return resultado;
}

/** \brief Divide dos numeros.
 *
 * \param a es el primer numero a sumar.
 * \param b es el segundo numero a sumar.
 * \return el valor de dicha division
 *
 */
float division(float a, float b)
{
    float resultado;
    resultado = a / b;
    return resultado;
}

/** \brief Multiplica dos numeros.
 *
 * \param a es el primer numero a sumar.
 * \param b es el segundo numero a sumar.
 * \return el valor de dicha multiplicacion
 *
 */
float multiplicacion(float a, float b)
{
    float resultado;
    resultado = a * b;
    return resultado;
}

/** \brief Calcula el factorial de un numero.
 *
 * \param a es el numero a factorizar.
 *
 */
void factorial(float a)
{
    int AuxiliarA;
    int resultado = 1;
    AuxiliarA = (int)a;
    if(AuxiliarA<0)
    {
        printf("No se puede realizar el factorial de un numero negativo.\n");
    }
    else if(a != AuxiliarA)
    {
        printf("No se puede realizar el factorial de un numero flotante.\n");
    }
    else
    {
        for(int i=AuxiliarA ; i>1 ; i--)
        {
            resultado = resultado * i;
        }
        printf("El factorial de %d es %d\n", AuxiliarA, resultado);
    }
}
