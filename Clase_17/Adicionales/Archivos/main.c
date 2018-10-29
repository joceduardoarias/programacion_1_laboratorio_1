#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int legajo;
    char nombre[20];
    float sueldo;
}eEmpleado;

int parseData(FILE* archivo, eEmpleado* arrayEmpleados, int len);

int main()
{
    FILE* fl;
    fl = fopen("empleados.csv", "r");
    if(fl == NULL)
    {
        printf("Error al cargar el archivo.\n");
        exit(EXIT_FAILURE);
    }
    else{
        printf("Archivo cargado con exito!\n");
    }
    return 0;
}

int parseData(FILE* archivo, eEmpleado* arrayEmpleados, int len)
{
    int todoOk = 0;



    return todoOk;
}
