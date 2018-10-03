#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "empleado.h"
#include "sector.h"
#include "comida.h"
#include "almuerzo.h"
#include "utn.h"
#define LEN_EMPLEADOS 100
#define LEN_COMIDAS 20

int main()
{

    char seguir = 's';
    eEmpleado empleados[LEN_EMPLEADOS];

    eSector sectores[] =
    {
        {1, "RRHH"},
        {2, "Ventas"},
        {3, "Compras"},
        {4, "Contable"},
        {5, "Sistemas"}
    };

    eComida comidas[LEN_COMIDAS] =
    {
        {1, "Milanesa"},
        {2, "Fideos"},
        {3, "Pizza"},
        {4, "Sopa"},
        {5, "Pescado"}
    };

    eAlmuerzo almuerzos[] =
    {
        {100, 1111, 2},
        {101, 5555, 1},
        {102, 4545, 3},
        {103, 3232, 4},
        {104, 1111, 1},
        {105, 5555, 5},
        {106, 4545, 2},
        {107, 3232, 5},
        {108, 1111, 2},
        {109, 4545, 1},
        {110, 3232, 1},
        {111, 1111, 4},
        {112, 5555, 3},
        {113, 4545, 5},
        {114, 3232, 2},
        {115, 5555, 5},
        {116, 4545, 2},
        {117, 3232, 3},
        {118, 1111, 2},
        {119, 5555, 1},
        {120, 4545, 3},

    };

    inicializarEmpleados(empleados, 10);
    harcodearEmpleados(empleados);

    do
    {
        switch(menu())
        {

        case 1:
            abmEmpelados(eEmpleado empleados[], LEN_EMPLEADOS, eSector sectores[], 5);
            system("pause");
            break;
        case 2:

            break;
        case 3:

            break;
        case 4:
            seguir = 'n';
            break;
        }
    }
    while(seguir == 's');



    return 0;
}

void inicializarEmpleados( eEmpleado x[], int tam)
{
    for(int i=0; i < tam; i++)
    {
        x[i].isEmpty = 0;
    }
}

