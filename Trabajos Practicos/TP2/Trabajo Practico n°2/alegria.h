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

int menu();
void initEmployees(Employee* arrayEmpleados, int tamanioArray);
int findFreePlace(Employee* arrayEmpleados, int tamanioArray, int valor);
int addEmployee(Employee* arrayEmpleados, int tamanioArray, int auxId, char auxName[],char
auxLastName[],float auxSalary,int auxSector);
int findEmployeeById(Employee* arrayEmpleados, int tamanioArray, int id);
void printEmployeeById(Employee* arrayEmpleados, int index);
void modifyEmployee(Employee* arrayyEmpleados, int tamanioArray);
void removeEmployee(Employee* arrayEmpleados, int tamanioarray, int id);


#endif // ALEGRIA_H_INCLUDED
