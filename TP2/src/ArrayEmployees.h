/*
 * ArrayEmployees.h
 *
 *  Created on: 4 oct. 2021
 *      Author: Leandro
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

#define TRUE 1
#define FALSE 0
#include <string.h>
#include <ctype.h>
#include "funciones.h"


typedef struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
}Employee;


int initEmployees(Employee* list, int len);

int addEmployee(Employee* list, int len, int id, char name[],char
lastName[],float salary,int sector);

int findEmployeeById(Employee* list, int len,int id);

int removeEmployee(Employee* list, int len, int id);

int sortEmployees(Employee* list, int len, int order);

int printEmployees(Employee* list, int length);

int altaUsuario(Employee *list, int len, int *id);

int modificarUsuario(Employee* list, int len);

int eliminarUsuario(Employee *list, int len);

int mostrarEmpleados(Employee *list, int len);

int salarioCalculo(Employee *list, int len);
#endif /* ARRAYEMPLOYEES_H_ */
