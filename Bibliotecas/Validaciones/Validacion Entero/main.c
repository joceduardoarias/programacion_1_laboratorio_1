#include <stdio.h>
#include <stdlib.h>
#include "Alegria.h"

int main()
{
    int numero;
    numero = validarRango("Ingrese edad: ", "Edad incorrecta, reintente.", 18, 65);
    printf("\nSu edad esta validada.\n");
    return 0;
}
