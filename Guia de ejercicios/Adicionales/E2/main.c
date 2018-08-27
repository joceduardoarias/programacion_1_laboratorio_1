#include <stdio.h>
#include <stdlib.h>

//Escribir el programa necesario para calcular la suma de dos números. Mostrar el resultado
int main()
{
    int num1, num2;
    int suma;
    printf("Ingrese el primer numero: ");
    scanf("%d", &num1);
    printf("Ingrese el segundo numero: ");
    scanf("%d", &num2);
    suma = num1 + num2;
    printf("\nLa suma entre %d y %d es %d\n", num1, num2, suma);
    return 0;
}
