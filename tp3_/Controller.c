#include "Controller.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char *path, LinkedList *pArrayListEmployee)
{
	FILE *pFile;
	int retorno;

	retorno = -1;
	pFile = fopen(path, "r");

	if(pFile != NULL)
	{
		parser_EmployeeFromText(pFile, pArrayListEmployee);
		retorno = 0;
	}
	fclose(pFile);

	return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char *path, LinkedList *pArrayListEmployee)
{
	FILE *pFile;
	int retorno;

	retorno = -1;
	pFile = fopen(path, "rb");

	if(pFile != NULL)
	{
		parser_EmployeeFromBinary(pFile, pArrayListEmployee);
		retorno = 0;
	}
	fclose(pFile);

	return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList *pArrayListEmployee)
{
	Employee *newEmployee;
	int id;
	int confirmation;
	int retorno;

	retorno = -1;
	confirmation = ConfirmarAccion("Si desea confirmar el alta de un empleado escriba 'si'\n", "si");

	if(confirmation == 0)
	{
		if(pArrayListEmployee != NULL)
		{
			get_id_Text(&id);
			id++;
			newEmployee = employee_add(id);
			set_id_Text(id);
			ll_add(pArrayListEmployee, newEmployee);
			printf("El empleado fue dada de alta correctamente\n");
			retorno = 0;
		}
	}

	return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList *pArrayListEmployee)
{
	Employee *aux;
	int idABuscar;
	int pos;
	int index;
	int confirmation;
	int retorno;

	controller_ListEmployee(pArrayListEmployee);
	IngresarEnteroValidado("Ingrese el id del empleado que desea eliminar\n", 0, 1000, &idABuscar);
	pos = findEmployee_by_Id(pArrayListEmployee, idABuscar);
	retorno = -1;

	if(pos != -1)
	{
		aux = ll_get(pArrayListEmployee, pos);
		employee_print(aux);
		confirmation = ConfirmarAccion("Si desea confirmar el alta de un empleado escriba 'si'\n", "si");

		if (confirmation == 0) {
			index = ll_indexOf(pArrayListEmployee, aux);
			ll_remove(pArrayListEmployee, index);
			employee_delete(aux);
			printf("El empleado fue dado de baja correctamente\n");
			employee_print(aux);
			printf("Eliminado\n");
			retorno = 0;
		}

	} else {
		printf("No se ha encontrado al empleado\n");

	}

	return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList *pArrayListEmployee)
{
	Employee *aux;
	int tam;
	int retorno;

	retorno = -1;

	if(pArrayListEmployee != NULL)
	{
		tam = ll_len(pArrayListEmployee);
		for(int i = 0; i < tam; i++)
		{
			aux = (Employee*) ll_get(pArrayListEmployee, i);
			employee_print(aux);
			retorno = 0;
		}
	}

	return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList *pArrayListEmployee)
{
	int retorno;
	Employee *aux;
	int idABuscar;
	int pos;

	retorno = -1;

	if(pArrayListEmployee != NULL)
	{

		controller_ListEmployee(pArrayListEmployee);
		IngresarEnteroValidado("Ingrese el id del empleado que desea modificar: ", 0, 1000, &idABuscar);
		pos = findEmployee_by_Id(pArrayListEmployee, idABuscar);

		if (pos != -1)
		{
			aux = ll_get(pArrayListEmployee, pos);
			aux = employee_modification(aux);
		}
		else
		{
			printf("No se ha encontrado al empleado\n");
		}

		retorno = 0;
	}

	return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

//int controller_sortEmployee(LinkedList *pArrayListEmployee) {
//	ll_sort(pArrayListEmployee, employee_compare_salary, 1);
//	controller_ListEmployee(pArrayListEmployee);
//	return 0;
//}
int controller_sortEmployee(LinkedList *pArrayListEmployee)
{
	int retorno;
	int option;
	int subOption;
	retorno = -1;

	if(pArrayListEmployee != NULL)
	{
		do
		{

			printf("*order lista\n*"
					"1-Ordenar Por Nombre\n"
					"2-Ordenar Por Salario\n"
					"3-Ordenar Por Horas de trabajo\n"
					"4-salir\n");
			IngresarEnteroValidado("Ingrese la opcion deseada: ", 1, 4, &option);
			switch(option)
			{
			case 1:
				printf("~Ordenar por nombre~\n"
						"0. Ordenar de mayor a menor\n"
						"1. Ordenar de menor a mayor\n"
						"2. Salir\n");
				IngresarEnteroValidado("Ingrese la opcion deseada: ", 0, 2, &subOption);

				if(subOption != 2)
				{
					ll_sort(pArrayListEmployee, employee_compare_name, subOption);
				}
				break;

			case 2:
				printf("~Ordenar por Salario~\n"
						"0. Ordenar de mayor a menor\n"
						"1. Ordenar de menor a mayor\n"
						"2. Salir\n");
				IngresarEnteroValidado("Ingrese la opcion deseada: ", 0, 2, &subOption);
				ll_sort(pArrayListEmployee, employee_compare_salary, subOption);
				break;

			case 3:
				printf("~Ordenar por horas trabajadas~\n"
						"0. Ordenar de mayor a menor\n"
						"1. Ordenar de menor a mayor\n"
						"2. Salir\n");
				IngresarEnteroValidado("Ingrese la opcion deseada: ", 0, 2, &subOption);
				ll_sort(pArrayListEmployee, employee_compare_hours, subOption);

				break;
			}

		} while (option != 4);

		retorno = 0;
	}

	return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char *path, LinkedList *pArrayListEmployee)
{
	FILE *pFile;
	int retorno;

	retorno = -1;
	pFile = fopen(path, "w");

	if(pFile != NULL)
	{
		parser_textFromEmployee(pFile, pArrayListEmployee);
		retorno = 0;
	}
	fclose(pFile);

	return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char *path, LinkedList *pArrayListEmployee)
{
	FILE *pFile;
	int retorno;

	retorno = -1;
	pFile = fopen(path, "wb");

	if(pFile != NULL)
	{
		parser_binaryFromEmployee(pFile, pArrayListEmployee);
		retorno = 0;
	}
	fclose(pFile);

	return retorno;
}

int generadorDeId(LinkedList *pArrayListEmployee, int *id)
{
	int retorno;
	int tam;
	int flagEntry;
	int idAux;
	int auxMayor;

	flagEntry = 0;
	Employee *aux;
	retorno = -1;

	if(pArrayListEmployee != NULL)
	{
		tam = ll_len(pArrayListEmployee);
		for (int i = 0; i < tam; i++)
		{

			aux = (Employee*) ll_get(pArrayListEmployee, (i));

			employee_getId(aux, &idAux);

			if(flagEntry == 0)
			{
				flagEntry = 1;
				auxMayor = idAux;

				if(auxMayor < idAux)
				{
					auxMayor = idAux;
				}
			}
			*id = idAux + 1;
			retorno = 0;
		}
	}

	return retorno;
}

int findEmployee_by_Id(LinkedList *pArrayListEmployee, int id)
{
	Employee *aux;
	int retorno;
	int tam;
	int idABuscar;

	retorno = -1;

	if (pArrayListEmployee != NULL)
	{
		tam = ll_len(pArrayListEmployee);
		for (int i = 0; i < tam; i++)
		{
			aux = ll_get(pArrayListEmployee, i);
			employee_getId(aux, &idABuscar);
			if (id == idABuscar)
			{
				retorno = i;
			}
		}
	}

	return retorno;
}

