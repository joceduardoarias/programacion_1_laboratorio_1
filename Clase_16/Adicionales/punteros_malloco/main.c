#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*esta manera de usar malloc en el main es de forma didactica
      para entender el concepto y la funcion malloc, pues de nada sirve reservar memoria estatica
      que ademas es muy chica [todo lo que se declara en el main esta compilado en memoria estatica].
    */
    int* puntero;
    //reservo la memoria del puntero entero
    puntero = (int*)malloc(sizeof(int));
    //valido que se haya reservado la memoria
    if(puntero == NULL)
    {
        printf("\n No hay memoria disponible!!!");
    }
    //libero memoria
    //simpre libero el espacio reservado del puntero que estoy utilizando
    free(puntero);
    return 0;
}
