/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */
#include "Passenger.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "InputsYValidaciones.h"

Passenger* Passenger_new()
{

	Passenger* pasajeroAuxiliar = NULL;

	pasajeroAuxiliar = (Passenger*) malloc(sizeof(Passenger)*1);

	if(pasajeroAuxiliar != NULL)
	{
		pasajeroAuxiliar->id = 0;
		strcpy(pasajeroAuxiliar->nombre, "");
		strcpy(pasajeroAuxiliar->apellido, "");
		strcpy(pasajeroAuxiliar->tipoPasajero, "");
		strcpy(pasajeroAuxiliar->estadoVuelo, "");
		strcpy(pasajeroAuxiliar->codigoVuelo, "");
		pasajeroAuxiliar->precio = 0;
	}

	return pasajeroAuxiliar;
}

/////////////////////////////////////////////////////////////////////////////

Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* codigoStr, char* apellidoStr, char* precioStr, char* tipoPasajeroStr, char* statusFlightStr)
{
	Passenger* pasajeroAuxiliar = NULL;

	if(idStr != NULL && nombreStr != NULL && tipoPasajeroStr != NULL && apellidoStr != NULL && precioStr != NULL && tipoPasajeroStr != NULL && codigoStr != NULL && statusFlightStr != NULL)
	{
		pasajeroAuxiliar = Passenger_new();
		Passenger_setId(pasajeroAuxiliar, atoi(idStr));
		Passenger_setNombre(pasajeroAuxiliar, nombreStr);
		Passenger_setTipoPasajero(pasajeroAuxiliar, tipoPasajeroStr);
		Passenger_setApellido(pasajeroAuxiliar, apellidoStr);
		Passenger_setPrecio(pasajeroAuxiliar, atof(precioStr));
		Passenger_setCodigoVuelo(pasajeroAuxiliar, codigoStr);
		Passenger_setEstadoVuelo(pasajeroAuxiliar, statusFlightStr);
	}

	return pasajeroAuxiliar;
}

/////////////////////////////////////////////////////////////////////////////

void Passenger_delete(Passenger* this)
{
	free(this);
	this = NULL;
}

/////////////////////////////////////////////////////////////////////////////

int Passenger_setId(Passenger* this, int id)
{
    int validacion = -1;

    if(this!=NULL && id > 0)
    {
        this->id = id;
        validacion = 0;
    }

    return validacion;
}

int Passenger_getId(Passenger* this, int* id)
{
    int validacion = -1;

    if(this!=NULL && id != NULL)
    {
        *id = this->id;
        validacion = 0;
    }

    return validacion;
}

/////////////////////////////////////////////////////////////////////////////

int Passenger_setNombre(Passenger* this, char* nombre)
{
    int validacion = -1;

    if(this!=NULL && nombre != NULL)
    {
    	strcpy(this->nombre, nombre);
        validacion = 0;
    }

    return validacion;
}

int Passenger_getNombre(Passenger* this, char* nombre)
{
    int validacion = -1;

    if(this!=NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        validacion = 0;
    }

    return validacion;
}

/////////////////////////////////////////////////////////////////////////////

int Passenger_setApellido(Passenger* this, char* apellido)
{
    int validacion = -1;

    if(this!=NULL && apellido != NULL)
    {
    	strcpy(this->apellido, apellido);
        validacion = 0;
    }

    return validacion;
}

int Passenger_getApellido(Passenger* this, char* apellido)
{
    int validacion = -1;

    if(this!=NULL && apellido != NULL)
    {
        strcpy(apellido, this->apellido);
        validacion = 0;
    }

    return validacion;
}

/////////////////////////////////////////////////////////////////////////////

int Passenger_setCodigoVuelo(Passenger* this, char* codigoVuelo)
{
    int validacion = -1;

    if(this!=NULL && codigoVuelo != NULL)
    {
    	strcpy(this->codigoVuelo, codigoVuelo);
        validacion = 0;
    }

    return validacion;
}

