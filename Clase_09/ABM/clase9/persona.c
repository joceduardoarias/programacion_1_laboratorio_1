#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include "persona.h"

int menu()
{
    int opcion;
    system("cls");
    printf("B I E N V E N I D O  <- ABM ->\n\n");
    printf("1- Agregar persona\n");
    printf("2- Borrar persona\n");
    printf("3- Modificar persona\n");
    printf("4- Imprimir lista ordenada por apellido y nombre\n\n");
    printf("5- Salir\n\n");
    printf("Ingrese opcion: ");

    scanf("%d", &opcion);
    return opcion;
}

void init(EPersona lista[], int len)
{
    int i;
    for(i=0; i<len; i++)
    {
        lista[i].isEmpty = 1;
    }
}

int obtenerEspacioLibre(EPersona lista[], int len)
{
    int i;
    int retorno = -1;
    for(i=0; i<len; i++)
    {
        if(lista[i].isEmpty == 1)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}

int buscarPorDni(EPersona lista[],int len, long int dni)
{
    int retorno = -1;
    for(int i=0; i<len; i++)
    {
        if(dni == lista[i].dni && lista[i].isEmpty==0)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}

void alta(EPersona lista[], int len)
{
    int index;
    int cantidad;
    index = obtenerEspacioLibre(lista, len);
    printf("ALTA DE USUARIO\n\n");
    if(index != -1)
    {
        printf("Ingrese nombre: ");
        fflush(stdin);
        fgets(lista[index].nombre, 31, stdin);
        cantidad = strlen(lista[index].nombre);
        lista[index].nombre[cantidad-1] = '\0';
        printf("Ingrese apellido: ");
        fflush(stdin);
        fgets(lista[index].apellido, 31, stdin);
        cantidad = strlen(lista[index].apellido);
        lista[index].apellido[cantidad-1] = '\0';
        printf("Ingrese DNI: ");
        scanf("%ld", &lista[index].dni);
        printf("Ingrese dia de nacimiento: ");
        scanf("%d", &lista[index].feNac.dia);
        printf("Ingrese mes de nacimiento: ");
        scanf("%d", &lista[index].feNac.mes);
        printf("Ingrese anio de nacimiento: ");
        scanf("%d", &lista[index].feNac.anio);
        lista[index].isEmpty = 0;
    }
    else
    {
        printf("\nNo quedan espacios disponibles, elimine o agrege un usuario para continuar.");
    }

    return;
}


void baja(EPersona lista[], int len)
{
    int index;
    int dniAux;
    char confirmar;
    printf("BAJA DE PERSONA\n\n");
    printf("Ingrese DNI del usuario: ");
    scanf("%d", &dniAux);
    index = buscarPorDni(lista, len, dniAux);
    if(index != -1)
    {
        printf("Se encontro usuario en sistema.\n");
        mostrarPersonaDNI(lista, index);
        printf("\nSeguro que desea eliminar al usuario?: ");
        fflush(stdin);
        scanf("%c", &confirmar);
        if(confirmar == 's')
        {
            lista[index].isEmpty = 1;
            printf("\nSe elimino al usuario %s %s con DNI %d exitosamente\n\n", lista[index].nombre, lista[index].apellido, lista[index].dni);
        }
        else
        {
            printf("Se cancelo la baja del usuario.\n\n");
        }
    }
    else
    {
        printf("\nEl DNI ingresado no se encuentra en sistema.\n\n");
    }


    return;
}

void mostrarPersonaDNI(EPersona lista[], int index)
{
    if(lista[index].isEmpty == 0)
    {
        printf("\nNombre\tApellido\tDNI\tFecha de nacimiento\n\n");
        printf("%s\t%s\t\t%02d\t%02d / %02d / %d\n", lista[index].nombre, lista[index].apellido, lista[index].dni, lista[index].feNac.dia, lista[index].feNac.mes, lista[index].feNac.anio);
    }
}

void modificar(EPersona lista[], int len)
{
    printf("MODIFICAR PERSONA\n\n");
    int opcion;
    int dniAux;
    int index;
    int cantidad;

    char confirmar;
    char auxNombre[31];
    char auxApellido[31];
    long int auxDNI;
    int diaAux;
    int mesAux;
    int anioAux;

    printf("Ingrese DNI de la persona: ");
    scanf("%d", &dniAux);
    index = buscarPorDni(lista, len, dniAux);
    if(index != -1)
    {
        mostrarPersonaDNI(lista, index);
        printf("\n\n1- Nombre\n2- Apellido\n3- DNI\n4- Fecha de Nacimiento\n5- Salir\n\n");
        printf("Ingrese opcion a modificar: ");
        fflush(stdin);
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            printf("\nIngrese nuevo nombre: ");
            fflush(stdin);
            fgets(auxNombre, 31, stdin);
            cantidad = strlen(auxNombre);
            auxNombre[cantidad-1] = '\0';
            printf("\nDesea modificar %s por %s ?: ", auxNombre, lista[index].nombre);
            fflush(stdin);
            scanf("%c", &confirmar);
            if(confirmar == 's'){
                strcpy(lista[index].nombre, auxNombre);
            }
            else{
                printf("\nNo se realizo la modificacion.\n");
            }
            /*fgets(lista[index].nombre, 31, stdin);
            cantidad = strlen(lista[index].nombre);
            lista[index].nombre[cantidad-1] = '\0';*/
            break;
        case 2:
            printf("\nIngrese nuevo apellido: ");
            fflush(stdin);
            fgets(auxApellido, 31, stdin);
            cantidad = strlen(auxApellido);
            auxApellido[cantidad-1] = '\0';
            printf("Desea modificar %s por %s ?: ", auxApellido, lista[index].apellido);
            fflush(stdin);
            scanf("%c", &confirmar);
            if(confirmar == 's'){
                strcpy(lista[index].apellido, auxApellido);
            }
            else{
                printf("\nNo se realizo la modificacion.\n");
            }
            /*fgets(lista[index].apellido, 31, stdin);
            cantidad = strlen(lista[index].apellido);
            lista[index].apellido[cantidad-1] = '\0';*/
            break;
        case 3:
            printf("\nIngrese nuevo DNI: ");
            scanf("%ld", &auxDNI);
            printf("Desea modificar %d por %d ?", auxDNI, lista[index].dni);
            fflush(stdin);
            scanf("%c", &confirmar);
            if(confirmar == 's'){
                lista[index].dni = auxDNI;
            }
            else{
                printf("\nNo se realizo la modificacion.\n");
            }
            break;
        case 4:
            printf("\nIngrese nuevo dia de nacimiento: ");
            scanf("%d", &diaAux);
            printf("\nIngrese nuevo mes de nacimiento: ");
            scanf("%d", &mesAux);
            printf("\nIngrese nuevo anio de nacimiento: ");
            scanf("%d", &anioAux);
            printf("\nDesea modificar %02d / %02d / %d por %02d / %02d / %d ?: ", lista[index].feNac.dia, lista[index].feNac.mes, lista[index].feNac.anio, diaAux, mesAux, anioAux);
            fflush(stdin);
            scanf("%c", &confirmar);
            if(confirmar == 's'){
                lista[index].feNac.dia = diaAux;
                lista[index].feNac.mes = mesAux;
                lista[index].feNac.anio = anioAux;
            }
            else{
                printf("\nNo se realizo la modificacion.\n");
            }
            break;
        case 5:
            break;
        default:
            printf("Opcion incorrecta, reintente.\n\n");
            system("pause");
        }
    }
    else
    {
        printf("No se encontro DNI en sistema\n\n");
    }
}


void mostrarUsuarios(EPersona lista[], int len)
{
    printf("\nNombre\tApellido\tDNI\tFecha de nacimiento\n\n");
    for(int i=0; i<len; i++)
    {
        if(lista[i].isEmpty == 0)
        {
            printf("%s\t%s\t\t%02d\t%02d / %02d / %d\n", lista[i].nombre, lista[i].apellido, lista[i].dni, lista[i].feNac.dia, lista[i].feNac.mes, lista[i].feNac.anio);
        }
    }
    printf("\n");
}

void listaOrdenada(EPersona lista[], int len)
{
    EPersona auxPersona;
    for(int i=0; i<len-1; i++)
    {
        for(int j=i+1; j<len; j++)
        {
            if(strcmp(lista[i].apellido,lista[j].apellido)>0)
            {
                auxPersona = lista[i];
                lista[i] = lista[j];
                lista[j] = auxPersona;
            }
            if((strcmp(lista[i].apellido,lista[j].apellido)==0) && (strcmp(lista[i].nombre,lista[j].nombre) > 0))
            {
                auxPersona = lista[i];
                lista[i] = lista[j];
                lista[j] = auxPersona;
            }
        }

    }

}
