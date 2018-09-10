#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void mostrarArrayChar(char vec[], int tam);
void ordenarCaracteres(char vec[], int tam, int criterio);

int main()
{
    char letras [] = {'g', 'f', 'a', 'A', 'e', 'g', 'b', 'Z'};
    int criterio;
    printf("Array desordenado.\n\n");
    printf("\t");
    mostrarArrayChar(letras, 8);
    printf("\n\nIngrese 1 para ordenar alfabeticamente, 0 para no alfabetico: ");
    criterio=getche();
    ordenarCaracteres(letras, 8, criterio);
    printf("\n\nArray ordenado.\n\n");
    printf("\t");
    mostrarArrayChar(letras, 8);
    printf("\n\n");
    return 0;
}

void mostrarArrayChar(char vec[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        printf("%c ", vec[i]);
    }
}

void ordenarCaracteres(char vec[], int tam, int criterio)
{
    char aux;
    for(int i=0; i<tam-1; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(criterio)
            {
                if(vec[i]>vec[j])
                {
                    aux=vec[i];
                    vec[i]=vec[j];
                    vec[j]=aux;
                }
            }
            else
            {
                if(vec[i]<vec[j])
                {
                    aux=vec[i];
                    vec[i]=vec[j];
                    vec[j]=aux;
                }
            }
        }
    }
}
