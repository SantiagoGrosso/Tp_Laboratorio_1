#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include "Controller.h"
#include "InputsYValidaciones.h"

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
    int validacion = -1;
    FILE* pArchivo;

    if(path != NULL && pArrayListPassenger != NULL)
    {
    	pArchivo = fopen(path, "r");

    	if(pArchivo != NULL)
    	{
    		if(!parser_PassengerFromText(pArchivo, pArrayListPassenger))
    		{
    			printf("Se carg� correctamente.\n");
    			validacion = 0;
    		}
    	}
    	else
    	{
    		printf("No se logr� abrir el archivo.\n");
    	}
    	fclose(pArchivo);
    }

    return validacion;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
    int validacion = -1;
    FILE* pArchivo;

    if(path != NULL && pArrayListPassenger != NULL)
    {
    	pArchivo = fopen(path, "rb");

    	if(pArchivo != NULL)
    	{
    		if(!parser_PassengerFromBinary(pArchivo, pArrayListPassenger))
    		{
    			printf("Se carg� correctamente.\n");
    			validacion = 0;
    		}
    		fclose(pArchivo);
    	}
    	else
		{
			printf("No se logr� abrir el archivo.\n");
		}
    }

    return validacion;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger, int* id)
{
    int validacion = -1;
    int idAuxiliar;

	if(pArrayListPassenger != NULL && id != NULL)
	{

		controller_loadIdFromText("IDS.csv", pArrayListPassenger, id);

		idAuxiliar = *id;

		if(!addPassenger(pArrayListPassenger, &idAuxiliar))
		{
			*id = idAuxiliar;
			validacion = 0;
		}
	}

	return validacion;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
    int validacion = -1;

    if(pArrayListPassenger != NULL)
    {
    	if(!modifyPassenger(pArrayListPassenger))
    	{
    		printf("Se realiz� la modificaci�n con �xito.\n");
    		validacion = 0;
    	}
    	else
    	{
    		printf("No se realiz� la modificaci�n.\n");
    	}
    }

    return validacion;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
    int validacion = -1;

    if(pArrayListPassenger != NULL)
    {
    	if(!removePassenger(pArrayListPassenger))
    	{
    		validacion = 0;
    	}
    }

    return validacion;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
    int validacion = -1;

    if(pArrayListPassenger != NULL)
    {
    	printPassengerList(pArrayListPassenger);
    	validacion = 0;
    }
    return validacion;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
    int validacion = -1;
    int orden;
    int opcion;
    LinkedList* clonacion;

    if(pArrayListPassenger != NULL)
    {
    	clonacion = ll_clone(pArrayListPassenger);

    	if(clonacion != NULL)
    	{
    		do
    		{
    			opcion = IngresarEntero("-------------------------------------\n"
    		                 "Ingrese una opci�n: \n"
    		                 "-------------------------------------\n"
    		                 "1- ORDENAR POR ID.\n"
    		                 "2- ORDENAR POR NOMBRE.\n"
    		                 "3- ORDENAR POR APELLIDO.\n"
    		                 "4- SALIR.\n"
    		                 "-------------------------------------\n", 1, 4);

    			if(opcion != 4)
    			{
    				orden = IngresarEntero("-------------------------------------\n"
    				"Ingrese una opci�n: \n"
					"-------------------------------------\n"
					"0- ORDEN DESCENDENTE.\n"
					"1- ORDENAR ASCENDENTE.\n"
					"-------------------------------------\n", 0, 1);
    			}

    			switch(opcion)
    			{
    				case 1:
    					if(!ll_sort(clonacion, ordenarPorId, orden))
    					{
    						if(orden == 1)
    						{
    							printf("Se orden� la lista por ID de manera ascendente.\n");
    							controller_ListPassenger(clonacion);
    						}
    						else
    						{
    							printf("Se orden� la lista por ID de manera descendente.\n");
    							controller_ListPassenger(clonacion);
    						}
    						validacion= 0;
    					}
    				break;

    				case 2:
    					if(!ll_sort(clonacion, ordenarPorNombre, orden))
    					{
    						if(orden == 1)
    						{
    							printf("Se orden� la lista por nombre de manera ascedente.\n");
    							controller_ListPassenger(clonacion);
    						}
    						else
    						{
    							printf("Se orden� la lista por nombre de manera descendente.\n");
    							controller_ListPassenger(clonacion);
    						}
    						validacion= 0;
    					}
    				break;

    				case 3:
    					if(!ll_sort(clonacion, ordenarPorApellido, orden))
						{
							if(orden == 1)
							{
								printf("Se orden� la lista por apellido de manera ascedente.\n");
								controller_ListPassenger(clonacion);
							}
							else
							{
								printf("Se orden� la lista por apellido de manera descendente.\n");
								controller_ListPassenger(clonacion);
							}
							validacion= 0;
						}
    				break;

    				case 4:
    					printf("Volviendo al men�.\n");
    				break;
    			}
    		}while(opcion != 4);
    	}
    }

    return validacion;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
    int validacion = -1;
    int size;
    int idAuxiliar;
    char nombreAuxiliar[50];
    char apellidoAuxiliar[50];
    float precioAuxiliar;
    char tipoPasajeroAuxiliar[20];
    char codigoVueloAuxiliar[20];
    char estadoVueloAuxiliar[20];
    FILE* pArchivo;
    Passenger* pasajeroAuxiliar = NULL;

    if(path != NULL && pArrayListPassenger != NULL)
    {
    	pArchivo = fopen(path, "w");

    	size= ll_len(pArrayListPassenger);

    	if(pArchivo != NULL && size > 0)
    	{
    		fprintf(pArchivo, "ID , NOMBRE , APELLIDO , PRECIO , TIPO DE PASAJERO , CODIGO DE VUELO , ESTADO DE VUELO");
    		for(int i = 0; i < size; i++)
    		{
    			pasajeroAuxiliar = (Passenger*) ll_get(pArrayListPassenger, i);

    			if(pasajeroAuxiliar != NULL)
    			{
    				validacion = validarGets(pasajeroAuxiliar, &idAuxiliar, nombreAuxiliar, apellidoAuxiliar, tipoPasajeroAuxiliar, &precioAuxiliar, codigoVueloAuxiliar, estadoVueloAuxiliar);
    				if(validacion == 0)
    				{
    					fprintf(pArchivo, "\n%5d,%10s,%10s,%2f,%s,%s,%s\n", idAuxiliar, nombreAuxiliar, apellidoAuxiliar, precioAuxiliar, tipoPasajeroAuxiliar, codigoVueloAuxiliar, estadoVueloAuxiliar);
    				}
    				else
    				{
    					Passenger_delete(pasajeroAuxiliar);
    					printf("No se pudo guardar el archivo.\n");
    				}
    			}
    		}
    	}
    	else
    	{
    		printf("No se pudo abrir el archivo.\n");
    	}
    	fclose(pArchivo);
    }
    if(validacion == 0)
	{
		printf("El archivo se guard� correctamente.\n");
	}
    return validacion;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
    int validacion = -1;
    int size;
    FILE* pArchivo;
    Passenger* pasajeroAuxiliar = NULL;

    if(path != NULL && pArrayListPassenger != NULL)
    {
    	size = ll_len(pArrayListPassenger);

    	pArchivo = fopen(path, "wb");

    	if(pArchivo != NULL && size > 0)
    	{
    		for(int i = 0; i < size; i++)
    		{
    			pasajeroAuxiliar = (Passenger*) ll_get(pArrayListPassenger, i);

    			if(pasajeroAuxiliar != NULL)
				{
					fwrite(pasajeroAuxiliar,sizeof(Passenger),1,pArchivo);
					validacion = 0;
				}
    		}
    	}
    	else
		{
			Passenger_delete(pasajeroAuxiliar);
			printf("No se pudo guardar el archivo.\n");
		}
    	fclose(pArchivo);
    }
    if(validacion == 0)
    {
    	printf("El archivo se guard� correctamente.\n");
    }

    return validacion;

}

