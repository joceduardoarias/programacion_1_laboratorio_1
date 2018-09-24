#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funciones.h"
#define MAX_ARRAY 1000

int main()
{
    char seguir = 's';
    eproductos producto[1000];
    eproductos aux;
    int opcion,i,j;
    int indiceLugarlibre;
    int indiceResultadoBusqueda;
    int auxId;
    int auxStock;
    float auxImporte;

    char IdStr [20];
    char descripcionStr[20];
    char stockStr[20];
    char importeStr[20];

    inicialiarArrayStruc(producto,MAX_ARRAY,-1);
    do
    {
        system("cls");
        printf("\n1. ALTA\n2. BAJA\n3. MODIFICACION\n4. LISTAR\n5. ORDENADO ALFABETICO\n6. ORDENADO X CANTIDAD\n7. INFORME MENOR IMPORTE \n8. SALIR");
        opcion = getInt("SELECCIONE UNA OPCION: ");
        switch(opcion)
        {
        case 1:
            system("cls");
            printf("\n ALTA");
            indiceLugarlibre = buscarPrimeraOcurrencia(producto,MAX_ARRAY,-1);
            if(indiceLugarlibre == -1)
            {
                printf("\nNO HAY LUGAR DISPONIBLE PARA CARGAR DATOS ");
            }
            if(getStringNumeros("\n Ingrese ID: ",IdStr) != 1)
            {
                printf("\n El ID debe ser solo numero");
                break;
            }
            auxId = atoi(IdStr);
            if(buscarPrimeraOcurrencia(producto,MAX_ARRAY,auxId) != -1)
            {
                printf("\n El ID  ya existe !!! ");
                break;
            }
            if(getStringLetras("Ingrese la Descripcion: ",descripcionStr) != 1)
            {
                printf("\n Debe ingresar solo letras ");
                break;
            }
            if(getStringNumeros("Ingrse el stock: ",stockStr) != 1)
            {
                printf("\n Debe ingresar solo numeros ");
                break;
            }
            auxStock = atoi(stockStr);
            if(getStringNumeros("Ingrese el importe: ",importeStr) != 1)
            {
                printf("\n Debe ingresar solo numeros ");
                break;
            }
            auxImporte = atof(importeStr);
            producto[indiceLugarlibre].id = auxId;
            strcpy(producto[indiceLugarlibre].descripcion,descripcionStr);
            producto[indiceLugarlibre].stock = auxStock;
            producto[indiceLugarlibre].importe = auxImporte;

            break;
        case 2:
            system("cls");
            printf("\n BAJA");
            if(getStringNumeros("Ingrese el numero del ID para hacer la baja: ",IdStr) != 1)
            {
                printf("\n Debe ingresar solo numeros ");
                break;
            }
            auxId = atoi(IdStr);
            if(buscarPrimeraOcurrencia(producto,MAX_ARRAY,auxId)== -1)
            {
                printf("\n El ID no existe ");
                break;
            }
            indiceResultadoBusqueda = buscarPrimeraOcurrencia(producto,MAX_ARRAY,auxId);
            producto[indiceResultadoBusqueda].id = -1;
            system("pause");
            break;
        case 3:
            system("cls");
            printf("\n MODIFICACION");
            if(getStringNumeros("\n Ingrese ID para modificar: ",IdStr) != 1)
            {
                printf("\n Debe ingresar solo numeros ");
                break;
            }
            auxId = atoi(IdStr);
            if(buscarPrimeraOcurrencia(producto,MAX_ARRAY,auxId) == -1)
            {
                printf("\n El ID NO EXISTE");
                break;
            }
            if(getStringLetras("\nIngrese nueva descripcion: ",descripcionStr) != 1 )
            {
                printf("\n Debe ingresar solo letras");
                break;
            }
            if(getStringNumeros("\n Ingrese nuevo stock: ",stockStr) != 1)
            {
                printf("\n Debe ingresar solo numeros");
                break;
            }
            auxStock = atoi(stockStr);
            if(getStringNumeros("\n Ingrese nuevo importe: ",importeStr) != 1)
            {
                printf("\n Debe ingresar solo numeros");
                break;
            }
            auxImporte = atof(importeStr);
            strcpy(producto[i].descripcion,descripcionStr);
            producto[i].stock = auxStock;
            producto[i].importe = auxImporte;
            system("pause");
            break;
        case 4:
            system("cls");
            printf("\n LISTAR ");
            printf("\n ID       NOMBRE       STOCK       IMPORTE");
            for(i=0; i<MAX_ARRAY; i++)
            {
                if(producto[i].id != -1)
                {
                    printf("\n %03d %10s %10d  %10.2f \n", producto[i].id,producto[i].descripcion,producto[i].stock,producto[i].importe );

                }
            }
            system("pause");
            break;
        case 5:
            system("cls");
            printf("\n ORDENAR");
            for(i=0; i<MAX_ARRAY-1; i++)
            {
                for(j=i+1; j<MAX_ARRAY; j++)
                {
                    if(strcmp(producto[i].descripcion,producto[j].descripcion)<0)
                    {
                        aux = producto[i];
                        producto[i] = producto[j];
                        producto[j] = aux;
                    }
                }
            }
            system("pause");
            break;
        case 6:
            system("cls");
            printf("\n ORDENAMIENTO X CANTIDAD");
            for(i=0; i<MAX_ARRAY-1; i++)
            {
                for(j=i+1; j<MAX_ARRAY; j++)
                {
                    if( producto[i].stock > producto[j].stock)
                    {
                        aux = producto[i];
                        producto[i] = producto[j];
                        producto[j] = aux;
                    }
                }
            }
            system("pause");
            break;
        case 7:
            system("cls");
            printf("\n PRODUCTO CON MENOR IMPORTE ");
            importeMinimo(producto,MAX_ARRAY);
            system("pause");
            break;
        case 8:
            seguir = 'n';
            break;
        }

    }
    while(seguir == 's');
    return 0;
}
