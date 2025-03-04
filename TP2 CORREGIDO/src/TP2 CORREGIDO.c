/*
 ============================================================================
 Name        : TP2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "Nexo.h"

#define TAM 2000

int main(void)
{
	setbuf(stdout, NULL);
	sPassenger unPasajero;
	sPassenger list[TAM];

	sStatusFlight statusFlight[4] = {{1, "EN HORARIO"} , {2, "EN CURSO"} , {3, "DEMORADO"} , {4, "CANCELADO"}};
	sTypePassenger typePassenger[3] = {{1, "ECON�MICO"} , {2, "ECON�MICO PREMIUM"} , {3, "CLASE EJECUTIVA"}};

	initPassengers(list, TAM);
	int opcionElegida;
	int validacion;
	int id;
	int eliminar;
	int validarEspacio;
	int retorno;

	do
	{
	opcionElegida=IngresarEntero("-------------------------------------\n"
	                 "Ingrese una opci�n: \n"
	                 "-------------------------------------\n"
	                 "1- ALTA PASAJERO.\n"
	                 "2- MODIFICAR PASAJERO.\n"
	                 "3- BAJA PASAJERO.\n"
	                 "4- INFORMAR LISTADOS.\n"
					 "5- CARGA FORZADA. \n"
					 "6- SALIR.\n"
	                 "-------------------------------------\n", 1,6 );

	switch(opcionElegida)
	{
		case 1:
			validacion = addPassenger(unPasajero, statusFlight, 4, typePassenger, 3, list, TAM);
			switch(validacion)
			{
				case -1:
					printf("Error al cargar pasajero, no hay m�s espacio. \n");
				break;
				default:
					printf("Se cargo correctamente el pasajero!\n");
				break;
			}
		break;

		case 2:
			printPassengers(list, TAM, statusFlight, typePassenger);
			validarEspacio=BuscarEspacioOcupado(list, TAM);
			if(validarEspacio != -1)
			{
				retorno = ModificarPasajero(list, TAM, statusFlight, 4, typePassenger, 3);
				if(retorno == 1)
				{
					printf("Se han realizado correctamente los cambios!\n");
				}
				else
				{
					printf("No se ha realizado ning�n cambio, volviendo al men�.\n");
				}
			}
			else
			{
				printf("No se dio de alta ning�n pasajero!\n");
			}
		break;

		case 3:
			printPassengers(list, TAM, statusFlight, typePassenger);
			validarEspacio=BuscarEspacioOcupado(list, TAM);
			if(validarEspacio != -1)
			{
				id= IngresarEntero("Ingrese el ID del pasajero a eliminar: \n", 1000, 3000);
				eliminar = removePassenger(list, TAM, id);
				if(eliminar == 0)
				{
					printf("\n Se ha eliminado correctamente al pasajero! \n");
				}
				else
				{
					printf("\n No se ha conseguido eliminar al pasajero, probablemente no existe el id o cancelaste la opci�n! vuelva a intentarlo! \n");
				}
			}
			else
			{
				printf("No se dio de alta ning�n pasajero!\n");
			}
		break;

		case 4:
			validarEspacio=BuscarEspacioOcupado(list, TAM);
			if(validarEspacio != -1)
			{
				MostrarListados(list, TAM, statusFlight, 4, typePassenger, 3);
			}
			else
			{
				printf("\n No se dio de alta ning�n pasajero! \n");
			}
		break;

		case 5:
			CargaForzada(list, 5);
		break;

		case 6:
			printf("\nSaliendo, hasta la pr�xima! :D \n");
		break;

		default:
			printf("\nError, ingrese una opci�n v�lida del men�!\n");
		break;
	}

	}while(opcionElegida != 6);

	return EXIT_SUCCESS;
}
