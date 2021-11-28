#include "Employee.h"

int employee_setSueldo(Employee *this, int salary)
{
	int retorno;

	retorno = -1;

	if(this != NULL)
	{
		this->salary = salary;
		retorno = 0;
	}

	return retorno;
}

int employee_getSueldo(Employee *this, int *salary)
{
	int retorno;

	retorno = -1;

	if (this != NULL) {
		*salary = this->salary;
		retorno = 0;

	}
	return retorno;
}

int employee_setId(Employee *this, int id)
{
	int retorno;

	retorno = -1;

	if (this != NULL) {
		this->id = id;
		retorno = 0;
	}

	return retorno;
}

int employee_getId(Employee *this, int *id)
{
	int retorno;

	retorno = -1;

	if (this != NULL) {
		*id = this->id;
		retorno = 0;
	}
	return retorno;
}

int employee_setNombre(Employee *this, char *name)
{
	int retorno;

	retorno = -1;

	if (this != NULL) {
		strcpy(this->name, name);
		retorno = 0;
	}

	return retorno;
}

int employee_getNombre(Employee *this, char *name)
{
	int retorno;

	retorno = -1;

	if(this != NULL)
	{
		strcpy(name, this->name);
		retorno = 0;

	}
	return retorno;
}

int employee_setHorasTrabajadas(Employee *this, int workedHours)
{
	int retorno;

	retorno = -1;

	if(this != NULL)
	{
		this->workedHours = workedHours;
		retorno = 0;
	}

	return retorno;
}
int employee_getHorasTrabajadas(Employee *this, int *workedHours)
{
	int retorno;

	retorno = -1;

	if(this != NULL)
	{
		*workedHours = this->workedHours;
		retorno = 0;

	}
	return retorno;
}

Employee* employee_new()
{
	Employee *retorno;

	retorno = (Employee*) calloc(1, sizeof(Employee));

	return retorno;
}

Employee* employee_newParametros(char *idStr, char *nameStr, char *workedHoursStr, char *salaryStr)
{
	Employee *newEmployee;
	newEmployee = employee_new();

	if(newEmployee != NULL)
	{
		employee_setHorasTrabajadas(newEmployee, atoi(workedHoursStr));
		employee_setNombre(newEmployee, nameStr);
		employee_setSueldo(newEmployee, atoi(salaryStr));
		employee_setId(newEmployee, atoi(idStr));
	}

	return newEmployee;
}

int employee_print(Employee *this)
{
	int retorno;
	char nameAux[50];
	int idAux;
	int workedHoursAux;
	int salaryAux;

	retorno = -1;

	if(this != NULL)
	{
		employee_getNombre(this, nameAux);
		employee_getId(this, &idAux);
		employee_getHorasTrabajadas(this, &workedHoursAux);
		employee_getSueldo(this, &salaryAux);
		printf("%d, %s, %d, %d\n", idAux, nameAux, workedHoursAux, salaryAux);
		retorno = 0;
	}

	return retorno;
}

Employee* employee_modification(Employee *this)
{
	int option;

	do
	{
		printf("*Modificacion de empleados*\n"
				"1. Modificar nombre\n"
				"2. Modificar horas trabajadas\n"
				"3. Modificar sueldo\n"
				"4. Salir\n");
		IngresarEnteroValidado("Ingrese la opcion deseada: ", 1, 4, &option);
		switch(option)
		{
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
	}
	while(option != 4);

	return this;
}

Employee* employee_name_Modification(Employee *this)
{
	char nameAux[50];

	employee_print(this);
	IngresarNombre("Ingrese el nuevo nombre del empleado: ", "Por favor, ingrese un nombre real: ", nameAux, 51);
	employee_setNombre(this, nameAux);
	employee_print(this);

	return this;
}

Employee* employee_salary_Modification(Employee *this)
{
	int salaryAux;

	employee_print(this);
	IngresarEnteroValidado("Ingrese su sueldo nuevo: ", 1000, 1000000, &salaryAux);
	employee_setSueldo(this, salaryAux);
	employee_print(this);

	return this;
}

Employee* employee_hours_Modification(Employee *this)
{
	int workedHours;

	employee_print(this);
	IngresarEnteroValidado("Ingrese su sueldo nuevo: ", 1000, 1000000, &workedHours);
	employee_setHorasTrabajadas(this, workedHours);
	employee_print(this);

	return this;
}

Employee* employee_add(int id)
{
	Employee *newEmployee;
	char nameAux[50];
	int workedHoursAux;
	int salaryAux;

	newEmployee = employee_new();
	if(newEmployee != NULL)
	{
		printf("~Ingreso de empleados~\n");
		IngresarNombre("Ingrese el nombre del empleado: ", "Por favor, ingrese un nombre real: ", nameAux, 51);
		IngresarEnteroValidado("ingrese el sueldo del nuevo empleado.\n", 1000, 1000000, &salaryAux);
		IngresarEnteroValidado("ingrese las horas trabajadas\n", 0, 24, &workedHoursAux);
		employee_setHorasTrabajadas(newEmployee, workedHoursAux);
		employee_setNombre(newEmployee, nameAux);
		employee_setSueldo(newEmployee, salaryAux);
		employee_setId(newEmployee, id);
	}

	return newEmployee;
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

int employee_delete(Employee *this)
{
	int retorno;

	retorno = -1;

	if(this != NULL)
	{
		free(this);
		retorno = 0;
	}

	return retorno;
}

