#include <stdio.h>
#include <stdlib.h>
#include "persona.h"

#define CANT 4

int main()
{
    char seguir='s';
    EPersona personas[]={{"Lopez", "Juan", 10, 0, {02, 05, 1992}}; {"Alegria", "Nestor", 20, 0,{01, 05, 1963}}; {"Zol", "Ana", 30, 0 ,{06, 8, 1963};  {"Alegria", "Carlos", 40, 0, {06, 9, 1963}}};

    init(personas, CANT);

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
                printf("\n\n");
                listaOrdenada(personas, CANT);
                mostrarUsuarios(personas, CANT);
                system("pause");
                break;
            case 5:
                seguir = 'n';
                break;
            default:
                printf("Error al ingresar opcion, reintente.\n\n");
                system("pause");
        }
    }while(seguir=='s');

    return 0;
}
