/*
 * input.h
 *
 *  Created on: 9 sep. 2021
 *      Author: Leandro
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_
#include <stdio.h>
#include <stdlib.h>

int MostrarPunteroFlotante(float *numeroFlotante);
///@brief Funcion que muestra un numero flotante que se la pasa como parametro
/// @param puntero a variable de tipo flotante
/// @return devuelve 1 si la funcion se ejecuto correctamente.
float IngresarNumero(char mensaje[], int *numeroIngresado);
///@brief Pide el ingreso de un numero
///@param Un mensaje impreso en pantalla donde pide el numero
/// @param Recibe un numero entero
/// @return devuelve un numero flotante
void IngresarArrayDeNumeros(int numeros[], int T);
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

int FormatearCadena(char cadena[]);
int RetornarNombreCompleto(char nombre[], char apellido[], char nombreCompleto[]);
int PedirEnteroValidadoEnRango(char[], int, int);
int ValidarNumero(int);
///@brief Valida si es positivo, negativo o 0.
/// @param numero ingresado
/// @return devuelve 1 si es positivo, -1 si es negativo .
void MostrarNumerosIngresados(char[], int numeros[], int T); //Muestra el array de los numeros ingresados.
void MostrarNumerosPares(char[], int numeros[], int T);
void MostrarNumerosImpares(char[], int numeros[], int T);
int VerificarParidad(int numeroIngresado);
///@brief verifica si el numero ingresado es par o impar
/// @param numero ingresado a verificar
/// @return devuelve 0 si es par , 1 si es impar y -1 si hubo un error
int Sumar1(int,int);
int Sumar2(void);
void Sumar3(int, int);
void Sumar4(void);
int SumarYMostrarNumeros(char[],int[], int);
///@brief Pide el ingreso de un array de numeros,los suma y los muestra por pantalla
/// @param mensaje a pasarle como primer parametro
/// @param array de enteros a pasarle como segundo parametro
/// @param constante a pasarle como parametro
/// @return devuelve la suma de los numeros
int PedirNumero(char mensaje[],int *num);
int GetNumero(int *pResultado, char *mensaje, char *mensajeError, int min, int max, int reintentos);
///@brief funcion que pide el ingreso de un numero validado en un rango y da una cantidad de reintentos
/// @param puntero al espacio en memoria en donde se dejara el resultado de la funcion
/// @param mensaje de ingreso de datos
/// @param mensaje de error por si los datos no son validos
/// @param numero minimo a ingresar
/// @param numero maximo a ingresar
/// @param reintentos posibles
/// @return Devuelve 0 si la funcion fue ejecutada con exito. -1 si hubo un error
int GetFlotante(float *pResultado, char *mensaje, char *mensajeError, float min, float max, int reintentos);
///@brief funcion que pide el ingreso de un flotante validado en un rango y da una cantidad de reintentos
/// @param puntero al espacio en memoria en donde se dejara el resultado de la funcion
/// @param mensaje de ingreso de datos
/// @param mensaje de error por si los datos no son validos
/// @param numero minimo a ingresar
/// @param numero maximo a ingresar
/// @param reintentos posibles
/// @return Devuelve 0 si la funcion fue ejecutada con exito. -1 si hubo un error
int GetCaracter(char *pResultado, char *mensaje, char *mensajeError, char min, char max, int reintentos);
///@brief funcion que pide el ingreso de un caracter validado en un rango y da una cantidad de reintentos
/// @param puntero que apunta al caracter
/// @param mensaje de ingreso de datos
/// @param mensaje de error por si los datos no son validos
/// @param caracter minimo a ingresar
/// @param caracter maximo a ingresar
/// @param reintentos posibles
/// @return Devuelve 0 si la funcion fue ejecutada con exito. -1 si hubo un error
 int GetInt(int *resultado);
 int GetFloat(float *pResultado);
 int EsNumerica(char *cadena, int limite);
 ///@brief verifica si la cadena ingresada es numerica
 /// @param cadena a ser verificada
 /// @return devuelve -1 si hay error de parametros, 1 si la cadena es numerica y 0 si es falso
 int EsFlotante(char *cadena);
///@brief verifica si la cadena es flotante
/// @param cadena a ser verificada
/// @return devuelve 1 si la cadena es flotante y 0 si no es flotante
 int MyGets(char *cadena, int longitud);
 int GetString(char mensaje[],char cadena[]);
 ///@brief Pide el ingreso de una cadena de texto y muestra un mensaje
 /// @param mensaje a mostrar
 /// @param cadena de texto ingresada
 /// @return devuelve 1 si la funcion fue ejecutada
 int MyIsAlpha(char cadena[]);
 int GetName(char mensaje[],char mensajeError[] , char cadena[]);
#endif /* FUNCIONES_H_ */

