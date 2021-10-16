/*
 * ArrayEmployees.c
 *
 *  Created on: 4 oct. 2021
 *      Author: Leandro
 */

#include "ArrayEmployees.h"

int initEmployees(Employee *list, int len) {
	int i;
	for (i = 0; i < len; i++) {
		list[i].isEmpty = TRUE;
	}
	return 0;
}

int addEmployee(Employee *list, int len, int id, char name[], char lastName[],
		float salary, int sector) {

	FormatearCadena(name);
	FormatearCadena(lastName);

	int posicion = 0;
	int encontrado = FALSE;
	while (posicion < len && !encontrado) {
		if (list[posicion].isEmpty == TRUE) {
			encontrado = TRUE;
		} else {
			posicion++;
		}
	}
	if (encontrado == TRUE) {
		list[posicion].isEmpty = FALSE;
		list[posicion].id = id;
		strcpy(list[posicion].lastName,lastName);
		strcpy( list[posicion].name,name);
		list[posicion].salary = salary;
		list[posicion].sector = sector;

	}

	return -1;
}

int findEmployeeById(Employee *list, int len, int id) {

	int i = 0;
	int encontrado = FALSE;
	int retorno = -1;
	while (i < len && !encontrado) {
		if (list[i].id == id && list[i].isEmpty == FALSE) {
			encontrado = TRUE;
			retorno = i;
		} else {
			i++;
		}

	}

	return retorno;
}

int removeEmployee(Employee *list, int len, int id) {
	int retorno = -1;
	int posicionBuscada;
	posicionBuscada = findEmployeeById(list, len, id);
	if (posicionBuscada != -1) {
		list[posicionBuscada].isEmpty = TRUE;
		retorno = 0;
	}
	return retorno;
}

int sortEmployees(Employee *list, int len, int order) {
	int i;
		int j;
		int retorno;
		Employee aux;

		retorno = -1;

		if(list != NULL && len > 0)
		{
			retorno = 0;
			for(i = 0 ; i < len ; i++)
			{
				for(j = i + 1 ; j < len ; j++)
				{
					if(list[i].isEmpty == FALSE && list[j].isEmpty == FALSE)
					{
					if(order == 1)
					{
						if((list[i].lastName < list[j].lastName) && (list[i].sector < list[j].sector))
						{
							aux = list[i];
							list[i] = list[j];
							list[j] = aux;
						}
					}
					else
					{
						if((list[i].lastName > list[j].lastName) && (list[i].sector > list[j].sector))
						{
							aux = list[i];
							list[i] = list[j];
							list[j] = aux;
						}
					}
					}
				}
			}
		}

		return retorno;
}

int printEmployees(Employee *list, int length) {
	int i;
	printf("    ID      APELLIDO  NOMBRE     SALARIO          SECTOR\n");
	for (i = 0; i < length; i++) {
		if (list[i].isEmpty != TRUE) {
			printf("%5d %12s %11s %11.2f %10d\n", list[i].id, list[i].lastName,
					list[i].name, list[i].salary, list[i].sector);
		}
	}
	return 0;
}

int altaUsuario(Employee *list, int len, int *id) {

	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int retorno=-1;

	if(list!=NULL && len >0){
	GetName("Ingrese nombre: ", "Este campo admite solo letras.", name);
	GetName("Ingrese apellido: ", "Este campo admite solo letras.", lastName);
	GetFlotante(&salary, "Ingrese su salario: ",
			"Ingrese un salario valido: ", 1000, 300000, 5);
	GetNumero(&sector, "Ingrese sector: ", "El sector máximo es: 100, minimo 0: ", 0,
			100, 5);

	addEmployee(list, len, *id, name, lastName, salary, sector);
	*id = *id + 1;
	retorno=1;
	}
	return retorno;
}

int modificarUsuario(Employee *list, int len) {


	float salary;
	int sector;
	int id;
	int indiceEmpleado;
	int opcion;
	int retorno = -1;

	GetNumero(&id, "Ingrese el ID del empleado que desea modificar: ",
			"Error, ID invalido. Reingrese: ", 0, 1000, 5);
	indiceEmpleado = findEmployeeById(list, len, id);

	if (indiceEmpleado != -1) {

			GetNumero(&opcion, "Seleccione la opcion para modificar el usuario:\n1-Modificar nombre\n2-Modificar apellido\n3-Modificar salario\n4-Modificar sector\n",
				"Opcion invalida...", 1, 4, 5);
		switch (opcion) {
		case 1:
			GetName("Ingrese nombre: ", "Ingrese solo letras.", list[indiceEmpleado].name);
			break;
		case 2:
			GetName("Ingrese apellido: ", "Ingrese solo letras.", list[indiceEmpleado].lastName);

			break;
		case 3:
			GetFlotante(&salary, "Ingrese su salario: ",
					"Ingrese un salario valido en la empresa.\n", 1000, 300000, 5);
			list[indiceEmpleado].salary = salary;
			break;
		case 4:
			GetNumero(&sector, "Ingrese sector: ",
					"El sector máximo es: 100, minimo 0.\n", 0, 100, 5);
			list[indiceEmpleado].sector = sector;
			break;

		}
		retorno = 0;
	}

	return retorno;
}

int eliminarUsuario(Employee *list, int len) {

	int id;
	int retorno=-1;
	if(list!=NULL && len>0){
	GetNumero(&id, "Ingrese el ID del empleado que desea eliminar: ",
			"Error, ID invalido. Reingrese:\n", 0, 1000, 5);
	removeEmployee(list, len, id);
	retorno=1;
	}
	return retorno;
}

int mostrarEmpleados(Employee *list, int len) {
	int retorno = -1;
	int orden;
	int opcion;

	if (list != NULL && len > 0) {
		GetNumero(&opcion,
				"Seleccione la opcion deseada:\n 1-Listado de los empleados ordenados alfabéticamente por Apellido y Sector.\n 2-Total y promedio de los salarios, y cuántos empleados superan el salario promedio.",
				"Error, opcion invalida.", 1, 2, 5);
		if (opcion == 1) {

			GetNumero(&orden,
					"Seleccione la opcion deseada:\n 1-Ascendente\n 0-Descendente",
					"Erorr, opcion invalida.", 0, 1, 5);
			sortEmployees(list, len, orden);
			printEmployees(list, len);

		} else {
			salarioCalculo(list, len);
		}
		retorno = 0;

	}
	return retorno;
}

int salarioCalculo(Employee *list, int len) {
	int retorno = -1;
	int i;
	int acumuladorSalario = 0;
	int contadorEmpleados = 0;
	int contadorEmpleadosMayor = 0;
	float promedioSalario;
	if (list != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			if (list[i].isEmpty != TRUE) {
				acumuladorSalario += list[i].salary;
				contadorEmpleados++;
			}
		}
		promedioSalario = acumuladorSalario / contadorEmpleados;

		for (i = 0; i < len; i++) {
			if (list[i].isEmpty != TRUE && list[i].salary > promedioSalario) {
				contadorEmpleadosMayor++;
			}
		}

	}

	printf(
			"El total de los salarios es:%d\nEl promedio de los salarios es:%f\nLa cantidad de empleados que superan el salario promedio es:%d\n",
			acumuladorSalario, promedioSalario, contadorEmpleadosMayor);
	return retorno;
}
