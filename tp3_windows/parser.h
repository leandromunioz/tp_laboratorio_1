/*
 * parser.h
 *
 *  Created on: 16 nov. 2021
 *      Author: Leandro
 */

#ifndef PARSER_H_
#define PARSER_H_

#include "funciones.h"
#include "LinkedList.h"
#include "Employee.h"

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);
int get_id_Text(int *id);
int set_id_Text(int id);




#endif /* PARSER_H_ */
