#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num = 5; //declaro variable int
    int *ptr; // declaro puntero ptr

    ptr = &num; //asigno direccion de memoria de num a ptr
    *ptr = 13; //con el operador de indireccion voy a la direccion de memoria que almacena ptr
               //y modifico el dato que tiene esa direccion, en este caso vamos a la direccion de memoria
               //num y modificamos 5 por 13
    printf("Num: %d", num);
    printf("\nPtr: %d", *ptr);

    printf("\n\n");
    return 0;
}
