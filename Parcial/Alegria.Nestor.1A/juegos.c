#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "juegos.h"
#include "utn.h"
#define ACTIVO 0
#define VACIO 1
#define BAJA 2

int menu()
{
    int option;
    system("cls");
    printf(" *** MENU DE OPCIONES ***\n\n");
    printf(":::::::::::::::::::::::::::::::::::::::\n\n");
    printf("  1- ABM Juegos\n");
    printf("  2- ABM Clientes\n");
    printf("  3- Alquileres\n");
    printf("  4- Salir\n");
    printf("\n:::::::::::::::::::::::::::::::::::::::\n\n");
    option = getInt("Ingrese opcion: ");
    return option;
}

int menuABMJuegos()
{
    int option;
    system("cls");
    printf(" *** ABM Juegos ***\n\n");
    printf(":::::::::::::::::::::::::::::::::::::::\n\n");
    printf("  1- Alta\n");
    printf("  2- Modificar\n");
    printf("  3- Baja\n");
    printf("  4- Listar\n");
    printf("  5- Salir\n");
    printf("\n:::::::::::::::::::::::::::::::::::::::\n\n");
    option = getInt("Ingrese opcion: ");
    return option;
}

void hardcodeoJuegos(eJuego juegos[])
{

    juegos[0].idJuego = 1;
    strcpy(juegos[0].descripcion, "Ping Pong");
    juegos[0].importe = 750;
    juegos[0].isEmpty = ACTIVO;

    juegos[1].idJuego = 2;
    strcpy(juegos[1].descripcion, "Metegol");
    juegos[1].importe = 1250.75;
    juegos[1].isEmpty = ACTIVO;

    juegos[2].idJuego = 3;
    strcpy(juegos[2].descripcion, "Inflable");
    juegos[2].importe = 1500;
    juegos[2].isEmpty = ACTIVO;

    juegos[3].idJuego = 4;
    strcpy(juegos[3].descripcion, "Cartas");
    juegos[3].importe = 250;
    juegos[3].isEmpty = ACTIVO;
}

int getNextId(eJuego juegos[],int tamanioJuegos)
{
    int flag = 0;
    for(int i=0; i<tamanioJuegos; i++)
    {
        if(juegos[i].isEmpty == ACTIVO || juegos[i].isEmpty == BAJA)
        {
            flag++;
        }
    }

    return flag+1;
}

int iniciarEstadosJuegos(eJuego juegos [], int tamanioJuegos)
{
    int flag = -1;
    for(int i=0; i<tamanioJuegos; i++)
    {
        juegos[i].isEmpty = VACIO;
    }
    return flag;
}


int buscarJuegoLibre(eJuego juegos[], int tamanioJuegos)
{
    int indice = -1;

    for(int i=0; i< tamanioJuegos; i++)
    {

        if( juegos[i].isEmpty == VACIO)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarJuego(eJuego juegos[], int tamanioJuegos, int idJuego)
{
    int indice = -1;
    for(int i=0; i < tamanioJuegos; i++)
    {


        if(juegos[i].idJuego == idJuego && juegos[i].isEmpty == ACTIVO)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void altaJuego(eJuego juegos[], int tamaniojuegos)
{
    eJuego nuevoJuego;
    int indice;
    int esta;

    int idAux;
    char descripcionAux[51];
    float importeAux;

    system("cls");
    printf("  *** Alta Juego ***\n\n");

    indice = buscarJuegoLibre(juegos, tamaniojuegos);


    if(indice == -1)
    {
        printf("No hay lugar para agregar mas juegos.\n\n");
    }
    else
    {
        idAux = getNextId(juegos, tamaniojuegos);
        printf("Id aux: %d", idAux);
        printf("\nIndice : %d\n\n", indice);

        getValidStringRango("Ingrese descripcion: ", "Error, solo se admiten letras. Reintente.\n\n", descripcionAux, 51);
        importeAux = getValidFloatMayor0("Ingrese importe: ", "Error solo se admiten numeros. Reintente.\n\n");
        nuevoJuego.isEmpty = ACTIVO;

        juegos[indice] = nuevoJuego;

    }
}

void abmJuegos(eJuego juegos[], int tamanioJuegos)
{
    char seguir = 's'; //Bandera continuar do-while.
    do
    {
        switch(menuABMJuegos())
        {
        case 1:
            altaJuego(juegos, tamanioJuegos);
            system("pause");
            break;
        case 2:

            system("pause");
            break;
        case 3:

            system("pause");
            break;
        case 4:

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

#include "juegos.h"
