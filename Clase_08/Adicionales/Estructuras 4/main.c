#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 5

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

int main()
{
    eEmpleado empleados[]={
        {1111,"Juan", 1000.5, 'm'},
        {2222, "Ana", 2000.5, 'f'},
        {3333, "Lucia", 3500.5, 'f'},
        {4444, "Raul", 5010.6, 'm'},
        {5555, "Carlos", 6010, 'm'},
    };
    printf("\nLegajo\tNombre\tSexo\tSueldo\n\n");
    mostrarEmpleados(empleados, TAM);
    return 0;
}

void mostrarEmpleado(eEmpleado employee){
    printf("%d\t%s\t%c\t%.2f\n", employee.legajo, employee.nombre, employee.sexo, employee.sueldo);
}

void mostrarEmpleados(eEmpleado employee[], int tam){
    for(int i=0; i<tam; i++){
        mostrarEmpleado(employee[i]);
    }
}
