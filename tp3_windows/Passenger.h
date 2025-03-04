/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_
#include "LinkedList.h"

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char tipoPasajero[20];
	char codigoVuelo[20];
	char estadoVuelo[20];

}Passenger;
/// @brief Constructor gen�rico de pasajero.
///
/// @return Retorna el pasajero cargado en memoria din�mica.
Passenger* Passenger_new();
/// @brief Constructor parametrizado.
///
/// @param idStr id cadena.
/// @param nombreStr nombre cadena.
/// @param codigoStr codigo cadena.
/// @param apellidoStr apellido cadena.
/// @param precioStr precio cadena.
/// @param tipoPasajeroStr tipo de pasajero cadena.
/// @param statusFlightStr estado de vuelo cadena.
/// @return Retorna el pasajero con los campos cargados.
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* codigoStr, char* apellidoStr, char* precioStr, char* tipoPasajeroStr, char* statusFlightStr);
/// @brief Para eliminar el pasajero.
///
/// @param Un pasajero solo.
void Passenger_delete(Passenger* this);

/// @brief Set de id.
///
/// @param this Un pasajero solo.
/// @param id El id a setear.
/// @return Valida si se pudo setear o no.
int Passenger_setId(Passenger* this,int id);
/// @brief Get de id.
///
/// @param this Un pasajero solo.
/// @param id El id a getear.
/// @return Valida si se pudo getear o no.
int Passenger_getId(Passenger* this,int* id);

/// @brief Set de nombre.
///
/// @param this Un pasajero solo.
/// @param nombre El nombre a setear.
/// @return Valida si se pudo setear o no.
int Passenger_setNombre(Passenger* this,char* nombre);
/// @brief Get de nombre.
///
/// @param this Un pasajero solo.
/// @param nombre El nombre a getear.
/// @return Valida si se pudo getear o no.
int Passenger_getNombre(Passenger* this,char* nombre);

/// @brief Set de apellido.
///
/// @param this Un pasajero solo.
/// @param apellido El apellido a getear.
/// @return Valida si se pudo setear o no.
int Passenger_setApellido(Passenger* this,char* apellido);
/// @brief Get de apellido.
///
/// @param this Un pasajero solo.
/// @param apellido El apellido a getear.
/// @return Valida si se pudo getear o no.
int Passenger_getApellido(Passenger* this,char* apellido);

/// @brief Set de c�digo de vuelo.
///
/// @param this Un pasajero solo.
/// @param codigoVuelo El c�digo de vuelo a setear.
/// @return Valida si se pudo setear o no.
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
/// @brief Get de c�digo de vuelo.
///
/// @param this Un pasajero solo.
/// @param codigoVuelo El c�digo de vuelo a getear.
/// @return valida si se pudo getear o no.
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

/// @brief Set de tipo de pasajero.
///
/// @param this Un pasajero solo.
/// @param tipoPasajero El tipo de pasajero a setear.
/// @return Valida si se pudo setear o no.
int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero);
/// @brief Get de tipo de pasajero.
///
/// @param this Un pasajero solo.
/// @param tipoPasajero El tipo de pasajero a getear.
/// @return Valida si se pudo getear o no.
int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero);

/// @brief Set de precio.
///
/// @param this Un pasajero solo.
/// @param precio El precio a setear.
/// @return Valida si se pudo setear o no.
int Passenger_setPrecio(Passenger* this,float precio);
/// @brief Get de precio.
///
/// @param this Un pasajero solo.
/// @param precio El precio a getear.
/// @return Valida si se pudo getear o no.
int Passenger_getPrecio(Passenger* this,float* precio);

/// @brief Set de estado de vuelo.
///
/// @param this Un pasajero solo.
/// @param estadoVuelo El estado de vuelo a setear.
/// @return Valida si se pudo setear o no.
int Passenger_setEstadoVuelo(Passenger* this,char* estadoVuelo);
/// @brief Get de estado de vuelo.
///
/// @param this Un pasajero solo.
/// @param estadoVuelo El estado de vuelo a getear.
/// @return Valida si se pudo getear o no.
int Passenger_getEstadoVuelo(Passenger* this,char* estadoVuelo);

