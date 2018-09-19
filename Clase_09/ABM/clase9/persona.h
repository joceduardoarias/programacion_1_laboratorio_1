#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

typedef struct {
    int dia, mes, anio;
}EFecha;

typedef struct {
    char apellido[31];
    char nombre[31];
    long int dni;
    int isEmpty;
    EFecha feNac;
}EPersona;

/** Menu principal
 * \return opcion ingresada
 */
int menu();

/**
 * Inicializa los isEmpty 1 = vacio / 0 = ocupado
 * @param lista el array se pasa como parametro.
 * @param tamaño de la lista
 */
void init(EPersona lista[], int len);

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona lista[], int len);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona lista[], int len, long int dni);


/**
 * Da de alta un usuario en sistema
 * @param lista el array se pasa como parametro.
 * @param tamaño del array
 */
void alta(EPersona[], int len);

/**
 * Da de baja un usuario en sistema
 * @param lista el array se pasa como parametro.
 * @param tamaño del array
 */
void baja(EPersona lista[], int len);


void mostrarPersonaDNI(EPersona lista[], int index);

void modificar(EPersona lista[], int len);

void mostrarUsuarios(EPersona lista[], int len);

void listaOrdenada(EPersona lista[], int len);

#endif // PERSONA_H_INCLUDED


