#include <stdio.h>
#include <stdlib.h>

/*  Escribir un programa que realice las siguientes acciones
- Limpie la pantalla
- Asigne a 2 variables numero1 y numero2 valores distintos de cero
- Efectúe el producto de dichas variables
- Muestre el resultado pos pantalla
- Obtenga el cuadrado de numero1 y lo muestre por pantalla  */

int main()
{
    system("cls");
    int numero1, numero2;
    printf("Ingrese el primer numero: ");
    scanf("%d", &numero1);
    printf("Ingrese el segundo numero: ");
    scanf("%d", &numero2);
    int producto, cuadrado;
    producto = numero1 * numero2;
    printf("\nEl producto entre %d y %d es %d", numero1, numero2, producto);
    cuadrado = numero1*numero1;
    printf("\nEl cuadrado de %d es %d\n",numero1, cuadrado);
    return 0;
}
