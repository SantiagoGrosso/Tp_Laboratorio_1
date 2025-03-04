/*
 * Nexo.c
 *
 *  Created on: 29 jun. 2022
 *      Author: RYZEN 2700X
 */

#include "Nexo.h"

///////////////////////////////////////////////////

sPassenger ingresarPasajero(sPassenger unPasajero, sStatusFlight statusFlight[], int size, sTypePassenger typePassenger[], int segundoSize)
{
	int validacion;

	unPasajero.id = obtenerID();
	CargarCadena(unPasajero.name, "\nIngrese su nombre: \n");
	validacion = ValidacionDeCaracteres(unPasajero.name);
	while(validacion == 0)
	{
		CargarCadena(unPasajero.name, "\nError, vuelva a ingresar su nombre: \n");
		validacion = ValidacionDeCaracteres(unPasajero.name);
	}
	DetectarEspacio(unPasajero.name);
	CargarCadena(unPasajero.lastname, "\nIngrese su apellido: \n");
	validacion = ValidacionDeCaracteres(unPasajero.lastname);
	while(validacion == 0)
		{
			CargarCadena(unPasajero.lastname, "\nError, vuelva a ingresar su apellido: \n");
			validacion = ValidacionDeCaracteres(unPasajero.lastname);
		}
	DetectarEspacio(unPasajero.lastname);
	unPasajero.price = IngresarFlotante("\nIngrese el precio del viaje: \n", 5000, 1000000);
	CargarCadena(unPasajero.flycode, "\nIngrese su c�digo de vuelo: \n");
	StatusFlight(statusFlight, size);
	unPasajero.idStatusFlight = IngresarEntero("\nIngrese el estado del vuelo (Del 1 al 4): \n", 1, 4);
	TypePassenger(typePassenger, segundoSize);
	unPasajero.idTypePassenger = IngresarEntero("\nIngrese el tipo de vuelo (Del 1 al 3): \n", 1, 3);
	unPasajero.isEmpty = OCUPADO;


	return unPasajero;
}

////////////////////////////////////////////////////////

int addPassenger(sPassenger unPasajero, sStatusFlight statusFlight[], int size,
				sTypePassenger typePassenger[], int segundoSize, sPassenger list[], int tercerSize)
{
	int index = -1;

		index = BuscarEspacioLibre(list, tercerSize);
		if(index != -1)
		{
			list[index] = ingresarPasajero(unPasajero, statusFlight, size, typePassenger, segundoSize);
		}

		return index;
}

////////////////////////////////////////////////////////

int printPassengers(sPassenger passengerList[], int size, sStatusFlight statusFlight[], sTypePassenger typePassenger[])
{
	int retorno=-1;
	int indiceStatusFlight;
	int indiceTypePassenger;

	for(int i=0;i<size;i++)
	{
		indiceStatusFlight= MatchearIdConEstadoDeVuelo(passengerList[i], statusFlight, 4);
		indiceTypePassenger= MatchearIdConTipoDePasajero(passengerList[i], typePassenger, 3);
		if(passengerList[i].isEmpty == OCUPADO)
		{
			printf("ID: %d - "
					"Nombre: %s |-| "
					"Apellido: %s |-| "
					"Precio: %.2f |-| "
					"C�digo de vuelo: %s |-| "
					"Estado de vuelo: %s |-| "
					"Tipo de pasajero: %s"
					"\n", passengerList[i].id,
					passengerList[i].name,
					passengerList[i].lastname,
					passengerList[i].price,
					passengerList[i].flycode,
					statusFlight[indiceStatusFlight].statusFlight,
					typePassenger[indiceTypePassenger].typePassenger);
			retorno = 0;
		}
	}

	return retorno;
}

////////////////////////////////////////////////////////

