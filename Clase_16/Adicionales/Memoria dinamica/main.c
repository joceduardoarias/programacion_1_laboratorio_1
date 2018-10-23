#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int codigo;
    char marca[20];
    int capacidad;
    float precio;
} ePendrive;

int cargarPendrive(ePendrive* pen);
void mostrarPendrive(ePendrive* pen);

int main()
{
    ePendrive pendrive;
    if(cargarPendrive(&pendrive)){
        mostrarPendrive(&pendrive);
    }
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