/// @brief Controlador para cargar las ID en un archivo.
///
/// @param path Ubicaci�n del archivo.
/// @param pArrayListPassenger La lista de pasajeros.
/// @param id El id a cargar.
/// @return Retorna si se pudo o no cargar el id.
int controller_loadIdFromText(char* path, LinkedList* pArrayListPassenger, int* id)
{
	int validacion = -1;
	FILE* pArchivo;

	if(path != NULL && pArrayListPassenger != NULL)
	{
		pArchivo = fopen(path, "r");

		if(pArchivo != NULL)
		{
			if(!parser_IdFromText(pArchivo, pArrayListPassenger, id))
			{
				validacion = 0;
			}
		}
		fclose(pArchivo);
	}
	return validacion;
}

/// @brief Controlador para guardar las ID en un archivo.
///
/// @param path Ubicaci�n del archivo.
/// @param pArrayListPassenger La lista de pasajeros.
/// @param id El id a guardar.
/// @return Retorna si se pudo o no guardar el id.
int controller_SaveIdAsText(char* path, LinkedList* pArrayListPassenger, int id)
{
	int validacion = -1;
	int mayorId = 0;
	FILE* pArchivo;

	if(path != NULL && pArrayListPassenger != NULL)
	{
		if(id == 1000)
		{
			mayorId = id;
			validacion = 0;
		}
		else
		{
			mayorId= ObtenerMayorId(pArrayListPassenger);
		}

		pArchivo = fopen(path, "w");

		if(pArchivo != NULL)
		{
			fprintf(pArchivo, "ID: ");
			fprintf(pArchivo, "%d\n", mayorId);
			validacion = 0;
		}

		fclose(pArchivo);
	}

	return validacion;
}
