#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "funciones.h"

//Menu
int menu()
{
    int opcion;
    system("cls");
    printf("Bienvenido.\n\n");
    printf("1- Alta de usuario\n");
    printf("2- Baja de usuario\n");
    printf("3- Modificar usuario\n");
    printf("4- Ordenar usuarios\n");
    printf("5- Buscar usuario\n");
    printf("6- Listar usuarios\n");
    printf("7- Salir\n\n");
    printf("Ingrese opcion: ");
    opcion = getche();
    return opcion;
}

//Pone los estados en 1
int inicializacion(int lista[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        lista[i]=1;
    }
    return 0;
}

//Busca espacio libre en el array, si no existe retorna -1
int buscaEspacio(int lista[], int tam)
{
    int retorno = -1;
    for(int i=0; i<tam; i++)
    {
        if(lista[i]==1)
        {
            retorno = i;
            return retorno;
            break;
        }
    }
    return retorno;
}


int mostrarUsuario(char nombre[][31], char apellido[][31], int legajo[], int edad[], int isEmpty[], int legajoAux, int tam)
{
    int retorno = -1;
    printf("Legajo\tApellido  \tNombre  \tEdad\n\n");
    for(int i=0; i<tam; i++)
    {
        if(legajoAux==legajo[i] && isEmpty[i]==0)
        {
            printf("\n%d\t%s\t\t%s\t\t%d", legajo[i], apellido[i], nombre[i], edad[i]);
        }
        return 0;
        break;
    }
    printf("\n\n");
    return retorno;
}

int altaUsuario(char nombre[][31], char apellido[][31], int legajo[], int edad[], int isEmpty[], int tam, int indice)
{
    int cantidad;
    printf("Ingrese nombre: ");
    fflush(stdin);
    fgets(nombre[indice], sizeof(nombre[indice]), stdin);
    cantidad = strlen(nombre[indice]);
    nombre[indice][cantidad-1] = '\0';
    printf("Ingrese apellido: ");
    fflush(stdin);
    fgets(apellido[indice], sizeof(apellido[indice]), stdin);
    cantidad = strlen(apellido[indice]);
    apellido[indice][cantidad-1] = '\0';
    fflush(stdin);
    printf("Ingrese legajo: ");
    scanf("%d", &legajo[indice]);
    printf("Ingrese edad: ");
    scanf("%d", &edad[indice]);
    isEmpty[indice]=0;
}
