/*
 * input.h
 *
 *  Created on: 9 sep. 2021
 *      Author: Leandro
 */

#ifndef BIBLIOTP1_H_
#define BIBLIOTP1_H_
#include <stdio.h>
#include <stdlib.h>

float IngresarNumero(char mensaje[]);
///@brief Pide el ingreso de un numero
///@param Un mensaje impreso en pantalla donde pide el numero
/// @param Recibe un numero entero
/// @return devuelve un numero flotante
void PedirNumero(int numeros[], int T);
double Operaciones(float numeroUno, float numeroDos, char operador);
///@brief Realiza operaciones matematicas y el calculo del factorial
/// @param primer numero a calcular
/// @param segundo numero a calcular
/// @param tipo de operacion a realizar
/// @return devuelve el resultado de la operacion
long double CalculoFactorial(int valor);
///@brief Realiza el calculo del factorial
/// @param primer numero a calcular el factorial
/// @return devuelve el resultado de la operacion
int ValidarFlotante(float numeroIngresado);
///@brief Verifica que el numero ingresado sea un numero float o int
/// @param  numero a validar
/// @return devuelve el valor de verdad de la variable retorno.
char IngresarCaracter(char mensaje[]); //Pide el ingreso de un caracter.
int SumarNumero(int numeros[], int T); //Realiza la suma de números.
int PedirEnteroValidadoEnRango(char[], int, int); //Pide numeros validados entre -1000 y 1000.
int ValidarNumero(int); // Valida si es positivo, negativo o 0.
int VerificarParidad(int); //Verifica si es par o impar.
void MostrarNumerosIngresados(char[], int numeros[], int T); //Muestra el array de los numeros ingresados.
void MostrarNumerosPares(char[], int numeros[], int T);
void MostrarNumerosImpares(char[], int numeros[], int T);

#endif /* BIBLIOTP1_H_ */

