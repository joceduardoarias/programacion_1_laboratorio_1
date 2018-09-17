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

void mostrasrEmpleado(eEmpleado employee);

int main()
{
    eEmpleado unEmpleado;

    unEmpleado.legajo = 1234;
    strcpy(unEmpleado.nombre, "Juan");
    unEmpleado.sexo = 'm';
    unEmpleado.sueldo = 10000.5;
    unEmpleado.fechaIngreso.dia = 17;
    unEmpleado.fechaIngreso.mes = 9;
    unEmpleado.fechaIngreso.anio = 2018;

    printf("Legajo\tNombre\tSexo\tSueldo\t\tDia     Mes     Anio\n\n");
    mostrasrEmpleado(unEmpleado);
    return 0;
}

void mostrasrEmpleado(eEmpleado employee){
    printf("%d\t%s\t%c\t%.2f\t%02d\t%02d\t%04d\n", employee.legajo, employee.nombre, employee.sexo, employee.sueldo, employee.fechaIngreso.dia, employee.fechaIngreso.mes, employee.fechaIngreso.anio);
}
