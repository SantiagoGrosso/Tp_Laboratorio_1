/*
 * Nexo.h
 *
 *  Created on: 29 jun. 2022
 *      Author: RYZEN 2700X
 */

#ifndef NEXO_H_
#define NEXO_H_

#include "InputsYValidaciones.h"
#include "ArrayPassenger.h"
#include "StatusFlight.h"
#include "TypePassenger.h"

/// @brief Para cargar un pasajero.
///
/// @param unPasajero Donde se carga el pasajero.
/// @param statusFlight La estructura del estado de vuelo.
/// @param size El tama�o de esta.
/// @param typePassenger La estructura del tipo de pasajero.
/// @param segundoSize El tama�o de esta.
/// @return Retorna un pasajero cargado.
sPassenger ingresarPasajero(sPassenger unPasajero, sStatusFlight statusFlight[], int size, sTypePassenger typePassenger[], int segundoSize);

/// @brief A�ade un pasajero a la lista.
///
/// @param unPasajero La estructura de un pasajero cargada.
/// @param statusFlight La estructura del estado de vuelo.
/// @param size El tama�o de esta.
/// @param typePassenger La estructura del tipo de pasajero.
/// @param segundoSize El tama�o de esta.
/// @param list La lista de pasajeros.
/// @param tercerSize El tama�o de esta.
/// @return Retorna si se pudo o no cargar al pasajero.
int addPassenger(sPassenger unPasajero, sStatusFlight statusFlight[], int size,
						 sTypePassenger typePassenger[], int segundoSize, sPassenger list[], int tercerSize);

/// @brief Muestra la lista de pasajeros.
///
/// @param passengerList La lista de pasajeros.
/// @param size El tama�o de esta.
/// @param statusFlight La estructura del estado de vuelo.
/// @param typePassenger La estructura del tipo de pasajero.
/// @return Retorna la lista printeada.
int printPassengers(sPassenger passengerList[], int size, sStatusFlight statusFlight[], sTypePassenger typePassenger[]);

/// @brief La funci�n para modificar los datos del pasajero.
///
/// @param list La lista de pasajeros.
/// @param size El tama�o de esta.
/// @param statusFlight La estructura del estado de vuelo.
/// @param otroSize El tama�o de esta.
/// @param typePassenger La estructura del tipo de pasajero.
/// @param segundoSize El tama�o de esta.
/// @return Retorna la si se modific� alg�n dato o no.
int ModificarPasajero(sPassenger list[], int size, sStatusFlight statusFlight[], int otroSize, sTypePassenger typePassenger[], int segundoSize);

/// @brief Linkea la ID del estado de vuelo con la descripci�n.
///
/// @param list La lista de pasajeros.
/// @param statusFlight La estructura del estado de vuelo.
/// @param size El tama�o de esta.
/// @return Retorna el id linkeado.
int MatchearIdConEstadoDeVuelo(sPassenger list,sStatusFlight statusFlight[], int size);

/// @brief Linkea la ID del tipo de pasajero con la descripci�n.
///
/// @param list La lista de pasajeros.
/// @param typePassenger La estructura del tipo de pasajero.
/// @param size El tama�o de esta.
/// @return Retorna el id linkeado.
int MatchearIdConTipoDePasajero(sPassenger list,sTypePassenger typePassenger[], int size);

/// @brief Muestra los listados del caso 4.
///
/// @param list La lista de pasajeros.
/// @param size El tama�o de la misma.
/// @param statusFlight La estructura del estado de vuelo.
/// @param segundoSize El tama�o de la misma.
/// @param typePassenger La estructura del tipo de pasajero.
/// @param tercerSize El tama�o de la misma.
void MostrarListados(sPassenger list[], int size, sStatusFlight statusFlight[], int segundoSize, sTypePassenger typePassenger[], int tercerSize);

/// @brief Muestra los precios en base al promedio.
///
/// @param list La lista de pasajeros.
/// @param size El tama�o de esta.
/// @param statusFlight La estructura del estado de vuelo.
/// @param segundoSize El tama�o de esta.
/// @param typePassenger La estructura del tipo de pasajero.
/// @param tercerSize El tama�o de esta.
void MostrarPreciosEnBaseAlPromedio(sPassenger list[], int size, sStatusFlight statusFlight[],
									   int segundoSize, sTypePassenger typePassenger[], int tercerSize);

/// @brief Muestra los vuelos que est�n solo en horario o en curso.
	///
	/// @param passengerList La lista de pasajeros.
	/// @param size El tama�o de esta.
	/// @param statusFlight La estructura del estado de vuelo.
	/// @param sizeStatus El tama�o de esta.
	/// @param typePassenger La estructura del tipo de pasajero.
	/// @param sizeType El tama�o de esta.
	/// @return Retorna los pasajeros en horario y en curso.
	int MostrarEnHorarioYEnCurso(sPassenger passengerList[], int size, sStatusFlight statusFlight[],
								 int sizeStatus, sTypePassenger typePassenger[], int sizeType);

#endif /* NEXO_H_ */
