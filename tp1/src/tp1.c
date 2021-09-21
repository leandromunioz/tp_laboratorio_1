/*
 ============================================================================
 Name        : tp1.c
 Author      : Leandro Mu�oz DIV C
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "bibliotp1.h"
#include "conio.h"

int main(void) {

	int opcion;
	float primerOperando;
	float segundoOperando;
	int banderaPrimerOperando;
	int banderaSegundoOperando;
	float resultadoSuma;
	float resultadoResta;
	float resultadoMultiplicacion;
	float resultadoDivision;
	long double resultadoFactorialA;
	long double resultadoFactorialB;
	int banderaOperacionesSinCompletar;


	banderaPrimerOperando=1;
	banderaSegundoOperando=1;
	banderaOperacionesSinCompletar=1;
	setbuf(stdout,NULL);
	do {
		if(banderaPrimerOperando==1)
				{
					printf("1- Ingresar primer operando (A=X) ");
				}
				else
				{
					printf("1- Ingrese el primer operando (A = %.2f) \n", primerOperando);
				}
				if(banderaSegundoOperando==1)
				{
					printf("\n2- Ingresar segundo operando (B=Y) ");
				}
				else
				{
					printf("2- Ingrese el segundo operando (B= %.2f)", segundoOperando);
				}

				opcion=IngresarNumero("\n3- Calcular todas las operaciones. \n4- Informar los resultados obtenidos.\n5- Salir. \nSeleccione la opcion deseada...");
		switch (opcion)
		{
		case 1:
			primerOperando=IngresarNumero("Ingrese el primer operando:\n");
			banderaPrimerOperando=0;
			system("cls");
			break;
		case 2:
			segundoOperando=IngresarNumero("Ingrese el segundo operando:\n");
			banderaSegundoOperando=0;
			system("cls");
			break;
		case 3:
			if(banderaPrimerOperando==1)
			{
				primerOperando=IngresarNumero("Por favor, ingrese el operando solicitado para realizar las operaciones.");
				banderaPrimerOperando=0;
			}
			if(banderaSegundoOperando==1)
			{
				segundoOperando=IngresarNumero("Por favor, ingrese el operando solicitado para realizar las operaciones.");
				banderaSegundoOperando=0;
			}
			system("cls");

			resultadoSuma=Operaciones(primerOperando, segundoOperando,'+');
			resultadoResta=Operaciones(primerOperando, segundoOperando,'-');
			resultadoMultiplicacion=Operaciones(primerOperando, segundoOperando,'*');
			resultadoDivision=Operaciones(primerOperando, segundoOperando,'/');
			resultadoFactorialA=Operaciones(primerOperando,0,'!');
			resultadoFactorialB=Operaciones(segundoOperando,0,'!');
			banderaOperacionesSinCompletar=0;

			printf("a- Calcular la suma (A+B)\nb- Calcular la resta (A-B)\nc- Calcular la multiplicacion (A*B)\nd- Calcular la division (A/B)\ne- Calcular el factorial (A!)\n");
			printf("4-Seleccione para mostrar los resultados obtenidos...");
			getch();
			system("cls");
			break;
		case 4:
			if(	banderaOperacionesSinCompletar==1)
							{
								printf("El programa debe calcular todas las operaciones antes de poder mostrar el resultado.");
								getch();
								system("cls");
							}
							else
							{
								printf("El resultado de A+B es: %.2f\nEl resultado de A-B es: %.2f\nEl resultado de A*B es: %.2f", resultadoSuma, resultadoResta, resultadoMultiplicacion);
								if(segundoOperando == 0)
								{
									printf("\nEl resultado de A/B es:\n ERROR. No es posible dividir por 0. Ingrese un operando disinto a 0.");
								}
								else
								{
									printf("\nEl resultado de A/B es: %.2f", resultadoDivision);
								}
								if(primerOperando < 0 || ValidarFlotante(primerOperando) == 1)
								{
									printf("\nEl factorial de A es: \nERROR. No es posible realizar el factorial de un numero con decimales o negativo. Ingrese un operando diferente.");
								}
								else
								{
									printf("\nEl factorial de A es: %.0Lf", resultadoFactorialA);
								}
								if(segundoOperando < 0 || ValidarFlotante(segundoOperando) == 1)
								{
									printf("\nEl factorial de B es:\n ERROR. No es posible realizar el factorial de un numero con decimales o negativo. Ingrese un operando diferente.");
								}
								else
								{
									printf("\nEl factorial de B es: %.0Lf", resultadoFactorialB);
								}
								getch();
								system("cls");
							}
			break;

		}
	} while (opcion != 5);

	return EXIT_SUCCESS;
}

