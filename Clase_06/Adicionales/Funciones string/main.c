#include <stdio.h>
#include <stdlib.h>

int main()
{
    char nombre[20]= {"ana"};
    char apellido[20] = {"aerez"};
    char nombreCompleto[40];

    strcpy(nombreCompleto, nombre);
    strcat(nombreCompleto, " ");
    strcat(nombreCompleto, apellido);
    printf("%s\n", nombreCompleto);

    strlwr(nombre);
    printf("%s\n\n", nombre);

    char nombre[20]= {"juAn carlos aLBerto"};
        int largo = strlen(nombre);
       strlwr(nombre);

       for(int i=0; i <= largo; i++){

        if(nombre[i] == ' '){
            nombre[i+1] = toupper(nombre[i+1]);
        }

       }

       nombre[0] = toupper(nombre[0]);





    printf("%s\n\n", nombre);

    return 0;
}
