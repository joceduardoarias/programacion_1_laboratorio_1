#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* vector;
    int* aux;
    vector = (int*) malloc(sizeof(int)*5);
    if(vector == NULL)
    {
        printf("No queda espacio en memoria.\n");
    }
    else
    {
        for(int i=0; i<5; i++)
        {
            printf("Ingrese numero: ");
            scanf("%d", vector + i);
        }
        printf("\n\n");
        for(int i=0; i<5; i++)
        {
            printf("%d ", *(vector+i));
        }
    }

    aux = (int*) realloc(vector, sizeof(int)*10);
    if(aux != NULL)
    {
        vector = aux;
        for(int i=5; i<10; i++)
        {
            printf("Ingrese numero: ");
            scanf("%d", vector + i);
        }
        printf("\n");
        for(int i=0; i<10; i++)
        {
            printf("%d ", *(vector+i));
        }
    }
    else{
        printf("No hay mas lugar en memoria.\n");

    }
    printf("\n\n");


    vector = (int*) realloc(vector, sizeof(int)*7);
    printf("\n");
    for(int i=0; i<10; i++)
    {
        printf("%d ", *(vector+i));
    }

    return 0;
}