int ModificarPasajero(sPassenger list[], int size, sStatusFlight statusFlight[], int otroSize, sTypePassenger typePassenger[], int segundoSize)
{
	int index;
	int id;
	int opcion;
	int aceptarModificacion;
	int retorno = 0;

	id= IngresarEntero("Ingrese la id del usuario a modificar: ", 1000, 3000);
	index=findPassengerById(list, size, id);

	while(index==-1)
	{
		id = IngresarEntero("No se ha encontrado el id, vuelva a ingresarlo: ", 1000, 3000);
		index=findPassengerById(list, size, id);
	}
	do
		{
		int validacion;
		char name[51];
		char lastname[51];
		float price;
		char flycode[10];
		int cambiarTypePassenger;

		opcion=IngresarEntero("\nIngrese la opci�n seg�n el campo del pasajero a modificar: \n"
				"1 -- NOMBRE.\n"
				"2 -- APELLIDO.\n"
				"3 -- PRECIO.\n"
				"4 -- C�DIGO DE VUELO.\n"
				"5 -- TIPO DE PASAJERO.\n"
				"6 -- SALIR.\n", 1, 6);

		switch(opcion)
		{
			case 1:
				CargarCadena(name, "Ingrese el nuevo nombre: ");
				validacion= ValidacionDeCaracteres(name);
				while(validacion == 0)
				{
					CargarCadena(name, "Error, ingrese el nuevo nombre: ");
					validacion= ValidacionDeCaracteres(name);
				}
				DetectarEspacio(name);
				printf("\n Est� usted seguro que este es el campo que quiere modificar? Si es as�, ingrese 1: \n");
				scanf("%d", &aceptarModificacion);
				if(aceptarModificacion == 1)
				{
					strcpy(list[index].name, name);
					printf("El cambio se guard� correctamente!");
				}
				retorno = 1;
			break;

			case 2:
				CargarCadena(lastname, "Ingrese el nuevo apellido: ");
				validacion= ValidacionDeCaracteres(lastname);
				while(validacion == 0)
				{
					CargarCadena(lastname, "Error, ingrese el nuevo apellido: ");
					validacion= ValidacionDeCaracteres(lastname);
				}
				DetectarEspacio(lastname);
				printf("\n Est� usted seguro que este es el campo que quiere modificar? Si es as�, ingrese 1: \n");
				scanf("%d", &aceptarModificacion);
				if(aceptarModificacion == 1)
				{
					strcpy(list[index].lastname, lastname);
					printf("El cambio se guard� correctamente!");
				}
				retorno = 1;
			break;

			case 3:
				price = IngresarFlotante("Ingrese el nuevo precio: ", 5000, 1000000);
				printf("\n Est� usted seguro que este es el campo que quiere modificar? Si es as�, ingrese 1: \n");
				scanf("%d", &aceptarModificacion);
				if(aceptarModificacion == 1)
				{
					list[index].price = price;
					printf("El cambio se guard� correctamente!");
				}
				retorno = 1;
			break;

			case 4:
				CargarCadena(flycode, "Ingrese el nuevo c�digo de vuelo: ");
				printf("\n Est� usted seguro que este es el campo que quiere modificar? Si es as�, ingrese 1: \n");
				scanf("%d", &aceptarModificacion);
				if(aceptarModificacion == 1)
				{
					strcpy(list[index].flycode, flycode);
					printf("El cambio se guard� correctamente!");
				}
				retorno = 1;
			break;

			case 5:
				TypePassenger(typePassenger, segundoSize);
								cambiarTypePassenger = IngresarEntero("Ingrese el nuevo tipo de pasajero: ", 1, 3);
								printf("\n Est� usted seguro que este es el campo que quiere modificar? Si es as�, ingrese 1: \n");
								scanf("%d", &aceptarModificacion);
								if(aceptarModificacion == 1)
								{
									list[index].idTypePassenger = cambiarTypePassenger;
									printf("El cambio se guard� correctamente!");
								}
								retorno = 1;
			break;

			case 6:
				printf("Saliendo del submen�.\n");
			break;
		}


		}while (opcion != 6);

	return  retorno;
}

////////////////////////////////////////////////////////

int MatchearIdConEstadoDeVuelo(sPassenger list,sStatusFlight statusFlight[], int size)
{
    int index =-1;

    for(int i=0;i<size;i++)
    {
        if(list.idStatusFlight==statusFlight[i].idStatusFlight)
        {
            index=i;
            break;
        }
    }
    return index;
}

////////////////////////////////////////////////////////

