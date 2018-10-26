#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int escribirTexto(char *);// recibe como parametro eltexto a escribir en el archivo
int leerTexto(char*);

int main()
{

int r;
char txt[100];

r=escribirTexto("hola a todos\nChau a todos!");
if(r)
{
    printf("Guardo con exito!");
}
else{
    printf("No se pudo abrir!");
}


/*
r=leerTexto(txt);
if(r)
{
    printf("%s",txt);
}
else{
    printf("Imposible leer");
}
*/
    return 0;
}

int escribirTexto(char* texto)
{
   FILE* pA;//puntero archivo ->representa el archivo en memoria , va a saber donde estaque hace
   int retorno=0;
   pA=fopen("archivoTXT.txt","w");//Devuelve puntero a file es decir al lugar donde lo guardamos, o null

  if(pA!=NULL)//Es porque pudo abrirlo
  {
    fprintf(pA,"%s",texto); // Para cargar datos
    fclose(pA);

    retorno=1;
  }
return retorno;
}

int leerTexto(char* texto )
{
    FILE * pA;
    char t[100];
    strcpy(texto,"");

    int retorno=0;

    pA=fopen("archivoTXT.txt","r");

    if(pA!=NULL)
    {
        while(!feof(pA))//verificamos que no llegue al final del archivo con "find end of file"
        {
         fgets(texto,50,pA);//recibe puntero a char es decir lugar a guardar, entero que representa cantidad de caracteres y file lee string desde consola
         strcat(texto,t);
        }

        fclose(pA);
        retorno=1;
    }

    return retorno;
}
