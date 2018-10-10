#ifndef JUEGOS_H_INCLUDED
#define JUEGOS_H_INCLUDED

typedef struct
{
    int idJuego;
    char descripcion[51];
    float importe;
    int isEmpty;

} eJuego;

/** \brief Menu principal
 *
 * \return int La opcion elegida por el usuario
 *
 */
int menu();


/** \brief Menu secundario - ABM
 *
 * \param mensaje[] char El mensaje a reemplazar en el menu
 * \return int La opcion elegida por el usuario
 *
 */
int menuABM(char mensaje[]);

/** \brief Inicializa el array de juegos
 *
 * \param juegos[] eJuego Array de juegos
 * \return void
 *
 */
void hardcodeoJuegos(eJuego juegos[]);

/** \brief Recorre el array juegos y chequea si hay al menos
 * un juego activo
 *
 * \param juegos[] eJuego Array de juegos
 * \param tamanioJuegos int El tamaño del array
 * \return int (-1) si el array esta vacio - (0) si hay al menos
 * un juego activo
 *
 */
int checkEmptyJuegos(eJuego juegos[], int tamanioJuegos);

/** \brief Recorre el array juegos y acumula los juegos activos y eliminados
 *
 * \param juegos[] eJuego Array de juegos
 * \param tamanioJuegos int El tamaño del array
 * \return int (0) si aun no hay juegos activos o eliminados -
 * (flag) la posicion libre en el array
 *
 */
int getNextId(eJuego juegos[],int tamanioJuegos);


/** \brief Inicializa todas las banderas isEmpty en (VACIO - 1)
 *
 * \param juegos[] eJuego Array de juegos
 * \param tamanioJuegos int El tamaño del array
 * \return void
 *
 */
void iniciarEstadosJuegos(eJuego juegos [], int tamanioJuegos);

/** \brief Muestra los datos de un juego
 *
 * \param juegos[] eJuego Array de juegos
 * \return void
 *
 */
void mostrarJuego(eJuego juegos);

/** \brief Muestra los datos de todos los juegos activos
 *
 * \param juegos[] eJuego Array de juegos
 * \param tamanioJuegos int El tamaño del array
 * \return void
 *
 */
void mostrarJuegos(eJuego juegos[], int tamanioJuegos);

/** \brief Busca la primer posicion libre en el array
 *
 * \param juegos[] eJuego Array de juegos
 * \param tamanioJuegos int El tamaño del array
 * \return int La posicion libre
 *
 */
int buscarJuegoLibre(eJuego juegos[], int tamanioJuegos);

/** \brief Recorre el array juegos y busca un juego con el idJuego
 *
 * \param juegos[] eJuego Array de juegos
 * \param tamanioJuegos int El tamaño del array
 * \param idJuego int ID del juego a buscar
 * \return int Posicion del juego dentro del array
 *
 */
int buscarJuego(eJuego juegos[], int tamanioJuegos, int idJuego);


/** \brief Recorre el array acumula todos los juegos activos
 *
 * \param juegos[] eJuego Array de juegos
 * \param tamanioJuegos int El tamaño del array
 * \return int La cantidad de juegos activos
 *
 */
int juegosActivos(eJuego juegos[], int tamanioJuegos);

/** \brief Da de alta un nuevo juego en sistema
 *
 * \param juegos[] eJuego Array de juegos
 * \param tamanioJuegos int El tamaño del array
 * \return void
 *
 */
void altaJuego(eJuego juegos[], int tamaniojuegos);

/** \brief Modifica los datos de un juego
 *
 * \param juegos[] eJuego Array de juegos
 * \param tamanioJuegos int El tamaño del array
 * \return void
 *
 */
void modificarJuego(eJuego juegos[], int tamanioJuegos);

/** \brief Carga la descripcion de un juego ingresando su id
 *
 * \param juegos[] eJuego Array de juegos
 * \param tamanioJuegos int El tamaño del array
 * \param idJuego int El identificador del juego dentro del array
 * \param cadena[] char Donde se almacenara la descripcion por referencia
 * \return void
 *
 */
void cargarDescripcion(eJuego juegos[], int tamanioJuegos, int idJuego, char cadena[]);

/** \brief Se da de baja un juego en sistema
 *
 * \param juegos[] eJuego Array de juegos
 * \param tamanioJuegos int El tamaño del array
 * \return void
 *
 */
void bajaJuego(eJuego juegos[], int tamaniojuegos);

/** \brief Lista todos los juegos
 *
 * \param juegos[] eJuego Array de juegos
 * \param tamanioJuegos int El tamaño del array
 * \return void
 *
 */
void listarJuegos(eJuego juegos[], int tamanioJuegos);

/** \brief Menu de opciones con el alta, modificar, baja y listar de juegos
 *
 * \param juegos[] eJuego Array de juegos
 * \param tamanioJuegos int El tamaño del array
 * \return void
 *
 */
void abmJuegos(eJuego juegos[], int tamanioJuegos);

#endif // JUEGOS_H_INCLUDED
