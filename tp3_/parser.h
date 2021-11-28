/*
 * parser.h
 *
 *  Created on: 5 nov. 2021
 *      Author: Gonza
 */

#ifndef PARSER_H_
#define PARSER_H_

#include "LinkedList.h"
#include "Employee.h"

int parser_EmployeeFromText(FILE *pFile, LinkedList *pArrayListEmployee);

int parser_EmployeeFromBinary(FILE *pFile, LinkedList *pArrayListEmployee);

int parser_textFromEmployee(FILE *pFile, LinkedList *pArrayListEmployee);

int parser_binaryFromEmployee(FILE *pFile, LinkedList *pArrayListEmployee);

int parser_idFromText(FILE *pFile, LinkedList *pArrayListEmployee);

int parser_textFromId(FILE *pFile, LinkedList *pArrayListEmployee);

int get_id_Text(int *id);

int set_id_Text( int id);

#endif /* PARSER_H_ */
