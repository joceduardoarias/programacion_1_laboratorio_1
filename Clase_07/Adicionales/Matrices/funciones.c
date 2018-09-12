#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "funciones.h"

//Menu
int menu()
{
    int opcion;
    system("cls");
    printf("Bienvenido.\n\n");
    printf("1- Alta de usuario\n");
    printf("2- Baja de usuario\n");
    printf("3- Modificar usuario\n");
    printf("4- Ordenar usuarios\n");
    printf("5- Buscar usuario\n");
    printf("6- Listar usuarios\n");
    printf("7- Salir\n\n");
    printf("Ingrese opcion: ");
    opcion = getche();
    return opcion;
}

//Pone los estados en 1
int inicializacion(int lista[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        lista[i]=1;
    }
    return 0;
}

//Busca espacio libre en el array, si no existe retorna -1
int buscaEspacio(int lista[], int tam)
{
    int retorno = -1;
    for(int i=0; i<tam; i++)
    {
        if(lista[i]==1)
        {
            retorno = i;
            return retorno;
            break;
        }
    }
    return retorno;
}

