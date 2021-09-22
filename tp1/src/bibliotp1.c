/*
 * input.c
 *
 *  Created on: 9 sep. 2021
 *      Author: Leandro
 */

#include "bibliotp1.h"


float IngresarNumero(char mensaje[])
{
	float numeroIngresado;

	printf("%s", mensaje);
	scanf("%f", &numeroIngresado);

	return numeroIngresado;
}



void PedirNumero(int numeros[], int T) {

	int i;

	for (i = 0; i < T; i++) {
		printf("Ingrese un numero:\n ");
		scanf("%d", &numeros[i]);
	}

}


double Operaciones(float numeroUno, float numeroDos, char operacion)
{
	double resultado;

	switch(operacion)
	{
		case '+':
			resultado = numeroUno + numeroDos;
			break;

		case '-':
			resultado = numeroUno - numeroDos;
			break;

		case '*':
			resultado = numeroUno * numeroDos;
			break;

		case '/':
			if(numeroDos == 0)
			{
				resultado = -999;
			}
			else
			{
				resultado = numeroUno / numeroDos;
			}
			break;

		case '!':
			if(numeroUno == 0)
			{
				resultado = 1;
			}
			else
			{
				if(numeroUno > 0)
				{
					resultado = CalculoFactorial(numeroUno);
				}
				else
				{
					resultado = -1;
				}
			}
			break;
	}

	return resultado;
}


long double CalculoFactorial(int valor)
{
	long double respuesta;

	if(valor == 1)
	{
		respuesta = 1;
	}
	else
	{
		respuesta = valor * CalculoFactorial(valor-1);
	}

	return respuesta;
}

int ValidarFlotante(float numeroIngresado)
{
	int enteroDeNumeroIngresado;
	float resultado;
	int respuesta;

	enteroDeNumeroIngresado = numeroIngresado;
	resultado = numeroIngresado - enteroDeNumeroIngresado;

	if(resultado != 0)
	{
		respuesta = 1;
	}
	else
	{
		respuesta = 0;
	}

	return respuesta;
}

char IngresarCaracter(char mensaje[])
{
	char caracterIngresado;

	printf("%s", mensaje);
	scanf("%c", &caracterIngresado);

	return caracterIngresado;
}


int SumarNumero(int numeros[], int T) {
	int acumulador;
	int i;

	acumulador = 0;

	for (i = 0; i < T; i++) {

		acumulador += numeros[i];
	}

	return acumulador;
}

int PedirEnteroValidadoEnRango(char mensaje[], int minimo, int maximo) {

	int numeroIngresado;

	printf("%s", mensaje);
	scanf("%d", &numeroIngresado);

	while (numeroIngresado < minimo || numeroIngresado > maximo) {
		printf("Error. Ingrese un numero entre -1000 y 1000: \n");
		scanf("%d", &numeroIngresado);
	}

	return numeroIngresado;

}

int ValidarNumero(int numeroIngresado) {

	int resultado;

	if (numeroIngresado > 0) {
		resultado = 1;
	} else {
		if (numeroIngresado < 0) {
			resultado = -1;
		} else {
			resultado = 0;
		}
	}

	return resultado;
}

int VerificarParidad(int numeroIngresado) {
	int resultado;

	if (numeroIngresado % 2 == 0) {
		resultado = 1;
	} else {
		resultado = 0;
	}

	return resultado;
}

void MostrarNumerosIngresados(char mensaje[], int numeroIngresado[], int T) {

	int i;
	printf("%s", mensaje);
	for (i = 0; i < T; i++) {
		printf("\n%d", numeroIngresado[i]);
	}
}

void MostrarNumerosPares(char mensaje[], int numeroIngresado[], int T) {

	int i;
	printf("%s", mensaje);
	for (i = 0; i < T; i++) {
		if (VerificarParidad(numeroIngresado[i]) == 1) {
			printf("\n%d", numeroIngresado[i]);
		}
	}

}

void MostrarNumerosImpares(char mensaje[], int numeroIngresado[], int T){

	int i;
		printf("%s", mensaje);
		for (i = 0; i < T; i++) {

			if (VerificarParidad(i) == 0) {
				printf("\n\t- El valor en la posicion impar [%d] es: %d",i,numeroIngresado[i]);
			}
		}

}


