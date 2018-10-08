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

void abmAlquiler(eJuego juegos[], int tamaniojuegos, eCliente clientes[], int tamanioClientes, eAlquiler alquileres[], int tamanioAlquileres)
{
    eAlquiler alquilerAux;

    int idAux;
    int idJuegoAux;
    int idClienteAux;
    int diaAux;
    int mesAux;
    int anioAux;

    int juegosActivo;
    int clientesActivo;

    system("cls");
    printf(" *** ALTA ALQUILER ***\n\n");
    juegosActivo = juegosActivos(juegos, tamaniojuegos);
    clientesActivo = clientesActivos(clientes, tamanioClientes);

    idAux = getNextIdAlquiler(alquileres, tamanioAlquileres);
    mostrarJuegos(juegos, tamaniojuegos);
    idJuegoAux = getValidIntRango("\nIngrese juego a alquilar: ", "Error de ingreso. Reintente.\n\n", 0, juegosActivo);
    mostrarClientes(clientes, tamanioClientes);
    idClienteAux = getValidIntRango("\nIngrese cliente: ", "Error de ingreso. Reintente.\n\n", 0, clientesActivo);
    diaAux = getValidIntRango("Ingrese dia: ", "Error de ingreso, reintente.\n\n", 1, 31);
    mesAux = getValidIntRango("Ingrese mes: ", "Error de ingreso, reintente.\n\n", 1, 12);
    anioAux = getValidIntRango("Ingrese anio (2017/2019): ", "Error de ingreso, reintente.\n\n", 2017, 2019);




}

int juegosActivos(eJuego juegos[], int tamanioJuegos)
{
    int juegoActivo=0;
    for(int i=0; i<tamanioJuegos; i++){
        if(juegos[i].isEmpty == ACTIVO){
            juegoActivo++;
        }
    }
    return juegoActivo;
}

int clientesActivos(eCliente clientes[], int tamanioClientes)
{
    int clientesActivos=0;
    for(int i=0; i<tamanioClientes; i++){
        if(clientes[i].isEmpty == ACTIVO){
            clientesActivos++;
        }
    }
    return clientesActivos;
}
