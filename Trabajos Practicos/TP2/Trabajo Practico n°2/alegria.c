#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "alegria.h"
#include "utn.h"
#define OCUPADO 1
#define VACIO 0

int menu()
{
    int opcion;
    system("cls || clear");
    printf("BIENVENIDO\n\n");
    printf("1- Alta\n");
    printf("2- Modificar\n");
    printf("3- Baja\n");
    printf("4- Informar\n");
    printf("5- Salir\n\n");
    printf("Ingrese opcion: ");
    opcion = getche();
    return opcion;
}

void initEmployees(Employee* arrayEmpleados, int tamanioArray)
{
    for(int i=0; i<tamanioArray; i++)
    {
        arrayEmpleados[i].isEmpty = VACIO;
    }
}

int findFreePlace(Employee* arrayEmpleados, int tamanioArray, int valor)
{
    int flag = -1;
    for(int i=0; i<tamanioArray; i++)
    {
        if(arrayEmpleados[i].isEmpty == valor)
        {
            flag = i;
            break;
        }
    }
    return flag;
}
//int findFreePlace(Employee* arrayEmpleados, int tamanioArray, int valor);

int addEmployee(Employee* arrayEmpleados, int tamanioArray, int auxId, char auxName[],char
                auxLastName[],float auxSalary,int auxSector)
{
    printf("\n");
    int index;
    index = findFreePlace(arrayEmpleados, tamanioArray, VACIO);
    if(index == -1)
    {
        printf("No quedan lugares disponibles.\n");
    }
    else
    {
        arrayEmpleados[index].id = auxId;
        strcpy(arrayEmpleados[index].name, auxName);
        strcpy(arrayEmpleados[index].lastName, auxLastName);
        arrayEmpleados[index].salary = auxSalary;
        arrayEmpleados[index].sector = auxSector;
        arrayEmpleados[index].isEmpty = OCUPADO;
    }
    return 0;
}

int findEmployeeById(Employee* arrayEmpleados, int tamanioArray, int id)
{
    int index = -1;
    for(int i=0; i<tamanioArray; i++)
    {
        if(arrayEmpleados[i].id == id && arrayEmpleados[i].isEmpty == OCUPADO)
        {
            index = i;
            break;
        }
    }
    return index;
}

void printEmployeeById(Employee* arrayEmpleados, int index)
{
    printf("\t  ID |  Nombre  |  Apellido  |  Salario  | Sector  \n");
    printf("\t%5d|%10s|%12s|%11.2f|%9d\n", arrayEmpleados[index].id, arrayEmpleados[index].name, arrayEmpleados[index].lastName, arrayEmpleados[index].salary, arrayEmpleados[index].sector);
}

