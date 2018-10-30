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

int idAlquiler;
int codigoJuego;
int codigoCliente;
eFecha fechaAlquiler;
int isEmpty;
void hardcodeoAlquileres(eAlquiler alquileres[])
{
    alquileres[0].idAlquiler = 1;
    alquileres[0].codigoJuego = 2;
    alquileres[0].codigoCliente = 2;
    alquileres[0].fechaAlquiler.dia = 10;
    alquileres[0].fechaAlquiler.mes = 02;
    alquileres[0].fechaAlquiler.anio = 2017;
    alquileres[0].isEmpty = ACTIVO;

    alquileres[1].idAlquiler = 2;
    alquileres[1].codigoJuego = 3;
    alquileres[1].codigoCliente = 4;
    alquileres[1].fechaAlquiler.dia = 01;
    alquileres[1].fechaAlquiler.mes = 05;
    alquileres[1].fechaAlquiler.anio = 2017;
    alquileres[1].isEmpty = ACTIVO;

    alquileres[2].idAlquiler = 3;
    alquileres[2].codigoJuego = 4;
    alquileres[2].codigoCliente = 2;
    alquileres[2].fechaAlquiler.dia = 22;
    alquileres[2].fechaAlquiler.mes = 05;
    alquileres[2].fechaAlquiler.anio = 2017;
    alquileres[2].isEmpty = ACTIVO;

    alquileres[3].idAlquiler = 4;
    alquileres[3].codigoJuego = 2;
    alquileres[3].codigoCliente = 3;
    alquileres[3].fechaAlquiler.dia = 05;
    alquileres[3].fechaAlquiler.mes = 10;
    alquileres[3].fechaAlquiler.anio = 2017;
    alquileres[3].isEmpty = ACTIVO;

    alquileres[4].idAlquiler = 5;
    alquileres[4].codigoJuego = 2;
    alquileres[4].codigoCliente = 3;
    alquileres[4].fechaAlquiler.dia = 05;
    alquileres[4].fechaAlquiler.mes = 10;
    alquileres[4].fechaAlquiler.anio = 2018;
    alquileres[4].isEmpty = ACTIVO;
}

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


int checkEmptyAlquileres(eAlquiler alquileres[], int tamanioAlquileres)
{
    int flag = -1;
    for(int i=0; i<tamanioAlquileres; i++)
    {
        if(alquileres[i].isEmpty == ACTIVO)
        {
            flag = 0;
            break;
        }
    }
    return flag;
}

