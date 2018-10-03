#ifndef ALMUERZO_H_INCLUDED
#define ALMUERZO_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;

typedef struct
{
    int id;
    int idEmpleado;
    int IdComida;
    eFecha fechaAlmuerzo;
} eAlmuerzo;

#endif // ALMUERZO_H_INCLUDED
