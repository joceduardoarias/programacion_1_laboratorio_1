#include <stdio.h>
#include <stdlib.h>
#include "Alegria.h"

int validarRango(char mensaje[], char mensajeError[], int limiteInferior, int limiteSuperior){
    printf("%s", mensaje);
    scanf("%d", &edad);
    while(edad<limInf || edad>limSup){
        printf("\n%s", mensajeError);
        printf("\n\n%s", mensaje);
        scanf("%d", &edad);
    }
    return edad;
}