int Passenger_getCodigoVuelo(Passenger* this, char* codigoVuelo)
{
    int validacion = -1;

    if(this!=NULL && codigoVuelo != NULL)
    {
        strcpy(codigoVuelo, this->codigoVuelo);
        validacion = 0;
    }

    return validacion;
}

/////////////////////////////////////////////////////////////////////////////

int Passenger_setTipoPasajero(Passenger* this, char* tipoPasajero)
{
    int validacion = -1;

    if(this!=NULL && tipoPasajero != NULL)
    {
    	strcpy(this->tipoPasajero, tipoPasajero);
        validacion = 0;
    }

    return validacion;
}

int Passenger_getTipoPasajero(Passenger* this, char* tipoPasajero)
{
    int validacion = -1;

    if(this!=NULL && tipoPasajero != NULL)
    {
        strcpy(tipoPasajero, this->tipoPasajero);
        validacion = 0;
    }

    return validacion;
}

/////////////////////////////////////////////////////////////////////////////

int Passenger_setPrecio(Passenger* this, float precio)
{
    int validacion = -1;

    if(this!=NULL && precio > 0)
    {
        this->precio = precio;
        validacion = 0;
    }

    return validacion;
}

int Passenger_getPrecio(Passenger* this, float* precio)
{
    int validacion = -1;

    if(this!=NULL && precio != NULL)
    {
        *precio = this->precio;
        validacion = 0;
    }

    return validacion;
}

/////////////////////////////////////////////////////////////////////////////

int Passenger_setEstadoVuelo(Passenger* this, char* estadoVuelo)
{
    int validacion = -1;

    if(this!=NULL && estadoVuelo != NULL)
    {
    	strcpy(this->estadoVuelo, estadoVuelo);
        validacion = 0;
    }

    return validacion;
}

int Passenger_getEstadoVuelo(Passenger* this, char* estadoVuelo)
{
    int validacion = -1;

    if(this!=NULL && estadoVuelo != NULL)
    {
        strcpy(estadoVuelo, this->estadoVuelo);
        validacion = 0;
    }

    return validacion;
}

/////////////////////////////////////////////////////////////////////////////

void printPassenger(Passenger* unPasajero)
{
	int idAuxiliar;
	char nombreAuxiliar[50];
	char apellidoAuxiliar[50];
	float precioAuxiliar;
	char tipoPasajeroAuxiliar[20];
	char codigoVueloAuxiliar[20];
	char estadoVueloAuxiliar[20];

	if(!validarGets(unPasajero, &idAuxiliar, nombreAuxiliar, apellidoAuxiliar, codigoVueloAuxiliar, &precioAuxiliar, tipoPasajeroAuxiliar, estadoVueloAuxiliar))
	{
		printf("\n%5d\t-\t%10s\t-\t%10s\t-\t%10s\t-\t%2f\t-\t%10s\t-\t%10s\t\n", idAuxiliar, nombreAuxiliar, apellidoAuxiliar, codigoVueloAuxiliar, precioAuxiliar, tipoPasajeroAuxiliar, estadoVueloAuxiliar);
	}
}

int printPassengerList(LinkedList* listaPasajeros)
{
	int validacion = -1;
	int size;

	Passenger* pasajeroAuxiliar = NULL;

	if(listaPasajeros != NULL)
	{
		size = ll_len(listaPasajeros);

		if(size > 0)
		{
			for(int i = 0; i < size; i++)
			{
				pasajeroAuxiliar = (Passenger*) ll_get(listaPasajeros, i);
				if(pasajeroAuxiliar != NULL)
				{
					printPassenger(pasajeroAuxiliar);
					validacion = 0;
				}
			}
		}
	}
	return validacion;
}

/////////////////////////////////////////////////////////////////////////////

