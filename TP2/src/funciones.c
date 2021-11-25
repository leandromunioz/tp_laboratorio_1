/*
 * input.c
 *
 *  Created on: 9 sep. 2021
 *      Author: Leandro
 */

#include "funciones.h"
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
int MostrarPunteroFlotante(float *numeroFlotante) {

	int retorno;
	retorno = 1;
	if (numeroFlotante != NULL) {
		printf("Su numero flotante es: %f\n", *numeroFlotante);
	}
	return retorno;
}

void IngresarArrayDeNumeros(int numeros[], int T) {

	int i;

	for (i = 0; i < T; i++) {
		printf("Ingrese un numero:\n ");
		scanf("%d", &numeros[i]);
	}

}

float IngresarNumero(char mensaje[], int *numeroIngresado) {
	int retorno;

	retorno = 1;

	printf("%s", mensaje);
	scanf("%d", numeroIngresado);

	return retorno;
}

int PedirEnteroValidadoEnRango(char mensaje[], int minimo, int maximo) {

	int numeroIngresado;

	printf("%s", mensaje);
	scanf("%d", &numeroIngresado);

	while (numeroIngresado < minimo || numeroIngresado > maximo) {
		printf("Error. Ingrese un numero valido en el rango disponible. \n");
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
		}
	}

	return resultado;
}

int RetornarNombreCompleto(char nombre[], char apellido[],
		char nombreCompleto[]) {

	int retorno;
	retorno = 0;

	if (nombre != NULL && apellido != NULL) {

		strcpy(nombreCompleto, apellido);
		strcat(nombreCompleto, ", ");
		strcat(nombreCompleto, nombre);

		FormatearCadena(nombreCompleto);

		retorno = 1;
	}

	return retorno;
}

int FormatearCadena(char cadena[]) {

	int retorno;
	int i;
	int tam;

	retorno = 0;
	tam = strlen(cadena);
	strlwr(cadena);

	if (cadena != NULL) {
		for (i = 0; i < tam; i++) {
			if (i == 0 || cadena[i - 1] == 32) {
				cadena[i] = toupper(cadena[i]);
			}
		}
		retorno = 1;
	}
	return retorno;
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
		if (VerificarParidad(numeroIngresado[i]) == 0) {
			printf("\n%d", numeroIngresado[i]);
		}
	}

}

void MostrarNumerosImpares(char mensaje[], int numeroIngresado[], int T) {

	int i;
	printf("%s", mensaje);
	for (i = 0; i < T; i++) {

		if (VerificarParidad(i) == 1) {
			printf("\n\t- El valor en la posicion impar [%d] es: %d", i,
					numeroIngresado[i]);
		}
	}

}

int pedirCadena(char mensaje[], char input[]) {

	printf("%s", mensaje);
	fflush(stdin);
	scanf("%s", input);

	return 1;
}

double Operaciones(float numeroUno, float numeroDos, char operacion) {
	double resultado;

	switch (operacion) {
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
		if (numeroDos == 0) {
			resultado = -999;
		} else {
			resultado = numeroUno / numeroDos;
		}
		break;

	case '!':
		if (numeroUno == 0) {
			resultado = 1;
		} else {
			if (numeroUno > 0) {
				resultado = CalculoFactorial(numeroUno);
			} else {
				resultado = -1;
			}
		}
		break;

	case 'P':
		resultado = numeroUno / numeroDos;
		break;
	}

	return resultado;
}

long double CalculoFactorial(int valor) {
	long double respuesta;

	if (valor == 1) {
		respuesta = 1;
	} else {
		respuesta = valor * CalculoFactorial(valor - 1);
	}

	return respuesta;
}

int VerificarParidad(int numeroIngresado) {

	int retorno;
	retorno = -1;
	if (numeroIngresado % 2 == 0) {
		retorno = 0;
	} else {

		retorno = 1;
	}
	return retorno;
}

int Sumar1(int num1, int num2) {
	int resultado;
	resultado = num1 + num2;

	return resultado;
}

int Sumar2(void) {
	int resultado;
	int n1;
	int n2;
	printf("Ingrese el primer numero:\n");
	scanf("%i", &n1);
	printf("Ingrese el segundo numero:\n");
	scanf("%i", &n2);
	resultado = n1 + n2;

	return resultado;
}

void Sumar3(int num1, int num2) {

	int resultado;
	resultado = num1 + num2;
	printf("El resultado es :\n%i", resultado);
}

void Sumar4(void) {
	int n1;
	int n2;
	printf("Ingrese el primer numero:\n");
	scanf("%i", &n1);
	printf("Ingrese el segundo numero:\n");
	scanf("%i", &n2);
	int resultado = n1 + n2;
	printf("El resultado es :\n%i", resultado);

}

int SumarYMostrarNumeros(char mensaje[], int numeros[], int tam) {

	int i;
	int acumulador;
	acumulador = 0;

	for (i = 0; i < tam; i++) {
		printf("%s", mensaje);
		scanf("%i", &numeros[i]);
		acumulador += numeros[i];

	}
	printf("La suma de los numeros es:\n%i", acumulador);

	return acumulador;
}

int PedirNumero(char mensaje[], int *num) {
	int retorno;
	retorno = 1;
	if (num != NULL) {
		printf("%s", mensaje);
		scanf("%i", num);
	}
	return retorno;
}

