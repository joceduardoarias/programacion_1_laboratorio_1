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
    printf("\nDireccion memoria Ptr: %p", ptr); // Con '%p' obtengo la direccion de memoria que tiene asignada la variable 'p'

    printf("\n\n\n");

    int *a;
    int b,c;
    b = 15; // Asignamos el valor 15 a la variable 'b'
    a = &b; // Obtenemos la posición de memoria de 'b' con el operador '&'
    c = *a; // Asignamos el valor 15 a la variable 'c' por indireccion con el operador '*'
    printf("Num c: %d", c);

    printf("\n\n\n");

    printf("\nComparacion entre punteros: \n");
    int* punteroA;
    int* punteroB;
    int auxiliarC, auxiliarD;
    punteroA = &auxiliarC; // Obtenemos la posición de memoria de 'auxiliarC'
    punteroB = &auxiliarD; // Obtenemos la posición de memoria de 'auxiliarD'
    if (punteroA<punteroB)
        printf("El punteroA apunta a una direccion mas baja que punteroB");
    else if (punteroA>punteroB)
        printf("El punteroB apunta a una direccion mas baja que punteroA");
    /*
    PUEDO HACER 4 COMPARACIONES ENTRE PUNTEROS
    if(punteroA == punteroB);
    if(puntero != NULL);
    if(punteroA > punteroB);
    if(punteroA == 0XAAFF); //COMPARO PUNTERO CON UNA DIRECCION DE MEMORIA
    */

    printf("\n\n\n");

    printf("Operador binario 'sizeof'\n\n");
    printf("Tamanio de char: %d",  sizeof(char));
    printf("\nTamanio de int: %d",  sizeof(int));

    printf("\n\n\n");



    return 0;
}