/// @brief Print de un solo pasajero.
///
/// @param unPasajero El pasajero a printear.
void printPassenger(Passenger* unPasajero);
/// @brief Print de la lista de pasajeros.
///
/// @param listaPasajeros La lista a printear.
/// @return Si se pudo printear o no.
int printPassengerList(LinkedList* listaPasajeros);

/// @brief Validacion de todos los gets.
///
/// @param unPasajero El pasajero a getear.
/// @param id El id a getear.
/// @param nombre El nombre a getear.
/// @param apellido El apellido a getear.
/// @param codigoVuelo El c�digo de vuelo a getear.
/// @param precio El precio a getear.
/// @param tipoPasajero El tipo de pasajero a getear.
/// @param estadoVuelo El estado de vuelo a getear.
/// @return Retorna si se pudo validar o no los gets.
int validarGets(Passenger* unPasajero, int* id, char* nombre, char* apellido, char* codigoVuelo, float* precio, char* tipoPasajero, char* estadoVuelo);
/// @brief Validacion de todos los sets.
///
/// @param unPasajero El pasajero a setear.
/// @param id El id a setear.
/// @param nombre El nombre a setear.
/// @param apellido El apellido a setear.
/// @param codigoVuelo El c�digo de vuelo a setear.
/// @param precio El precio a setear.
/// @param tipoPasajero El tipo de pasajero a setear.
/// @param estadoVuelo El estado de vuelo a setear.
/// @return Retorna si se pudo validar o no los sets.
int validarSets(Passenger* unPasajero, int id, char* nombre, char* apellido, char* codigoVuelo, float precio, char* tipoPasajero, char* estadoVuelo);

/// @brief Funci�n para buscar el mayor id en la lista.
///
/// @param lista La lista en la que se busca.
/// @return Retorna el mayor id.
int ObtenerMayorId(LinkedList* lista);
/// @brief Busca el id comparando con el pedido.
///
/// @param listaPasajeros La lista donde compara.
/// @param id El id con el que comparar.
/// @return Retorna si lo encontr� o no cargado.
int buscarId(LinkedList* listaPasajeros, int id);

/// @brief Funci�n para a�adir pasajeros.
///
/// @param listaPasajeros La lista para donde a�adirlos.
/// @param id El id que asignarles.
/// @return Retorna si se pudo o no a�adir un pasajero.
int addPassenger(LinkedList* listaPasajeros, int* id);
/// @brief Funci�n para eliminar pasajeros.
///
/// @param listaPasajeros La lista de donde eliminarlos.
/// @return Retorna si se pudo o no eliminar un pasajero.
int removePassenger(LinkedList* listaPasajeros);
/// @brief Funci�n para modificar pasajeros.
///
/// @param listaPasajeros La lista del pasajero a modificar.
/// @return Retorna si se llevo a cabo alguna modificaci�n.
int modifyPassenger(LinkedList* listaPasajeros);

/// @brief La funci�n del case nombre para las modificaciones.
///
/// @param listaPasajeros La lista de pasajeros a modificar.
/// @param index El index del pasajero a modificar.
/// @param auxiliar Un auxiliar que guarde las modificaciones.
/// @return Retorna si se modific� o no el nombre.
int caseNombre(LinkedList* listaPasajeros, int index, Passenger auxiliar);
/// @brief Carga la modificaci�n en el pasajero.
///
/// @param listaPasajeros La lista de pasajeros a modificar.
/// @param index El index del pasajero a modificar.
/// @param nombreAuxiliar Un auxiliar que guarde las modificaciones.
/// @return Retorna si se guard� la modificaci�n o no.
int modifyNombre(LinkedList* listaPasajeros, int index, char* nombreAuxiliar);