int validarGets(Passenger* unPasajero, int* id, char* nombre, char* apellido, char* codigoVuelo, float* precio, char* tipoPasajero, char* estadoVuelo)
{
	int validacion = -1;

	if(unPasajero != NULL && id != NULL && nombre != NULL && apellido != NULL && tipoPasajero != NULL && precio != NULL && codigoVuelo != NULL && estadoVuelo != NULL)
	{
		if(Passenger_getId(unPasajero, id) == 0 &&
			   Passenger_getNombre(unPasajero, nombre) == 0 &&
			   Passenger_getApellido(unPasajero, apellido) == 0 &&
			   Passenger_getTipoPasajero(unPasajero, tipoPasajero) == 0 &&
			   Passenger_getPrecio(unPasajero, precio) == 0 &&
			   Passenger_getCodigoVuelo(unPasajero, codigoVuelo) == 0 &&
			   Passenger_getEstadoVuelo(unPasajero, estadoVuelo) == 0)
			{
				validacion = 0;
			}
	}

	return validacion;
}

/////////////////////////////////////////////////////////////////////////////

int validarSets(Passenger* unPasajero, int id, char* nombre, char* apellido, char* codigoVuelo, float precio, char* tipoPasajero, char* estadoVuelo)
{
	int validacion = -1;
	printf("%s", codigoVuelo);

	if(unPasajero != NULL && id > 0 && nombre != NULL && apellido != NULL && tipoPasajero != NULL && precio > 0 && codigoVuelo != NULL && estadoVuelo != NULL)
	{
		if(Passenger_setId(unPasajero, id) == 0 &&
		   Passenger_setNombre(unPasajero, nombre) == 0 &&
		   Passenger_setApellido(unPasajero, apellido) == 0 &&
		   Passenger_setTipoPasajero(unPasajero, tipoPasajero) == 0 &&
		   Passenger_setPrecio(unPasajero, precio) == 0 &&
		   Passenger_setCodigoVuelo(unPasajero, codigoVuelo) == 0 &&
		   Passenger_setEstadoVuelo(unPasajero, estadoVuelo) == 0)
		{
			validacion = 0;
		}
	}

	return validacion;
}

/////////////////////////////////////////////////////////////////////////////

