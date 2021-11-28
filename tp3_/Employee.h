
#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

#include "Funciones.h"

typedef struct {
	int id;
	char name[128];
	int workedHours;
	int salary;
} Employee;

/// @return Empleado creado en malloc y vacio
Employee* employee_new();

/// @brief Crea un empleado y carga dentro de los campos correspondientes los parametros recibidos
/// @param idStr ID a cargar
/// @param nameStr Nombre a cargar
/// @param workedHoursStr Horas a cargar
/// @param salaryStr Sueldo a cargar
/// @return Retorna el empleado con los campos cargados
Employee* employee_newParametros(char *idStr, char *nameStr, char *workedHoursStr, char *salaryStr);

/// @brief Recibe un empleado y lo elimina de la memoria del programa
/// @param this Punter a empleado
/// @return Retorna 0 si se pudo o -1 si hubo error
int employee_delete(Employee *this);

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
int employee_setNombre(Employee *this, char *name);

/// @brief Recibe el empleado y una variablde donde cargar el nombre del empleado
/// @param this Puntero a empleado
/// @param name Puntero a variable donde se almacenara el nombre
/// @return Retorna 0 si se pudo o -1 si el puntero null
int employee_getNombre(Employee *this, char *name);

/// @brief Recibe horas, un puntero e ingresa las horas en el campo correspondiente de la estrucura.
/// @param this Puntero a empleado
/// @param workedHours Horas a setear
/// @return Retorna 0 si se pudo o -1 si el puntero es null
int employee_setHorasTrabajadas(Employee *this, int workedHours);

/// @brief Recibe el empleado y una variablde donde cargar las horas trabajadas del empleado
/// @param this Puntero a empleado
/// @param workedHours Puntero a variable donde se almacenaran las horas
/// @return Retorna 0 si se pudo o -1 si el puntero es null
int employee_getHorasTrabajadas(Employee *this, int *workedHours);

/// @brief Recibe un sueldo, un puntero e ingresa el sueldo en el campo correspondiente de la estrucura.
/// @param this Puntero a empleado
/// @param salary Sueldo a setear
/// @return Retorna 0 si se pudo o -1 si el puntero es null
int employee_setSueldo(Employee *this, int salary);

/// @fn int employee_getSueldo(Employee*, int*)
/// @brief Recibe el empleado y una variablde donde cargar el sueldo del empleado
/// @param this Puntero a empleado
/// @param salary Puntero a variable donde se almacenara el sueldo
/// @return Retorna 0 si se pudo o -1 si el puntero es null
int employee_getSueldo(Employee *this, int *salary);

/// @brief Imprime un empleado que recibe como parametro
/// @param this Puntero a empleado
/// @return Retorna 0 si se pudo o -1 si el puntero es null
int employee_print(Employee *this);

/// @brief Recibe una empleado y modifica el empleado donde se pida
/// @param this Puntero a empleado
/// @return Retorna el empleado modificado.
Employee* employee_modification(Employee *this);

/// @brief Recibe un empleado y modifica el nombre con los datos que el usuario ponga.
/// @param this Puntero a empleado
/// @return Retorna el empleado modificado.
Employee* employee_name_Modification(Employee *this);

/// @brief Recibe un empleado y modifica el salario con los datos que el usuario ponga.
/// @param this Puntero a empleado
/// @return Retorna el empleado modificado.
Employee* employee_salary_Modification(Employee *this);

/// @brief Recibe un empleado y modifica las horas con los datos que el usuario ponga.
/// @param this Puntero a empleado
/// @return Retorna el empleado modificado.
Employee* employee_hours_Modification(Employee *this);

/// @brief Aniade un empleado por teclado
/// @return Retorna el empleado ingresado.
Employee* employee_add();

/// @brief Compara dos nombres que se reciben por parametro
/// @param one Primer nombre
/// @param two Segundo nombre
/// @return Retorna el resultado de la comparacion.
int employee_compare_name(void *one, void *two);

/// @brief Compara las horas trabajadas que se reciben por parametro
/// @param one primer empleado
/// @param two Segundo empleado
/// @return Retorna 0 si las horas son iguales, 1 si el primero es menor que el segundo y -1 si las horas del primero es mayor que el segundo
int employee_compare_hours(void *one, void *two);

/// @brief Compara los salarios que se reciben por parametro
/// @param one Primer empleado
/// @param two Segundo empleado
/// @return Retorna 0 si las horas son iguales, 1 si el sueldo del primero  es menor que el segundo y -1 si el sueldo del primero es mayor  que el segundo
int employee_compare_salary(void *one, void *two);

#endif // employee_H_INCLUDED
