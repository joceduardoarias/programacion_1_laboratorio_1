#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

typedef struct
{
    int idCliente;
    char apellido[51];
    char nombre[51];
    char sexo;
    char domicilio[30];
    int isEmpty;
} eCliente;

/** \brief Inicializa el array de clientes
 *
 * \param clientes[] eCliente Array de clientes
 * \return void
 *
 */

void hardcodeoClientes(eCliente clientes[]);

/** \brief Inicializa todas las banderas isEmpty en (VACIO - 1)
 *
 * \param clientes[] eClientes Array de clientes
 * \param tamanioClientes int El tamaño del array
 * \return void
 *
 */
int iniciarEstadosClientes(eCliente clientes [], int tamanioClientes);

/** \brief Recorre el array clientes y acumula los empleados activos y eliminados
 *
 * \param clientes[] eCliente Array de clientes
 * \param tamanioClientes int El tamaño del array
 * \return int (0) si aun no hay empleados actuvos o eliminados -
 * (flag) la posicion libre en el array
 *
 */
int getNextIdCliente(eCliente clientes[],int tamanioClientes);

/** \brief Busca la primer posicion libre en el array
 *
 * \param clientes[] eCliente Array de clientes
 * \param tamanioClientes int El tamaño del array
 * \return int La posicion libre
 *
 */
int buscarClienteLibre(eCliente clientes[], int tamanioClientes);

/** \brief Recorre el array clientes y busca un cliente con el idCliente
 *
 * \param clientes[] eClientes Array de clientes
 * \param tamanioJuegos int El tamaño del array
 * \param idCliente int ID del cliente a buscar
 * \return int Posicion del cliente dentro del array
 *
 */
int buscarCliente(eCliente clientes[], int tamanioClientes, int idCliente);

/** \brief Carga el nombre de un cliente ingresando su id
 *
 * \param clientes[] eClientes Array de clientes
 * \param tamanioJuegos int El tamaño del array
 * \param idCliente int El identificador del cliente dentro del array
 * \param cadena[] char Donde se almacenara el nombre por referencia
 * \return void
 *
 */
void cargarNombre(eCliente clientes[], int tamanioClientes, int idCliente, char cadena[]);

/** \brief Recorre el array clientes y chequea si hay al menos
 * un cliente activo
 *
 * \param clientes[] eClientes Array de clientes
 * \param tamanioJuegos int El tamaño del array
 * \return int (-1) si el array esta vacio - (0) si hay al menos
 * un cliente activo
 *
 */
int checkEmptyClientes(eCliente clientes[], int tamanioClientes);

/** \brief Muestra los datos de un cliente
 *
 * \param clientes[] eClientes Array de cliente
 * \return void
 *
 */
void mostrarCliente(eCliente clientes);

/** \brief Muestra los datos de todos los clientes activos
 *
 * \param clientes[] eClientes Array de clientes
 * \param tamanioJuegos int El tamaño del array
 * \return void
 *
 */
void mostrarClientes(eCliente clientes[], int tamanioClientes);

/** \brief Recorre el array acumula todos los clientes activos
 *
 * \param clientes[] eClientes Array de clientes
 * \param tamanioJuegos int El tamaño del array
 * \return int La cantidad de clientes activos
 *
 */
int clientesActivos(eCliente clientes[], int tamanioClientes);

/** \brief Da de alta un nuevo cliente en sistema
 *
 * \param clientes[] eClientes Array de clientes
 * \param tamanioJuegos int El tamaño del array
 * \return void
 *
 */
void altaClientes(eCliente clientes[], int tamanioClientes);

/** \brief modifica los datos de un cliente
 *
 * \param clientes[] eClientes Array de clientes
 * \param tamanioJuegos int El tamaño del array
 * \return void
 *
 */
void modificarCliente(eCliente clientes[], int tamanioClientes);

/** \brief Da de baja un cliente en sistema
 *
 * \param clientes[] eClientes Array de clientes
 * \param tamanioJuegos int El tamaño del array
 * \return void
 *
 */
void bajaCliente(eCliente clientes[], int tamanioClientes);

/** \brief Lista los datos de todos los clientes
 *
 * \param clientes[] eClientes Array de clientes
 * \param tamanioJuegos int El tamaño del array
 * \return void
 *
 */
void listarClientes(eCliente clientes[], int tamanioClientes);
void abmClientes(eCliente clientes[], int tamanioClientes);
#endif // CLIENTES_H_INCLUDED
