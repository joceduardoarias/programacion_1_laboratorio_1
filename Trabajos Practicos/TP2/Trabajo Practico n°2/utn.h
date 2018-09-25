#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

//Retorna valor ingresado - mensaje por parametro

int getInt(char mensaje[]);
float getFloat(char mensaje[]);
char getChar(char mensaje[]);

//Validacion de datos - string como parametro

int esNumerico(char str[]);
int AlfaNumerico(char str[]);
int esSoloLetras(char str[]);

//Valida string(letras y numeros)

void getString(char mensaje[], char input[]);
int getStringLetras(char mensaje[], char input[]);
int getStringLetrasRango(char mensaje[], char input[], int maximo);
int getStringNumerosRango(char mensaje[], char input[], int minimo, int maximo);
int getStringNumeros(char mensaje[], char input[]);
int esNumericoFlotante(char str[]);
int getStringNumerosFlotantes(char mensaje[], char input[]);

#endif // UTN_H_INCLUDED