int addPassenger(LinkedList* listaPasajeros, int* id)
{
	int validacion = -1;
	int corroboracion = -1;
	int idAuxiliar;
	char nombreAuxiliar[50];
	char apellidoAuxiliar[50];
	float precioAuxiliar;
	char tipoPasajeroAuxiliar[50];
	char codigoVueloAuxiliar[50];
	char estadoVueloAuxiliar[50];
	int confirmacion;

	Passenger* pasajeroAuxiliar = NULL;

	if(listaPasajeros != NULL && id != NULL)
	{
		pasajeroAuxiliar = Passenger_new();

		if(pasajeroAuxiliar != NULL)
		{
			idAuxiliar= *id;
			idAuxiliar = idAuxiliar + 1;

			CargarCadena(nombreAuxiliar, "\nIngrese el nombre del pasajero: \n");
			corroboracion = ValidacionDeCaracteres(nombreAuxiliar);
			while(corroboracion == 0)
			{
				CargarCadena(nombreAuxiliar, "\nError, reingrese el nombre del pasajero: \n");
				corroboracion = ValidacionDeCaracteres(nombreAuxiliar);
			}
			DetectarEspacio(nombreAuxiliar);

			CargarCadena(apellidoAuxiliar, "\nIngrese el apellido del pasajero: \n");
			corroboracion = ValidacionDeCaracteres(apellidoAuxiliar);
			while(corroboracion == 0)
			{
				CargarCadena(apellidoAuxiliar, "\nError, reingrese el apellido del pasajero: \n");
				corroboracion = ValidacionDeCaracteres(apellidoAuxiliar);
			}
			DetectarEspacio(apellidoAuxiliar);

			precioAuxiliar = IngresarFlotante("\nIngrese el precio del viaje (entre 5000 y 1000000): \n", 5000, 1000000);

			CargarCadena(tipoPasajeroAuxiliar, "\nIngrese el tipo de pasajero del pasajero: \n");
			corroboracion = ValidacionDeCaracteres(tipoPasajeroAuxiliar);
			while(corroboracion == 0)
			{
				CargarCadena(tipoPasajeroAuxiliar, "\nError, reingrese el tipo de pasajero del pasajero: \n");
				corroboracion = ValidacionDeCaracteres(tipoPasajeroAuxiliar);
			}
			DetectarEspacio(tipoPasajeroAuxiliar);

			CargarCadena(codigoVueloAuxiliar, "\nIngrese el c�digo de vuelo del pasajero: \n");

			CargarCadena(estadoVueloAuxiliar, "\nIngrese el estado del vuelo del pasajero: \n");
			corroboracion = ValidacionDeCaracteres(estadoVueloAuxiliar);
			while(corroboracion == 0)
			{
				CargarCadena(estadoVueloAuxiliar, "\nError, reingrese el estado del vuelo del pasajero: \n");
				corroboracion = ValidacionDeCaracteres(estadoVueloAuxiliar);
			}
			DetectarEspacio(estadoVueloAuxiliar);

			if(!validarSets(pasajeroAuxiliar, idAuxiliar, nombreAuxiliar, apellidoAuxiliar, codigoVueloAuxiliar, precioAuxiliar, tipoPasajeroAuxiliar, estadoVueloAuxiliar))
			{
				printPassenger(pasajeroAuxiliar);

				confirmacion = IngresarEntero("\nIngrese 1 si confirma el dar de alta este pasajero o 2 si no:\n", 1, 2);
				if(confirmacion == 1)
				{
					ll_add(listaPasajeros, pasajeroAuxiliar);
					*id = idAuxiliar;
					validacion = 0;
					printf("El pasajero se carg� correctamente.\n");
				}
				else
				{
					printf("No se carg� al pasajero.\n");
					Passenger_delete(pasajeroAuxiliar);
				}
			}
		}
		else
		{
			printf("No hay espacio para un nuevo pasajero.\n");
		}
	}

	return validacion;
}

/////////////////////////////////////////////////////////////////////////////

int ObtenerMayorId(LinkedList* lista)
{
	int mayorId = 0;
	int id;
	int size;
	Passenger* pasajeroAuxiliar;

	if(lista != NULL)
	{
		size= ll_len(lista);

		if(size > 0)
		{
			for(int i = 0; i < size; i++)
			{
				pasajeroAuxiliar = (Passenger*)ll_get(lista, i);
				Passenger_getId(pasajeroAuxiliar, &id);

				if(i==0 || (mayorId<id))
				{
					mayorId= id;
				}
			}
		}
	}

	return mayorId;
}

/////////////////////////////////////////////////////////////////////////////

int removePassenger(LinkedList* listaPasajeros)
{
	int validacion = -1;
	int id;
	int index = -1;
	int confirmacion;
	Passenger* pasajeroAuxiliar = NULL;

	if(listaPasajeros != NULL)
	{
		ll_sort(listaPasajeros, ordenarPorId, 1);
		printPassengerList(listaPasajeros);
		id = IngresarEntero("Ingrese el ID del pasajero a dar de baja: \n", 1, 2500);
		index = buscarId(listaPasajeros, id);

		if(index != -1)
		{
			pasajeroAuxiliar = ll_get(listaPasajeros, index);
			printPassenger(pasajeroAuxiliar);

			confirmacion = IngresarEntero("Ingrese 1 si quiere eliminar ese pasajero o 2 si no.\n", 1, 2);

			if(confirmacion == 1)
			{
				ll_remove(listaPasajeros, index);
				Passenger_delete(pasajeroAuxiliar);
				printf("El pasajero fue dado de baja.\n");
				validacion = 0;
			}
			else
			{
				printf("No se ha llevado a cabo la dada de baja.\n");
			}
		}
		else
		{
			printf("No se ha encontrado el ID.\n");
		}
	}

	return validacion;
}

