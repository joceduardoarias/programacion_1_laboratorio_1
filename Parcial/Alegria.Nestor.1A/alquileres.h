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

/** \brief Inicializa el array de alquileres
 *
 * \param alquileres[] eAlquiler Array de alquileres
 * \return void
 *
 */
void hardcodeoAlquileres(eAlquiler alquileres[]);

/** \brief Recorre el array alquileres y acumula los alquileres activos y eliminados
 *
 * \param alquileres[] eAlquileres Array de alquileres
 * \param tamanioAlquileres int El tamaño del array
 * \return int (0) si aun no hay alquileres activos o eliminados -
 * (flag) la posicion libre en el array
 *
 */
int getNextIdAlquiler(eAlquiler alquileres[],int tamanioAlquiler);

/** \brief Inicializa todas las banderas isEmpty en (VACIO - 1)
 *
 * \param alquileres[] eAlquileres Array de alquileres
 * \param tamanioAlquileres int El tamaño del array
 * \return void
 *
 */
int iniciarEstadosAlquileres(eAlquiler alquileres [], int tamanioAlquileres);

/** \brief Busca la primer posicion libre en el array
 *
 * \param alquileres[] eAlquileres Array de alquileres
 * \param tamanioAlquileres int El tamaño del array
 * \return int La posicion libre
 *
 */
int buscarAlquilerLibre(eAlquiler alquileres[], int tamanioAlquileres);

/** \brief Recorre el array alquileres y busca un alquiler con el idAlquiler
 *
 * \param alquileres[] eAlquileres Array de alquileres
 * \param tamanioAlquileres int El tamaño del array
 * \param idAlquiler int ID del juego a buscar
 * \return int Posicion del alquiler dentro del array
 *
 */
int buscarAlquiler(eAlquiler alquileres[], int tamanioAlquileres, int idAlquiler);

/** \brief Recorre el array alquileres y chequea si hay al menos
 * un alquiler activo
 *
 * \param alquileres[] eAlquileres Array de alquileres
 * \param tamanioAlquileres int El tamaño del array
 * \return int (-1) si el array esta vacio - (0) si hay al menos
 * un alquiler activo
 *
 */
int checkEmptyAlquileres(eAlquiler alquileres[], int tamanioAlquileres);

/** \brief Muestra los datos de un alquiler
 *
 * \param juegos[] eJuego Array de juegos
 * \param tamanioJuegos int El tamaño del array
 * \param clientes[] eClientes Array de clientes
 * \param tamanioJuegos int El tamaño del array
 * \param alquileres[] eAlquileres Array de alquileres
 * \param tamanioAlquileres int El tamaño del array
 * \param indiceAlquiler int La posicion del alquiler en el array
 * \return void
 *
 */
void mostrarAlquiler(eJuego juegos[], int tamaniojuegos, eCliente clientes[], int tamanioClientes, eAlquiler alquileres[], int tamanioAlquileres, int indiceAlquiler);

/** \brief Muestra los datos de todos los alquileres
 *
 * \param juegos[] eJuego Array de juegos
 * \param tamanioJuegos int El tamaño del array
 * \param clientes[] eClientes Array de clientes
 * \param tamanioJuegos int El tamaño del array
 * \param alquileres[] eAlquileres Array de alquileres
 * \param tamanioAlquileres int El tamaño del array
 * \param indiceAlquiler int La posicion del alquiler en el array
 * \return void
 *
 */
void mostrarAlquileres(eJuego juegos[], int tamaniojuegos, eCliente clientes[], int tamanioClientes, eAlquiler alquileres[], int tamanioAlquileres);

/** \brief Da de alta un nuevo alquiler
 *
 * \param juegos[] eJuego Array de juegos
 * \param tamanioJuegos int El tamaño del array
 * \param clientes[] eClientes Array de clientes
 * \param tamanioJuegos int El tamaño del array
 * \param alquileres[] eAlquileres Array de alquileres
 * \param tamanioAlquileres int El tamaño del array
 * \return void
 *
 */
void altaAlquiler(eJuego juegos[], int tamaniojuegos, eCliente clientes[], int tamanioClientes, eAlquiler alquileres[], int tamanioAlquileres);

/** \brief Da de vaja un alquiler
 *
 * \param juegos[] eJuego Array de juegos
 * \param tamanioJuegos int El tamaño del array
 * \param clientes[] eClientes Array de clientes
 * \param tamanioJuegos int El tamaño del array
 * \param alquileres[] eAlquileres Array de alquileres
 * \param tamanioAlquileres int El tamaño del array
 * \return void
 *
 */
void bajaAlquiler(eJuego juegos[], int tamaniojuegos, eCliente clientes[], int tamanioClientes, eAlquiler alquileres[], int tamanioAlquileres);

/** \brief Lista todos los alquileres
 *
 * \param juegos[] eJuego Array de juegos
 * \param tamanioJuegos int El tamaño del array
 * \param clientes[] eClientes Array de clientes
 * \param tamanioJuegos int El tamaño del array
 * \param alquileres[] eAlquileres Array de alquileres
 * \param tamanioAlquileres int El tamaño del array
 * \return void
 *
 */
void listarAlquileres(eJuego juegos[], int tamaniojuegos, eCliente clientes[], int tamanioClientes, eAlquiler alquileres[], int tamanioAlquileres);

/** \brief Menu de opciones con el alta, modificar, baja y listar de juegos
 *
 * \param juegos[] eJuego Array de juegos
 * \param tamanioJuegos int El tamaño del array
 * \param clientes[] eClientes Array de clientes
 * \param tamanioJuegos int El tamaño del array
 * \param alquileres[] eAlquileres Array de alquileres
 * \param tamanioAlquileres int El tamaño del array
 * \return void
 *
 */
void abmAlquiler(eJuego juegos[], int tamaniojuegos, eCliente clientes[], int tamanioClientes, eAlquiler alquileres[], int tamanioAlquileres);
#endif // ALQUILERES_H_INCLUDED
