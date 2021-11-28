#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE *pFile, LinkedList *pArrayListEmployee) {
	Employee *aux;

	int retorno;
	char id[128];
	char nombre[128];
	char horasTrabajadas[128];
	char sueldo[128];
	fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n ", id, nombre, horasTrabajadas,
			sueldo);
	do {
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n ", id, nombre,
				horasTrabajadas, sueldo);
		aux = employee_newParametros(id, nombre, horasTrabajadas, sueldo);
		ll_add(pArrayListEmployee, aux);
		retorno = 0;

	} while (!feof(pFile));

	return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int parser_EmployeeFromBinary(FILE *pFile, LinkedList *pArrayListEmployee) {
	Employee *aux;
	int retorno;
	retorno = -1;
	if (pArrayListEmployee != NULL && pFile != NULL) {

		do {
			aux = employee_new();
			if (aux != NULL) {

				fread(aux, sizeof(Employee), 1, pFile);

				if (feof(pFile)) {
					break;
				} else {

					ll_add(pArrayListEmployee, aux);
				}
				retorno = 0;
			}

		} while (!feof(pFile));

	}

	return retorno;

}

int parser_textFromEmployee(FILE *pFile, LinkedList *pArrayListEmployee) {
	int retorno;
	int tam;
	int idAux;
	int horasTrabajadasAux;
	int sueldoAux;
	char nombreAux[128];

	Employee *aux;
	retorno = -1;

	if (pArrayListEmployee != NULL && pFile != NULL) {

		tam = ll_len(pArrayListEmployee);
		fprintf(pFile, "id,nombre,horasTrabajadas,sueldo\n");
		for (int i = 0; i < tam; i++) {
			aux = ll_get(pArrayListEmployee, i);
			employee_getId(aux, &idAux);
			employee_getSueldo(aux, &sueldoAux);
			employee_getNombre(aux, nombreAux);
			employee_getHorasTrabajadas(aux, &horasTrabajadasAux);
			fprintf(pFile, "%d,%s,"
					"%d,%d\n ", idAux, nombreAux, horasTrabajadasAux,
					sueldoAux);

		}

		retorno = 0;
	}

	return retorno;

}

int parser_binaryFromEmployee(FILE *pFile, LinkedList *pArrayListEmployee) {
	int tam;
	int retorno;
	Employee *aux;
	retorno = -1;
	if (pArrayListEmployee != NULL && pFile != NULL) {

		tam = ll_len(pArrayListEmployee);
		for (int i = 0; i < tam; i++) {
			aux = (Employee*) ll_get(pArrayListEmployee, i);
			fwrite(aux, sizeof(Employee), 1, pFile);

			retorno = 0;
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