/////////////////////////////////////////////////////////////////////////////

int buscarId(LinkedList* listaPasajeros, int id)
{
	int size;
	int index = -1;
	Passenger* pasajeroAuxiliar;

	if(listaPasajeros != NULL)
	{
		size = ll_len(listaPasajeros);

		if(size > 0)
		{
			for(int i = 0; i < size; i++)
			{
				pasajeroAuxiliar = (Passenger*) ll_get(listaPasajeros, i);
				if(pasajeroAuxiliar->id == id)
				{
					index = i;
					break;
				}
			}
		}
	}

	return index;
}

/////////////////////////////////////////////////////////////////////////////

int modifyPassenger(LinkedList* listaPasajeros)
{
	int validacion = -1;
	int id;
	int index= -1;
	int confirmacion;
	int opcion;

	Passenger* auxiliar;
	Passenger  pasajeroAuxiliar;

	if(listaPasajeros != NULL)
	{
		ll_sort(listaPasajeros, ordenarPorId, 1);
		printPassengerList(listaPasajeros);
		id = IngresarEntero("Ingrese el ID del pasajero a modificar: \n", 1, 2500);
		index = buscarId(listaPasajeros, id);

		if(index != -1)
		{
			auxiliar = (Passenger*) ll_get(listaPasajeros, index);
			pasajeroAuxiliar = *auxiliar;

			printPassenger(&pasajeroAuxiliar);

			confirmacion = IngresarEntero("Ingrese 1 si quiere modificar ese pasajero o 2 si no.\n", 1, 2);

			if(confirmacion == 1)
			{

				do
				{
					opcion = IngresarEntero("Ingrese el campo a modificar: \n"
											 "1- NOMBRE.\n"
											 "2- APELLIDO.\n"
											 "3- C�DIGO DE VUELO.\n"
											 "4- PRECIO.\n"
											 "5- TIPO DE PASAJERO. \n"
											 "6- SALIR.\n", 1, 6);
					switch(opcion)
					{
						case 1:
							caseNombre(listaPasajeros, index, pasajeroAuxiliar);
							validacion = 0;
						break;

						case 2:
							caseApellido(listaPasajeros, index, pasajeroAuxiliar);
							validacion = 0;
						break;

						case 3:
							caseCodigoVuelo(listaPasajeros, index, pasajeroAuxiliar);
							validacion = 0;
						break;

						case 4:
							casePrecio(listaPasajeros, index, pasajeroAuxiliar);
							validacion = 0;
						break;

						case 5:
							caseTipoPasajero(listaPasajeros, index, pasajeroAuxiliar);
							validacion = 0;
						break;

						case 6:
							printf("Volviendo al men� principal.\n");
						break;
					}
				}while(opcion != 6);
			}
			else
			{
				printf("Cancelaste la modificaci�n.\n");
			}
		}
		else
		{
			printf("No se encontr� el ID.\n");
		}
	}

	return validacion;
}

/////////////////////////////////////////////////////////////////////////////

int caseNombre(LinkedList* listaPasajeros, int index, Passenger auxiliar)
{
	int validacion = -1;
	char nombreAuxiliar[50];
	int corroboracion;
	int confirmacion;

	if(listaPasajeros != NULL && index != -1)
	{
		CargarCadena(nombreAuxiliar, "Ingrese el nuevo nombre: ");
		corroboracion= ValidacionDeCaracteres(nombreAuxiliar);
		while(corroboracion == 0)
		{
			CargarCadena(nombreAuxiliar, "Error, ingrese el nuevo nombre: ");
			corroboracion= ValidacionDeCaracteres(nombreAuxiliar);
		}
		DetectarEspacio(nombreAuxiliar);

		strcpy(auxiliar.nombre, nombreAuxiliar);
		printPassenger(&auxiliar);

		confirmacion = IngresarEntero("Ingrese 1 para confirmar la modificaci�n o 2 para cancelarla.\n", 1, 2);
		if(confirmacion == 1)
		{
			modifyNombre(listaPasajeros, index, nombreAuxiliar);
			validacion = 1;
		}
		else
		{
			printf("Cancelaste la modificaci�n.\n");
		}
	}

	return validacion;
}

