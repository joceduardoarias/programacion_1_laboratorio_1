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


void hardcodeoClientes(eCliente clientes[]);
int iniciarEstadosClientes(eCliente clientes [], int tamanioClientes);
int getNextIdCliente(eCliente clientes[],int tamanioClientes);
int buscarClienteLibre(eCliente clientes[], int tamanioClientes);
int buscarCliente(eCliente clientes[], int tamanioClientes, int idCliente);
void cargarNombre(eCliente clientes[], int tamanioClientes, int idCliente, char cadena[]);
int checkEmptyClientes(eCliente clientes[], int tamanioClientes);
void mostrarCliente(eCliente clientes);
void mostrarClientes(eCliente clientes[], int tamanioClientes);
void altaClientes(eCliente clientes[], int tamanioClientes);
void bajaCliente(eCliente clientes[], int tamanioClientes);
void listarClientes(eCliente clientes[], int tamanioClientes);
void abmClientes(eCliente clientes[], int tamanioClientes);
#endif // CLIENTES_H_INCLUDED
