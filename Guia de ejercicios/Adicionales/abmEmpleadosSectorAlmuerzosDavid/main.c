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

    eAlmuerzo almuerzos[20000] =
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

    inicializarEmpleados(empleados, LEN_EMPLEADOS);
    inicializarAlmuerzos(almuerzos, 20000);
    harcodearEmpleados(empleados);

    do
    {
        switch(menu())
        {

        case 1:
            abmEmpleado(empleados, LEN_EMPLEADOS, sectores, 5);
            system("pause");
            break;
        case 2:
            listarEmpleadosXSector(empleados, LEN_EMPLEADOS, sectores, 5);
            system("pause");
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