int buscarLibre( eEmpleado x[], int tam)
{
    int indice = -1;

    for(int i=0; i< tam; i++)
    {

        if( x[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarEmpleado(eEmpleado x[], int tam, int legajo)
{
    int indice = -1;
    for(int i=0; i < tam; i++)
    {


        if( x[i].legajo == legajo && x[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int menu()
{
    int opcion;
    system("cls");
    printf("***Menu de Opciones***\n\n");
    printf("1- Alta de empleado\n");
    printf("2- Alta menu\n");
    printf("3- Alta Almuerzo\n");
    printf("4- Salir\n\n");
    opcion = getValidIntRango("Ingrese opcion: ", "Error, solo se admiten numeros. Reintente.\n", 1, 4);
    return opcion;
}



void mostrarEmpleado(eEmpleado emp, eSector sectores[], int tamSector)
{
    char descripcion[20];

    cargarDescripcion(sectores, tamSector, emp.idSector, descripcion);

    printf("%4d %10s %2c    %5.2f   %10s \n\n", emp.legajo, emp.nombre, emp.sexo, emp.sueldo, descripcion);

}


void mostrarEmpleados(eEmpleado nomina[], int tam, eSector sectores[], int tamSector)
{
    system("cls");
    printf(("Legajo  Nombre  Sexo    Sueldo     Sector\n\n"));
    for(int i=0; i< tam; i++)
    {
        if( nomina[i].isEmpty == 1)
        {
            mostrarEmpleado(nomina[i], sectores, tamSector);
        }
    }
}

void eliminarEmpleado(eEmpleado empleados[], int tam, eSector sectores[], int tamSector)
{

    int legajo;
    int indice;
    char borrar;

    printf("Ingrese legajo: ");
    scanf("%d", &legajo);

    indice = buscarEmpleado(empleados, tam, legajo);

    if( indice == -1)
    {
        printf("No hay ningun empleado con el legajo %d\n", legajo);
    }
    else
    {
        mostrarEmpleado( empleados[indice], sectores, tamSector);

        printf("\nConfirma borrado?: ");
        fflush(stdin);
        scanf("%c", &borrar);
        if(borrar != 's')
        {
            printf("Borrado cancelado\n\n");
        }
        else
        {
            empleados[indice].isEmpty = 0;
            printf("Se ha eliminado el empleado\n\n");
        }
        system("pause");
    }

}

void modificarEmpleado(eEmpleado empleados[], int tam, eSector sectores[], int tamSector)
{

    int legajo;
    int indice;
    char modificar;
    float nuevoSueldo;

    printf("Ingrese legajo: ");
    scanf("%d", &legajo);

    indice = buscarEmpleado(empleados, tam, legajo);

    if( indice == -1)
    {
        printf("No hay ningun empleado con el legajo %d\n", legajo);
    }
    else
    {
        mostrarEmpleado( empleados[indice], sectores, tamSector);

        printf("\nModifica sueldo?: ");
        fflush(stdin);
        scanf("%c", &modificar);
        if(modificar != 's')
        {
            printf("Modificacion cancelada\n\n");
        }
        else
        {
            printf("Ingrese nuevo sueldo: ");
            scanf("%f", &nuevoSueldo);

            empleados[indice].sueldo = nuevoSueldo;
            printf("Se ha modificado el sueldo con exito\n\n");
        }

        system("pause");
    }

}


int elegirSector(eSector sectores[], int tam)
{
    int idSector;
    printf("\nSectores\n\n");
    for(int i=0; i < tam; i++)
    {
        printf("%d %s\n", sectores[i].id, sectores[i].descripcion);
    }
    printf("\nSeleccione sector: ");
    scanf("%d", &idSector);
    return idSector;
}

void cargarDescripcion(eSector sectores[], int tamSector, int idSector, char cadena[])
{

    for(int i=0; i < tamSector; i++)
    {
        if( sectores[i].id == idSector)
        {
            strcpy(cadena, sectores[i].descripcion);
            break;
        }
    }
}
void cargarDescripcionComida(eComida comidas[], int tamComida, int idComida, char cadena[])
{
    for(int i=0; i < tamComida; i++)
    {
        if( comidas[i].id == idComida)
        {
            strcpy(cadena, comidas[i].descripcion);
            break;
        }
    }
}

void cargarNombreEmpleado(eEmpleado empleados[], int tam, int legajo, char cadena[])
{
    for(int i=0; i < tam; i++)
    {
        if( empleados[i].legajo == legajo)
        {
            strcpy(cadena, empleados[i].nombre);
            break;
        }
    }
}

void listarEmpleadosXSector(eEmpleado x[],int tam, eSector sectores[], int tamSector)
{
    int idSector;
    char descripcion[20];
    int flag = 0;

    idSector = elegirSector(sectores, tamSector);

    cargarDescripcion(sectores, tam, idSector, descripcion);

    system("cls");
    printf("Empleados del sector %s\n\n", descripcion);
    for(int i=0; i< tam; i++)
    {
        if(x[i].isEmpty == 1 && x[i].idSector == idSector)
        {
            mostrarEmpleado(x[i], sectores, tamSector);
            flag = 1;
        }
    }

    if(flag == 0)
    {
        printf("No hay empleados que mostrar\n\n");
    }

}

void ordenarXSectorYNombre(eEmpleado x[],int tam, eSector sectores[], int tamSector)
{

    char descripcionI[20];
    char descripcionJ[20];
    eEmpleado auxEmpleado;

    for(int i=0; i<tam -1; i++)
    {
        for(int j = i +1; j < tam; j++)
        {
            cargarDescripcion(sectores, tamSector, x[i].idSector, descripcionI);
            cargarDescripcion(sectores, tamSector, x[j].idSector, descripcionJ);
            if( strcmp(descripcionI, descripcionJ) > 0)
            {
                auxEmpleado = x[i];
                x[i] = x[j];
                x[j] = auxEmpleado;
            }
            else if( strcmp(descripcionI, descripcionJ) == 0 && strcmp(x[i].nombre, x[j].nombre) > 0)
            {
                auxEmpleado = x[i];
                x[i] = x[j];
                x[j] = auxEmpleado;
            }
        }
    }

}
void harcodearEmpleados(eEmpleado x[])
{

    eEmpleado y[]=
    {
        {1111, "fernandez", "ana", 5, 15000, 'f', {1, 2, 1980}, 1},
        {3333, "rodriguez", "luis", 4, 25000, 'm', {1, 2, 1980}, 1},
        {4444, "albarez", "alberto", 5,  10000, 'm',{1, 2, 1980}, 1},
        {5555, "cian", "julia", 1,  30000, 'f', {1, 2, 1980}, 1},
        {1313, "diaz", "julieta",  2, 23000, 'f',{1, 2, 1980},1},
        {4545, "castillo", "andrea", 5, 31000, 'f',  {1, 2, 1980}, 1},
        {3232, "garcia", "mauro", 5, 27000, 'm',  {1, 2, 1980},1},
    };

    for(int i=0; i<7; i++)
    {
        x[i] = y[i];
    }

}

void mostrarEmpleadosMasGanadores(eEmpleado x[],int tam, eSector sectores[], int tamSector)
{
    float maxSueldo;
    char descripcion[20];
    int flag;
    int flag2;

    system("cls");
    printf("\n*** Empleados que mas ganan por sector ***\n\n");

    for(int i=0; i < tamSector; i++)
    {

        cargarDescripcion(sectores, tamSector, sectores[i].id, descripcion);
        printf("Sector %s\n\n", descripcion);
        flag = 0;
        flag2 = 0;
        for(int j=0; j < tam; j++)
        {
            if( (x[j].sueldo > maxSueldo && x[j].isEmpty == 1 && x[j].idSector == sectores[i].id) || flag == 0)
            {
                maxSueldo = x[j].sueldo;
                flag = 1;
            }

            if( x[j].isEmpty == 1 && x[j].idSector == sectores[i].id)
            {
                flag2 = 1;
            }

        }

        if(flag2 == 0)
        {
            printf("Sector Vacio\n");
        }
        else
        {

            for(int j=0; j < tam; j++)
            {
                if( x[j].sueldo == maxSueldo)
                {
                    mostrarEmpleado(x[j], sectores, tamSector);
                }
            }

        }

        printf("\n\n");
    }
}

void mostrarAlmuerzos(eAlmuerzo almuerzos[], int tamAlmuerzo, eEmpleado empleados[], int tamEmpleados, eComida comidas[], int tamComidas)
{
    char descComida[20];
    char nombreEmpleado[20];

    system("cls");
    printf("  *** Listado de Almuerzos ***\n\n");
    printf("Id  Legajo     Nombre     Comida\n\n");

    for(int i=0; i< tamAlmuerzo; i++)
    {
        for(int j = 0; j < tamEmpleados; j++)
        {
            if(almuerzos[i].idEmpleado == empleados[j].legajo)
            {
                strcpy(nombreEmpleado, empleados[j].nombre);
                break;
            }
        }
        for(int k = 0; k < tamComidas; k++)
        {
            if(almuerzos[i].IdComida == comidas[k].id)
            {
                strcpy(descComida, comidas[k].descripcion);
                break;
            }
        }

        printf("%d  %d %10s   %10s\n", almuerzos[i].id, almuerzos[i].idEmpleado, nombreEmpleado, descComida);

    }

    printf("\n\n");

}

void mostrarAlmuerzosEmpleado(eAlmuerzo almuerzos[], int tamAlmuerzo, eEmpleado empleados[], int tamEmpleados, eComida comidas[], int tamComidas, eSector sectores[], int tamSector)
{

    int legajo;
    int flag = 0;

    system("cls");

    mostrarEmpleados(empleados,tamEmpleados, sectores, tamSector);
    printf("Ingrese legajo: ");
    scanf("%d", &legajo);
    system("cls");
    printf("  *** Listado de almuerzos legajo %d ***\n\n", legajo);

    for(int i=0; i < tamAlmuerzo; i++)
    {
        if( almuerzos[i].idEmpleado == legajo)
        {
            for(int j=0; j < tamComidas; j++)
            {
                if( comidas[j].id == almuerzos[i].IdComida)
                {
                    printf("%d  %10s\n", almuerzos[i].id, comidas[j].descripcion);
                }
            }
            flag = 1;
        }
    }

    if(flag == 0)
    {
        printf("El empleado no presenta almuerzos");
    }
    printf("\n\n");
}
