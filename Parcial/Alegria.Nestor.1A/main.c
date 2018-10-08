#include <stdio.h>
#include <stdlib.h>
#include "juegos.h"
#include "clientes.h"
#include "utn.h"
#define TAM_JUEGOS 10
#define TAM_CLIENTES 10
#define TAM_ALQUILERES 10

int main()
{

    eJuego juegos[TAM_JUEGOS]; //Inicializo el array JUEGOS.
    eCliente clientes[TAM_CLIENTES]; //Inicializo el array CLIENTES.

    char seguir = 's'; //Bandera continuar do-while.

    iniciarEstadosJuegos(juegos, TAM_JUEGOS); //Inicializo los estados en VACIO.
    hardcodeoJuegos(juegos); //Harcodea datos de 4 juegos.
    hardcodeoClientes(clientes); //Harcodea datos de 4 juegos.

    do
    {
        switch(menu())
        {
        case 1:
            abmJuegos(juegos, TAM_JUEGOS);
            system("pause");
            break;
        case 2:
            abmClientes(clientes, TAM_CLIENTES);
            system("pause");
            break;
        case 3:

            system("pause");
            break;
        case 4:
            seguir = 'n';
            break;
        default:
            printf("Error, ingreso una opcion no valida. Reintente.\n\n");
        }




    }
    while(seguir == 's');
    return 0;
}