int buscarAlquilerLibre(eAlquiler alquileres[], int tamanioAlquileres)
{
    int indice = -1;

    for(int i=0; i< tamanioAlquileres; i++)
    {

        if(alquileres[i].isEmpty == VACIO)
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

void altaAlquiler(eJuego juegos[], int tamaniojuegos, eCliente clientes[], int tamanioClientes, eAlquiler alquileres[], int tamanioAlquileres)
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
        printf("Id aux: %d", idAux);
        printf("\nIndice : %d\n\n", indice);

        if(juegosActivo != 0)
        {
            mostrarJuegos(juegos, tamaniojuegos);
            idJuegoAux = getValidIntRango("\nIngrese juego a alquilar: ", "Error de ingreso. Reintente.\n\n", 1, juegosActivo);
        }
        else
        {
            printf("\nAun no se han cargado juegos.\n\n");
        }
        if(clientesActivo != 0)
        {
            mostrarClientes(clientes, tamanioClientes);
            idClienteAux = getValidIntRango("\nIngrese cliente: ", "Error de ingreso. Reintente.\n\n", 1, clientesActivo);
        }
        else
        {
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

void mostrarAlquiler(eJuego juegos[], int tamaniojuegos, eCliente clientes[], int tamanioClientes, eAlquiler alquileres[], int tamanioAlquileres, int indiceAlquiler)
{
    char descripcionJuego[20];
    char nombreCliente[51];
    printf("\n\tID Alquiler  | Nombre Cliente |      Juego    |  Fecha de alquiler\n\n");
    for(int i = 0; i< tamanioAlquileres; i++)
    {
        for(int j = 0; j<tamanioClientes; j++)
        {
            if(alquileres[indiceAlquiler].codigoCliente == clientes[j].idCliente)
            {
                strcpy(nombreCliente, clientes[j].nombre);
                break;
            }
        }
        for(int k = 0; k<tamaniojuegos; k++)
        {
            if(alquileres[indiceAlquiler].codigoJuego == juegos[k].idJuego)
            {
                strcpy(descripcionJuego, juegos[k].descripcion);
                break;
            }
        }


    }
    printf("\t\t%02d   | %13s  |   %10s  |    %02d-%02d-%4d\n", alquileres[indiceAlquiler].idAlquiler, nombreCliente, descripcionJuego, alquileres[indiceAlquiler].fechaAlquiler.dia, alquileres[indiceAlquiler].fechaAlquiler.mes, alquileres[indiceAlquiler].fechaAlquiler.anio);
    printf("\n");
}

void mostrarAlquileres(eJuego juegos[], int tamaniojuegos, eCliente clientes[], int tamanioClientes, eAlquiler alquileres[], int tamanioAlquileres)
{
    char descripcionJuego[20];
    char nombreCliente[51];
    printf("\tID Alquiler  | Nombre Cliente |      Juego    |  Fecha de alquiler\n\n");
    for(int i = 0; i< tamanioAlquileres; i++)
    {
        if(alquileres[i].isEmpty == ACTIVO)
        {
            for(int j = 0; j<tamanioClientes; j++)
            {
                if(alquileres[i].codigoCliente == clientes[j].idCliente)
                {
                    strcpy(nombreCliente, clientes[j].nombre);
                    break;
                }
            }
            for(int k = 0; k<tamaniojuegos; k++)
            {
                if(alquileres[i].codigoJuego == juegos[k].idJuego)
                {
                    strcpy(descripcionJuego, juegos[k].descripcion);
                    break;
                }
            }
            printf("\t\t%02d   | %13s  |   %10s  |    %02d-%02d-%4d\n", alquileres[i].idAlquiler, nombreCliente, descripcionJuego, alquileres[i].fechaAlquiler.dia, alquileres[i].fechaAlquiler.mes, alquileres[i].fechaAlquiler.anio);
        }
    }
    printf("\n");
}

void bajaAlquiler(eJuego juegos[], int tamaniojuegos, eCliente clientes[], int tamanioClientes, eAlquiler alquileres[], int tamanioAlquileres)
{
    int indice;
    int idAlquiler;
    char confirmacion;

    system("cls");
    printf("  *** Baja Alquiler ***\n\n");

    idAlquiler = getValidInt("Ingrese el ID del alquiler: ", "Error, solo se admiten numeros. Reintente.\n\n");
    indice = buscarAlquiler(alquileres, tamanioAlquileres, idAlquiler);

    if( indice == -1)
    {
        printf("No hay ningun alquiler con el ID %d\n\n", idAlquiler);
    }
    else
    {
        mostrarAlquiler(juegos, tamaniojuegos, clientes, tamanioClientes, alquileres, tamanioAlquileres, indice);
        printf("\nSe eliminara el alquiler.\n");
        confirmacion = getValidChar("\nConfirma baja del alquiler (s/n)?: ", "Error al ingresar opcion. Reintente.\n\n", 's', 'n');
        if(confirmacion != 's')
        {
            printf("Borrado cancelado.\n\n");
        }
        else
        {
            alquileres[indice].isEmpty = BAJA;
            printf("Se ha eliminado el alquiler con exito.\n\n");
        }
    }
}


void listarAlquileres(eJuego juegos[], int tamaniojuegos, eCliente clientes[], int tamanioClientes, eAlquiler alquileres[], int tamanioAlquileres)
{
    system("cls");
    printf(" *** LISTAR ALQUILERES ***\n\n");
    mostrarAlquileres(juegos, tamaniojuegos, clientes, tamanioClientes, alquileres, tamanioAlquileres);
}


void abmAlquiler(eJuego juegos[], int tamaniojuegos, eCliente clientes[], int tamanioClientes, eAlquiler alquileres[], int tamanioAlquileres)
{
    int checkArrayAlquileres;
    char seguir = 's'; //Bandera continuar do-while.
    do
    {
        checkArrayAlquileres = checkEmptyAlquileres(alquileres, tamanioAlquileres);
        switch(menuABM("Alquileres"))
        {
        case 1:
            altaAlquiler(juegos, tamaniojuegos, clientes, tamanioClientes, alquileres, tamanioAlquileres);
            system("pause");
            break;
        case 2:
            if(checkArrayAlquileres == -1) //Si checkArrayAlquileres() es -1 aun no hay alquileres cargados en el sistema y lo informa.
            {
                printf("No hay alquileres dados de alta en el sistema.\n\n");
            }
            else
            {

            }
            system("pause");
            break;
        case 3:
            if(checkArrayAlquileres == -1) //Si checkArrayAlquileres() es -1 aun no hay alquileres cargados en el sistema y lo informa.
            {
                printf("No hay alquileres dados de alta en el sistema.\n\n");
            }
            else
            {
                bajaAlquiler(juegos, tamaniojuegos, clientes, tamanioClientes, alquileres, tamanioAlquileres);
            }
            system("pause");
            break;
        case 4:
            if(checkArrayAlquileres == -1) //Si checkArrayAlquileres() es -1 aun no hay juegos cargados en el sistema y lo informa.
            {
                printf("No hay alquileres dados de alta en el sistema.\n\n");
            }
            else
            {
                listarAlquileres(juegos, tamaniojuegos, clientes, tamanioClientes, alquileres, tamanioAlquileres);
            }
            system("pause");
            break;
        case 5:
            seguir = 'n';
            break;
        default:
            printf("Error, ingreso una opcion no valida. Reintente.\n\n");
        }
    }
    while(seguir == 's');
}
