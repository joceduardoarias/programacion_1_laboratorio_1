#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    int codigo;
    char marca[20];
    int capacidad;
    float precio;
    }ePendrive;

int cargarPendrive(ePendrive* pen);
int cargarPendriveParam(ePendrive* pen, int codigo,char marca[],int capacidad,float precio);
void mostrarPendrive(ePendrive* pen);

int main()
{
    ePendrive pen;

    if((cargarPendrive(&pen))==1)
    {
        mostrarPendrive(&pen);
    }

    return 0;
}

int cargarPendrive(ePendrive *pen)
{
    int flag = 0;
    int codigo,capacidad;
    char marca[20];
    float precio;

    if(pen != NULL)
    {
     printf("Ingrese codigo: ");
     scanf("%d ",&codigo);

     printf("Ingrese marca: ");
     fflush(stdin);
     gets(marca);

     printf("Ingrese capacidad: ");
     scanf("%d ",&capacidad);

     printf("Ingrese precio: ");
     scanf("%f ",&precio);

    flag = cargarPendriveParam(pen,codigo,marca,capacidad,precio);
    }

    return flag;
}

//-------------------------------------------------------------

void mostrarPendrive(ePendrive *pen)
{
    if(pen != NULL)
    {

        printf("%d  %s  %d  %.2f",pen->codigo,pen->marca,pen->capacidad,pen->precio);
    }
}


//-------------------------------------------------------------



int cargarPendriveParam(ePendrive* pen, int codigo,char marca[],int capacidad,float precio)
{
    int retorno = 0;
    if(pen != NULL)
    {
        pen->codigo = codigo;
        strcpy(pen->marca,marca);
        pen->capacidad = capacidad;
        pen->precio = precio;

        retorno = 1;
    }
    return retorno;
}
