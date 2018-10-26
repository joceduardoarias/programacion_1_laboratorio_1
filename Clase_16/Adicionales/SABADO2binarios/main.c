#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id ;
    char nombre[50];
    int estado;
}ePersona;
/** para una sola persona*/
/*int main()
{

  ePersona miPersona; //={1,"juan"};
  FILE* f;
  f=fopen("miArchivo.dat","wb");
 fwrite(&miPersona,sizeof(ePersona),1,f);
 fclose(f);

 f=fopen("miArchivo.dat","rb");

 fread(&miPersona,sizeof(ePersona),1,f);

 fclose(f);

 printf("%d--%s",miPersona.id,miPersona.nombre);
    return 0;
}*/


int main()
{
ePersona listaPersonas[4]={{1,"juan",1},{2,"mariana",0},{3,"jose",1},{0,"",0}}; /** origen de datos*/
ePersona lectura[4]; /** destino*/
int i;
for(i=0;i<4;i++)
{
lectura[i].estado=0;
}
  FILE* f;
  int cont=0;

/* f=fopen("miArchivo.dat","wb");

 for(i=0;i<4;i++)
 {
     if(listaPersonas[i].estado==1)
     {
       //fwrite(&listaPersonas[i],sizeof(ePersona),1,f); si guardo de esta manera guardo todo
       cont++;
     }
 }
fwrite(&cont,sizeof(int),1,f);

 for(i=0;i<4;i++)
 {
     if(listaPersonas[i].estado==1)
     {
       fwrite(&listaPersonas[i],sizeof(ePersona),1,f); //si guardo de esta manera guardo todo

     }
 }


 fclose(f);*/

 f=fopen("miArchivo.dat","rb");
fread(&cont,sizeof(int),1,f);
 fread(lectura,sizeof(ePersona),cont,f);
printf("%d\n",cont);
 fclose(f);

 for(i=0;i<4;i++)
 {
     if(lectura[i].estado==1)
     {
      printf("%d--%s\n",lectura[i].id,lectura[i].nombre);
     }
 }

return 0;
}
