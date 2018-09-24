#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funciones.h"
int getInt(char mensaje[])
{
    int aux;
    printf("%s",mensaje);
    scanf("%d", &aux);
    return aux;
}
float getFloat(char mensaje[])
{
    float aux;
    printf("%s",mensaje);
    scanf("%f", &aux);
    return aux;
}
char getChar(char mensaje[])
{
    char aux;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c", &aux);
    return aux;
}
int esNumerico(char vec[])
{
    int i = 0;
    while(vec [i] != '\0')
    {
        if(vec[i] < '0' || vec[i] > '9' )
        {
            return 0;
        }
        i++;
    }
    return 1;
}
int esSoloLetras(char vec[])
{
    int i = 0;
    while(vec[i] != '\0')
    {
        if((vec[i] < 'a' || vec[i] > 'z') && (vec[i] < 'A' || vec[i] > 'Z'))
        {
            return 0;
        }
        i++;
    }
    return 1;
}
void getsTring(char mensjase[], char input[])
{
    printf(mensjase);
    fflush(stdin);
    gets(input);
}
int getStringLetras(char mensjase[], char input[])
{
    char aux[256];
    getsTring(mensjase,aux);
    if(esSoloLetras(aux) == 1)
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}
int getStringNumeros(char mensjase[], char input[])
{
    char aux[256];
    getsTring(mensjase,aux);
    if(esNumerico(aux) == 1)
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}
void inicialiarArrayStruc(eproductos prod_array_struc [], int longitud_array_struc,int valor)
{
    int i;
    for(i=0; i<longitud_array_struc; i++)
    {
        prod_array_struc[i].id = valor;
    }
}
int buscarPrimeraOcurrencia(eproductos prod_array_struc [], int longitud_array_struc,int valor)
{
    int i;
    for(i=0; i<longitud_array_struc; i++)
    {
        if(prod_array_struc[i].id == valor)
        {
            return i;
            break;
        }
    }
    return -1;
}
float buscarMinimo(eproductos prod_array_struc [], int longitud_array_struc)
{
    float minimo = -1;
    int i;
    for(i=0; i<longitud_array_struc; i++)
    {
        if(prod_array_struc[i].id != -1)
        {
            minimo = prod_array_struc[i].importe;
            break;
        }
    }
    if(minimo == -1)
    {
        return -1;
    }
    for(i=0; i<longitud_array_struc; i++)
    {
        if(prod_array_struc[i].importe < minimo && prod_array_struc[i].id != -1)
        {
            minimo = prod_array_struc[i].importe;
        }
    }
    return minimo;
}
void importeMinimo(eproductos prod_array_struc [], int longitud_array_struc)
{
    float minimo;
    int i;
    minimo = buscarMinimo(prod_array_struc,longitud_array_struc);
    if(minimo == -1)
    {
        printf("\n NO HAY DATOS CARGADOS");
    }
    printf("\n ID       NOMBRE       STOCK       IMPORTE");
    for(i=0; i<longitud_array_struc; i++)
    {
        if(prod_array_struc[i].importe == minimo && prod_array_struc[i].importe)
        {

            printf("\n %03d %10s %10d  %10.2f \n", prod_array_struc[i].id,prod_array_struc[i].descripcion,prod_array_struc[i].stock,prod_array_struc[i].importe );

        }

    }
}