void modifyEmployee(Employee* arrayyEmpleados, int tamanioArray)
{
    int opcion;
    char respuesta;
    int id;
    int index;
    char auxName[51];
    char auxLastName[51];
    char salaryString[51];
    char sectorString[51];

    float auxSalary;
    int auxSector;

    id = getInt("Ingrese ID del empleado: ");
    index = findEmployeeById(arrayyEmpleados, tamanioArray, id);
    if(index == -1)
    {
        printf("\nNo existe empleado con el ID %d\n\n", id);
    }
    else
    {
        printf("\nDatos del empleado.\n\n");
        printEmployeeById(arrayyEmpleados, index);
        printf("\nMenu de opciones.\n\n1- Nombre\n2- Apellido\n3- Salario\n4- Sector\n5- Salir\n\n");
        opcion = getInt("Ingrese la opcion que desea modificar: ");
        switch(opcion)
        {
        case 1:
            //NOMBRE
            if(!getStringLetrasRango("\nIngrese nuevo nombre: ", auxName, 51))
            {
                printf("\nIngrese solo letras.\n");
                break;
            }
            printf("\nDesea reemplazar %s por %s (s/n): ", arrayyEmpleados[index].name, auxName);
            fflush(stdin);
            scanf("%c", &respuesta);
            while(respuesta!='s' && respuesta!='n')
            {
                printf("Ingreso una opcion incorrecta, reintente.\n");
                printf("\nDesea reemplazar \"%s\" por \"%s\" (s/n): ", arrayyEmpleados[index].name, auxName);
                fflush(stdin);
                scanf("%c", &respuesta);
            }
            if(respuesta == 's')
            {
                strcpy(arrayyEmpleados[index].name, auxName);
                printf("Cambio realizado con exito.\n\n");
            }
            else
            {
                printf("Se cancelo el cambio de nombre.\n\n");
            }
            break;
        case 2:
            //APELLIDO
            if(!getStringLetrasRango("\nIngrese nuevo apellido: ", auxLastName, 51))
            {
                printf("\nIngrese solo letras.\n");
                break;
            }
            printf("\nDesea reemplazar %s por %s (s/n): ", arrayyEmpleados[index].lastName, auxLastName);
            fflush(stdin);
            scanf("%c", &respuesta);
            while(respuesta!='s' && respuesta!='n')
            {
                printf("Ingreso una opcion incorrecta, reintente.\n");
                printf("\nDesea reemplazar \"%s\" por \"%s\" (s/n): ", arrayyEmpleados[index].lastName, auxLastName);
                fflush(stdin);
                scanf("%c", &respuesta);
            }
            if(respuesta == 's')
            {
                strcpy(arrayyEmpleados[index].lastName, auxLastName);
                printf("Cambio realizado con exito.\n\n");
            }
            else
            {
                printf("Se cancelo el cambio de apellido.\n\n");
            }
            break;
        case 3:
            //SALARIO
            if(!getStringNumerosFlotantes("Ingrese nuevo sueldo: ", salaryString))
            {
                printf("\nIngrese solo numeros.\n");
            }
            auxSalary = atof(salaryString);
            printf("\nDesea reemplazar %.2f por %.2f (s/n): ", arrayyEmpleados[index].salary, auxSalary);
            fflush(stdin);
            scanf("%c", &respuesta);
            while(respuesta!='s' && respuesta!='n')
            {
                printf("Ingreso una opcion incorrecta, reintente.\n");
                printf("\nDesea reemplazar %.2f por %.2f (s/n): ", arrayyEmpleados[index].salary, auxSalary);
                fflush(stdin);
                scanf("%c", &respuesta);
            }
            if(respuesta == 's')
            {
                arrayyEmpleados[index].salary = auxSalary;
                printf("Cambio realizado con exito.\n\n");
            }
            else
            {
                printf("Se cancelo el cambio de salario.\n\n");
            }
            break;
        case 4:
            //Sector
            if(!getStringNumeros("Ingrese nuevo sector: ", sectorString))
            {
                printf("\nIngrese solo numeros.\n");
            }
            auxSector = atoi(sectorString);
            printf("\nDesea reemplazar %d por %d (s/n): ", arrayyEmpleados[index].sector, auxSector);
            fflush(stdin);
            scanf("%c", &respuesta);
            while(respuesta!='s' && respuesta!='n')
            {
                printf("Ingreso una opcion incorrecta, reintente.\n");
                printf("\nDesea reemplazar %d por %d (s/n): ", arrayyEmpleados[index].sector, auxSector);
                fflush(stdin);
                scanf("%c", &respuesta);
            }
            if(respuesta == 's')
            {
                arrayyEmpleados[index].sector = auxSector;
                printf("Cambio realizado con exito.\n\n");
            }
            else
            {
                printf("Se cancelo el cambio de sector.\n\n");
            }
            break;
        case 5:
            break;
        default:
            printf("\nOpcion incorrecta, reintente.\n\n");
        }
    }
}

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/
void removeEmployee(Employee* arrayEmpleados, int tamanioarray, int id)
{
    int index;
    char confirma;


    index = findEmployeeById(arrayEmpleados, tamanioarray, id);
    if(index == -1)
    {
        printf("\nNo se encuentra empleado con ese ID\n\n");
    }
    else
    {
        printf("\nDatos del empleado.\n\n");
        printEmployeeById(arrayEmpleados, index);
        confirma = getChar("\nDesea eliminar al empleado (s/n)?: ");
        if(confirma == 's')
        {
            arrayEmpleados[index].isEmpty = VACIO;
            printf("\nSe elimino al empleado correctamente.\n\n");
        }
        else
        {
            printf("\nSe cancelo la baja del empleado.\n\n");
        }
    }
}

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
*
* \param list Employee*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
void sortEmployees(Employee* arrayEmpleados, int tamanioArray)
{
    Employee auxPersona;
    for(int i=0; i<tamanioArray-1; i++)
    {
        for(int j=i+1; j<tamanioArray; j++)
        {
            if(arrayEmpleados[i].sector > arrayEmpleados[j].sector)
            {
                auxPersona = arrayEmpleados[i];
                arrayEmpleados[i] = arrayEmpleados[j];
                arrayEmpleados[j] = auxPersona;
            }

            if(arrayEmpleados[i].sector == arrayEmpleados[j].sector && (strcmp(arrayEmpleados[i].lastName, arrayEmpleados[j].lastName) > 0 ))
            {

                auxPersona = arrayEmpleados[i];
                arrayEmpleados[i] = arrayEmpleados[j];
                arrayEmpleados[j] = auxPersona;
            }
        }
    }
}


