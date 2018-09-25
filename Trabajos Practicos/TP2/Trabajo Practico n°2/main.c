#include <stdio.h>
#include <stdlib.h>
#include "alegria.h"
#include "utn.h"
#define TAM 3

int main()
{
    Employee empleados[TAM];

    char seguir = 's';
    //int index;
    //int posicionLibre;


    //---> Variables Auxiliares para el alta
    int auxId = 1;
    char auxName[51];
    char auxLastName[51];
    char salaryString[51];
    char sectorString[51];

     float auxSalary;
     int auxSector;
    //<---

    //Inicializo todos los estados en TRUE (1)
    initEmployees(empleados, TAM);

    do
    {
        switch(menu())
        {
        case '1':
            system("cls");
            printf("<-- ALTA DE USUARIO -->\n\n");
            if(getStringLetrasRango("Ingrese nombre: ", auxName, 51) != 1){
                printf("\nIngrese solo letras.\n");
                system("pause");
                break;
            }
            if(getStringLetrasRango("Ingrese apellido: ", auxLastName, 51) != 1){
                printf("\nIngrese solo letras.\n");
                system("pause");
                break;
            }
            if(!getStringNumerosFlotantes("Ingrese salario: ", salaryString)){
                printf("\nIngrese solo numeros.\n");
                system("pause");
                break;
            }
            auxSalary = atof(salaryString);
            if(!getStringNumeros("Ingrese sector: ", sectorString)){
                printf("\nIngrese solo numeros.\n");
                system("pause");
                break;
            }
            auxSector = atoi(sectorString);

            addEmployee(empleados, TAM, auxId, auxName, auxLastName, auxSalary, auxSector);
            auxId++;
            system("pause");
            break;
        case '2':
            system("cls");
            printf("<-- MODIFICAR EMPLEADO -->\n\n");
            modifyEmployee(empleados, TAM);
            system("pause");
            break;
        case '3':
            system("cls");
            printf("<-- BAJA EMPLEADO -->\n\n");
            system("pause");
            break;
        case '4':
            system("cls");
            printf("<-- LISTAR EMPLEADOS -->\n\n");
            system("pause");
            break;
        case '5':
            printf("\n");
            seguir = 'n';
            break;
        default:
            printf("\n\nOpcion incorrecta, reintente.\n\n");
            system("pause");
            system("cls");
        }
    }
    while(seguir == 's');



    return 0;
}
