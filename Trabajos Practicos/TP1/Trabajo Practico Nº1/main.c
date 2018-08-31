#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int menu();

int main()
{
    float primerOperando = 0;
    float segundoOperando = 0;
    int opcion;
    char seguir='s';

    float suma;
    float resta;
    float division;
    float multiplicacion;

    while(seguir == 's'){
        printf("1. Ingresar 1er operando (A=%.2f)\n", primerOperando);
        printf("2. Ingresar 2do operando (B=%.2f)\n", segundoOperando);
        printf("3. Calcular todas las operaciones\n");
        printf("\ta) Calcular la suma (A+B)\n");
        printf("\tb) Calcular la resta (A-B)\n");
        printf("\tc) Calcular la division (A/B)\n");
        printf("\td) Calcular la multiplicacion (A*B)\n");
        printf("\te) Calcular el factorial (A!)\n");
        printf("4. Informar resultados\n");
        printf("\ta) El resultado de A+B es: r\n");
        printf("\tb) El resultado de A-B es: r\n");
        printf("\tc) El resultado de A/B es: r” o “No es posible dividir por cero”\n");
        printf("\td) El resultado de A*B es: r”\n");
        printf("\te) El factorial de A es: r1 y El factorial de B es: r2”\n");
        printf("5. Salir\n\n");
        printf("Ingrese una opcion: ");
        opcion = getche();
        switch(opcion)
        {
            case '1':
                printf("\n\nIngrese primer operando: ");
                scanf("%f", &primerOperando);
                system("cls");
                break;
            case '2':
                printf("\n\nIngrese segundo operando: ");
                scanf("%f", &segundoOperando);
                system("cls");
                break;
            case '3':
                suma = primerOperando + segundoOperando;
                resta = primerOperando - segundoOperando;
                multiplicacion = primerOperando * segundoOperando;
                division = primerOperando / segundoOperando;
                break;
        }

    }

    return 0;
}
