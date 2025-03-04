/*
 * TypePassenger.h
 *
 *  Created on: 29 jun. 2022
 *      Author: RYZEN 2700X
 */

#ifndef TYPEPASSENGER_H_
#define TYPEPASSENGER_H_

#include "InputsYValidaciones.h"

typedef struct
{
	int idTypePassenger;
	char typePassenger[20];
}sTypePassenger;

/// @brief Muestra la id y la descripci�n del tipo de pasajero.
///
/// @param typePassenger La estructura del tipo de vuelo.
/// @param size El tama�o de esta.
void TypePassenger(sTypePassenger typePassenger[], int size);

#endif /* TYPEPASSENGER_H_ */


