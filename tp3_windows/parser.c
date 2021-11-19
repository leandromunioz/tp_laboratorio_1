#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	Employee* employeeAux;
	char id [128];
	char nombre [128];
	char sueldo [128];
	char horasTrabajadas [128];
	int retorno=-1;

	if(pFile != NULL && pArrayListEmployee != NULL){
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n ", id, nombre, horasTrabajadas,
			sueldo);
		retorno=0;

		while(!feof(pFile)){
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n ", id, nombre, horasTrabajadas,
						sueldo);
			employeeAux=employee_newParametros(id, nombre,horasTrabajadas , sueldo);
			ll_add(pArrayListEmployee, employeeAux);
		}

	}


    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	Employee* employeeAux;
	int retorno = -1;

	if(pFile != NULL && pArrayListEmployee != NULL){
		retorno = 0;
		while(!feof(pFile)){
			employeeAux = employee_new();
			if(employeeAux != NULL){
				fread(employeeAux,sizeof(Employee),1,pFile);
				ll_add(pArrayListEmployee, employeeAux);
			}
		}
	}
    return retorno;
}

int get_id_Text(int *id) {
	char idStr[128];
	FILE *pFile;
	int retorno;
	retorno = -1;
	pFile = fopen("id.csv", "r");

	if (pFile != NULL) {
		fscanf(pFile, "%[^\n]", idStr);
		*id = atoi(idStr);
	}
	fclose(pFile);
	return retorno;
}

int set_id_Text(int id) {
	int retorno;
	FILE *pFile;
	retorno = -1;
	pFile = fopen("id.csv", "w");
	if (pFile != NULL) {

		fprintf(pFile, "%d\n ", id);

		retorno = 0;
		fclose(pFile);
	}

	return retorno;
}