/** \brief print the content of employees array
*
* \param list Employee*
* \param length int
* \return int
*
*/
void printEmployees(Employee* arrayEmpleados, int tamanioArray)
{
    printf("\n\t   ID  |   Nombre   |   Apellido   |   Salario   |  Sector  \n");
    for(int i=0; i<tamanioArray; i++)
    {
        if(arrayEmpleados[i].isEmpty == OCUPADO)
        {
            printf("\t%7d|%12s|%14s|%13.2f|%10d\n", arrayEmpleados[i].id, arrayEmpleados[i].name, arrayEmpleados[i].lastName, arrayEmpleados[i].salary, arrayEmpleados[i].sector);
        }
    }
    printf("\n\n");
}

void enlistEmployee(Employee arrayEmpleados[], int tamanioArray)
{
    int opcion;
    printf("1- Listado de los empleados ordenados alfabeticamente por Apellido y Sector.\n2- Total y promedio de los salarios, y cuantos empleados superan el salario promedio.\n\n");
    opcion = getInt("Ingrese opcion: ");
    /*while(opcion!= 1 && opcion != 2)
    {
        printf("\nOpcion Incorrecta, reintente.\n");
        opcion = getInt("Ingrese opcion: ");
    }*/
    switch(opcion)
    {
    case 1:
        system("cls");
        printf("Lista de los empleados ordenados alfabéticamente por Apellido y Sector.\n");
        sortEmployees(arrayEmpleados, tamanioArray);
        printEmployees(arrayEmpleados, tamanioArray);
        break;
    case 2:
        system("cls || clear");
        printf("Total y promedio de los salarios, y cuantos empleados superan el salario promedio.\n");
        listaCalculosEmpleados(arrayEmpleados, tamanioArray);
        break;

    }

}

void listaCalculosEmpleados(Employee* arrayEmpleados, int tamanioArray){

    float acumuladorSueldos = 0;
    int contadorSueldos = 0;
    int superaSueldo = 0;
    float promedioSueldos;
    for(int i=0; i<tamanioArray; i++){
        if(arrayEmpleados[i].isEmpty == OCUPADO){
            acumuladorSueldos = acumuladorSueldos + arrayEmpleados[i].salary;
            contadorSueldos++;
        }
    }
    promedioSueldos = acumuladorSueldos / contadorSueldos;
    for(int i=0; i<tamanioArray; i++){
        if(arrayEmpleados[i].salary > promedioSueldos && arrayEmpleados[i].isEmpty == OCUPADO){
            superaSueldo++;
        }
    }

    printf("\nEl total de los salarios es de $%.2f, el promedio de sueldo es $%.2f y %d superan al sueldo promedio.\n\n", acumuladorSueldos, promedioSueldos, superaSueldo);



}


void hardcodeo(Employee* arrayEmpleados)
{

    arrayEmpleados[0].id = 1;
    arrayEmpleados[0].isEmpty = OCUPADO;
    strcpy(arrayEmpleados[0].lastName, "Lopez");
    strcpy(arrayEmpleados[0].name, "Juan");
    arrayEmpleados[0].salary = 200.2;
    arrayEmpleados[0].sector = 2;

    arrayEmpleados[1].id = 2;
    arrayEmpleados[1].isEmpty = OCUPADO;
    strcpy(arrayEmpleados[1].lastName, "Fernandez");
    strcpy(arrayEmpleados[1].name, "Lorena");
    arrayEmpleados[1].salary = 300.2;
    arrayEmpleados[1].sector = 1;

    arrayEmpleados[2].id = 3;
    arrayEmpleados[2].isEmpty = OCUPADO;
    strcpy(arrayEmpleados[2].lastName, "Alvarez");
    strcpy(arrayEmpleados[2].name, "Gabriel");
    arrayEmpleados[2].salary = 100.15;
    arrayEmpleados[2].sector = 1;

    arrayEmpleados[3].id = 4;
    arrayEmpleados[3].isEmpty = OCUPADO;
    strcpy(arrayEmpleados[3].lastName, "Fernandez");
    strcpy(arrayEmpleados[3].name, "Ana");
    arrayEmpleados[3].salary = 250.15;
    arrayEmpleados[3].sector = 3;
}
