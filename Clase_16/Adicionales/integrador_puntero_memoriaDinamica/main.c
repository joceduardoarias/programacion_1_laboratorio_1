#include <stdio.h>
#include <stdlib.h>
struct persona
{
    char nombre[50];
    int edad;
};
int main()
{
    int seguirCargando;
    int i;
    int auxNuevaLogitud;
    int logitudPersonas = 1; // tiene que valer uno para que no pise la sigiente iteracion, pues esta es
                            //  es la posicion del la primera persona cargada
    struct persona* pArrayPersona;
    struct persona* pAuxPersona;
// Creamos el array de personas
    pArrayPersona = (struct persona* )malloc(sizeof(struct persona));
    if (pArrayPersona == NULL)
    {
        printf("\nNo hay lugar en memoria\n");
        exit(0);
    }
    while(1)
    {
        printf("\nIngrese nombre: ");
        scanf("%s",(pArrayPersona+logitudPersonas-1)->nombre);
        printf("\nIngrese edad: ");
        scanf("%d",&((pArrayPersona+logitudPersonas-1)->edad));
        printf("\nSi desea cargar otra persona ingrese (1): ");
        scanf("%d",&seguirCargando);
        if(seguirCargando == 1)
        {
            logitudPersonas++; //Incremento el contador de personas
            //a medida que aumenta el contador aumento quiere decir que es una nueva persona por ende
            // otra casilla mas del array. !!! no confundir con el indice!!!
// Calculamos el nuevo tamaño del array
            auxNuevaLogitud = sizeof(struct persona) * logitudPersonas;
// Redimencionamos la lista
            pAuxPersona = (struct persona*)realloc( pArrayPersona, auxNuevaLogitud);
            if (pAuxPersona == NULL)
            {
                printf("\nNo hay lugar en memoria\n");
                break;
            }

            pArrayPersona = pAuxPersona;
        }
        else
        {
            break;
        }
    }
    for(i = 0; i < logitudPersonas; i++)
    {
        printf("\nNombre: %s - ",(pArrayPersona+i)->nombre);
        printf("Edad: %d",(pArrayPersona+i)->edad);
    }
    free(pArrayPersona); // Liberamos la memoria
    return 0;
}