/// @brief La funci�n del case apellido para las modificaciones.
///
/// @param listaPasajeros La lista de pasajeros a modificar.
/// @param index El index del pasajero a modificar.
/// @param auxiliar Un auxiliar que guarde las modificaciones.
/// @return Retorna si se modific� o no el apellido.
int caseApellido(LinkedList* listaPasajeros, int index, Passenger auxiliar);
/// @brief Carga la modificaci�n en el pasajero.
///
/// @param listaPasajeros La lista de pasajeros a modificar.
/// @param index El index del pasajero a modificar.
/// @param apellidoAuxiliar Un auxiliar que guarde las modificaciones.
/// @return Retorna si se guard� la modificaci�n o no.
int modifyApellido(LinkedList* listaPasajeros, int index, char* apellidoAuxiliar);

/// @brief La funci�n del case c�digo de vuelo para las modificaciones.
///
/// @param listaPasajeros La lista de pasajeros a modificar.
/// @param index El index del pasajero a modificar.
/// @param auxiliar Un auxiliar que guarde las modificaciones.
/// @return Retorna si se modific� o no el c�digo de vuelo.
int caseCodigoVuelo(LinkedList* listaPasajeros, int index, Passenger auxiliar);
/// @brief Carga la modificaci�n en el pasajero.
///
/// @param listaPasajeros La lista de pasajeros a modificar.
/// @param index El index del pasajero a modificar.
/// @param codigoVueloAuxiliar Un auxiliar que guarde las modificaciones.
/// @return Retorna si se guard� la modificaci�n o no.
int modifyCodigoVuelo(LinkedList* listaPasajeros, int index, char* codigoVueloAuxiliar);

/// @brief La funci�n del case precio para las modificaciones.
///
/// @param listaPasajeros La lista de pasajeros a modificar.
/// @param index El index del pasajero a modificar.
/// @param auxiliar Un auxiliar que guarde las modificaciones.
/// @return Retorna si se modific� o no el precio.
int casePrecio(LinkedList* listaPasajeros, int index, Passenger auxiliar);
/// @brief Carga la modificaci�n en el pasajero.
///
/// @param listaPasajeros La lista de pasajeros a modificar.
/// @param index El index del pasajero a modificar.
/// @param precioAuxiliar Un auxiliar que guarde las modificaciones.
/// @return Retorna si se guard� la modificaci�n o no.
int modifyPrecio(LinkedList* listaPasajeros, int index, float precioAuxiliar);

/// @brief La funci�n del case tipo de pasajero para las modificaciones.
///
/// @param listaPasajeros La lista de pasajeros a modificar.
/// @param index El index del pasajero a modificar.
/// @param auxiliar Un auxiliar que guarde las modificaciones.
/// @return Retorna si se modific� o no el tipo de pasajero.
int caseTipoPasajero(LinkedList* listaPasajeros, int index, Passenger auxiliar);
/// @brief Carga la modificaci�n en el pasajero.
///
/// @param listaPasajeros La lista de pasajeros a modificar.
/// @param index El index del pasajero a modificar.
/// @param tipoPasajeroAuxiliar Un auxiliar que guarde las modificaciones.
/// @return Retorna si se guard� la modificaci�n o no.
int modifyTipoPasajero(LinkedList* listaPasajeros, int index, char* tipoPasajeroAuxiliar);

/// @brief Funci�n para ordenar por id.
///
/// @param unPasajero Un pasajero a comparar.
/// @param otroPasajero El otro pasajero a comparar.
/// @return Retorna la validacion;
int ordenarPorId(void* unPasajero, void* otroPasajero);
/// @brief Funci�n para ordenar por nombre.
///
/// @param unPasajero Un pasajero a comparar.
/// @param otroPasajero El otro pasajero a comparar.
/// @return Retorna la validacion;
int ordenarPorNombre(void* unPasajero, void* otroPasajero);
/// @brief Funci�n para ordenar por apellido.
///
/// @param unPasajero Un pasajero a comparar.
/// @param otroPasajero El otro pasajero a comparar.
/// @return Retorna la validacion;
int ordenarPorApellido(void* unPasajero, void* otroPasajero);

#endif /* PASSENGER_H_ */
