#ifndef COMIDA_H_INCLUDED
#define COMIDA_H_INCLUDED
#include "empleado.h"
#include "sector.h"
#include "comida.h"
#include "almuerzo.h"
#include "utn.h"

typedef struct
{
    int id; //autoincremental
    char descripcion[51];
    float importe; //mayor a 0
} eComida;

#endif // COMIDA_H_INCLUDED
