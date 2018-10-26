#include "set-get.h"
#include <stdio.h>
#include <string.h>
int eDato_set_a(eDato* dato ,int valor)
/** setie el valor cuando el valor sea mayor a 1500*/
{
    int retorno=0;
    if(dato!=NULL&&valor>1500)
      {
            dato->a=valor;
            retorno=1;
      }
      return retorno;
}

int eDato_set_b(eDato* dato ,char* valor)
/** setie el valor cuando el valor sea mayor a 1500*/
{
    int retorno=0;
    if(dato!=NULL&&valor!=NULL)
      {
          strcpy(dato->b,valor);
          retorno=1;
      }
      return retorno;
}

int eDato_get_a(eDato* dato)
{
int valor;

if(dato!=NULL)
{
    valor=dato->a;
}
return valor;
}

char* eDato_get_b(eDato* dato)
{
    //char valor[50];
    char* valor;
    if(dato!=NULL)
    {
       // strcpy(valor,dato->b);
       valor=dato->b;
    }
return valor; //devuelve la direccion de memoria
}

