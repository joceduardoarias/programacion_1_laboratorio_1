#ifndef ALMUERZO_H_INCLUDED
#define ALMUERZO_H_INCLUDED
#include "empleado.h"
#include "sector.h"
#include "comida.h"
#include "almuerzo.h"
#include "fecha.h"
#include "utn.h"

typedef struct
{
    int id; //autoincremental
    int idEmpleado; //debe existir
    int IdComida; //debe existir
    eFecha fechaAlmuerzo;
} eAlmuerzo;

#endif // ALMUERZO_H_INCLUDED
