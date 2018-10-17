#include <stdio.h>
#include <stdlib.h>

int main()
{
    char cad[10], *ptrCad;
    printf("Ingrese dato: ");
    fflush(stdin);
    scanf("%s", cad);
    printf("\n%s", cad);

    ptrCad = cad;
    return 0;
}
