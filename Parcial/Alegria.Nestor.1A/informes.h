#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

int menuInformes();
void abmInformes(eJuego juegos[], int tamaniojuegos, eCliente clientes[], int tamanioClientes, eAlquiler alquileres[], int tamanioAlquileres);

//Punto1 y 2
float totalImportes(eJuego juegos[], int tamanioJuegos);
float promedioJuegos(eJuego juegos[], int tamanioJuegos, float totalImportes);
void promedioYTotalImportes(eJuego juegos[], int tamanioJuegos);
int juegosNoSuperanPromedio(eJuego juegos[], int tamanioJuegos, int promedio);
void cantidadJuegosNoSuperanPromedio(eJuego juegos[], int tamanioJuegos);
//Fin punto 1 y dos

void listarClientesPorJuego(eJuego juegos[], int tamaniojuegos, eCliente clientes[], int tamanioClientes, eAlquiler alquileres[], int tamanioAlquileres);
int elegirCliente(eCliente clientes[], int tamanioClientes);
int elegirJuego(eJuego juegos[], int tamanioJuegos);

void listarJuegosImporte(eJuego juegos[], int tamaniojuegos);
void listarClientesApellidos(eCliente clientes[], int tamanioClientes);




#endif // INFORMES_H_INCLUDED
