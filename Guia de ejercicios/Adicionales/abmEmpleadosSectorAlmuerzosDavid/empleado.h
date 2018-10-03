#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED
#include "empleado.h"
#include "sector.h"
#include "comida.h"
#include "almuerzo.h"
#include "fecha.h"
#include "utn.h"

typedef struct
{
    int legajo; //autoincremental
    char apellido[51];
    char nombre[51];
    int idSector;
    float sueldo; //mayor a 0
    char sexo;
    eFecha fechaIngreso;
    int isEmpty;
} eEmpleado;


int menu();
void inicializarEmpleados( eEmpleado x[], int tam);
int buscarLibre( eEmpleado x[], int tam);
int buscarEmpleado(eEmpleado x[], int tam, int legajo);
void mostrarEmpleado(eEmpleado emp, eSector sectores[], int tamSector);
void mostrarEmpleados(eEmpleado nomina[], int tam, eSector sectores[], int tamSector);
void abmEmpleado(eEmpleado empleados[], int tam, eSector sectores[], int tamSector);
void eliminarEmpleado(eEmpleado *empleados, int tam, eSector sectores[], int tamSector);
void modificarEmpleado(eEmpleado empleados[], int tam, eSector sectores[], int tamSector);;
int elegirSector(eSector sectores[], int tam);
void cargarDescripcion(eSector sectores[], int tamSector, int idSector, char cadena[]);
void listarEmpleadosXSector(eEmpleado x[],int tam, eSector sectores[], int tamSector);
void ordenarXSectorYNombre(eEmpleado x[],int tam, eSector sectores[], int tamSector);
void mostrarEmpleadosMasGanadores(eEmpleado x[],int tam, eSector sectores[], int tamSector);
void harcodearEmpleados(eEmpleado x[]);
void cargarDescripcionComida(eComida comidas[], int tamComida, int idComida, char cadena[]);
void mostrarAlmuerzos(eAlmuerzo almuerzos[], int tamAlmuerzo, eEmpleado empleados[], int tamEmpleados, eComida comidas[], int tamComidas);
void cargarNombreEmpleado(eEmpleado empleados[], int tam, int legajo, char cadena[]);
void mostrarAlmuerzosEmpleado(eAlmuerzo almuerzos[], int tamAlmuerzo, eEmpleado empleados[], int tamEmpleados, eComida comidas[], int tamComidas, eSector sectores[], int tamSector);


#endif // EMPLEADO_H_INCLUDED
