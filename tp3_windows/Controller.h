#include "funciones.h"
#include "parser.h"
#include "Employee.h"
#include "LinkedList.h"

/// @brief Carga los datos de texto en la memoria
/// @param path Archivo a leer y cargar
/// @param pArrayListEmployee Lista donde cargar los datos
/// @return Retorna 0 si salio bien -1 si salio mal.
int controller_loadFromText(char *path, LinkedList *pArrayListEmployee);
/// @brief Carga los datos de binario en la memoria
/// @param path Archivo a leer y cargar
/// @param pArrayListEmployee Lista donde cargar los datos
/// @return Retorna 0 si salio bien -1 si salio mal.
int controller_loadFromBinary(char *path, LinkedList *pArrayListEmployee);
/// @brief Aniade un nuevo empleado
/// @param pArrayListEmployee lista de empleados
/// @return Retorna 0 si salio bien -1 si salio mal
int controller_addEmployee(LinkedList *pArrayListEmployee);
/// @brief Edita un campo de un empleado, especificando el id
/// @param pArrayListEmployee Lista de empleados
/// @return Retorna 0 si salio bien -1 si salio mal
int controller_editEmployee(LinkedList *pArrayListEmployee);

/// @brief Elimina un empleado de la lista.
/// @param pArrayListEmployee Lista de empleados
/// @return Retorna 0 si salio bien -1 si salio mal
int controller_removeEmployee(LinkedList *pArrayListEmployee);
/// @brief Imprime los empleados.
/// @param pArrayListEmployee Lista de empleados
/// @return Retorna 0 si salio bien -1 si salio mal
int controller_ListEmployee(LinkedList *pArrayListEmployee);
/// @brief Ordena la lista segun lo que se reciba dentro
/// @param pArrayListEmployee Lista de empleados
/// @return Retorna 0 si salio bien -1 si salio mal
int controller_sortEmployee(LinkedList *pArrayListEmployee);
/// @brief Guarda en texto el nuevo archivo.
/// @param path
/// @param pArrayListEmployee Lista de empleados
/// @return Retorna 0 si salio bien -1 si salio mal
int controller_saveAsText(char *path, LinkedList *pArrayListEmployee);
/// @brief Guarda en binario el archivo.
/// @param path
/// @param pArrayListEmployee Lista de empleados
/// @return Retorna 0 si salio bien -1 si salio mal
int controller_saveAsBinary(char *path, LinkedList *pArrayListEmployee);
/// @brief Recibe una lista y un id y busca que elemento tiene ese id
/// @param pArrayListEmployee Lista de empleados
/// @param id ID a buscar
/// @return Retorna -1 si no encontro o salio algo mal y si no la posicion del elemento
int findEmployee_by_Id(LinkedList *pArrayListEmployee, int id);
