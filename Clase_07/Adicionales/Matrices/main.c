#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "funciones.h"
#define TAM 3

int altaUsuario(char nombre[][31], char apellido[][31], int legajo[], int edad[], int isEmpty[], int tam);
int mostrarUsuario(char nombre[][31], char apellido[][31], int legajo[], int edad[], int isEmpty[], int legajoAux, int tam);

int main()
{
    char seguir;
    int cantidad;
    int auxiliar;

    char nombre[TAM][31], nombreAux[31];
    char apellido[TAM][31], apellidoAux[31];
    int legajo[TAM], legajoAux;
    int edad[TAM], edadAux;
    int isEmpty[TAM], isEmptyAux;
    int flag=0;

    inicializacion(isEmpty, TAM);

    do
    {
        switch(menu())
        {
        case '1':
            system("cls");
            printf("Alta de usuario\n\n");

            int indice;
            indice = buscaEspacio(isEmpty, TAM);
            if(indice==-1)
            {
                printf("No queda espacio disponible\n\n");
            }
            else
            {
                printf("Ingrese nombre: ");
                fflush(stdin);
                fgets(nombre[indice], sizeof(nombre[indice]), stdin);
                cantidad = strlen(nombre[indice]);
                nombre[indice][cantidad-1] = '\0';
                printf("Ingrese apellido: ");
                fflush(stdin);
                fgets(apellido[indice], sizeof(apellido[indice]), stdin);
                cantidad = strlen(apellido[indice]);
                apellido[indice][cantidad-1] = '\0';
                fflush(stdin);
                printf("Ingrese legajo: ");
                scanf("%d", &legajo[indice]);
                printf("Ingrese edad: ");
                scanf("%d", &edad[indice]);
                isEmpty[indice]=0;
                system("pause");
                break;
            case '2':
                system("cls");
                printf("Baja de usuario\n\n");
                printf("Ingrese legajo: ");
                scanf("%d", &legajoAux);
                flag=0;
                for(int i=0; i<TAM; i++)
                {
                    if(legajo[i]==legajoAux && isEmpty==0)
                    {
                        isEmpty[i]=1;
                        flag=1;
                    }
                }
                if(flag==0)
                {
                    printf("Dato no encontrado\n");
                }
                system("pause");
                break;
            case '3':
                system("cls");
                printf("Modificacion de usuario\n\n");
                system("pause");
                break;
            case '4':
                system("cls");
                printf("Ordenamiento de empleados\n\n");
                for(int i=0; i<TAM-1; i++)
                {
                    for(int j=i+1; i<TAM; i++)
                    {
                        if(strcmp(nombre[i],nombre[j])>0)
                        {
                            strcpy(nombreAux, nombre[i]);
                            strcpy(nombre[i], nombre[j]);
                            strcpy(nombre[j], nombreAux);
                            strcpy(apellidoAux, apellido[i]);
                            strcpy(apellido[i], apellido[j]);
                            strcpy(apellido[j], apellidoAux);
                            edadAux= edad[i];
                            edad[i]= edad[j];
                            edad[j]= edadAux;
                            legajoAux= legajo[i];
                            legajo[i]= legajo[j];
                            legajo[j]= legajoAux;
                            isEmptyAux= isEmpty[i];
                            isEmpty[i]= isEmpty[j];
                            isEmpty[j]= isEmptyAux;
                        }
                        else
                        {
                            if(strcmp(apellido[i], apellido[j])==0)//Doble ordenamiento, Quito la parte fel apellido
                            {
                                strcpy(nombreAux, nombre[i]);
                                strcpy(nombre[i], nombre[j]);
                                strcpy(nombre[j], nombreAux);
                                edadAux= edad[i];
                                edad[i]= edad[j];
                                edad[j]= edadAux;
                                legajoAux= legajo[i];
                                legajo[i]= legajo[j];
                                legajo[j]= legajoAux;
                                isEmptyAux= isEmpty[i];
                                isEmpty[i]= isEmpty[j];
                                isEmpty[j]= isEmptyAux;
                            }

                        }
                    }
                }
                system("pause");
                break;
            case '5':
                system("cls");
                printf("Buscar usuario\n\n");
                printf("Ingrese legajo a buscar: ");
                scanf("%d", &auxiliar);
                legajoAux=auxiliar;
                auxiliar = mostrarUsuario(nombre, apellido, legajo, edad, isEmpty, legajoAux, TAM);
                if(auxiliar==0){
                    mostrarUsuario(nombre, apellido, legajo, edad, isEmpty, legajoAux, TAM);

                }
                else{
                    printf("No se encuentra usuario\n");
                }
                system("pause");
                break;
            case '6':
                system("cls");
                printf("Lista de usuarios\n\n");

                system("pause");
                break;
            case '7':
                seguir='n';
                break;
            default:
                printf("\nIngreso una opcion no disponible, reintente");
                system("pause");
            }
        }
        printf("\n\n");
    }
    while(menu()!='7');
    return 0;
}

int mostrarUsuario(char nombre[][31], char apellido[][31], int legajo[], int edad[], int isEmpty[], int legajoAux, int tam)
{
    int retorno = -1;
    printf("Legajo\tApellido  \tNombre  \tEdad\n\n");
    for(int i=0; i<TAM; i++)
    {
        if(legajoAux==legajo[i] && isEmpty[i]==0)
        {
            printf("\n%d\t%s\t\t%s\t\t%d", legajo[i], apellido[i], nombre[i], edad[i]);
        }
        return 0;
        break;
    }
    printf("\n\n");
    return retorno;
}


int altaUsuario(char nombre[][31], char apellido[][31], int legajo[], int edad[], int isEmpty[], int tam){

}
