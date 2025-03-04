#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "InputsYValidaciones.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir.
*****************************************************/



int main()
{
	setbuf(stdout, NULL);

    int option = 0;
    int banderaTexto = 0;
    int banderaBinario = 0;
    int banderaGuardarTexto = 0;
    int banderaGuardarBinario = 0;
    int id = 1000;

    LinkedList* listaPasajeros = ll_newLinkedList();



    do{
    	option = IngresarEntero("-------------------------------------\n"
    		                 "Ingrese una opci�n: \n"
    		                 "-------------------------------------\n"
    		                 "1- CARGAR DATOS EN MODO TEXTO.\n"
    		                 "2- CARGAR DATOS EN MODO BINARIO.\n"
    		                 "3- DAR DE ALTA PASAJERO.\n"
    		                 "4- MODIFICAR PASAJERO.\n"
    						 "5- DAR DE BAJA PASAJERO. \n"
    						 "6- LISTAR PASAJEROS.\n"
    						 "7- ORDENAR PASAJEROS.\n"
							 "8- GUARDAR DATOS EN MODO TEXTO.\n"
							 "9- GUARDAR DATOS EN MODO BINARIO.\n"
							 "10- SALIR.\n"
    		                 "-------------------------------------\n", 1, 10);
        switch(option)
        {
            case 1:
                if(ll_isEmpty(listaPasajeros) || (banderaTexto == 0 && banderaBinario == 0))
				{
					controller_loadFromText("data.csv", listaPasajeros);
					banderaTexto = 1;
				}
                else
                {
                	printf("No se puede cargar el archivo m�s de una vez.\n");
                }
            break;

            case 2:
            	if(ll_isEmpty(listaPasajeros) || (banderaTexto == 0 && banderaBinario == 0))
				{
            		controller_loadFromBinary("data.bin", listaPasajeros);
            		banderaBinario = 1;
				}
            	else
            	{
            		printf("No se puede cargar el archivo m�s de una vez.\n");
            	}
			break;

            case 3:
            	if(!controller_addPassenger(listaPasajeros, &id))
            	{
            		controller_SaveIdAsText("IDS.csv", listaPasajeros, id);
            	}
            break;

            case 4:
            	if(!ll_isEmpty(listaPasajeros))
            	{
            		controller_editPassenger(listaPasajeros);
            	}
            	else
            	{
            		printf("No hay pasajeros cargados.\n");
            	}
            break;

            case 5:
            	if(!ll_isEmpty(listaPasajeros))
            	{
            		controller_removePassenger(listaPasajeros);
            	}
            	else
            	{
            		printf("No hay pasajeros cargados.\n");
            	}
            break;

            case 6:
            	if(!ll_isEmpty(listaPasajeros))
				{
            		ll_sort(listaPasajeros, ordenarPorId, 1);
            		controller_ListPassenger(listaPasajeros);
				}
				else
				{
					printf("No hay pasajeros cargados.\n");
				}
            break;

            case 7:
            	if(!ll_isEmpty(listaPasajeros))
            	{
            		controller_sortPassenger(listaPasajeros);
            	}
            	else
            	{
            		printf("No hay pasajeros cargados.\n");
            	}
            break;

            case 8:
            	if(!ll_isEmpty(listaPasajeros))
            	{
					controller_saveAsText("data.csv", listaPasajeros);
					controller_SaveIdAsText("IDS.csv", listaPasajeros, id);
					banderaGuardarTexto = 1;
            	}
            	else
            	{
            		printf("No hay pasajeros cargados o debe cargar la lista.\n");
            	}
            break;

            case 9:
            	if(!ll_isEmpty(listaPasajeros))
            	{
					controller_saveAsBinary("data.bin", listaPasajeros);
					controller_SaveIdAsText("IDS.csv", listaPasajeros, id);
					banderaGuardarBinario = 1;
            	}
            	else
            	{
            		printf("No hay pasajeros cargados o debe cargar la lista.\n");
            	}
            break;

            case 10:
				if(banderaGuardarTexto == 1 || banderaGuardarBinario == 1)
				{
					printf("Saliendo!");
				}
				else
				{
					printf("Primero debe guardar el archivo en modo binario o texto.\n");
					option = 1;
				}

            break;

        }
    }while(option != 10);

    return 0;
}
