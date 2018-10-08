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
    juegos[2].importe = 1250.75;
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

void mostrarJuego(eJuego juegos)
{
    printf("\t%2d  | %15s  |  %.2f  \n", juegos.idJuego, juegos.descripcion, juegos.importe);

}

void mostrarJuegos(eJuego juegos[], int tamanioJuegos)
{
    printf("\n\tId  |     Descripcion  |  Importe\n\n");
    for(int i=0; i<tamanioJuegos; i++){
        if(juegos[i].isEmpty == ACTIVO){
        mostrarJuego(juegos[i]);
        }
    }
}

void altaJuego(eJuego juegos[], int tamaniojuegos)
{
    eJuego nuevoJuego;
    int indice;
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

        nuevoJuego.idJuego = idAux;
        nuevoJuego.isEmpty = ACTIVO;
        strcpy(nuevoJuego.descripcion, descripcionAux);
        nuevoJuego.importe = importeAux;

        juegos[indice] = nuevoJuego;
        printf("\nSe agrego nuevo juego:\n\n");
        printf("\tId  |     Descripcion  |  Importe\n\n");
        mostrarJuego(juegos[indice]);
        printf("\n");
    }
}

void modificarJuego(eJuego juegos[], int tamanioJuegos)
{
    int idJuego;
    int indice;
    int opcion;
    char confirmacion;

    char descripcionAux[51];
    float importeAux;

    system("cls");
    printf("  *** Modificar Juego ***\n\n");
    idJuego = getValidInt("Ingrese el ID del juego: ", "Error, solo se admiten numeros. Reintente.\n\n");
    indice = buscarJuego(juegos, tamanioJuegos, idJuego);
    if( indice == -1)
    {
        printf("No hay ningun juego con el ID %d\n\n", idJuego);
    }
    else
    {
        printf("\n\tId  |     Descripcion  |  Importe\n\n");
        mostrarJuego( juegos[indice]);
        printf("\n Menu de opciones -->\n\n1- Modificar descripcion\n2- Modificar importe\n3- Salir\n\n");
        opcion = getValidInt("Ingrese opcion: ", "Error, ingreso no valido. Reintente.\n\n");
        switch(opcion)
        {
        case 1:
            printf("\nModificar descripcion -->\n\n");
            getValidStringRango("Ingrese nueva descripcion: ", "Error, solo se admiten letras.\n", descripcionAux, 51);
            printf("\nSe modificara \"%s\" por \"%s\"", juegos[indice].descripcion, descripcionAux);
            confirmacion = getValidChar("\nConfirma cambio (s/n)?: ", "Error al ingresar opcion. Reintente.\n\n", 's', 'n');
            if(confirmacion == 'n')
            {
                printf("Se cancelo la modificacion de la descripcion.\n\n");
            }
            else
            {
                strcpy(juegos[indice].descripcion, descripcionAux);
                printf("Se modifico la decripcion con exito.\n\n");
            }
            break;
        case 2:
            printf("\nModificar importe -->\n\n");
            importeAux = getValidFloatMayor0("Ingrese importe: ", "Error solo se admiten numeros. Reintente.\n\n");
            printf("\nSe modificara \"%.2f\" por \"%.2f\"", juegos[indice].importe, importeAux);
            confirmacion = getValidChar("\nConfirma cambio (s/n)?: ", "Error al ingresar opcion. Reintente.\n\n", 's', 'n');
            if(confirmacion == 'n')
            {
                printf("Se cancelo la modificacion del importe.\n\n");
            }
            else
            {
                juegos[indice].importe = importeAux;
                printf("Se modifico el importe con exito.\n\n");
            }
            break;
        case 3:
            break;
        default:
            printf("Error, opcion incorrecta.\n\n");

        }
    }

}

void bajaJuego(eJuego juegos[], int tamaniojuegos)
{
    int indice;
    int idJuego;
    char confirmacion;

    system("cls");
    printf("  *** Baja Juego ***\n\n");

    idJuego = getValidInt("Ingrese el ID del juego: ", "Error, solo se admiten numeros. Reintente.\n\n");
    indice = buscarJuego(juegos, tamaniojuegos, idJuego);

    if( indice == -1)
    {
        printf("No hay ningun juego con el ID %d\n\n", idJuego);
    }
    else
    {
        printf("\n\tId  |     Descripcion  |  Importe\n\n");
        mostrarJuego(juegos[indice]);
        printf("\nSe eliminara el juego.\n");
        confirmacion = getValidChar("\nConfirma baja de juego (s/n)?: ", "Error al ingresar opcion. Reintente.\n\n", 's', 'n');
        if(confirmacion != 's')
        {
            printf("Borrado cancelado.\n\n");
        }
        else
        {
            juegos[indice].isEmpty = BAJA;
            printf("Se ha eliminado el juego con exito.\n\n");
        }
    }

}

void listarJuegos(eJuego juegos[], int tamanioJuegos)
{
    system("cls");
    printf("  *** Lista de Juegos ***\n");
    printf("  Ordenados por Importe (descendente) y descripcion (ascendente).\n\n");
    eJuego auxJuego;
    for(int i=0; i<tamanioJuegos-1; i++)
    {
        for(int j=i+1; j<tamanioJuegos; j++)
        {
            if(juegos[i].importe < juegos[j].importe)
            {
                auxJuego = juegos[i];
                juegos[i] = juegos[j];
                juegos[j] = auxJuego;
            }
            else if((juegos[i].importe == juegos[j].importe) && strcmp(juegos[i].descripcion, juegos[j].descripcion) > 0)
            {
                auxJuego = juegos[i];
                juegos[i] = juegos[j];
                juegos[j] = auxJuego;
            }
        }
    }
    mostrarJuegos(juegos, tamanioJuegos);
    printf("\n");
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
            modificarJuego(juegos, tamanioJuegos);
            system("pause");
            break;
        case 3:
            bajaJuego(juegos, tamanioJuegos);
            system("pause");
            break;
        case 4:
            listarJuegos(juegos, tamanioJuegos);
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
