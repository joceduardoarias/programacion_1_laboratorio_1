#include <stdio.h>
#include <stdlib.h>

int main()
{

int* pNumero;

pNumero = (int*)  malloc(sizeof(int));

    if(pNumero == NULL)
    {

        printf("No hay espacio en memoria.");

    }

    *pNumero = 25;

    printf("%d",*pNumero);

    free(pNumero);


    return 0;
}
