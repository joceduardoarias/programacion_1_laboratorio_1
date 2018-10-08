#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alquileres.h"
#include "juegos.h"
#include "clientes.h"
#include "utn.h"
#define ACTIVO 0
#define VACIO 1
#define BAJA 2

int getNextIdAlquiler(eAlquiler alquileres[],int tamanioAlquiler)
{
    int flag = 0;
    for(int i=0; i<tamanioAlquiler; i++)
    {
        if(alquileres[i].isEmpty == ACTIVO || alquileres[i].isEmpty == BAJA)
        {
            flag++;
        }
    }

    return flag+1;
}

int iniciarEstadosAlquileres(eAlquiler alquileres [], int tamanioAlquileres)
{
    int flag = -1;
    for(int i=0; i<tamanioAlquileres; i++)
    {
        alquileres[i].isEmpty = VACIO;
    }
    return flag;
}


int buscarAlquilerLibre(eAlquiler alquileres[], int tamanioAlquileres)
{
    int indice = -1;

    for(int i=0; i< tamanioAlquileres; i++)
    {

        if( alquileres[i].isEmpty == VACIO)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarAlquiler(eAlquiler alquileres[], int tamanioAlquileres, int idAlquiler)
{
    int indice = -1;
    for(int i=0; i < tamanioAlquileres; i++)
    {
        if(alquileres[i].idAlquiler == idAlquiler && alquileres[i].isEmpty == ACTIVO)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void abmAlquiler(eJuego juegos[], int tamaniojuegos, eCliente clientes[], int tamanioClientes, eAlquiler alquileres[], int tamanioAlquileres){

    system("cls");
    printf(" *** ALTA ALQUILER ***\n\n");


}
