#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include "funciones.h"
typedef struct {
	int id;
	char nombre[128];
	int horasTrabajadas;
	int sueldo;
} Employee;

Employee* employee_new();
Employee* employee_newParametros(char *idStr, char *nombreStr,
		char *horasTrabajadasStr, char *sueldoStr);
int employee_delete(Employee *this);
Employee* employee_add(int id);

/// @brief Recibe un id y lo ingresa en el campo correspondinete de la estructura
/// @param this Puntero a empleado
/// @param id ID que recibe para ingresar
/// @return Retorna 0 si se pudo o -1 si el puntero es null
int employee_setId(Employee *this, int id);
/// @brief Recibe el empleado y una variable donde cargar el id del empleado
/// @param this Puntero a empleado
/// @param id Puntero a variable donde se almacenara el ID
/// @return Retorna 0 si se pudo o -1 si el puntero es null
int employee_getId(Employee *this, int *id);
/// @brief Recibe nombre, un puntero e ingresa el nombre en el campo correspondiente de la estrucura.
/// @param this Puntero a empleado
/// @param name Nombre a setear
/// @return Retorna 0 si se pudo o -1 si el puntero es null
int employee_setNombre(Employee *this, char *nombre);
/// @brief Recibe el empleado y una variablde donde cargar el nombre del empleado
/// @param this Puntero a empleado
/// @param name Puntero a variable donde se almacenara el nombre
/// @return Retorna 0 si se pudo o -1 si el puntero null
int employee_getNombre(Employee *this, char *nombre);
/// @brief Recibe horas, un puntero e ingresa las horas en el campo correspondiente de la estrucura.
/// @param this Puntero a empleado
/// @param workedHours Horas a setear
/// @return Retorna 0 si se pudo o -1 si el puntero es null
int employee_setHorasTrabajadas(Employee *this, int horasTrabajadas);
/// @brief Recibe el empleado y una variablde donde cargar las horas trabajadas del empleado
/// @param this Puntero a empleado
/// @param workedHours Puntero a variable donde se almacenaran las horas
/// @return Retorna 0 si se pudo o -1 si el puntero es null
int employee_getHorasTrabajadas(Employee *this, int *horasTrabajadas);
/// @brief Recibe un sueldo, un puntero e ingresa el sueldo en el campo correspondiente de la estrucura.
/// @param this Puntero a empleado
/// @param salary Sueldo a setear
/// @return Retorna 0 si se pudo o -1 si el puntero es null
int employee_setSueldo(Employee *this, int sueldo);
/// @fn int employee_getSueldo(Employee*, int*)
/// @brief Recibe el empleado y una variablde donde cargar el sueldo del empleado
/// @param this Puntero a empleado
/// @param salary Puntero a variable donde se almacenara el sueldo
/// @return Retorna 0 si se pudo o -1 si el puntero es null
int employee_getSueldo(Employee *this, int *sueldo);
/// @brief Recibe un empleado y modifica las horas con los datos que el usuario ponga.
/// @param this Puntero a empleado
/// @return Retorna el empleado modificado.
Employee* employee_hours_Modification(Employee *this);

/// @brief Recibe un empleado y modifica el salario con los datos que el usuario ponga.
/// @param this Puntero a empleado
/// @return Retorna el empleado modificado.
Employee* employee_salary_Modification(Employee *this);

/// @brief Recibe un empleado y modifica el nombre con los datos que el usuario ponga.
/// @param this Puntero a empleado
/// @return Retorna el empleado modificado.
Employee* employee_name_Modification(Employee *this);

/// @brief Imprime un empleado que recibe como parametro
/// @param this Puntero a empleado
/// @return Retorna 0 si se pudo o -1 si el puntero es null
int employee_print(Employee *this);
/// @brief Recibe una empleado y modifica el empleado donde se pida
/// @param this Puntero a empleado
/// @return Retorna el empleado modificado.
Employee* employee_modification(Employee *this);

#endif // employee_H_INCLUDED
