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
    int indice;

    int idAux;
    int idJuegoAux;
    int idClienteAux;
    int diaAux;
    int mesAux;
    int anioAux;

    int juegosActivo;
    int clientesActivo;

    char descripcionJuego[51];
    char nombreCliente[51];

    system("cls");
    printf(" *** ALTA ALQUILER ***\n\n");
    juegosActivo = juegosActivos(juegos, tamaniojuegos);
    clientesActivo = clientesActivos(clientes, tamanioClientes);

    indice = buscarAlquilerLibre(alquileres, tamanioAlquileres);
    if(indice == -1)
    {
        printf("No hay lugar para la carga de alquileres.\n\n");
    }
    else
    {
        idAux = getNextIdAlquiler(alquileres, tamanioAlquileres);
        if(juegosActivo != 0){
            mostrarJuegos(juegos, tamaniojuegos);
            idJuegoAux = getValidIntRango("\nIngrese juego a alquilar: ", "Error de ingreso. Reintente.\n\n", 1, juegosActivo);
        }
        else{
            printf("\nAun no se han cargado juegos.\n\n");
        }
        if(clientesActivo != 0){
            mostrarClientes(clientes, tamanioClientes);
            idClienteAux = getValidIntRango("\nIngrese cliente: ", "Error de ingreso. Reintente.\n\n", 1, clientesActivo);
        }
        else{
            printf("\nAun no se han cargado clientes.\n\n");
        }
        diaAux = getValidIntRango("Ingrese dia de alquiler: ", "Error de ingreso, reintente.\n\n", 1, 31);
        mesAux = getValidIntRango("Ingrese mes de alquiler: ", "Error de ingreso, reintente.\n\n", 1, 12);
        anioAux = getValidIntRango("Ingrese anio de alquiler (2017/2019): ", "Error de ingreso, reintente.\n\n", 2017, 2019);

        alquilerAux.idAlquiler = idAux;
        alquilerAux.codigoJuego = idJuegoAux;
        alquilerAux.codigoCliente = idClienteAux;
        alquilerAux.fechaAlquiler.dia = diaAux;
        alquilerAux.fechaAlquiler.mes = mesAux;
        alquilerAux.fechaAlquiler.anio = anioAux;
        alquilerAux.isEmpty = ACTIVO;

        alquileres[indice] = alquilerAux;

        system("cls");
        printf("\nSe agrego nuevo alquiler.\n\n");
        cargarDescripcion(juegos, tamaniojuegos, alquileres[indice].codigoJuego, descripcionJuego);
        cargarNombre(clientes, tamanioClientes, alquileres[indice].codigoCliente, nombreCliente);
        printf("\tID Alquiler  | Nombre Cliente |      Juego    |  Fecha de alquiler\n\n");
        printf("\t\t%02d   | %13s  |   %10s  |    %02d-%02d-%4d\n", alquileres[indice].idAlquiler, nombreCliente, descripcionJuego, alquileres[indice].fechaAlquiler.dia, alquileres[indice].fechaAlquiler.mes, alquileres[indice].fechaAlquiler.anio);
        printf("\n");
    }
}

int juegosActivos(eJuego juegos[], int tamanioJuegos)
{
    int juegoActivo = 0;
    for(int i=0; i<tamanioJuegos; i++)
    {
        if(juegos[i].isEmpty == ACTIVO)
        {
            juegoActivo++;
        }
    }
    return juegoActivo;
}

int clientesActivos(eCliente clientes[], int tamanioClientes)
{
    int clientesActivos=0;
    for(int i=0; i<tamanioClientes; i++)
    {
        if(clientes[i].isEmpty == ACTIVO)
        {
            clientesActivos++;
        }
    }
    return clientesActivos;
}


void cargarNombre(eCliente clientes[], int tamanioClientes, int idCliente, char cadena[])
{
    for(int i=0; i < tamanioClientes; i++)
    {
        if( clientes[i].idCliente == idCliente)
        {
            strcpy(cadena, clientes[i].nombre);
            break;
        }
    }
}

void cargarDescripcion(eJuego juegos[], int tamanioJuegos, int idJuego, char cadena[])
{
    for(int i=0; i < tamanioJuegos; i++)
    {
        if( juegos[i].idJuego == idJuego)
        {
            strcpy(cadena, juegos[i].descripcion);
            break;
        }
    }
}
