#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "juegos.h"
#include "clientes.h"
#include "alquileres.h"
#include "informes.h"
#include "utn.h"
#define ACTIVO 0
#define VACIO 1
#define BAJA 2

int menuInformes()
{
    int option;
    system("cls");
    printf(" *** MENU DE INFORMES ***\n\n");
    printf(":::::::::::::::::::::::::::::::::::::::\n\n");
    printf("  1- Promedio y total de los Importes de los juegos alquilados.\n");
    printf("  2- Cantidad de juegos cuyo importe NO supera el promedio del item anterior.\n");
    printf("  3- Listar todos los clientes que alquilaron un juego determinado.\n");
    printf("  4- \n");
    printf("  5- \n");
    printf("  6- \n");
    printf("  7- \n");
    printf("  8- \n");
    printf("  9- Listar todos los juegos ordenados por Importe (descendente). Metodo Burbujero.\n");
    printf("  10- Listar todos los clientes ordenados por APellido (ascendente). Metodo Insercion.\n");
    printf("  11- Salir\n");
    printf("\n:::::::::::::::::::::::::::::::::::::::\n\n");
    option = getInt("Ingrese opcion: ");
    return option;
}

void abmInformes(eJuego juegos[], int tamaniojuegos, eCliente clientes[], int tamanioClientes, eAlquiler alquileres[], int tamanioAlquileres)
{
    char seguir = 's'; //Bandera continuar do-while.
    do
    {
        switch(menuInformes())
        {
        case 1:
            promedioYTotalImportes(juegos, tamaniojuegos);
            system("pause");
            break;
        case 2:
            cantidadJuegosNoSuperanPromedio(juegos, tamaniojuegos);
            system("pause");
            break;
        case 3:
            //listarClientesAlquilaronUnJuego(juegos, tamaniojuegos, clientes, tamanioClientes, alquileres, tamanioAlquileres);
            system("pause");
            break;
        case 4:

            system("pause");
            break;

        case 9:
            listarJuegosImporte(juegos, tamaniojuegos);
            system("pause");
            break;
        case 10:
            listarClientesApellidos(clientes, tamanioClientes);
            system("pause");
            break;
        case 11:
            seguir = 'n';
            break;
        default:
            printf("Error, ingreso una opcion no valida. Reintente.\n\n");
        }
    }
    while(seguir == 's');
}

float totalImportes(eJuego juegos[], int tamanioJuegos)
{
    float sueldos = 0;
    for(int i=0; i<tamanioJuegos; i++)
    {
        if(juegos[i].isEmpty == ACTIVO)
        {
            sueldos = sueldos + juegos[i].importe;
        }
    }
    return sueldos;
}

float promedioJuegos(eJuego juegos[], int tamanioJuegos, float totalImportes)
{
    float promedio;
    int contador = 0;
    for(int i=0; i<tamanioJuegos; i++)
    {
        if(juegos[i].isEmpty == ACTIVO)
        {
            contador++;
        }
    }
    promedio = totalImportes/contador;
    return promedio;
}

int juegosNoSuperanPromedio(eJuego juegos[], int tamanioJuegos, int promedio)
{
    int cantidadJuegos = 0;
    for(int i=0; i<tamanioJuegos; i++)
    {
        if(juegos[i].importe < promedio && juegos[i].isEmpty == ACTIVO)
        {
            cantidadJuegos++;
        }
    }
    return cantidadJuegos;
}

void promedioYTotalImportes(eJuego juegos[], int tamanioJuegos)
{
    float totalImportesJuegos;
    float promedioImportesJuegos;
    system("cls");
    printf(" Promedio y total de los Importes de los juegos alquilados.\n\n");
    totalImportesJuegos = totalImportes(juegos, tamanioJuegos);
    promedioImportesJuegos = promedioJuegos(juegos, tamanioJuegos, totalImportesJuegos);
    printf("El total de los juegos alquilados es de %.2f, el promedio es de %.2f.\n\n", totalImportesJuegos, promedioImportesJuegos);
}

