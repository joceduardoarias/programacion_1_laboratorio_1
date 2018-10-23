#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int codigo;
    char marca[20];
    int capacidad;
    float precio;
} ePendrive;

int cargarPendrive(ePendrive* pen);
void mostrarPendrive(ePendrive* pen);
ePendrive* new_Pendrive();

int main()
{

    ePendrive* miPendrive = new_Pendrive();
    mostrarPendrive(miPendrive);

    return 0;
}

int cargarPendrive(ePendrive* pendrive)
{
    int retorno=0;
    if(pendrive != NULL)
    {
        printf("Ingrese codigo: ");
        scanf("%d",&pendrive->codigo);
        printf("Ingrese marca: ");
        fflush(stdin);
        gets(pendrive->marca);
        printf("Ingrese capacidad: ");
        scanf("%d",&pendrive->capacidad);
        printf("Ingrese precio: ");
        scanf("%f",&pendrive->precio);
        retorno=1;
    }
    return retorno;
}

void mostrarPendrive(ePendrive* pendrive)
{
    if(pendrive!= NULL)
    {
        printf("\nCODIGO       MARCA       CAPACIDAD      PRECIO\n");
        printf("     %d\t        %s\t        %d\t  %.2f\t \n",pendrive->codigo, pendrive->marca, pendrive->capacidad, pendrive->precio );
    }
}

ePendrive* new_Pendrive()
{
    ePendrive* nuevoPendrive;
    nuevoPendrive = (ePendrive*) malloc(sizeof(ePendrive));
    if(nuevoPendrive != NULL)
    {
        nuevoPendrive->codigo = 0;
        strcpy(nuevoPendrive->marca, "");
        nuevoPendrive->capacidad = 0;
        nuevoPendrive->precio = 0;
    }
    return nuevoPendrive;
}
