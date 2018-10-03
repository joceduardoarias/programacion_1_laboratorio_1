#include <stdio.h>
#include <stdlib.h>
#include "empleado.h"
#include "sector.h"
#include "almuerzo.h"
#include "utn.h"
#define VACIO 0
#define ACTIVO 1
#define BAJA 2

void inicializarAlmuerzos(eAlmuerzo almuerzos[], int tamanio){
    for(int i=0; i<tamanio; i++){
        almuerzos[i].isEmpty = VACIO;
    }
}
