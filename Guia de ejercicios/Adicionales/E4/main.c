#include <stdio.h>
#include <stdlib.h>

/*  Escribir un programa que realice las siguientes acciones:
- Limpie la pantalla
- Declare 2 variables y les asigne sendos valores
- Realice la resta de dichas variables y muestre por pantalla la leyenda "Resultado positivo" en caso de
ser mayor que cero o "Resultado negativo" si es menor que cero  */

int main()
{
    system("cls");
    int numero1, numero2;
    int resta;
    printf("Ingrese el primer numero: ");
    scanf("%d", &numero1);
    printf("Ingrese el segundo numero: ");
    scanf("%d", &numero2);
    resta = numero1 - numero2;
    if(resta>0){
        printf("\nResultado positivo.");
    }
    else{
        printf("\nResultado negativo.");
    }
    return 0;
}
