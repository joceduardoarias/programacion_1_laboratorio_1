#ifndef JUEGOS_H_INCLUDED
#define JUEGOS_H_INCLUDED

typedef struct
{
    int idJuego;
    char descripcion[51];
    float importe;
    int isEmpty;

} eJuego;

int menu();
int menuABMJuegos();
void hardcodeoJuegos(eJuego juegos[]);
int getNextId(eJuego juegos[],int tamanioJuegos);
int iniciarEstadosJuegos(eJuego juegos [], int tamanioJuegos);
int buscarJuegoLibre(eJuego juegos[], int tamanioJuegos);
int buscarJuego(eJuego juegos[], int tamanioJuegos, int idJuego);
void altaJuego(eJuego juegos[], int tamaniojuegos);
void abmJuegos(eJuego juegos[], int tamanioJuegos);

#endif // JUEGOS_H_INCLUDED
