#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* f;
    char texto[50]="Los pelos verdes de agustin";

    f=fopen("miHTML.html","w");

    /*fprintf(f,"<html><body><h1>");
    fprintf(f,"%s",texto);
     fprintf(f,"</h1></body></html>");*/

     fprintf(f,"<html><body><h1></h1> %s </body></html>",texto); /** otra forma */




    fclose(f);



    return 0;
}
