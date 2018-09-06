#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "funciones.h"

int main()
{
    float primerOperando = 0;
    float segundoOperando = 0;
    int opcion;
    char seguir='s';

    int flagA = 0;
    int flagB = 0;
    int flagC = 0;
    float resultadoSuma;
    float resultadoResta;
    float resultadoDivision;
    float resultadoMultiplicacion;

    do
    {
        system("cls");
        printf("1. Ingresar 1er operando (A=%.2f)\n", primerOperando);
        printf("2. Ingresar 2do operando (B=%.2f)\n", segundoOperando);
        printf("3. Calcular todas las operaciones\n");
        printf("\ta) Calcular la suma (A+B)\n");
        printf("\tb) Calcular la resta (A-B)\n");
        printf("\tc) Calcular la division (A/B)\n");
        printf("\td) Calcular la multiplicacion (A*B)\n");
        printf("\te) Calcular el factorial (A!)\n");
        printf("4. Informar resultados\n");
        printf("5. Salir\n\n");
        printf("%d   %d   %d\n", flagA, flagB, flagC);
        printf("Ingrese una opcion: ");
        opcion = getche();

        switch(opcion)
        {
        case '1':
            printf("\n\nIngrese primer operando: ");
            scanf("%f", &primerOperando);
            flagA = 1;
            system("cls");
            break;
        case '2':
            printf("\n\nIngrese segundo operando: ");
            scanf("%f", &segundoOperando);
            flagB = 1;
            system("cls");
            break;
        case '3':
            system("cls");
            if(flagA==1 && flagB==1)
            {
                flagC = 1;
                resultadoSuma = suma(primerOperando, segundoOperando);
                resultadoResta = resta(primerOperando, segundoOperando);
                resultadoDivision = division(primerOperando, segundoOperando);
                resultadoMultiplicacion = multiplicacion(primerOperando, segundoOperando);

                printf("Se realizaron las operaciones solicitadas.\n\n");
            }
            else
            {
                printf("Aun no se han ingresado operandos.\n\n");
            }
            system("pause");
            system("cls");
            break;
        case '4':
            system("cls");
            if(flagA==1 && flagB==1 && flagC==1)
            {
                printf("Resultados\n\n");
                printf("\ta) El resultado de %.2f + %.2f es: %.2f\n", primerOperando, segundoOperando, resultadoSuma);
                printf("\tb) El resultado de %.2f - %.2f es: %.2f\n", primerOperando, segundoOperando, resultadoResta);
                printf("\tc) El resultado de %.2f / %.2f es: %.2f o No es posible dividir por cero\n", primerOperando, segundoOperando, division);
                printf("\td) El resultado de %.2f * %.2f es: %.2f\n", primerOperando, segundoOperando, resultadoMultiplicacion);
                printf("\te) El factorial de A es: r1 y El factorial de B es: r2\n\n");
            }
            else
            {
                printf("Aun no se realiazaron operaciones.\n\n");
            }
            system("pause");
            break;
        case '5':
            seguir = 'n';
            break;
        default:
            printf("\nUsted ingreso una opcion incorrecta, reinente.\n\n");
            system("pause");
        }
    }
    while(seguir == 's');
    return 0;
}
