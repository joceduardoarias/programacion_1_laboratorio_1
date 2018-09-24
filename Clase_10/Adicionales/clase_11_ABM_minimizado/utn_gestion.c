#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_gestion.h"
int getInt(char mensaje[])
{
    int aux;
    printf("%s",mensaje);
    scanf("%d", &aux);
    return aux;
}
float getFloat(char mensaje[])
{
    float aux;
    printf("%s",mensaje);
    scanf("%f", &aux);
    return aux;
}
char getChar(char mensaje[])
{
    char aux;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c", &aux);
    return aux;
}
void inicializarArrayStruct(eproductos prod[],int cantidad_elementos_arrayStruct,int valor)
{
    int i;
    for(i=0; i<cantidad_elementos_arrayStruct; i++)
    {
        prod[i].id = valor;
    }
}
int buscarPrimeraOcurrencia(eproductos prod[],int cantidad_elementos_arrayStruct,int valor)
{
    int i;
    for(i=0; i<cantidad_elementos_arrayStruct; i++)
    {
        if(prod[i].id == valor)
        {
            return i;
            break;
        }
    }
    return -1;
}
void Alta(eproductos producto[],int cantidad_elementos_arrayStruct)
{
    //DECLARO LA VARIABLES
    int indiceLugarLibre;
    int auxId;


    // INDICO EN QUE LUGAR DE LA APLICACION ESTOY
    printf("\nALTA\n");
    //BUSCO UN LUGAR LIBRE DENTRO DEL ARRAY ESTRUCTURA
    indiceLugarLibre = buscarPrimeraOcurrencia(producto,1000,-1);
    if(indiceLugarLibre == -1)
    {
        printf("\n No hay lugares libres para cargar datos");

    }
    else
    {
        auxId = getInt("\n Ingrese el ID: ");
        if(buscarPrimeraOcurrencia(producto,1000,auxId)!= -1)
        {
            printf("\n El producto %d ya existe\n", auxId);

        }
        else
        {
            producto[indiceLugarLibre].id = auxId;
            printf("\n Ingrese descripcion del producto: ");
            fflush(stdin);
            gets(producto[indiceLugarLibre].descripcion);
            fflush(stdin);
            printf("\n Ingrese la cantidad: ");
            scanf("%d",&producto[indiceLugarLibre].cantidad);
            printf("\n Ingrese el importe: ");
            scanf("%f",&producto[indiceLugarLibre].importe);
        }


    }


}
void baja(eproductos producto[],int cantidad_elementos_arrayStruct)
{
    int auxId;
    int indiceResultadoBusqueda;

    printf("\n BAJA ");
    auxId = getInt("\n Ingrese ID del producto a dar de baja: ");
    if(buscarPrimeraOcurrencia(producto,1000,auxId) == -1)
    {
        printf("\n El ID %03d del producto no existe ", auxId);

    }
    else
    {
        indiceResultadoBusqueda = buscarPrimeraOcurrencia(producto,1000,auxId);
        producto[indiceResultadoBusqueda].id = -1;
    }

}
void modificaion(eproductos producto[],int cantidad_elementos_arrayStruct)
{
    int auxId;
    int indiceResultadoBusqueda;

    printf("\n MODIFICACIONES ");
    auxId = getInt("\n Ingrese ID de producto a modificar: ");
    if(buscarPrimeraOcurrencia(producto,1000,auxId)== -1)
    {
        printf("\n El ID %d del producto no existe !!!",auxId);
    }
    else
    {
        indiceResultadoBusqueda = buscarPrimeraOcurrencia(producto,1000,auxId);
        printf("\n ingrese nueva descripcion: ");
        fflush(stdin);
        gets(producto[indiceResultadoBusqueda].descripcion);
        printf("\n Ingrese nuevo stock: ");
        fflush(stdin);
        scanf("%d",&producto[indiceResultadoBusqueda].cantidad);
        printf("\n Ingrese nuevo importe: ");
        fflush(stdin);
        scanf("%f",&producto[indiceResultadoBusqueda].importe);

    }

}
void listar(eproductos producto[],int cantidad_elementos_arrayStruct)
{
    int i;

    printf("\n ID   DESCRIPCION  CANTIDAD  IMPORTE ");
    for(i=0; i<1000; i++)
    {
        if(producto[i].id != -1)
        {
            printf("\n %03d %10s %10d %10.2f \n", producto[i].id,producto[i].descripcion,producto[i].cantidad,producto[i].importe);
        }
    }

}
void ordenar(eproductos producto[],int cantidad_elementos_arrayStruct)
{
    int i,j;
    eproductos auxStruc;
    printf("\n ORDEN DESCENDENTE");
    for(i=0; i<1000-1; i++)
    {
        for(j=i+1; j<1000; j++)
        {
            if(strcmp(producto[i].descripcion,producto[j].descripcion)<0)
            {
                auxStruc = producto[i];
                producto[i]=producto[j];
                producto[j]=auxStruc;

            }
        }
    }
    listar(producto,1000);
    //eproductos auxStruc;
    printf(" _________________________________________");
    printf("\n ORDEN POR CANTIDAD");
    for(i=0; i<1000-1; i++)
    {
        for(j=i+1; j<1000; j++)
        {
            if(producto[i].cantidad > producto[j].cantidad)
            {
                auxStruc = producto[i];
                producto[i]=producto[j];
                producto[j]=auxStruc;

            }
        }
    }
    listar(producto,1000);
}
float buscarValorMinimo(eproductos producto[],int cantidad_elementos_arrayStruct)
{
    float minimo = -1;
    int i;
    for(i=0; i<1000; i++)
    {
        if(producto[i].id != -1)
        {
            minimo = producto[i].importe;
            break;
        }
    }
    if(minimo == -1)
    {
        return -1;
    }
    else
    {
        for(i=0; i<1000; i++)
        {
            if(producto[i].importe < minimo && producto[i].id != -1)
            {
                minimo = producto[i].importe;
            }
        }
        return minimo;
    }


}
void productoMasBarato(eproductos producto[],int cantidad_elementos_arrayStruct)
{
    int i;
    float minimo;
    minimo = buscarValorMinimo(producto,1000);
    for(i=0; i<1000; i++)
    {
        if(minimo == -1)
        {
            printf("\n no hay datos cargados\n");
            break;
        }
        else
        {
            if(producto[i].importe == minimo)
            {
                printf("\n %03d %10s %d  %.2f \n",producto[i].id,producto[i].descripcion,producto[i].cantidad,producto[i].importe );
            }
        }

    }

}
float promdeioImporte(eproductos producto[],int cantidad_elementos_arrayStruct)
{
    int i;
    float acumulador;
    float promedio;
    acumulador = 0;
    for(i=0; i<1000; i++)
    {
        if(producto[i].id != -1)
        {
            acumulador = acumulador + producto[i].importe;

        }
    }
    promedio = acumulador / i;
    if(promedio != 0)
    {
        return promedio;
    }
    else
    {
        return -1;
    }
}
void productosMayorPromedioImporte(eproductos producto[],int cantidad_elementos_arrayStruct)
{

    float promedio;
    int i;
    promedio = promdeioImporte(producto,1000);
    if(promedio == -1)
    {
        printf("\n no hay datos cargados \n");

    }
    else
    {
        printf("\n ID  DESCRIPCION  STOCK  IMPORTE ");
        for(i=0; i<1000; i++)
        {
            if(producto[i].importe > promedio && producto[i].id != -1)
            {
                printf("\n %03d %10s %d %.2f ",producto[i].id,producto[i].descripcion,producto[i].cantidad,producto[i].importe);
            }
        }
    }


}
