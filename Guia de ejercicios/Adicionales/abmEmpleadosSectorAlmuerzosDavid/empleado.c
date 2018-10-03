#include <stdio.h>
#include <stdlib.h>
#include "empleado.h"
#include "sector.h"
#include "utn.h"
#define VACIO 0
#define ACTIVO 1
#define BAJA 2

void inicializarEmpleados( eEmpleado x[], int tam)
{
    for(int i=0; i < tam; i++)
    {
        x[i].isEmpty = VACIO;
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

int getNextId(eEmpleado x[], int tam)
{
    int flag = 0;
    if(x != NULL && tam > 0)
    {
        for(int i=0; i<tam; i++)
        {
            if(x[i].isEmpty == ACTIVO || x[i].isEmpty == BAJA)
            {
                flag++;
            }
        }
    }
    return flag+1;
}

void abmEmpleado(eEmpleado empleados[], int tamanio, eSector sectores[], int tamSector)
{
    int indice;
    int opcion;
    char seguir = 's';
    do
    {
        system("cls");
        printf("  *** Alta Empleado ***\n\n");
        indice = buscarLibre(empleados, tamanio);
        if(indice == -1)
        {
            printf("No hay lugar\n\n");
        }
        else
        {
            printf("1- Alta\n2- Modificar\n3- Baja\n4- Listar\n5- Salir\n\n");
            opcion = getValidInt("Ingrese opcion: ", "Error, solo se permiten numeros. Reintente\n\n");
            switch(opcion)
            {
            case 1:
                altaEmpleado(empleados, tamanio, sectores, tamSector, indice);
                system("pause");
                break;
            case 2:
                modificarEmpleado(empleados, tamanio, sectores, tamSector);
                system("pause");
                break;
            case 3:
                system("pause");
                break;
            case 4:
                system("pause");
                break;
            case 5:
                seguir = 'n';
                break;
            default:
                printf("Error al ingresar opcion, reintente.\n");
            }
        }
    }
    while(seguir=='s');


}

void altaEmpleado(eEmpleado empleados[], int tamanio, eSector sectores[], int tamSector, int indice)
{
    system("cls");
    printf("  *** Alta Empleado ***\n\n");
    eEmpleado nuevoEmpleado;
    nuevoEmpleado.legajo = getNextId(empleados, tamanio);
    getValidStringRango("Ingrese nombre: ", "Error, solo se permiten letras. Reintente", nuevoEmpleado.nombre, 51);
    getValidStringRango("Ingrese apellido: ", "Error, solo se permiten letras. Reintente", nuevoEmpleado.apellido, 51);
    nuevoEmpleado.sueldo = getValidFloatMayor0("Ingrese sueldo: ", "Error, solo se permiten numeros. Reintente");
    nuevoEmpleado.sexo = getValidChar("Ingrese sexo: ", "Error, solo se permiten letras. Reintente", 'f', 'm');
    nuevoEmpleado.fechaIngreso.dia = getValidIntRango("Ingrese dia de ingreso: ", "Error, solo se permiten numeros. Reintente", 1, 31);
    nuevoEmpleado.fechaIngreso.mes = getValidIntRango("Ingrese mes de ingreso: ", "Error, solo se permiten numeros. Reintente", 1, 31);
    nuevoEmpleado.fechaIngreso.dia = getValidIntRango("Ingrese anio de ingreso: ", "Error, solo se permiten numeros. Reintente", 1950, 2018);

    nuevoEmpleado.idSector = elegirSector(sectores, 5);

    nuevoEmpleado.isEmpty = 1;

    empleados[indice] = nuevoEmpleado;
    mostrarEmpleado(empleados[indice], sectores, 5);
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

    printf("\n%4d %10s %2c    %5.2f   %10s    %d | %d | %d\n\n", emp.legajo, emp.nombre, emp.sexo, emp.sueldo, descripcion, emp.fechaIngreso.dia, emp.fechaIngreso.mes, emp.fechaIngreso.anio);

}


void mostrarEmpleados(eEmpleado nomina[], int tam, eSector sectores[], int tamSector)
{
    system("cls");
    printf("\nLegajo  Nombre  Sexo    Sueldo     Sector\n\n");
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
    system("cls");
    printf("  *** Modificar Empleado ***\n\n");
    int legajo;
    int indice;
    int opcion;
    char confirmacion;

    char auxNombre[51];
    char auxApellido[51];
    char auxSexo;
    float auxSueldo;
    int auxDia;
    int auxMes;
    int auxAnio;

    legajo = getValidInt("Ingrese legajo: ", "Error, solo se admiten numeros. Reintente.\n");
    indice = buscarEmpleado(empleados, tam, legajo);
    if( indice == -1)
    {
        printf("No hay ningun empleado con el legajo %d\n", legajo);
    }
    else
    {
        printf("\nLegajo  Nombre  Sexo    Sueldo     Sector     Dia  Mes  Anio\n\n");
        mostrarEmpleado( empleados[indice], sectores, tamSector);
        printf("Menu de opciones\n\n1- Nombre\n2- Apellido\n3- Sexo\n4- Salario\n5- Fecha de ingreso\n6- Salir\n\n");
        opcion = getValidInt("Ingrese opcion: ", "Error, solo se admiten numeros. Reintente.\n");
        switch(opcion){
        case 1:
            getValidStringRango("Ingrese nuevo nombre: ", "Error, solo letras.\n", auxNombre, 51);
            printf("Desea modificar \"%s\" por \"%s\"? (s/n): ", auxNombre, empleados[indice].nombre);
            confirmacion = getValidChar("Ingrese confirmacion: ", "Error\n", 's', 'n');
            if(confirmacion == 's'){
                strcpy(empleados[indice].nombre, auxNombre);
                printf("Se modifico con exito\n");
            }
            else{
                printf("Se cancelo modificacion\n");
            }
            break;
        case 2:
            getValidStringRango("Ingrese nuevo apellido: ", "Error, solo letras.\n", auxApellido, 51);
            printf("Desea modificar \"%s\" por \"%s\"? (s/n): ", auxApellido, empleados[indice].apellido);
            confirmacion = getValidChar("Ingrese confirmacion: ", "Error\n", 's', 'n');
            if(confirmacion == 's'){
                strcpy(empleados[indice].apellido, auxApellido);
                printf("Se modifico con exito\n");
            }
            else{
                printf("Se cancelo modificacion\n");
            }
            break;
        case 3:
            auxSexo = getValidChar("Ingrese nuevo sexo: ", "Error, solo letras.\n", 'm', 'f');
            printf("\nSe modificara \"%c\" por \"%c\"\n", auxSexo, empleados[indice].sexo);
            confirmacion = getValidChar("\nIngrese confirmacion (s/n): ", "Error\n", 's', 'n');
            if(confirmacion == 's'){
                empleados[indice].sexo = auxSexo;
                printf("Se modifico con exito\n");
            }
            else{
                printf("Se cancelo modificacion\n");
            }
        case 4:
            auxSueldo = getValidFloatMayor0("Ingrese nuevo sueldo: ", "Error, solo numeros.\n");
            printf("\nSe modificara \"%.2f\" por \"%.2f\"\n", auxSueldo, empleados[indice].sueldo);
            confirmacion = getValidChar("\nIngrese confirmacion (s/n): ", "Error\n", 's', 'n');
            if(confirmacion == 's'){
                empleados[indice].sueldo = auxSueldo;
                printf("Se modifico con exito\n");
            }
            else{
                printf("Se cancelo modificacion\n");
            }
            break;
        case 5:
            auxDia = getValidIntRango("Ingrese nuevo dia: ", "Error\n", 1, 31);
            auxMes = getValidIntRango("Ingrese nuevo mes: ", "Error\n", 1, 31);
            auxAnio = getValidIntRango("Ingrese nuevo anio: ", "Error\n", 1970, 2018);
            printf("\nSe modificara \"%d | %d | %d\" por \"%d | %d | %d\"\n", auxDia, auxMes, auxAnio, empleados[indice].fechaIngreso.dia, empleados[indice].fechaIngreso.mes, empleados[indice].fechaIngreso.anio);
            confirmacion = getValidChar("\nIngrese confirmacion (s/n): ", "Error\n", 's', 'n');
            if(confirmacion == 's'){
                empleados[indice].fechaIngreso.dia = auxDia;
                empleados[indice].fechaIngreso.mes = auxMes;
                empleados[indice].fechaIngreso.anio = auxAnio;
                printf("Se modifico con exito\n");
            }
            else{
                printf("Se cancelo modificacion\n");
            }
            break;

        }
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

