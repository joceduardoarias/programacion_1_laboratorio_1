#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero, respuesta, mayor, menor;
    int flag = 0;
    while(respuesta != 0){
        printf("Ingrese numero: ");
        scanf("%d", &numero);
        if(flag==0){
            mayor=numero;
            menor=numero;
            flag=1;
        }
        //Mayor
        if(numero>mayor){
            mayor=numero;
        }
        if(numero>mayor){
            mayor=numero;
        }
        //Menor
        if(numero<menor){
            menor=numero;
        }
        if(numero<menor){
            menor=numero;
        }
        printf("\nEl mayor es: %d", mayor);
        printf("\nEl menor es: %d\n", menor);

        printf("\n¿Desea continuar? (0 para salir): ");
        scanf("%d", &respuesta);
    }
    return 0;
}