int MatchearIdConTipoDePasajero(sPassenger list,sTypePassenger typePassenger[], int size)
{
    int index =-1;

    for(int i=0;i<size;i++)
    {
        if(list.idTypePassenger==typePassenger[i].idTypePassenger)
        {
            index=i;
            break;
        }
    }
    return index;
}

////////////////////////////////////////////////////////

void MostrarListados(sPassenger list[], int size, sStatusFlight statusFlight[], int segundoSize, sTypePassenger typePassenger[], int tercerSize)
{
	int orden;
	int opcion;

	opcion = IngresarEntero("-------------------------------------\n"
	    	                 "Ingrese una opci�n: \n"
	    	                 "-------------------------------------\n"
	    	                 "1- Ordenar pasajeros por apellido y tipo de vuelo.\n"
	    	                 "2- Mostrar pasajeros que superan el promedio de pasaje.\n"
	    	                 "3- Ordenar pasajeros por c�digo de vuelo y estados de vuelo 'Activo' (Sin cancelar).\n"
	    	                 "-------------------------------------\n", 1, 3);

	switch(opcion)
	{
		case 1:
			orden=IngresarEntero("Ingrese 1 si quiere ordenar de manera ascendente o 0 si quiere ordenarlo de manera descendente.", 0, 1);
			if(orden == 1)
			{
				sortPassengers(list, size, 1);
			}
			else
			{
				sortPassengers(list, size, -1);
			}

			printPassengers(list, size, statusFlight, typePassenger);
		break;

		case 2:
			MostrarPreciosEnBaseAlPromedio(list, size, statusFlight, 4, typePassenger, 3);
		break;

		case 3:
			orden=IngresarEntero("Ingresar 1 si quiere ordenar de manera ascendente o 0 si quiere ordenarlo de manera descendente.", 0, 1);
			if(orden == 1)
			{
				sortPassengersByCode(list, size, 1);
			}
			else
			{
				sortPassengersByCode(list, size, -1);
			}
			MostrarEnHorarioYEnCurso(list, size, statusFlight, segundoSize, typePassenger, tercerSize);
		break;
	}
}

////////////////////////////////////////////////////////

void MostrarPreciosEnBaseAlPromedio(sPassenger list[], int size, sStatusFlight statusFlight[],
								   int segundoSize, sTypePassenger typePassenger[], int tercerSize)
{
	float promedio;
	int contadorPasajeros;

	contadorPasajeros = 0;

	promedio = CalcularPromedioViajes(list, size);

	for(int i; i < size; i++)
	{
		if(promedio < list[i].price && list[i].isEmpty == OCUPADO)
		{
			contadorPasajeros++;
		}
	}
	printf("El promedio de los viajes es: %2f. \nLa cantidad de personas que superan el promedio son: %d\n",promedio , contadorPasajeros);
}

////////////////////////////////////////////////////////

int MostrarEnHorarioYEnCurso(sPassenger passengerList[], int size, sStatusFlight statusFlight[], int sizeStatus, sTypePassenger typePassenger[], int sizeType)
{
	int indiceStatusFlight;
	int indiceTypePassenger;

    for(int i=0; i<size;i++)
    {
        if(passengerList[i].idStatusFlight == 1 || passengerList[i].idStatusFlight == 2)
        {
        			indiceStatusFlight= MatchearIdConEstadoDeVuelo(passengerList[i], statusFlight, 4);
        			indiceTypePassenger= MatchearIdConTipoDePasajero(passengerList[i], typePassenger, 3);
        			if(passengerList[i].isEmpty == OCUPADO)
        			{
        				printf("ID: %d |-| "
        						"Nombre: %s |-| "
        						"Apellido: %s |-| "
        						"Precio: %.2f |-| "
        						"C�digo de vuelo: %s |-| "
        						"Estado de vuelo: %s |-| "
        						"Tipo de pasajero: %s"
        						"\n", passengerList[i].id,
        						passengerList[i].name,
        						passengerList[i].lastname,
        						passengerList[i].price,
        						passengerList[i].flycode,
        						statusFlight[indiceStatusFlight].statusFlight,
        						typePassenger[indiceTypePassenger].typePassenger);
        			}
        }
    }
    return 0;
}
