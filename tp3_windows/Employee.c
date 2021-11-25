#include "Employee.h"

Employee* employee_new() {
	Employee *employeeAux;

	employeeAux = (Employee*) calloc(1, sizeof(Employee));

	return employeeAux;
}

Employee* employee_newParametros(char *idStr, char *nombreStr,
		char *horasTrabajadasStr, char *sueldoStr) {
	Employee *employeeAux;

	employeeAux = employee_new();

	if (employeeAux != NULL) {
		employee_setHorasTrabajadas(employeeAux, atoi(horasTrabajadasStr));
		employee_setId(employeeAux, atoi(idStr));
		employee_setNombre(employeeAux, nombreStr);
		employee_setSueldo(employeeAux, atoi(sueldoStr));
	}

	return employeeAux;
}

int employee_setId(Employee *this, int id) {

	int retorno;
	retorno = -1;

	if (this != NULL) {
		this->id = id;
		retorno = 0;
	}
	return retorno;
}

int employee_getId(Employee *this, int *id) {

	int retorno;
	retorno = -1;

	if (this != NULL) {
		*id = this->id;
		retorno = 0;
	}

	return retorno;
}

int employee_setNombre(Employee *this, char *nombre) {

	int retorno;
	retorno = -1;

	if (this != NULL) {
		strcpy(this->nombre, nombre);
		retorno = 0;
	}

	return retorno;
}

int employee_getNombre(Employee *this, char *nombre) {

	int retorno;
	retorno = -1;

	if (this != NULL) {
		strcpy(nombre, this->nombre);
		retorno = 0;
	}

	return retorno;
}

int employee_setHorasTrabajadas(Employee *this, int horasTrabajadas) {

	int retorno;
	retorno = -1;

	if (this != NULL) {
		this->horasTrabajadas = horasTrabajadas;
		retorno = 0;
	}

	return retorno;
}

int employee_getHorasTrabajadas(Employee *this, int *horasTrabajadas) {

	int retorno;
	retorno = -1;

	if (this != NULL) {
		*horasTrabajadas = this->horasTrabajadas;
		retorno = 0;
	}

	return retorno;
}

int employee_setSueldo(Employee *this, int sueldo) {

	int retorno;
	retorno = -1;

	if (this != NULL) {
		this->sueldo = sueldo;
		retorno = 0;
	}

	return retorno;
}

int employee_getSueldo(Employee *this, int *sueldo) {

	int retorno;
	retorno = -1;

	if (this != NULL) {
		*sueldo = this->sueldo;
		retorno = 0;
	}

	return retorno;
}

Employee* employee_add(int id) {
	Employee *employeeAux;
	int horasTrabajadas;
	int sueldo;
	char nombre[54];

	employeeAux = employee_new();


	if (employeeAux != NULL) {
		GetString("Ingrese nombre:\n", nombre);
		GetNumero(&horasTrabajadas, "Ingrese horas trabajadas:\n",
				"Las horas ingresadas son incorrectas. Minimo 1, maximo 100. Reingrese:\n", 1, 100,
				5);
		GetNumero(&sueldo, "Ingrese sueldo:\n", "Suelo invalido. Minimo 1000, maximo 300000. Reingrese:\n",
				10000, 300000, 5);
		FormatearCadena(nombre);
		employee_setNombre(employeeAux, nombre);
		employee_setHorasTrabajadas(employeeAux, horasTrabajadas);
		employee_setSueldo(employeeAux, sueldo);
		employee_setId(employeeAux, id);
	}


	return employeeAux;
}

Employee* employee_modification(Employee *this) {
	int option;

	do {
		printf("*Modificacion de empleados*\n"
				"1. Modificar nombre\n"
				"2. Modificar horas trabajadas\n"
				"3. Modificar sueldo\n"
				"4. Salir\n");
		GetNumero(&option, "Ingrese nuevo sueldo:\n",
				"Ingrese un sueldo valido. Minimo 1000, maximo 300000. Reingrese:\n", 1000, 300000, 5);
		switch (option) {
		case 1:
			employee_name_Modification(this);
			break;

		case 2:
			employee_hours_Modification(this);
			break;

		case 3:
			employee_salary_Modification(this);
			break;
		}
	} while (option != 4);

	return this;
}