int modifyNombre(LinkedList* listaPasajeros, int index, char* nombreAuxiliar)
{
	int validacion = -1;
	Passenger* pasajeroAuxiliar;

	if(listaPasajeros != NULL && index >= 0 && nombreAuxiliar != NULL)
	{
		pasajeroAuxiliar = (Passenger*) ll_get(listaPasajeros, index);
		DetectarEspacio(nombreAuxiliar);

		if(pasajeroAuxiliar != NULL)
		{
			if(!Passenger_setNombre(pasajeroAuxiliar, nombreAuxiliar))
			{
				printf("Se carg� correctamente el nuevo nombre.\n");
			}
			else
			{
				printf("No se carg� el nuevo nombre.\n");
			}
			validacion = 0;
		}
	}

	return validacion;
}

/////////////////////////////////////////////////////////////////////////////

int caseApellido(LinkedList* listaPasajeros, int index, Passenger auxiliar)
{
	int validacion = -1;
	char apellidoAuxiliar[50];
	int corroboracion;
	int confirmacion;

	if(listaPasajeros != NULL && index != -1)
	{
		CargarCadena(apellidoAuxiliar, "Ingrese el nuevo apellido: ");
		corroboracion= ValidacionDeCaracteres(apellidoAuxiliar);
		while(corroboracion == 0)
		{
			CargarCadena(apellidoAuxiliar, "Error, ingrese el nuevo apellido: ");
			corroboracion= ValidacionDeCaracteres(apellidoAuxiliar);
		}
		DetectarEspacio(apellidoAuxiliar);

		strcpy(auxiliar.apellido, apellidoAuxiliar);
		printPassenger(&auxiliar);

		confirmacion = IngresarEntero("Ingrese 1 para confirmar la modificaci�n o 2 para cancelarla.\n", 1, 2);
		if(confirmacion == 1)
		{
			modifyApellido(listaPasajeros, index, apellidoAuxiliar);
			validacion = 0;
		}
		else
		{
			printf("Cancelaste la modificaci�n.\n");
		}
	}

	return validacion;
}

int modifyApellido(LinkedList* listaPasajeros, int index, char* apellidoAuxiliar)
{
	int validacion = -1;
	Passenger* pasajeroAuxiliar;

	if(listaPasajeros != NULL && index >= 0 && apellidoAuxiliar != NULL)
	{
		pasajeroAuxiliar = (Passenger*) ll_get(listaPasajeros, index);
		DetectarEspacio(apellidoAuxiliar);

		if(pasajeroAuxiliar != NULL)
		{
			if(!Passenger_setApellido(pasajeroAuxiliar, apellidoAuxiliar))
			{
				printf("Se carg� correctamente el nuevo apellido.\n");
			}
			else
			{
				printf("No se carg� el nuevo apellido.\n");
			}
			validacion = 0;
		}
	}

	return validacion;
}

/////////////////////////////////////////////////////////////////////////////

