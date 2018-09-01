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

    int flag = 0;
    float suma;
    float resta;
    float division;
    float multiplicacion;

    while(seguir == 's'){
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
                system("cls");
                printf("Se realizaron las operaciones solicitadas.\n\n");
                suma = primerOperando + segundoOperando;
                resta = primerOperando - segundoOperando;
                multiplicacion = primerOperando * segundoOperando;
                division = primerOperando / segundoOperando;
                flag = 1;
                system("pause");
                break;
            case '4':
                system("cls");
                if(primerOperando == 0 && segundoOperando == 0){
                    printf("Aun no se realiazaron operaciones.\n\n");
                }
                else{
                    printf("Resultados\n\n");
                    printf("\ta) El resultado de %.2f+%.2f es: %.2f\n", primerOperando, segundoOperando, suma);
                    printf("\tb) El resultado de %.2f-%.2f es: %.2f\n", primerOperando, segundoOperando, resta);
                    printf("\tc) El resultado de %.2f/%.2f es: %.2f o No es posible dividir por cero\n", primerOperando, segundoOperando, division);
                    printf("\td) El resultado de %.2f*%.2f es: %.2f\n", primerOperando, segundoOperando, multiplicacion);
                    printf("\te) El factorial de A es: r1 y El factorial de B es: r2\n\n");
                }
                system("pause");
                break;
            case '5':
                seguir = 'n';
                break;
        }

    }

    return 0;
}
