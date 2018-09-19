#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "persona.h"

#define CANT 5

int main()
{
    char seguir='s';
    EPersona personas[]={{"Lopez", "Juan", 10, 0, {2, 5, 1992}}, {"Alegria", "Nestor", 20, 0,{1, 5, 1963}}, {"Zol", "Ana", 30, 0 ,{6, 8, 1963}},  {"Alegria", "Carlos", 40, 0, {6, 9, 1963}}, {"Lopez", "Ana", 50, 0, {2, 5, 1982}}  };

    //init(personas, CANT);

    do{

        switch(menu())
        {
            case 1:
                system("cls");
                alta(personas, CANT);
                system("pause");
                break;
            case 2:
                system("cls");
                baja(personas, CANT);
                system("pause");
                break;
            case 3:
                system("cls");
                modificar(personas, CANT);
                system("pause");
                break;
            case 4:
                system("cls");
                printf("MOSTRAR USUARIOS\n");
                mostrarUsuarios(personas, CANT);
                listaOrdenada(personas, CANT);
                mostrarUsuarios(personas, CANT);
                system("pause");
                break;
            case 5:
                seguir = 'n';
                break;
            default:
                printf("Error al ingresar opcion, reintente.");
                system("pause");
        }
    }while(seguir=='s');

    return 0;
}
