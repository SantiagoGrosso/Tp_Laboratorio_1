/*
 * InputsYValidaciones.h
 *
 *  Created on: 29 jun. 2022
 *      Author: RYZEN 2700X
 */

#ifndef INPUTSYVALIDACIONES_H_
#define INPUTSYVALIDACIONES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define VACIO 1
#define OCUPADO 0

/// @brief Permite pedir un flotante y validarlo.
///
/// @param mensaje Para mostrar un mensaje.
/// @param minimo Validar entre el m�nimo.
/// @param maximo Validar entre el m�ximo.
/// @return Retorna un flotante.
float IngresarFlotante(char mensaje [], float minimo, float maximo);

/// @brief Permite pedir un entero y validarlo.
///
/// @param mensaje Para mostrar un mensaje.
/// @param minimo Validar entre el m�nimo.
/// @param maximo Validar entre el m�ximo.
/// @return Retorna un entero.
int IngresarEntero(char mensaje [], int minimo, int maximo);

/// @brief Pide un un caracter.
///
/// @param mensaje Para mostrar un mensaje.
/// @return	Retorna un caracter.
char IngresarCaracter(char mensaje []);

/// @brief Pide la carga de un vector.
///
/// @param El vector.
/// @param size El tama�o del vector.
void CargarVector(int numeros[], int size);

/// @brief Pide la carga de una cadena.
///
/// @param cadena La cadena.
/// @param mensaje Para mostrar un mensaje.
void CargarCadena(char cadena[],char mensaje[]);

/// @brief Busca espacios y transforma en may�scula la primera letra de los nombres.
///
/// @param NombreApellido La cadena a cambiar.
void DetectarEspacio (char NombreApellido []);

/// @brief Da el id incremental.
///
/// @return Retorna el id incremental.
int obtenerID();

/// @brief Valida n�meros para que no ingresen ni letras ni caracteres especiales.
///
/// @param numeros Pasa los n�meros como cadena para validarlos.
/// @return Retorna los n�meros validados.
int ValidarNumero (char numeros[]);

/// @brief Valida letras para que no ingresen ni n�meros ni caracteres especiales.
///
/// @param cadena La cadena a validar.
/// @return La cadena validada.
int ValidacionDeCaracteres (char cadena[]);

/// @brief Calcula promedios.
///
/// @param acumulador La variable a ser divida.
/// @param contador La variable por la que se divide.
/// @return Retorna el promedio con la divisi�n.
float CalcularPromedio (float acumulador, int contador);


#endif /* INPUTSYVALIDACIONES_H_ */
