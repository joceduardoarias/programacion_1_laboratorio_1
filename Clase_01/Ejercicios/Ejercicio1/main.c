#include <stdio.h>
#include <stdlib.h>

//Ingresar 3 numeros y decir cual es el mayor y menor de los 3.

int main()
{
    //Declaro variables
    int nro1, nro2, nro3, mayor, menor;
    //Ingreso variables
    printf("Ingrese: ");
    scanf("%d", &nro1);
    printf("\nIngrese: ");
    scanf("%d", &nro2);
    printf("\nIngrese: ");
    scanf("%d", &nro3);
    /*//Mayor -->
    if(nro1>nro2 && nro1>nro3){
        mayor = nro1;
    }
    else{
        if(nro2>nro1 && nro2>nro3){
            mayor = nro2;
        }
        else{
            mayor = nro3;
        }
    }
    //<-- Fin mayor
    //Menor -->
    if(nro1<nro2 && nro1<nro3){
        menor = nro1;
    }
    else{
        if(nro2<nro1 && nro2<nro3){
            menor = nro2;
        }
        else{
            menor = nro3;
        }
    }
    //<-- Fin menor*/
    mayor = nro1;
    menor = nro1;
    //Mayor
    if(nro2>mayor){
        mayor=nro2;
    }
    if(nro3>mayor){
        mayor=nro3;
    }
    //Menor
    if(nro2<menor){
        menor=nro2;
    }
    if(nro3<menor){
        menor=nro3;
    }
    printf("\nEl mayor es: %d", mayor);
    printf("\nEl menor es: %d\n", menor);
    return 0;
}
