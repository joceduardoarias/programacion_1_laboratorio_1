#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

typedef struct
{
    int legajo;
    char apellido[21];
    char nombre[21];
    int idSector;
    float sueldo;
    char sexo;
    int isEmpty;
} eEmpleado;

#endif // EMPLEADO_H_INCLUDED
