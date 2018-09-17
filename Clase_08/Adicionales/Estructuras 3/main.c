#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 3

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
    int cantidad;
    eEmpleado empleados[TAM];

    for(int i = 0; i<TAM; i++)
    {
        printf("Ingrese Legajo: ");
        scanf("%d", &empleados[i].legajo);
        printf("Ingrese nombre: ");
        fflush(stdin);
        fgets(empleados[i].nombre, 20, stdin);
        cantidad = strlen(empleados[i].nombre);
        empleados[i].nombre[cantidad-1]='\0';
        printf("Ingrese sexo: ");
        fflush(stdin);
        scanf("%c", &empleados[i].sexo);
        printf("Ingrese sueldo: ");
        scanf("%f", &empleados[i].sueldo);
    }
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
