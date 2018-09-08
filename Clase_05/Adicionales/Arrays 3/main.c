#include <stdio.h>
#include <stdlib.h>
#define TAM 5

int buscarMayor(int x[], int tam);

int main()
{
    int valor;
    int vector [TAM] = {5,100,9,30,2};
    valor = buscarMayor(vector, TAM);
    printf("El numero mayor es: %d\n\n", valor);
    return 0;
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
