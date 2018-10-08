#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientes.h"
#include "juegos.h"
#include "utn.h"
#define ACTIVO 0
#define VACIO 1
#define BAJA 2

void hardcodeoClientes(eCliente clientes[])
{
    clientes[0].idCliente = 1;
    strcpy(clientes[0].apellido, "Lopez");
    strcpy(clientes[0].nombre, "Juan");
    clientes[0].sexo = 'm';
    strcpy(clientes[0].domicilio, "Solier 750");
    clientes[0].isEmpty = ACTIVO;

    clientes[1].idCliente = 2;
    strcpy(clientes[1].apellido, "Fernandez");
    strcpy(clientes[1].nombre, "Lorena");
    clientes[1].sexo = 'f';
    strcpy(clientes[1].domicilio, "Deheza 417");
    clientes[1].isEmpty = ACTIVO;

    clientes[2].idCliente = 3;
    strcpy(clientes[2].apellido, "Alvarez");
    strcpy(clientes[2].nombre, "Gabriel");
    clientes[2].sexo = 'm';
    strcpy(clientes[2].domicilio, "Suipacha 318");
    clientes[2].isEmpty = ACTIVO;

    clientes[3].idCliente = 4;
    strcpy(clientes[3].apellido, "Fernandez");
    strcpy(clientes[3].nombre, "Ramon");
    clientes[3].sexo = 'm';
    strcpy(clientes[3].domicilio, "Genova 1798");
    clientes[3].isEmpty = ACTIVO;
}

int getNextIdCliente(eCliente clientes[],int tamanioClientes)
{
    int flag = 0;
    for(int i=0; i<tamanioClientes; i++)
    {
        if(clientes[i].isEmpty == ACTIVO || clientes[i].isEmpty == BAJA)
        {
            flag++;
        }
    }

    return flag+1;
}

int iniciarEstadosClientes(eCliente clientes [], int tamanioClientes)
{
    int flag = -1;
    for(int i=0; i<tamanioClientes; i++)
    {
        clientes[i].isEmpty = VACIO;
    }
    return flag;
}

int buscarClienteLibre(eCliente clientes[], int tamanioClientes)
{
    int indice = -1;

    for(int i=0; i< tamanioClientes; i++)
    {

        if( clientes[i].isEmpty == VACIO)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarCliente(eCliente clientes[], int tamanioClientes, int idCliente)
{
    int indice = -1;
    for(int i=0; i < tamanioClientes; i++)
    {


        if(clientes[i].idCliente == idCliente && clientes[i].isEmpty == ACTIVO)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void mostrarCliente(eCliente clientes)
{
    printf("\t%2d  | %12s  | %12s  |   %c  |  %12s  \n", clientes.idCliente, clientes.apellido, clientes.nombre, clientes.sexo, clientes.domicilio);
}

void mostrarClientes(eCliente clientes[], int tamanioClientes)
{
    printf("\n\t Id |      Apellido |        Nombre | Sexo |     Direccion\n\n");
    for(int i=0; i<tamanioClientes; i++){
        if(clientes[i].isEmpty == ACTIVO){
        mostrarCliente(clientes[i]);
        }
    }
}

void altaCliente(eCliente clientes[], int tamanioClientes)
{
    eCliente nuevoCliente;
    int indice;
    int idCliente;

    char apellidoAux[51];
    char nombreAux[51];
    char sexoAux;
    char direccionAux[51];

    system("cls");
    printf("  *** Alta Cliente ***\n\n");

    indice = buscarClienteLibre(clientes, tamanioClientes);
    if(indice == -1)
    {
        printf("No hay lugar para agregar mas clientes.\n\n");
    }
    else
    {
        idCliente = getNextIdCliente(clientes, tamanioClientes);

        printf("Id aux: %d", idCliente);
        printf("\nIndice : %d\n\n", indice);

        getValidStringRango("Ingrese apellido: ", "Error, solo se admiten letras. Reintente.\n\n", apellidoAux, 51);
        getValidStringRango("Ingrese nombre: ", "Error, solo se admiten letras. Reintente.\n\n", nombreAux, 51);
        sexoAux = getValidChar("Ingrese sexo: ", "Error de ingreso. Reintente.\n\n", 'm', 'f');
        getValidStringDireccionRango("Ingrese direccion: ", "Error, solo se admiten letras. Reintente.\n\n", direccionAux, 51);



        clientes[indice] = nuevoCliente;
        printf("\nSe agrego nuevo juego:\n\n");
        printf("\n\t Id |      Apellido |        Nombre | Sexo |     Direccion\n\n");
        mostrarCliente(clientes[indice]);
        printf("\n");
    }
}







void abmClientes(eCliente clientes[], int tamanioClientes)
{
    char seguir = 's'; //Bandera continuar do-while.
    do
    {
        switch(menuABM())
        {
        case 1:
            altaCliente(clientes, tamanioClientes);
            system("pause");
            break;
        case 2:
           // modificarJuego(juegos, tamanioJuegos);
            system("pause");
            break;
        case 3:
            //bajaJuego(juegos, tamanioJuegos);
            system("pause");
            break;
        case 4:
            //listarJuegos(juegos, tamanioJuegos);
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
