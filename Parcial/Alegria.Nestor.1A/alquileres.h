#ifndef ALQUILERES_H_INCLUDED
#define ALQUILERES_H_INCLUDED
#include "alquileres.h"
#include "juegos.h"
#include "clientes.h"

typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;

typedef struct
{
    int idAlquiler;
    int codigoJuego;
    int codigoCliente;
    eFecha fechaAlquiler;
    int isEmpty;
}eAlquiler;

int getNextIdAlquiler(eAlquiler alquileres[],int tamanioAlquiler);
int iniciarEstadosAlquileres(eAlquiler alquileres [], int tamanioAlquileres);
int buscarAlquilerLibre(eAlquiler alquileres[], int tamanioAlquileres);
int buscarAlquiler(eAlquiler alquileres[], int tamanioAlquileres, int idAlquiler);
int juegosActivos(eJuego juegos[], int tamanioJuegos);
int clientesActivos(eCliente clientes[], int tamanioClientes);

void cargarNombre(eCliente clientes[], int tamanioClientes, int idCliente, char cadena[]);
void cargarDescripcion(eJuego juegos[], int tamanioJuegos, int idJuego, char cadena[]);

void abmAlquiler(eJuego juegos[], int tamaniojuegos, eCliente clientes[], int tamanioClientes, eAlquiler alquileres[], int tamanioAlquileres);

#endif // ALQUILERES_H_INCLUDED
