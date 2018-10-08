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
    strcpy(clientes[1].apellido, "Lopez");
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
    for(int i=0; i<tamanioClientes; i++)
    {
        if(clientes[i].isEmpty == ACTIVO)
        {
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

        nuevoCliente.idCliente = idCliente;
        strcpy(nuevoCliente.apellido, apellidoAux);
        strcpy(nuevoCliente.nombre, nombreAux);
        nuevoCliente.sexo = sexoAux;
        strcpy(nuevoCliente.domicilio, direccionAux);

        clientes[indice] = nuevoCliente;
        printf("\nSe agrego nuevo juego:\n\n");
        printf("\n\t Id |      Apellido |        Nombre | Sexo |     Direccion\n\n");
        mostrarCliente(clientes[indice]);
        printf("\n");
    }
}

void modificarCliente(eCliente clientes[], int tamanioClientes)
{
    int idCliente;
    int indice;
    int opcion;
    char confirmacion;

    char apellidoAux[51];
    char nombreAux[51];
    char sexoAux;
    char direccionAux[51];

    system("cls");
    printf("  *** Modificar Cliente ***\n\n");
    idCliente = getValidInt("Ingrese el ID del cliente: ", "Error, solo se admiten numeros. Reintente.\n\n");
    indice = buscarCliente(clientes, tamanioClientes, idCliente);
    if( indice == -1)
    {
        printf("No hay ningun cliente con el ID %d\n\n", idCliente);
    }
    else
    {
        printf("\n\t Id |      Apellido |        Nombre | Sexo |     Direccion\n\n");
        mostrarCliente(clientes[indice]);
        printf("\n Menu de opciones -->\n\n1- Modificar apellido\n2- Modificar nombre\n3- Sexo\n4- Domicilio\n5- Salir\n\n");
        opcion = getValidInt("Ingrese opcion: ", "Error, ingreso no valido. Reintente.\n\n");
        switch(opcion)
        {
        case 1:
            printf("\nModificar apellido -->\n\n");
            getValidStringRango("Ingrese nuevo apellido: ", "Error, solo se admiten letras.\n", apellidoAux, 51);
            printf("\nSe modificara \"%s\" por \"%s\"", apellidoAux , clientes[indice].apellido);
            confirmacion = getValidChar("\nConfirma cambio (s/n)?: ", "Error al ingresar opcion. Reintente.\n\n", 's', 'n');
            if(confirmacion == 'n')
            {
                printf("Se cancelo la modificacion del apellido.\n\n");
            }
            else
            {
                strcpy(clientes[indice].apellido, apellidoAux);
                printf("Se modifico el apellido con exito.\n\n");
            }
            break;
        case 2:
            printf("\nModificar nombre -->\n\n");
            getValidStringRango("Ingrese nuevo nombre: ", "Error, solo se admiten letras.\n", nombreAux, 51);
            printf("\nSe modificara \"%s\" por \"%s\"", nombreAux , clientes[indice].nombre);
            confirmacion = getValidChar("\nConfirma cambio (s/n)?: ", "Error al ingresar opcion. Reintente.\n\n", 's', 'n');
            if(confirmacion == 'n')
            {
                printf("Se cancelo la modificacion del nombre.\n\n");
            }
            else
            {
                strcpy(clientes[indice].nombre, nombreAux);
                printf("Se modifico el nombre con exito.\n\n");
            }
            break;
        case 3:
            printf("\nModificar sexo -->\n\n");
            sexoAux = getValidChar("Ingrese nuevo sexo: ", "Error, solo se admiten letras.\n", 'm', 'f');
            printf("\nSe modificara \"%c\" por \"%c\"", sexoAux , clientes[indice].sexo);
            confirmacion = getValidChar("\nConfirma cambio (s/n)?: ", "Error al ingresar opcion. Reintente.\n\n", 's', 'n');
            if(confirmacion == 'n')
            {
                printf("Se cancelo la modificacion del sexo.\n\n");
            }
            else
            {
                clientes[indice].sexo = sexoAux;
                printf("Se modifico el sexo con exito.\n\n");
            }
            break;
        case 4:
            printf("\nModificar direccion -->\n\n");
            getValidStringDireccionRango("Ingrese nueva direccion: ", "Error, solo se admiten letras.\n", direccionAux, 51);
            printf("\nSe modificara \"%s\" por \"%s\"", direccionAux, clientes[indice].domicilio);
            confirmacion = getValidChar("\nConfirma cambio (s/n)?: ", "Error al ingresar opcion. Reintente.\n\n", 's', 'n');
            if(confirmacion == 'n')
            {
                printf("Se cancelo la modificacion del nombre.\n\n");
            }
            else
            {
                strcpy(clientes[indice].domicilio, direccionAux);
                printf("Se modifico la direccion con exito.\n\n");
            }
            break;
        case 5:
            break;
        default:
            printf("Error, opcion incorrecta.\n\n");
        }
    }
}

void bajaCliente(eCliente clientes[], int tamanioClientes)
{
    int indice;
    int idCliente;
    char confirmacion;

    system("cls");
    printf("  *** Baja Cliente ***\n\n");

    idCliente = getValidInt("Ingrese el ID del cliente: ", "Error, solo se admiten numeros. Reintente.\n\n");
    indice = buscarCliente(clientes, tamanioClientes, idCliente);

    if( indice == -1)
    {
        printf("No hay ningun cliente con el ID %d\n\n", idCliente);
    }
    else
    {
        printf("\n\t Id |      Apellido |        Nombre | Sexo |     Direccion\n\n");
        mostrarCliente(clientes[indice]);
        printf("\nSe eliminara el cliente.\n");
        confirmacion = getValidChar("\nConfirma baja del cliente (s/n)?: ", "Error al ingresar opcion. Reintente.\n\n", 's', 'n');
        if(confirmacion != 's')
        {
            printf("Borrado cancelado.\n\n");
        }
        else
        {
            clientes[indice].isEmpty = BAJA;
            printf("Se ha eliminado el cliente con exito.\n\n");
        }
    }

}

void listarClientes(eCliente clientes[], int tamanioClientes)
{
    eCliente auxCliente;
    system("cls");
    printf("  *** Lista de Clientes ***\n");
    printf("  Ordenados por Apellido (ascendente) y Nombre (descendente).\n\n");
    for(int i=0; i<tamanioClientes-1; i++)
    {
        for(int j=i+1; j<tamanioClientes; j++)
        {
            if(strcmp(clientes[i].apellido, clientes[j].apellido) > 0)
            {
                auxCliente = clientes[i];
                clientes[i] = clientes[j];
                clientes[j] = auxCliente;
            }
            else if((strcmp(clientes[i].apellido, clientes[j].apellido) == 0) && strcmp(clientes[i].nombre, clientes[j].nombre) < 0)
            {
                auxCliente = clientes[i];
                clientes[i] = clientes[j];
                clientes[j] = auxCliente;
            }
        }
    }
    mostrarClientes(clientes, tamanioClientes);
    printf("\n");
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
            modificarCliente(clientes, tamanioClientes);
            system("pause");
            break;
        case 3:
            bajaCliente(clientes, tamanioClientes);
            system("pause");
            break;
        case 4:
            listarClientes(clientes, tamanioClientes);
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