int caseCodigoVuelo(LinkedList* listaPasajeros, int index, Passenger auxiliar)
{
	int validacion = -1;
	char codigoVueloAuxiliar[50];
	int corroboracion;
	int confirmacion;

	if(listaPasajeros != NULL && index != -1)
	{
		CargarCadena(codigoVueloAuxiliar, "Ingrese el nuevo c�digo de vuelo: ");
		corroboracion= ValidacionDeCaracteres(codigoVueloAuxiliar);
		while(corroboracion == 0)
		{
			CargarCadena(codigoVueloAuxiliar, "Error, ingrese el nuevo c�digo de vuelo: ");
			corroboracion= ValidacionDeCaracteres(codigoVueloAuxiliar);
		}

		strcpy(auxiliar.codigoVuelo, codigoVueloAuxiliar);
		printPassenger(&auxiliar);

		confirmacion = IngresarEntero("Ingrese 1 para confirmar la modificaci�n o 2 para cancelarla.\n", 1, 2);
		if(confirmacion == 1)
		{
			modifyCodigoVuelo(listaPasajeros, index, codigoVueloAuxiliar);
			validacion = 0;
		}
		else
		{
			printf("Cancelaste la modificaci�n.\n");
		}
	}

	return validacion;
}

int modifyCodigoVuelo(LinkedList* listaPasajeros, int index, char* codigoVueloAuxiliar)
{
	int validacion = -1;
	Passenger* pasajeroAuxiliar;

	if(listaPasajeros != NULL && index >= 0 && codigoVueloAuxiliar != NULL)
	{
		pasajeroAuxiliar = (Passenger*) ll_get(listaPasajeros, index);

		if(pasajeroAuxiliar != NULL)
		{
			if(!Passenger_setCodigoVuelo(pasajeroAuxiliar, codigoVueloAuxiliar))
			{
				printf("Se carg� correctamente el nuevo c�digo de vuelo.\n");
			}
			else
			{
				printf("No se carg� el nuevo c�digo de vuelo.\n");
			}
			validacion = 0;
		}
	}

	return validacion;
}

/////////////////////////////////////////////////////////////////////////////

int casePrecio(LinkedList* listaPasajeros, int index, Passenger auxiliar)
{
	int validacion = -1;
	int precioAuxiliar;
	int confirmacion;

	if(listaPasajeros != NULL && index != -1)
	{
		precioAuxiliar = IngresarFlotante("Ingrese el nuevo precio: ", 5000, 1000000);
		auxiliar.precio = precioAuxiliar;
		printPassenger(&auxiliar);

		confirmacion = IngresarEntero("Ingrese 1 para confirmar la modificaci�n o 2 para cancelarla.\n", 1, 2);
		if(confirmacion == 1)
		{
			modifyPrecio(listaPasajeros, index, precioAuxiliar);
			validacion = 0;
		}
		else
		{
			printf("Cancelaste la modificaci�n.\n");
		}
	}

	return validacion;
}

int modifyPrecio(LinkedList* listaPasajeros, int index, float precioAuxiliar)
{
	int validacion = -1;
	Passenger* pasajeroAuxiliar;

	if(listaPasajeros != NULL && index >= 0 && precioAuxiliar >= 5000)
	{
		pasajeroAuxiliar = (Passenger*) ll_get(listaPasajeros, index);

		if(pasajeroAuxiliar != NULL)
		{
			if(!Passenger_setPrecio(pasajeroAuxiliar, precioAuxiliar))
			{
				printf("Se carg� correctamente el nuevo precio.\n");
			}
			else
			{
				printf("No se carg� el nuevo precio\n");
			}
			validacion = 0;
		}
	}

	return validacion;
}

/////////////////////////////////////////////////////////////////////////////

int caseTipoPasajero(LinkedList* listaPasajeros, int index, Passenger auxiliar)
{
	int validacion = -1;
	char tipoPasajeroAuxiliar[50];
	int corroboracion;
	int confirmacion;

	if(listaPasajeros != NULL && index != -1)
	{
		CargarCadena(tipoPasajeroAuxiliar, "Ingrese el nuevo tipo de pasajero: ");
		corroboracion= ValidacionDeCaracteres(tipoPasajeroAuxiliar);
		while(corroboracion == 0)
		{
			CargarCadena(tipoPasajeroAuxiliar, "Error, ingrese el nuevo tipo de pasajero: ");
			corroboracion= ValidacionDeCaracteres(tipoPasajeroAuxiliar);
		}
		DetectarEspacio(tipoPasajeroAuxiliar);

		strcpy(auxiliar.tipoPasajero, tipoPasajeroAuxiliar);
		printPassenger(&auxiliar);

		confirmacion = IngresarEntero("Ingrese 1 para confirmar la modificaci�n o 2 para cancelarla.\n", 1, 2);
		if(confirmacion == 1)
		{
			modifyTipoPasajero(listaPasajeros, index, tipoPasajeroAuxiliar);
			validacion = 0;
		}
		else
		{
			printf("Cancelaste la modificaci�n.\n");
		}
	}

	return validacion;
}

