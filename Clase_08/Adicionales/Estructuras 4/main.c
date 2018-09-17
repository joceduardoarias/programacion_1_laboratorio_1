#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 7

typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;

typedef struct
{
    int legajo;
    char nombre[20];
    float sueldo;
    char sexo;
    eFecha fechaIngreso;
} eEmpleado;

void mostrarEmpleado(eEmpleado employee);
void mostrarEmpleados(eEmpleado employee[], int tam);
void ordenarEmpleados(eEmpleado employee[], int tam);

int main()
{
    eEmpleado empleados[]=
    {
        {1111,"Juan", 1000.5, 'm'},
        {2222, "Ana", 2000.5, 'f'},
        {3333, "Lucia", 3500.5, 'f'},
        {4444, "Raul", 5010.6, 'm'},
        {5555, "Carlos", 6010, 'm'},
        {6666, "Carla", 15010.6, 'f'},
        {7777, "Sabrina", 16010, 'f'},
    };
    printf("\nLegajo\tNombre\t\tSexo\tSueldo\n\n");
    mostrarEmpleados(empleados, TAM);
    printf("\n\n");
    ordenarEmpleados(empleados, TAM);
    printf("\n\n");
    mostrarEmpleados(empleados, TAM);
    return 0;
}

void mostrarEmpleado(eEmpleado employee)
{
    printf("%d\t%s\t\t%c\t%.2f\n", employee.legajo, employee.nombre, employee.sexo, employee.sueldo);
}

void mostrarEmpleados(eEmpleado employee[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        mostrarEmpleado(employee[i]);
    }
}

void ordenarEmpleados(eEmpleado employee[], int tam)
{
    eEmpleado auxEmpleado;
    for(int i=0; i < tam-1; i++){
        for(int j= i+1; j< tam; j++){
            if( employee[i].sexo > employee[j].sexo){
                auxEmpleado = employee[i];
                employee[i] = employee[j];
                employee[j] = auxEmpleado;
            }else if( employee[i].sexo == employee[j].sexo && strcmp(employee[i].nombre, employee[j].nombre) > 0){
                auxEmpleado = employee[i];
                employee[i] = employee[j];
                employee[j] = auxEmpleado;
            }
        }
    }
}
