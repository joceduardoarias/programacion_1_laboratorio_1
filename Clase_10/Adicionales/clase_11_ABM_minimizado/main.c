#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_gestion.h"

int main()
{
    eproductos producto[1000];
    //eproductos auxStruc;
    char seguir = 's';
    int opcion;
    // float minimo;
    //int i,j;
    //int indiceLugarLibre;
    //int indiceResultadoBusqueda;
    //int auxId;
    inicializarArrayStruct(producto,1000,-1);

    do
    {
        system("cls");
        printf("\n1. ALTA\n2. BAJA\n3. MODIFICACION\n4. LISTAR\n5. ORDENAR\n6.PRODUCTO IMPORTE MAS BAJO\n7. PRODUCTO IMPORTE MAYOR PROMEDIO\n10. SALIR ");
        opcion = getInt("\n Selecione una opcion: ");
        system("pause");
        switch(opcion)
        {
        case 1:
            system("cls");
            Alta(producto,1000);
            system("pause");
            break;
        case 2:
            system("cls");
            baja(producto,1000);
            system("pause");
            break;
        case 3:
            system("cls");
            modificaion(producto,1000);
            system("pause");
            break;
        case 4:
            system("cls");
            listar(producto,1000);
            system("pause");
            break;
        case 5:
            system("cls");
            ordenar(producto,1000);
            system("pause");
            break;
        case 6:
            system("cls");
            productoMasBarato(producto,1000);
            system("pause");
            break;
        case 7:
            system("cls");
            printf("\n PRODUCTOS QUE SUPERAN EL PRECIO PROMEDO \n");
            productosMayorPromedioImporte(producto,1000);
            system("pause");
            break;
        case 10:
            seguir = 'n';
            break;
        }
    }
    while(seguir == 's');
    return 0;
}
