#include "Controller.h"

#define ARCHIVOTEXTO "data.csv"
#define ARCHIVOBINARIO "data.bin"
#define ARCHIVOID "id.csv"

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

int main() {
	setbuf(stdout, NULL);

	int id;
	int option = 0;
	int banderaCambios = 0;
	int banderaLectura = 0;

	LinkedList *listaEmpleados = ll_newLinkedList();

	do {
		printf(
				"*******************************************************\n Menu:\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n3. Alta de empleado\n4. Modificar datos de empleado\n5. Baja de empleado\n6. Listar empleados\n7. Ordenar empleados\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n10. Salir\n*******************************************************\n");
		if (GetNumero(&option, "Seleccione la opcion deseada:\n",
				"Opcion invalida. Reingrese:\n", 1, 10, 5) == 0) {
			printf("Operacion exitosa.\n");
		} else {
			printf(
					"Ha ocurrido un error en la operacion. Intente nuevamente.\n");
		}
		switch (option) {
		case 1:
			if (banderaLectura == 0) {
				set_id_Text(1000);
				get_id_Text(&id);
				controller_loadFromText(ARCHIVOTEXTO, listaEmpleados);
				banderaLectura = 1;
			} else {
				printf("Datos cargados exitosamente.\n");
			}

			break;

		case 2:
			if (banderaLectura == 0) {
				controller_loadFromBinary(ARCHIVOBINARIO, listaEmpleados);
				banderaLectura = 1;
			} else {
				printf("Datos cargados exitosamente.\n");
			}

			break;

		case 3:
			if (banderaLectura == 0) {
				printf(
						"Por favor, cargue los datos antes de realizar esta operacion.\n");
			} else {
				controller_addEmployee(listaEmpleados);
				banderaCambios = 1;
				printf("Operacion exitosa.\n");
			}

			break;
		case 4:
			if (banderaLectura == 0) {
				printf("Por favor, cargue los datos antes de realizar esta operacion.\n");
			}else{
				controller_editEmployee(listaEmpleados);
				banderaCambios=1;
				printf("Operacion exitosa.\n");

			}
			break;

		case 5:

			if(banderaLectura == 0)
					{
						printf("Por favor, cargue los datos antes de realizar esta operacion.\n");
					}
					else
					{
						controller_removeEmployee(listaEmpleados);
						banderaCambios = 0;
						printf("Operacion exitosa.\n");

					}

			break;

		case 6:
					if(banderaLectura == 0)
					{
						printf("Por favor, cargue los datos antes de realizar esta operacion.\n");
					}
					else
					{
						controller_ListEmployee(listaEmpleados);
						printf("Operacion exitosa.\n");

					}
					break;

		case 7:
				if(banderaLectura == 0)
				{
					printf("Por favor, cargue los datos antes de realizar esta operacion.\n");
				}
				else
				{
					controller_sortEmployee(listaEmpleados);
					printf("Operacion exitosa.\n");

				}
				break;


		case 8:
			if(banderaLectura == 0)
			{
				printf("Por favor, cargue los datos antes de realizar esta operacion.\n");
			}
			else
			{
				banderaCambios = 1;
				controller_saveAsText(ARCHIVOTEXTO, listaEmpleados);
				printf("Operacion exitosa.\n");

			}
			break;

		case 9:
				if(banderaLectura == 0)
				{
					printf("Por favor, cargue los datos antes de realizar esta operacion.\n");
				}
				else
				{
					banderaCambios = 1;
					controller_saveAsBinary(ARCHIVOBINARIO, listaEmpleados);
					printf("Operacion exitosa.\n");

				}
				break;

		case 10:
					if(banderaLectura != 0)
					{
						if(banderaCambios == 0)
						{
							printf("Asegurese de guardar correctamente sus modificaciones.\n");
							printf("1. Guardar en texto\n2. Guardar en binario\n3. Salir\n");
							GetNumero(&option, "Seleccione la opcion deseada:\n", "Opcion incorrecta. Reingrese:\n", 1, 3, 5);
							switch (option)
							{
							case 1:
								controller_saveAsText(ARCHIVOTEXTO, listaEmpleados);
								banderaCambios = 1;
								printf("Operacion exitosa.\n");

								break;

							case 2:
								controller_saveAsBinary(ARCHIVOBINARIO, listaEmpleados);
								banderaCambios = 1;
								printf("Operacion exitosa.\n");

								break;

							case 3:
								option = 10;
								banderaCambios = 1;
								printf("Operacion exitosa.\n");

								break;
							}
						}
					}
					break;
		}
	} while (option != 10);
	return 0;
}

