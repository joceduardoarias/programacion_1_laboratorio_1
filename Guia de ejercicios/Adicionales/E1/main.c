#include <stdio.h>
#include <stdlib.h>

//Ingresar 5 numeros y calcular su media
int main()
{
    int i;
    int suma=0;
    float promedio;
    for(i=0; i<5; i++){
        int aux;
        printf("Ingrese numero: ");
        scanf("%d", &aux);
        suma=suma+aux;
        fflush(stdin);
    }
    promedio = (float) suma/5; // lo casteo para que me tome la parte decimal
    printf("\nLa suma de los 5 numeros es %d y su promedio es %.2f\n", suma, promedio);

    return 0;
}
