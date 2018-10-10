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

void hardcodeoAlquileres(eAlquiler alquileres[]);
int getNextIdAlquiler(eAlquiler alquileres[],int tamanioAlquiler);
int iniciarEstadosAlquileres(eAlquiler alquileres [], int tamanioAlquileres);
int buscarAlquilerLibre(eAlquiler alquileres[], int tamanioAlquileres);
int buscarAlquiler(eAlquiler alquileres[], int tamanioAlquileres, int idAlquiler);
int juegosActivos(eJuego juegos[], int tamanioJuegos);
int checkEmptyAlquileres(eAlquiler alquileres[], int tamanioAlquileres);
int clientesActivos(eCliente clientes[], int tamanioClientes);
void mostrarAlquileres(eJuego juegos[], int tamaniojuegos, eCliente clientes[], int tamanioClientes, eAlquiler alquileres[], int tamanioAlquileres);
void altaAlquiler(eJuego juegos[], int tamaniojuegos, eCliente clientes[], int tamanioClientes, eAlquiler alquileres[], int tamanioAlquileres);
void listarAlquileres(eJuego juegos[], int tamaniojuegos, eCliente clientes[], int tamanioClientes, eAlquiler alquileres[], int tamanioAlquileres);
void abmAlquiler(eJuego juegos[], int tamaniojuegos, eCliente clientes[], int tamanioClientes, eAlquiler alquileres[], int tamanioAlquileres);
#endif // ALQUILERES_H_INCLUDED
