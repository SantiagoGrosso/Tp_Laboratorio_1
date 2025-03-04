
/*
 * ArrayPassenger.h
 *
 *  Created on: 11 may. 2022
 *      Author: RYZEN 2700X
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

#include "InputsYValidaciones.h"

typedef struct
	{
		int id;
		char name[51];
		char lastname[51];
		float price;
		char flycode[10];
		int idStatusFlight;
		int idTypePassenger;
		int isEmpty;

	}sPassenger;

	/// @brief Incia todos los espacios en vac�o, para la carga.
	///
	/// @param list La lista de pasajeros.
	/// @param len El tama�o de la lista.
	/// @return Retorna los lugares vac�os.
	int initPassengers(sPassenger list[], int len);

	/// @brief Busca un pasajero por ID.
	///
	/// @param list La lista de pasajeros.
	/// @param len El tama�o de esta.
	/// @param id El ID.
	/// @return Retorna el id.
	int findPassengerById(sPassenger list[], int len,int id);

	/// @brief Para eliminar un pasajero.
	///
	/// @param list La lista de pasajeros.
	/// @param len El tama�o de esta.
	/// @param id El ID.
	/// @return Retorna si se pudo eliminar o no el pasajero.
	int removePassenger(sPassenger list[], int len, int id);

	/// @brief Acomoda los pasajeros por apellido y tipo de pasajero.
	///
	/// @param passengerList La lista de pasajeros.
	/// @param size El tama�o de esta.
	/// @param order El orden (si ascendente o descendente).
	/// @return Retorna ordenada la lista de manera ascendente o descendente.
	int sortPassengers(sPassenger passengerList[], int size, int order);

	/// @brief Ordena los pasajeros por el c�digo de vuelo y si el estado es "Activo" (en horario o en curso).
	///
	/// @param list La lista de pasajeros.
	/// @param len El tama�o de esta.
	/// @param order El orden (si ascendente o descendente)
	/// @return Retorna ordenada la lista de manera ascendente o descendente.
	int sortPassengersByCode(sPassenger list[], int len, int order);

	/// @brief Busca el primer espacio libre.
	///
	/// @param list La lista de pasajeros.
	/// @param size el tama�o de la lista.
	/// @return Retorna donde hay un espacio libre.
	int BuscarEspacioLibre(sPassenger list[], int size);

	/// @brief Busca si hay alg�n espacio ocupado para que no pueda hacer nada sin cargar 1 pasajero.
	///
	/// @param list La lista de pasajeros.
	/// @param size El tama�o de esta.
	/// @return Retorna si encontr� alg�n espacio ocupado.
	int BuscarEspacioOcupado(sPassenger list[], int size);

	/// @brief Calcula el promedio de los viajes.
	///
	/// @param list La lista de pasajeros.
	/// @param size el tama�o de la lista.
	/// @return Retorna el promedio de los viajes,
	float CalcularPromedioViajes(sPassenger list[], int size);

	/// @brief Hace la carga forzada de 5 pasajeros.
	///
	/// @param list La lista de pasajeros.
	/// @param size El tama�o de esta.
	void CargaForzada (sPassenger list[], int size);

#endif /* ARRAYPASSENGER_H_ */
