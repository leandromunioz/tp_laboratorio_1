/****************************************************
 Menu:
 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
 2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
 3. Alta de empleado
 4. Modificar datos de empleado
 5. Baja de empleado
 6. Listar empleados
 7. Ordenar empleados
 8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
 9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
 10. Salir
 *****************************************************/

#include "Controller.h"
#define ARCHIVOTEXTO "data.csv"
#define ARCHIVOBINARIO "data.bin"
#define ARCHIVOID "id.csv"

int main() {
	setbuf(stdout, NULL);
	int option;
	int id;
	int flagChanges;
	int flagReading;
	LinkedList *employeeList = ll_newLinkedList();

	option = 0;
	flagChanges = -1;
	flagReading = 0;

	do {
		printf(
						"\n1) Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n"
						"2) Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n"
						"3) Alta de empleado\n"
						"4) Modificar datos de empleado\n"
						"5) Baja de empleado\n"
						"6) Listar empleados\n"
						"7) Ordenar empleados\n"
						"8) Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
						"9) Guardar los datos de los empleados en el archivo data.csv (modo binario).\n"
						"10) Salir\n");
		IngresarEnteroValidado(" Ingrese la opcion deseada: ", 1, 10, &option);
		switch (option)
		{
		case 1:
			if(flagReading == 0)
			{
				get_id_Text(&id);
				controller_loadFromText(ARCHIVOTEXTO, employeeList);
				//	set_id_Text(2);
				flagReading = 1;
			}
			else
			{
				printf("Ya se han cargado los datos\n");
			}

			break;

		case 2:
			if(flagReading == 0)
			{
				controller_loadFromBinary(ARCHIVOBINARIO, employeeList);
				flagReading = 1;
			}
			else
			{
				printf("Ya se han cargado los datos\n");
			}

			break;

		case 3:
			if(flagReading == 0)
			{
				printf("Se deben cargar los datos antes de realizar cualquier operacion\n");
			}
			else
			{
				controller_addEmployee(employeeList);
				flagChanges = 0;

			}

			break;

		case 4:
			if(flagReading == 0)
			{
				printf("Se deben cargar los datos antes de realizar cualquier operacion\n");
			}
			else
			{
				controller_editEmployee(employeeList);
				flagChanges = 0;
			}
			break;

		case 5:
			if(flagReading == 0)
			{
				printf("Se deben cargar los datos antes de realizar cualquier operacion\n");
			}
			else
			{
				controller_removeEmployee(employeeList);
				flagChanges = 0;
			}
			break;

		case 6:
			if(flagReading == 0)
			{
				printf("Se deben cargar los datos antes de realizar cualquier operacion\n");
			}
			else
			{
				controller_ListEmployee(employeeList);
			}
			break;

		case 7:
			if(flagReading == 0)
			{
				printf("Se deben cargar los datos antes de realizar cualquier operacion\n");
			}
			else
			{
				controller_sortEmployee(employeeList);
			}
			break;

		case 8:
			if(flagReading == 0)
			{
				printf("Se deben cargar los datos antes de realizar cualquier operacion\n");
			}
			else
			{
				flagChanges = 1;
				controller_saveAsText(ARCHIVOTEXTO, employeeList);
			}
			break;

		case 9:
			if(flagReading == 0)
			{
				printf("Se deben cargar los datos antes de realizar cualquier operacion\n");
			}
			else
			{
				flagChanges = 1;
				controller_saveAsBinary(ARCHIVOBINARIO, employeeList);
			}
			break;

		case 10:
			if(flagReading != 0)
			{
				if(flagChanges == 0)
				{
					printf("No se han guardado los archivos, si no los guarda pueden haber problemas");
					printf("1. Guardar en texto\n2. Guardar en binario\n3. Salir\n");
					IngresarEnteroValidado("Ingrese la opcion deseada: ", 1, 3, &option);
					switch (option)
					{
					case 1:
						controller_saveAsText(ARCHIVOTEXTO, employeeList);
						flagChanges = 1;
						break;

					case 2:
						controller_saveAsBinary(ARCHIVOBINARIO, employeeList);
						flagChanges = 1;
						break;

					case 3:
						option = 10;
						flagChanges = 1;
						break;
					}
				}
			}
			break;
		}
	}
	while(option != 10);

	return 0;
}

