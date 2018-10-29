#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int legajo;
    char nombre[20];
    float sueldo;
} eEmpleado;

int parseData(char* archivo, eEmpleado* arrayEmpleados);

int main()
{
    int r, i;
    eEmpleado* pArrayEmpleados;

    pArrayEmpleados = (eEmpleado*) malloc(sizeof(eEmpleado)*50);
    if(pArrayEmpleados == NULL)
    {
        printf("No hay lugar para crear array.\n");
        exit(EXIT_FAILURE);
    }
    printf("Array creado correctamente.\n");

    r = parseData("empleados.csv", pArrayEmpleados);
    for(i=0; i<r; i++)
    {
        printf("Legajo: %d   Nombre: %s   Sueldo: %.2f\n", pArrayEmpleados[i].legajo, pArrayEmpleados[i].nombre, pArrayEmpleados[i].sueldo);
    }
    return 0;
}

int parseData(char* archivo, eEmpleado* arrayEmpleados)
{
    FILE *pFile;
    int todoOk = 0;
    int r,i=0;
    char var1[50],var2[50],var3[50];
    pFile = fopen(archivo,"r");
    fscanf(pFile,"%[^,],%[^,],%[^\n]\n",var1,var2,var3);

    if(pFile == NULL)
    {
        todoOk = 1;
    }
    do
    {
        r = fscanf(pFile,"%[^,],%[^,],%[^\n]\n",var1,var2,var3);
        if(r==3)
        {
            arrayEmpleados[i].legajo = atoi(var1);
            strcpy(arrayEmpleados[i].nombre,var2);
            arrayEmpleados[i].sueldo = atof(var3);

            i++;
        }
        else
            break;
    }
    while(!feof(pFile));
    fclose(pFile);

    return i;
}
