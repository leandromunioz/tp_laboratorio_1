#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char *path, LinkedList *pArrayListEmployee) {
	int retorno;
	retorno = -1;

	FILE *pFile;

	pFile = fopen(path, "r");

	if (pFile != NULL) {
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
int controller_loadFromBinary(char *path, LinkedList *pArrayListEmployee) {

	int retorno;
	retorno = -1;

	FILE *pFile;

	pFile = fopen(path, "rb");

	if (pFile != NULL) {
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
int controller_addEmployee(LinkedList *pArrayListEmployee) {
	int id;
	int retorno;
	retorno = -1;
	Employee *employeeAux;

	if (pArrayListEmployee != NULL) {
		get_id_Text(&id);
		id++;
		printf("EL ID ES ACA %d", id);
		employeeAux = employee_add(id);
		set_id_Text(id);
		ll_add(pArrayListEmployee, employeeAux);
		retorno = 0;
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
int controller_editEmployee(LinkedList *pArrayListEmployee) {

	int retorno;
	retorno = -1;
	int posicion;
	int id;
	Employee *employeeAux;

	if (pArrayListEmployee != NULL) {

		controller_ListEmployee(pArrayListEmployee);
		GetNumero(&id, "Ingrese id:\n", "Ingrese un id valido por favor.\n", 1,
				3000, 5);
		posicion = findEmployee_by_Id(pArrayListEmployee, id);

		if (posicion != -1) {
			employeeAux = ll_get(pArrayListEmployee, posicion);
			employeeAux = employee_modification(employeeAux);
		} else {
			printf("No se ha encontrado al empleado\n");
		}

		retorno = 0;
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
int controller_removeEmployee(LinkedList *pArrayListEmployee) {
	Employee *aux;
	int idABuscar;
	int pos;
	int index;
	int confirmation;
	int retorno;

	controller_ListEmployee(pArrayListEmployee);
	GetNumero(&idABuscar, "Ingrese el id del empleado que desea eliminar:\n", "id invalido. Reingrese:\n", 1, 3000, 5);
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


/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList *pArrayListEmployee) {
return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char *path, LinkedList *pArrayListEmployee) {
return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char *path, LinkedList *pArrayListEmployee) {
return 1;
}

int findEmployee_by_Id(LinkedList *pArrayListEmployee, int id) {
Employee *employeeAuxiliar;
int retorno;
int tam;
int idABuscar;

retorno = -1;

if (pArrayListEmployee != NULL) {
	tam = ll_len(pArrayListEmployee);
	for (int i = 0; i < tam; i++) {
		employeeAuxiliar = ll_get(pArrayListEmployee, i);
		employee_getId(employeeAuxiliar, &idABuscar);
		if (id == idABuscar) {
			retorno = i;
		}
	}
}

return retorno;
}
