#include <stdio.h>
#include <stdlib.h>
#define TAM 5

int main()
{
    int numeros[TAM];
    int i;
    int j;
    for(i=0; i<5; i++){
        printf("Ingrese un numero: ");
        scanf("%d", &numeros[i]);
    }
    printf("\nUsted ingreso: ");
    for(i=0; i<TAM; i++){
        printf("%d ", numeros[i]);
    }
    for(i=0; i<TAM-1; i++){
        for(j=i+1; j<TAM; j++){

            if(numeros[i]>numeros[j]){
                int aux;
                aux=numeros[i];
                numeros[i]=numeros[j];
                numeros[j]=aux;
            }
        }
    }
    printf("\nUsted ingreso: ");
    for(i=0; i<TAM; i++){
        printf("%d ", numeros[i]);
    }
    return 0;
}