int GetNumero(int *pResultado, char *mensaje, char *mensajeError, int min,
		int max, int reintentos) {

	int retorno = -1;
	int bufferInt;
	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
			&& min <= max && reintentos >= 0) {
		do {
			printf("%s", mensaje);
			//scanf("%i", &bufferInt); aca se reemplaza por GetInt
			if (GetInt(&bufferInt) == 0 && bufferInt >= min
					&& bufferInt <= max) {
				*pResultado = bufferInt;
				retorno = 0;
				break;
			} else {
				printf("%s", mensajeError);
				reintentos--;
			}

		} while (reintentos >= 0);
	}

	return retorno;
}

int GetFlotante(float *pResultado, char *mensaje, char *mensajeError, float min,
		float max, int reintentos) {
	int retorno = -1;
	float bufferFloat;
	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
			&& min <= max && reintentos >= 0) {
		do {
			printf("%s", mensaje);
			scanf("%f", &bufferFloat);
			if (bufferFloat >= min && bufferFloat <= max) {
				*pResultado = bufferFloat;
				retorno = 0;
				break;
			} else {
				printf("%s", mensajeError);
				reintentos--;
			}

		} while (reintentos >= 0);
	}

	return retorno;
}

int GetCaracter(char *pResultado, char *mensaje, char *mensajeError, char min,
		char max, int reintentos) {

	int retorno = -1;
	char bufferChar;
	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
			&& min <= max && reintentos >= 0) {
		do {
			printf("%s", mensaje);
			fflush(stdin);
			scanf("%c", &bufferChar);
			if (bufferChar >= min && bufferChar <= max) {
				*pResultado = bufferChar;
				retorno = 0;
				break;
			} else {
				printf("%s", mensajeError);
				reintentos--;
			}

		} while (reintentos >= 0);
	}

	return retorno;
}

int GetInt(int *pResultado) {
	int retorno = -1;
	char buffer[4096];

	if (MyGets(buffer, sizeof(buffer)) == 0 && EsNumerica(buffer, 10)) {
		retorno = 0;
		*pResultado = atoi(buffer);
	}

	return retorno;
}

int EsNumerica(char *cadena, int limite) {

	int retorno = -1; // ERROR
	int i = 0;
	if (cadena != NULL && limite > 0) {
		retorno = 1; //VERDADERO
		for (i = 0; i < limite && cadena[i] != '\0'; i++) {
			if (i == 0 && cadena[i] == '+' && cadena[i] == '-') {
				continue;
			}
			if (cadena[i] > '9' || cadena[i] < '0') {
				retorno = 0;
				break;
			}
			//CONTINUE
		}
		//BREAK
	}

	return retorno;
}

int MyGets(char *cadena, int longitud) {

	fflush(stdin);
	fgets(cadena, longitud, stdin);
	cadena[strlen(cadena) - 1] = '\0';
	return 0;
}

int GetFloat(float *pResultado) {

	int retorno = -1;
	char buffer[4096];

	if (pResultado != NULL) {

		if (MyGets(buffer, sizeof(buffer)) == 0 && EsFlotante(buffer)) {
			retorno = 0;
			*pResultado = atof(buffer);
		}
	}
	return retorno;

}

int EsFlotante(char *cadena) {
	int i = 0;
	int retorno = 1;
	int contadorPuntos = 0;

	if (cadena != NULL && strlen(cadena) > 0) {
		for (i = 0; cadena[i] != '\0'; i++) {
			if (i == 0 && (cadena[i] == '-' || cadena[i] == '+')) {
				continue;
			}
			if (cadena[i] > '9' || cadena[i] < '0') {
				if (cadena[i] == '.' && contadorPuntos == 0) {
					contadorPuntos++;
				} else {
					retorno = 0;
					break;
				}

			}
		}
	}

	return retorno;
}

int GetString(char mensaje[], char cadena[]) {
	int retorno;
	retorno = 0;
	if (mensaje != NULL && cadena != NULL) {
		fflush(stdin);
		printf("\n%s", mensaje);
		scanf("%[^\n]", cadena);
		retorno = 1;
	}
	return retorno;
}

int GetName(char mensaje[], char mensajeError[], char cadena[]) {
	int retorno;
	retorno = 0;

	if (mensaje != NULL && cadena != NULL) {
		printf("\n%s", mensaje);
		fflush(stdin);
		scanf("%[^\n]", cadena);
		while (MyIsAlpha(cadena) == -1) {
			printf("%s", mensajeError);
			fflush(stdin);
			scanf("%[^\n]", cadena);
		}
		retorno = 1;
	}
	return retorno;
}

int MyIsAlpha(char cadena[]) {
	int i;
	int retorno;
	int flagNonAlphabetic;

	i = 0;
	flagNonAlphabetic = 0;
	retorno = 1;

	if (cadena != NULL && strlen(cadena) > 0) {
		while ((i < strlen(cadena) || cadena[i] != '\0')
				&& flagNonAlphabetic == 0) {
			if (!isalpha(cadena[i])) {
				flagNonAlphabetic = 1;
				retorno = -1;
			} else {
				i++;
			}
		}
	}

	return retorno;
}

