#include <stdio.h>
#include <stdlib.h>

/** \brief Valida un entero
 *
 * \param mensaje, mensaje para solicitar dato
 * \param mensajeError, mensaje en caso de no validar dato
 * \param limInf, entero limite inferior a validar
 * \param limSup, entero limite superior a validad
 * \return edad, entero validado
 *
 */

//Obtener un numero entero validado en un rango
int validarRango(char mensaje[], char mensajeError[], int limInf, int limSup);

int main()
{
    int numero;
    numero = validarRango("Ingrese edad: ", "Edad incorrecta, reintente.", 18, 65);
    printf("\nSu edad esta validada.\n");
    return 0;
}

int validarRango(char mensaje[], char mensajeError[], int limInf, int limSup){
    int edad;
    printf("%s", mensaje);
    scanf("%d", &edad);
    while(edad<limInf || edad>limSup){
        printf("\n%s", mensajeError);
        printf("\n\n%s", mensaje);
        scanf("%d", &edad);
    }
    return edad;
}
