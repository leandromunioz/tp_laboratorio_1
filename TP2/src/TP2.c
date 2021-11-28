/*
 ============================================================================
 Name        : TP2.c
 Author      : Leandro Mu�oz DIV C
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include <unistd.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#define TAM 5

int main(void) {

	setbuf(stdout, NULL);
	Employee empleados[TAM];
	initEmployees(empleados, TAM);
	int opcion;
	int id = 0;
	int banderaDeAlta = 0;

	do {

		if (GetNumero(&opcion,
				" 1.ALTAS\n 2.MODIFICACION\n 3.BAJA\n 4.INFORMAR\n Seleccione la opcion deseada: ",
				"Opcion invalida. Reingrese: ", 1, 4, 5) != -1) {

			switch (opcion) {
			case 1:
				if (altaUsuario(empleados, TAM, &id) == 1) {
					printf("El empleado fue dado de alta exitosamente.\n");
					banderaDeAlta = 1;
				} else {
					printf("Ha ocurrido un error en la carga del empleado.\n");
				}
				break;

			case 2:
				if (banderaDeAlta == 1) {
					modificarUsuario(empleados, TAM);
				} else {

					printf(
							"Para continuar con el programa por favor cargue en el sistema al menos un empleado.\n");
				}
				break;
			case 3:
				if (banderaDeAlta == 1) {
					eliminarUsuario(empleados, TAM);
				} else {
					printf(
							"Para continuar con el programa por favor, cargue en el sistema al menos un empleado.\n");

				}
				break;
			case 4:
				if (banderaDeAlta == 1) {
					mostrarEmpleados(empleados, TAM);
				} else {
					printf(
							"Para continuar con el programa por favor cargue en el sistema al menos un empleado.\n");

				}
				break;
			}

		} else {
			printf("Error. Se acabaron los reintentos. Reinicie el programa.\n");
		}

	} while (opcion != 0);

	return EXIT_SUCCESS;
}
