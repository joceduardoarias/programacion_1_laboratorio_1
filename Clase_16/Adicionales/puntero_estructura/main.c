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
int cargarPendrive(ePendrive* pen, int codigo,char marca[],int capacidad, float precio);
void mostrarPendrive(ePendrive* pen);
int main()
{
    ePendrive pendrive;

    if(cargarPendrive(&pendrive,1,"usb",16,500)!=0)
    {
        mostrarPendrive(&pendrive);
    }
    else
    {
        printf("\n Carga de datos fallida!!!!");
    }
    return 0;
}
int cargarPendrive(ePendrive* pen, int codigo,char marca[],int capacidad, float precio)
{
    int retorno = 0;

    if(pen != NULL)
    {
        pen->codigo = codigo;
        strcpy( pen->marca, marca);
        pen->capacidad = capacidad;
        pen->precio = precio;
        retorno = 1;
    }
    return retorno;
}
void mostrarPendrive(ePendrive* pen)
{
    if(pen != NULL)
    {
        printf("\n %d \t %s \t %d \t %.2f \n", pen->codigo,pen->marca,pen->capacidad,pen->precio);

    }
}