int modifyTipoPasajero(LinkedList* listaPasajeros, int index, char* tipoPasajeroAuxiliar)
{
	int validacion = -1;
	Passenger* pasajeroAuxiliar;

	if(listaPasajeros != NULL && index >= 0 && tipoPasajeroAuxiliar != NULL)
	{
		pasajeroAuxiliar = (Passenger*) ll_get(listaPasajeros, index);

		if(pasajeroAuxiliar != NULL)
		{
			if(!Passenger_setTipoPasajero(pasajeroAuxiliar, tipoPasajeroAuxiliar))
			{
				printf("Se carg� correctamente el nuevo tipo de pasajero.\n");
			}
			else
			{
				printf("No se carg� el nuevo tipo de pasajero.\n");
			}
			validacion = 0;
		}
	}

	return validacion;
}

/////////////////////////////////////////////////////////////////////////////

int ordenarPorId(void* unPasajero, void* otroPasajero)
{
	int validacion = 0;
	Passenger* unPasajeroAuxiliar = NULL;
	Passenger* otroPasajeroAuxiliar = NULL;

	int unId;
	int otroId;

	if(unPasajero != NULL && otroPasajero != NULL)
	{
		unPasajeroAuxiliar = (Passenger*) unPasajero;
		otroPasajeroAuxiliar = (Passenger*) otroPasajero;

		if((!Passenger_getId(unPasajeroAuxiliar, &unId)) && (!Passenger_getId(otroPasajeroAuxiliar, &otroId)))
		{
			if(unId > otroId)
			{
				validacion = 1;
			}
			else
			{
				if(unId < otroId)
				{
					validacion = -1;
				}
			}
		}
	}

	return validacion;
}

int ordenarPorNombre(void* unPasajero, void* otroPasajero)
{
	int validacion = -1;
	Passenger* unPasajeroAuxiliar = NULL;
	Passenger* otroPasajeroAuxiliar = NULL;

	char unNombre[50];
	char otroNombre[50];

	if(unPasajero != NULL && otroPasajero != NULL)
	{
		unPasajeroAuxiliar = (Passenger*) unPasajero;
		otroPasajeroAuxiliar = (Passenger*) otroPasajero;

		if((!Passenger_getNombre(unPasajeroAuxiliar,unNombre)) && (!Passenger_getNombre(otroPasajeroAuxiliar, otroNombre)))
		{
			validacion = strcmp(unNombre, otroNombre);
		}
	}

	return validacion;
}

int ordenarPorApellido(void* unPasajero, void* otroPasajero)
{
	int validacion = -1;
	Passenger* unPasajeroAuxiliar = NULL;
	Passenger* otroPasajeroAuxiliar = NULL;

	char unApellido[50];
	char otroApellido[50];

	if(unPasajero != NULL && otroPasajero != NULL)
	{
		unPasajeroAuxiliar = (Passenger*) unPasajero;
		otroPasajeroAuxiliar = (Passenger*) otroPasajero;

		if((!Passenger_getApellido(unPasajeroAuxiliar,unApellido)) && (!Passenger_getApellido(otroPasajeroAuxiliar, otroApellido)))
		{
			validacion = strcmp(unApellido, otroApellido);
		}
	}

	return validacion;
}
