/*
 * InputsYValidaciones.h
 *
 *  Created on: 4 jun. 2022
 *      Author: RYZEN 2700X
 */

#ifndef INPUTSYVALIDACIONES_H_
#define INPUTSYVALIDACIONES_H_



#endif /* INPUTSYVALIDACIONES_H_ */

/// @fn float IngresarFlotante(char[], float, float)
/// @brief Funci�n para ingresar y validar un flotante.
///
/// @param mensaje El mensaje para darle a entender al usuario lo que queremos.
/// @param minimo El m�nimo requerido.
/// @param maximo El m�ximo requerido.
/// @return Retorna el flotante validado.
float IngresarFlotante(char mensaje [], float minimo, float maximo);

/// @fn int IngresarEntero(char[], int, int)
/// @brief Funci�n para ingresar y validar un entero.
///
/// @param mensaje El mensaje para darle a entender al usuario lo que queremos.
/// @param minimo El m�nimo requerido.
/// @param maximo El m�ximo requerido.
/// @return Retorna el entero validado.
int IngresarEntero(char mensaje [], int minimo, int maximo);

/// @fn char IngresarCaracter(char[])
/// @brief Funci�n para ingresar un caracter.
///
/// @param mensaje El mensaje para darle a entender al usuario lo que queremos.
/// @return Retorna el caracter.
char IngresarCaracter(char mensaje []);

/// @fn void CargarVector(int[], int)
/// @brief Para cargar un vector de numeros.
///
/// @param numeros El vector.
/// @param size El tama�o de este.
void CargarVector(int numeros[], int size);

/// @fn void CargarCadena(char[], char[])
/// @brief Para cargar una cadena.
///
/// @param cadena La cadena.
/// @param mensaje El mensaje para darle a entender al usuario lo que queremos.
void CargarCadena(char cadena[],char mensaje[]);

/// @fn void DetectarEspacio(char[])
/// @brief Busca espacios y transforma en may�scula la primera letra de los nombres o luego de encontrar un espacio.
///
/// @param NombreApellido La cadena a cambiar.
void DetectarEspacio (char NombreApellido []);

/// @fn int obtenerID()
/// @brief Da el id incremental.
///
/// @return Retorna el id incremental.
int obtenerID();

/// @fn int ValidarNumero(char[])
/// @brief Valida n�meros para que no ingresen ni letras ni caracteres especiales.
///
/// @param numeros Pasa los n�meros como cadena para validarlos.
/// @return Retorna los n�meros validados.
int ValidarNumero (char numeros[]);

/// @fn int ValidacionDeCaracteres(char[])
/// @brief Valida letras para que no ingresen ni n�meros ni caracteres especiales.
///
/// @param cadena La cadena a validar.
/// @return La cadena validada.
int ValidacionDeCaracteres (char cadena[]);

/// @fn float CalcularPromedio(float, int)
/// @brief Calcula promedios.
///
/// @param acumulador La variable a ser divida.
/// @param contador La variable por la que se divide.
/// @return Retorna el promedio con la divisi�n.
float CalcularPromedio (float acumulador, int contador);

/// @fn int ValidarDias(int)
/// @brief Valida los d�as para que no puedan ingresar m�s cantidad de d�as de los que tiene un mes determinado.
///
/// @param mes El mes que eligieron anteriormente.
/// @return Retorna el d�a validado.
int ValidarDias(int mes);
