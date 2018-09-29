#include <stdio.h>
#include <stdlib.h>
#define TAM 3
#define VACIO 1
#define LLENO 0

typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
    int isEmpty;
} eEmpleado;

int menu();
void inicializarEstados(eEmpleado lista[], int tam);
void mostrarEmpelado(eEmpleado unEmpleado);
void mostrarEmpelados(eEmpleado lista[], int tam);
int buscarLibre(eEmpleado lista[], int tam);
int buscarEmpleado(eEmpleado lista[], int tam, int legajo);
void altaEmpleado(eEmpleado lista[], int tam);
void bajaEmpleado(eEmpleado lista[], int tam);
void modificarEmpleadoPorSueldo(eEmpleado lista[], int tam);
void ordenarEmpleadosPorLegajo(eEmpleado lista[], int tam);

int main()
{
    char seguir='s';
    eEmpleado empleados[TAM];

    inicializarEstados(empleados, TAM);

    do
    {
        switch(menu())
        {
        case 1:
            printf("Alta\n\n");
            altaEmpleado(empleados, TAM);
            system("pause");
            break;
        case 2:
            printf("Baja\n\n");
            bajaEmpleado(empleados, TAM);
            system("pause");
            break;
        case 3:
            printf("Modificacion\n\n");
            modificarEmpleadoPorSueldo(empleados, TAM);
            system("pause");
            break;
        case 4:
            printf("Listar\n\n");
            mostrarEmpelados(empleados, TAM);
            system("pause");
            break;
        case 5:
            printf("Ordenar\n\n");
            system("pause");
            break;
        case 6:
            printf("Salir\n\n");
            seguir = 'n';
            break;
        default:
            printf("Error. Ingrese una opcion correcta.\n\n");
        }

    }
    while(seguir == 's');
    return 0;
}

int menu()
{
    system("cls");
    int opcion;
    printf("*** Menu de opciones ***\n\n");
    printf("1- Alta\n");
    printf("2- Baja\n");
    printf("3- Modificacion\n");
    printf("4- Listar\n");
    printf("5- Ordenar empleados\n");
    printf("6- Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);
    return opcion;
}

void inicializarEstados(eEmpleado lista[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        lista[i].isEmpty = VACIO;
    }
}

int buscarLibre(eEmpleado lista[], int tam)
{
    int index = -1;
    for(int i=0; i<tam; i++)
    {
        if(lista[i].isEmpty == VACIO) //esta vacio true (1)
        {
            index = i;
            break;
        }
    }
    return index;
}

void mostrarEmpelado(eEmpleado unEmpleado)
{
    printf("%d %s %c %.2f\n", unEmpleado.legajo, unEmpleado.nombre, unEmpleado.sexo, unEmpleado.sueldo);
}

void mostrarEmpelados(eEmpleado lista[], int tam)
{
    system("cls");
    printf("Legajo Nombre Sexo Sueldo\n\n");
    for(int i =0; i<tam; i++)
    {
        if(lista[i].isEmpty == 0)
        {
            mostrarEmpelado(lista[i]);
        }
    }
}

int buscarEmpleado(eEmpleado lista[], int tam, int legajo)
{
    int index = -1;
    for(int i=0; i<tam; i++)
    {
        if(lista[i].legajo == legajo && lista[i].isEmpty == LLENO)
        {
            index = i;
            break;
        }
    }
    return index;
}

void altaEmpleado(eEmpleado lista[], int tam)
{
    system("cls");
    printf("*** ALTA *** \n\n");
    int indice;
    int existe;
    int legajo;
    eEmpleado nuevoEmpleado;

    indice = buscarLibre(lista, tam);
    if(indice == -1)
    {
        printf("\nNo quedan espacios disponibles.\n\n");
    }
    else
    {
        printf("Ingrese legajo: ");
        scanf("%d", &legajo);
        existe = buscarEmpleado(lista, tam, legajo);
        if(existe != -1)
        {
            printf("\nEl usuario existe en sistema.\n");
            mostrarEmpelado(lista[existe]);
        }
        else
        {
            nuevoEmpleado.legajo = legajo;
            printf("Ingrese nombre: ");
            fflush(stdin);
            scanf("%s", nuevoEmpleado.nombre);
            printf("Ingrese sexo: ");
            fflush(stdin);
            scanf("%c", &nuevoEmpleado.sexo);
            printf("Ingrese sueldo: ");
            scanf("%f", &nuevoEmpleado.sueldo);
            nuevoEmpleado.isEmpty = 0;

            lista[indice] = nuevoEmpleado;

            printf("\nSe agrego un nuevo empleado\n");

        }
    }

}


void bajaEmpleado(eEmpleado lista[], int tam)
{
    system("cls");
    printf("*** BAJA ***\n\n");
    int existe;
    int legajo;
    char confirma;

    printf("Ingrese legajo: ");
    scanf("%d", &legajo);
    existe = buscarEmpleado(lista, tam, legajo);
    if(existe == -1)
    {
        printf("\nNo existe el empleado con el legajo %d\n", legajo);
    }
    else
    {
        printf("\nSe encontro empleado en sistema\n");
        mostrarEmpelado(lista[existe]);
        printf("\nDesea eliminar al usuario? (s/n): ");
        fflush(stdin);
        scanf("%c", &confirma);
        if(confirma=='s')
        {
            lista[existe].isEmpty = VACIO;
            printf("\nSe elimino usuario con exito.\n");
        }
        else
        {
            printf("\nSe cancelo baja de usuario.\n");
        }
    }

}

void modificarEmpleadoPorSueldo(eEmpleado lista[], int tam)
{
    system("cls");
    printf("*** MODIFICACION ***\n\n");
    int existe;
    int legajo;
    char confirma;
    float sueldo;

    printf("Ingrese legajo: ");
    scanf("%d", &legajo);
    existe = buscarEmpleado(lista, tam, legajo);
    if(existe == -1)
    {
        printf("\nNo existe el empleado con el legajo %d\n", legajo);
    }
    else
    {
        printf("\nSe encontro empleado en sistema\n");
        mostrarEmpelado(lista[existe]);
        printf("Ingrese nuevo sueldo: ");
        scanf("%f", &sueldo);
        printf("\nDesea modificar el sueldo? (s/n): ");
        fflush(stdin);
        scanf("%c", &confirma);
        if(confirma=='s')
        {
            lista[existe].sueldo = sueldo;
            printf("\nSe modifico el sueldo con exito.\n");
        }
        else
        {
            printf("\nSe cancelo la modificacion del sueldo.\n");
        }
    }

}


void ordenarEmpleadosPorLegajo(eEmpleado lista[], int tam)
{
    eEmpleado auxEmpleado;
    for(int i=0; i<tam-1; i++)
    {
        for(int j= i+1; j < tam; j++)
        {

            if( lista[i].legajo > lista[j].legajo)
            {
                auxEmpleado = lista[i];
                lista[i] = lista[j];
                lista[j] = auxEmpleado;

            }
        }
    }

    printf("Empleados oredenados con exito!!!\n\n");


}