Employee* employee_name_Modification(Employee *this) {
	char nameAux[50];

	employee_print(this);
	GetName("Ingrese nombre:\n", "Nombre invalido. Reingrese\n", nameAux);
	employee_setNombre(this, nameAux);
	employee_print(this);

	return this;
}

Employee* employee_salary_Modification(Employee *this) {

	int sueldoAuxiliar;

	employee_print(this);
	GetNumero(&sueldoAuxiliar, "Ingrese sueldo nuevo:\n", "Sueldo invalido. Minimo 1000, maximo 300000. Reingrese:\n",
			1000, 300000, 5);
	employee_setSueldo(this, sueldoAuxiliar);
	employee_print(this);

	return this;
}

Employee* employee_hours_Modification(Employee *this) {

	int horasTrabajadas;

	employee_print(this);
	GetNumero(&horasTrabajadas, "Ingrese sueldo nuevo:\n", "Sueldo invalido. Minimo 1000, maximo 300000. Reingrese:\n",
			1000, 300000, 5);

	employee_setHorasTrabajadas(this, horasTrabajadas);
	employee_print(this);

	return this;
}

int employee_print(Employee *this) {
	int retorno;
	char nameAux[50];
	int idAux;
	int auxHorasTrabajadas;
	int auxiliarSueldo;

	retorno = -1;

	if (this != NULL) {
		employee_getNombre(this, nameAux);
		employee_getId(this, &idAux);
		employee_getHorasTrabajadas(this, &auxHorasTrabajadas);
		employee_getSueldo(this, &auxiliarSueldo);
		printf("%d, %s, %d, %d\n", idAux, nameAux, auxHorasTrabajadas,
				auxiliarSueldo);
		retorno = 0;
	}

	return retorno;
}

int employee_delete(Employee *this) {
	int retorno;

	retorno = -1;

	if (this != NULL) {
		free(this);
		retorno = 0;
	}

	return retorno;
}



int employee_compare_name(void *one, void *two)
{
	int retorno;
	char nameOne[128];
	char nameTwo[128];
	Employee *first;
	Employee *second;

	retorno = -1;
	first = (Employee*) one;
	second = (Employee*) two;
	employee_getNombre(first, nameOne);
	employee_getNombre(second, nameTwo);
	retorno = stricmp(nameOne, nameTwo);

	return retorno;
}

int employee_compare_salary(void *one, void *two)
{
	int retorno;
	int salaryOne;
	int salaryTwo;
	retorno = -1;
	Employee *first;
	Employee *second;

	first = (Employee*) one;
	second = (Employee*) two;

	if((employee_getSueldo(first, &salaryOne) == 0) && (employee_getSueldo(second, &salaryTwo) == 0))
	{
		retorno = 0;
		if (salaryOne < salaryTwo)
		{
			retorno = 1;
		}
		else
		{
			if(salaryOne > salaryTwo)
			{
				retorno = -1;
			}
		}
	}

	return retorno;
}

int employee_compare_hours(void *one, void *two)
{
	int retorno;
	int hoursOne;
	int hoursTwo;
	Employee *first;
	Employee *second;

	retorno = -1;
	first = (Employee*) one;
	second = (Employee*) two;

	if((employee_getHorasTrabajadas(first, &hoursOne) == 0) && (employee_getHorasTrabajadas(second, &hoursTwo) == 0))
	{
		retorno = 0;
		if(hoursOne < hoursTwo)
		{
			retorno = 1;
		}
		else
		{
			if(hoursOne > hoursTwo)
			{
				retorno = -1;
			}
		}
	}

	return retorno;
}

