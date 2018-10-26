#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "set-get.h"
int main()
{
    eDato dato;
    eDato* d;

    d=&dato;

   // d->a=7;
   eDato_set_a(d,1800);

    //strcpy(d->b,"hola");
   eDato_set_b(d,"hola");

    printf("%d--%s",eDato_get_a(d),eDato_get_b(d));

    return 0;
}




