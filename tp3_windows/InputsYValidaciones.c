/*
 * InputsYValidaciones.c
 *
 *  Created on: 4 jun. 2022
 *      Author: RYZEN 2700X
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "InputsYValidaciones.h"

float IngresarFlotante(char mensaje [], float minimo, float maximo)
{
	float retorno;
	char numeroIngresado[100];
	int validacion;

	printf("%s", mensaje);
	fflush(stdin);
	gets(numeroIngresado);
	validacion= ValidarNumero(numeroIngresado);
	while(validacion==0)
	{
		printf("\n Vuelva a ingresar el n�mero (sin letras). \n ");
		fflush(stdin);
		gets(numeroIngresado);
		validacion= ValidarNumero(numeroIngresado);
	}

	retorno=atof(numeroIngresado);

	while(retorno < minimo || retorno > maximo)
	{
		printf("\nError, vuelva a ingresar el n�mero en los l�mites correspondientes. \n");
		fflush(stdin);
		gets(numeroIngresado);
		validacion= ValidarNumero(numeroIngresado);
		while(validacion==0)
			{
				printf("\n Vuelva a ingresar el n�mero (sin letras). \n");
				fflush(stdin);
				scanf("%s", numeroIngresado);
				validacion= ValidarNumero(numeroIngresado);
			}
		retorno=atof(numeroIngresado);
	}
	return retorno;
}

///////////////////////////////////////////////////

int IngresarEntero(char mensaje [], int minimo, int maximo)
{
	int retorno;
	char numeroIngresado[100];
	int validacion;

	printf("%s", mensaje);
	fflush(stdin);
	scanf("%s", numeroIngresado);
	validacion=ValidarNumero(numeroIngresado);
	while(validacion==0)
	{
		printf("\n Vuelva a ingresar el n�mero (sin letras). \n");
		fflush(stdin);
		scanf("%s", numeroIngresado);
		validacion= ValidarNumero(numeroIngresado);
	}

	retorno=atoi(numeroIngresado);

	while(retorno < minimo || retorno > maximo)
		{
			printf("\nError, vuelva a ingresar el n�mero en los l�mites correspondientes. \n");
			fflush(stdin);
			scanf("%s", numeroIngresado);
			validacion= ValidarNumero(numeroIngresado);
			while(validacion==0)
				{
					printf("\n Vuelva a ingresar el n�mero (sin letras). \n");
					fflush(stdin);
					scanf("%s", numeroIngresado);
					validacion= ValidarNumero(numeroIngresado);
				}
			retorno=atoi(numeroIngresado);
		}

	return retorno;
}

///////////////////////////////////////////////////

char IngresarCaracter(char mensaje [])
{
	char caracterIngresado;

		printf("%s", mensaje);
		fflush(stdin);
		scanf("%c", &caracterIngresado);
		while(caracterIngresado != 's' && caracterIngresado != 'n')
		{
			printf("Dato incorrecto, por favor, vuelva a ingresarlo: ");
			fflush(stdin);
			scanf("%c", &caracterIngresado);
		}

		return caracterIngresado;
}

///////////////////////////////////////////////////

void CargarVector(int numeros[], int size)
{
	for(int i=0; i<size; i++)
	{
		numeros[i] = IngresarEntero("Ingrese entero: ", -1000000, 1000000);
	}
}

///////////////////////////////////////////////////

void CargarCadena(char cadena[],char mensaje[])
{
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%[^\n]",cadena);
}

///////////////////////////////////////////////////

void DetectarEspacio (char NombreApellido [])
{
    int i;
    int size;

    size= strlen(NombreApellido);
    strlwr(NombreApellido);

    for(i= 0; i<size; i++)
    {
        if(NombreApellido[i-1]==32 || i==0)
        {
            NombreApellido[i] = toupper(NombreApellido[i]);
        }
    }

}

///////////////////////////////////////////////////

int obtenerID()
{
    static int idIncremental = 1;
    return idIncremental++;
}

///////////////////////////////////////////////////

int ValidarNumero (char numeros[])
{
	int validacion=-1;
	for(int i=0;i<strlen(numeros);i++)
	{
		if(!(numeros[i] == 46 || (numeros[i]>=48 && numeros[i]<=57)))
		{

			validacion=0;

		}
	}
	return validacion;
}

///////////////////////////////////////////////////

int ValidacionDeCaracteres (char cadena[])
{
	int size = strlen(cadena);
	int validacion=-1;
	for(int i=0;i<size;i++)
	{
		if ((isdigit(cadena[i]) || isalpha(cadena[i]) == 0) && (cadena[i] != 32))
		{
			validacion=0;
		}
	}
	return validacion;
}

///////////////////////////////////////////////////

float CalcularPromedio (float acumulador, int contador)
{
	float promedio;

	promedio = acumulador / contador;

	return promedio;
}

///////////////////////////////////////////////////

int ValidarDias(int mes)
{
	int dia;
	switch (mes)
	{
		case 2:
			dia = IngresarEntero("\nIngrese el d�a (Entre 1 y 28): \n", 1, 28);
		break;

		case 4:
		case 6:
		case 9:
		case 11:
			dia = IngresarEntero("\nIngrese el d�a (Entre 1 y 30): \n", 1, 30);
		break;

		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			dia = IngresarEntero("\nIngrese el d�a (Entre 1 y 31): \n", 1, 31);
		break;
	}
	return dia;
}
