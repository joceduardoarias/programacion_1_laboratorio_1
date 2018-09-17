#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 5

typedef struct
{
    int legajo;
    char nombre[20];
    float sueldo;
    char sexo;
}eEmpleado;

void mostrasrEmpleado(eEmpleado employee);

int main()
{
    int cantidad;

    eEmpleado unEmpleado;
    eEmpleado otroEmpleado;
    eEmpleado empleadoTres = {2222, "Jose", 20000.6, 'm'};// Hardcodeo igual a como fue cargado, sino no funciona
    eEmpleado empleadoCuatro;
    eEmpleado empleadoCinco;


    empleadoCuatro = empleadoTres; // le doy los valores de empleado tres

    unEmpleado.legajo = 1234;
    strcpy(unEmpleado.nombre, "Juan");
    unEmpleado.sexo = 'm';
    unEmpleado.sueldo = 10000.5;

    otroEmpleado.legajo = 1122;
    strcpy(otroEmpleado.nombre, "Lucia");
    otroEmpleado.sexo = 'f';
    otroEmpleado.sueldo = 15000.75;

    printf("Ingrese Legajo: ");
    scanf("%d", &empleadoCinco.legajo);
    printf("Ingrese nombre: ");
    fflush(stdin);
    fgets(empleadoCinco.nombre, 20, stdin);
    cantidad = strlen(empleadoCinco.nombre);
    empleadoCinco.nombre[cantidad-1]='\0';
    printf("Ingrese sexo: ");
    fflush(stdin);
    scanf("%c", &empleadoCinco.sexo);
    printf("Ingrese sueldo: ");
    scanf("%f", &empleadoCinco.sueldo);

    printf("\n\nLegajo\tNombre\tSexo\tSueldo\n\n");
    mostrasrEmpleado(unEmpleado);
    mostrasrEmpleado(otroEmpleado);
    mostrasrEmpleado(empleadoTres);
    mostrasrEmpleado(empleadoCuatro);
    mostrasrEmpleado(empleadoCinco);
    return 0;
}

void mostrasrEmpleado(eEmpleado employee){
    printf("%d\t%s\t%c\t%.2f\n", employee.legajo, employee.nombre, employee.sexo, employee.sueldo);
}
