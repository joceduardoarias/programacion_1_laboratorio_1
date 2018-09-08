#include <stdio.h>
#include <stdlib.h>
#define TAM 5

int buscarNumero(int x[], int tam, int valor);
int buscarMayor(int x[], int tam);
void mostrarVector(int x[], int tam);

int main()
{
    int valor;
    int indice;
    int vector [TAM] = {5,10,9,300,2};
    valor = buscarMayor(vector, TAM);
    indice = buscarNumero(vector, TAM, valor);
    mostrarVector(vector, TAM);
    printf("\n\nEl numero mayor es: %d y esta en el indice %d\n\n", valor, indice);
    return 0;
}

int buscarNumero(int x[], int tam, int valor)
{
    int indice = -1;
    for(int i = 0; i<tam; i++){
        if(valor == x[i]){
            indice=i;
        }
    }
    return indice;
}


int buscarMayor(int x[], int tam)
{
    int mayor=0;
    for(int i=0; i<tam; i++){
        if(x[i]>mayor){
            mayor=x[i];
        }
    }
    return mayor;
}

void mostrarVector(int x[], int tam)
{
    printf("Vector: ");
    for(int i=0; i<tam; i++)
    {
        printf("%d ", x[i]);
    }
}