void cantidadJuegosNoSuperanPromedio(eJuego juegos[], int tamanioJuegos)
{
    int totalNoSuperanPromedio;
    float totalImportesJuegos;
    float promedioImportesJuegos;
    system("cls");
    printf(" Cantidad de juegos cuyo importe NO supera el promedio del item anterior.\n\n");
    totalImportesJuegos = totalImportes(juegos, tamanioJuegos);
    promedioImportesJuegos = promedioJuegos(juegos, tamanioJuegos, totalImportesJuegos);
    totalNoSuperanPromedio = juegosNoSuperanPromedio(juegos, tamanioJuegos, promedioImportesJuegos);
    printf("Existen %d juegos cuyos importes no superan el promedio.\n\n", totalNoSuperanPromedio);
}

/*void listarClientesAlquilaronUnJuego(eJuego juegos[], int tamaniojuegos, eCliente clientes[], int tamanioClientes, eAlquiler alquileres[], int tamanioAlquileres)
{
    int idJuego;
    int indiceJuego;
    char descripcion[51];
    char nombre[51];
    char apellido[51];
    int flag = 0;

    system("cls");
    printf(" Listar todos los clientes que alquilaron un juego determinado.\n\n");
    idJuego = elegirJuego(juegos, tamaniojuegos);
    indiceJuego = buscarJuego(juegos, tamaniojuegos, idJuego);
    cargarDescripcion(juegos, tamaniojuegos, juegos[indiceJuego].idJuego, descripcion);

    system("cls");
    printf(" Clientes que alquilaron el juego %d %s\n\n", idJuego, descripcion);
    for(int i=0; i< tamanioAlquileres; i++)
    {
        if(alquileres[i].isEmpty == ACTIVO && alquileres[i].codigoJuego == idJuego)
        {
            for(int j=0; j<tamanioClientes; j++){
                if(alquileres[i].codigoCliente == clientes[j].idCliente){
                    printf(" %d   |   %s  ", alquileres[i].idAlquiler, clientes[i].nombre);
                    flag = 1;
                }
            }


        }
    }
    if(flag == 0)
    {
        printf("No hay clientes que mostrar\n\n");
    }

}*/


int elegirCliente(eCliente clientes[], int tamanioClientes)
{
    int idCliente;
    printf("Clientes: \n\n");
    printf("\t Id |      Apellido |        Nombre | Sexo |     Direccion\n\n");
    for(int i=0; i < tamanioClientes; i++)
    {
        if(clientes[i].isEmpty == ACTIVO){
            mostrarCliente(clientes[i]);
        }
    }
    idCliente = getValidInt("\nSeleccione un cliente: ", "Error de ingreso. Reintente.\n\n");
    return idCliente;
}

int elegirJuego(eJuego juegos[], int tamanioJuegos)
{
    int idJuego;
    printf("Juegos: \n\n");
    printf("\tId  |     Descripcion  |  Importe\n\n");
    for(int i=0; i < tamanioJuegos; i++)
    {
        if(juegos[i].isEmpty == ACTIVO){
            mostrarJuego(juegos[i]);
        }
    }
    idJuego = getValidInt("\nSeleccione un juego: ", "Error de ingreso. Reintente.\n\n");
    return idJuego;
}


void listarJuegosImporte(eJuego juegos[], int tamanioJuegos){
    eJuego juegoAux;
    system("cls");
    printf(" Listar todos los juegos ordenados por Importe (descendente).\n\n");
    for(int i=0; i<tamanioJuegos-1 ; i++)
    {
        for(int j=i+1; j<tamanioJuegos; j++)
        {
            if(juegos[i].importe < juegos[j].importe)
            {
                juegoAux = juegos[i];
                juegos[i] = juegos[j];
                juegos[j] = juegoAux;
            }
        }
    }
    mostrarJuegos(juegos, tamanioJuegos);
    printf("\n");
}

void listarClientesApellidos(eCliente clientes[], int tamanioClientes)
{
    system("cls");
    printf(" Listar todos los clientes ordenados por Apellido (ascendente). Metodo Insercion.\n\n");

}
