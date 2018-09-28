#ifndef ALEGRIA_H_INCLUDED
#define ALEGRIA_H_INCLUDED

typedef struct{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}Employee;


void hardcodeo(Employee* arrayEmpleados);
int menu();
void initEmployees(Employee* arrayEmpleados, int tamanioArray);
int findFreePlace(Employee* arrayEmpleados, int tamanioArray, int valor);
int addEmployee(Employee* arrayEmpleados, int tamanioArray, int auxId, char auxName[],char
auxLastName[],float auxSalary,int auxSector);
int findEmployeeById(Employee* arrayEmpleados, int tamanioArray, int id);
void printEmployeeById(Employee* arrayEmpleados, int index);
void modifyEmployee(Employee* arrayyEmpleados, int tamanioArray);
void removeEmployee(Employee* arrayEmpleados, int tamanioarray, int id);
void sortEmployees(Employee* arrayEmpleados, int tamanioArray);
void printEmployees(Employee* arrayEmpleados, int tamanioArray);
void enlistEmployee(Employee* arrayEmpleados, int tamanioArray);
void listaCalculosEmpleados(Employee* arrayEmpleados, int tamanioArray);

#endif // ALEGRIA_H_INCLUDED
