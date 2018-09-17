#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int main()
{
    eEmpleado unEmpleado;
    eEmpleado otroEmpelado = {1224, "Analia", 30000.5, 'f',{17, 9 , 2018}};

    unEmpleado.legajo = 1234;
    strcpy(unEmpleado.nombre, "Juan");
    unEmpleado.sexo = 'm';
    unEmpleado.sueldo = 10000.5;
    unEmpleado.fechaIngreso.dia = 17;
    unEmpleado.fechaIngreso.mes = 9;
    unEmpleado.fechaIngreso.anio = 2018;

    printf("Legajo\tNombre\tSexo\tSueldo\t\tDia     Mes     Anio\n\n");
    mostrarEmpleado(unEmpleado);
    mostrarEmpleado(otroEmpelado);
    return 0;
}

void mostrarEmpleado(eEmpleado employee){
    printf("%d\t%s\t%c\t%.2f\t%02d\t%02d\t%04d\n", employee.legajo, employee.nombre, employee.sexo, employee.sueldo, employee.fechaIngreso.dia, employee.fechaIngreso.mes, employee.fechaIngreso.anio);
}
