#include <stdio.h>
#include <stdlib.h>
#include <string.h>

///Hacer una funcion que se llame cargar persona

typedef struct
{
 int codigo;
 char marca[20];
 int capacidad;
 float precio;
 //int isEmpty;
}ePendrive;

int cargarPendrive(ePendrive* pendrive);
void mostrarPendrive(ePendrive* pendrive);
int cargarPendriveParametro(ePendrive* pendrive, int codigo, char marca[], int cap, float precio);

int main()
{
    ePendrive pendrive;

    if( (cargarPendriveParametro(&pendrive, 156, "Epson", 35, 15200.50)) == 1)
    {
            mostrarPendrive(&pendrive);
    }

    return 0;
}

int cargarPendrive(ePendrive* pendrive)
{
    int retorno=0;

    if(pendrive!= NULL)
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
        printf("CODIGO       MARCA       CAPACIDAD      PRECIO\n");
        printf("%d\t %s\t %d\t %.2f\t ",pendrive->codigo, pendrive->marca, pendrive->capacidad, pendrive->precio );
    }
}

int cargarPendriveParametro(ePendrive* pendrive, int codigo, char marca[], int cap, float precio)
{
    int retorno=0;

    if( pendrive!=NULL)
    {
        if(marca!=NULL)
        {

                pendrive->codigo = codigo;
                strcpy(pendrive->marca, marca);
                pendrive->capacidad = cap;
                pendrive->precio = precio;

            retorno = 1;
        }
    }

    return retorno;
}
