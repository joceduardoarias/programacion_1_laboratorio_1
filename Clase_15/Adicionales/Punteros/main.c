#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Punteros inicializar y asignar  -->\n\n");
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
    printf("Valor B: %d", b);
    printf("\nValor A: %d", *a);
    printf("\nNum c: %d", c);
    printf("\n<------------------");
    printf("\n\n\n");

    printf("Comparacion entre punteros: -->\n");
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
    printf("\n<------------------");
    printf("\n\n\n");

    printf("Operador binario 'sizeof' -->\n\n");
    printf("Tamanio de char: %d",  sizeof(char));
    printf("\nTamanio de int: %d",  sizeof(int));
    printf("\n<------------------");

    printf("\n\n\n");

    printf("Vectores y punteros -->\n\n");
    int vec[5];
    int *p;
    p = vec;
    printf("Asigno con Vector.\n");
    for(int i=0; i<5; i++){//asigno
        vec[i] = i+3;
    }
    for(int i=0; i<5; i++){//imprimo
        printf("%d ", vec[i]);
    }
    printf("\n\nAsigno con Puntero.\n");
    for(int i=0; i<5; i++){//asigno
        *(p+i) = i+5;
    }
    for(int i=0; i<5; i++){//imprimo
        printf("%d ", *(p+i));
    }
    printf("\n<------------------");

    printf("\n\n\n");

    printf("Puntero a puntero -->\n\n");
    int j=5;
    int *punteroInt;
    int **punteroPuntero;

    punteroInt = &j; // Obtenemos la posición de memoria
    punteroPuntero = &punteroInt; // Obtenemos la posición de memoria

    printf("Direccion de memoria j: %p", &j);
    printf("\nDato de j: %d", j);

    printf("\n\nDireccion de memoria punteroInt: %p", punteroInt);
    printf("\nDato de punteroInt: %d", *punteroInt);

    printf("\n\nDireccion de memoria punteroPuntero: %p", *punteroPuntero);
    printf("\nDato de punteroPuntero: %d", *punteroPuntero);
    printf("\n<------------------");

    printf("\n\n");
    return 0;
}
