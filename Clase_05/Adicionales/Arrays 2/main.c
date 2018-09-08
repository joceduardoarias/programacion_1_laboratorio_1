#include <stdio.h>
#include <stdlib.h>
#define TAM 10

void mostrarVector(int x[], int tam);
int validarRango(char mensaje[], char mensajeError[], int limInf, int limSup);

int main()
{
    int vector [TAM] = {0};
    char seguir;
    int indice;
    int numero;
    do
    {
        printf("Ingrese un numero: ");
        scanf("%d", &numero);
        indice = validarRango("Ingrese el indice donde desea guardarlo: ", "Error al ingresar indice", 0, 9);
        vector[indice]=numero;
        fflush(stdin);
        printf("\nDesea continuar agregando numeros? (s/n): ");
        scanf("%c", &seguir);
        system("cls");
    }
    while(seguir=='s');
    mostrarVector(vector, TAM);
    printf("\n\n");
    return 0;
}

void mostrarVector(int x[], int tam)
{
    printf("Ingreso: ");
    for(int i=0; i<tam; i++)
    {
        printf("%d ", x[i]);
    }
}

int validarRango(char mensaje[], char mensajeError[], int limInf, int limSup)
{
    int numero;
    printf("%s", mensaje);
    scanf("%d", &numero);
    while(numero<limInf || numero>limSup)
    {
        printf("\n%s", mensajeError);
        printf("\n\n%s", mensaje);
        scanf("%d", &numero);
    }
    return numero;
}
