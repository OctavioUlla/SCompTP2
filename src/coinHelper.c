#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include "../inc/coinHelper.h"
#include "../inc/simbolos.h"

/* Funcion que obtiene por consola el número del simbolo
  @return simbolo seleccionado por el usuario
*/
int getSymbol()
{
    int simbolo; // Variable que guarda el nro del simbolo

    // Se solicita por consola elegir un simbolo
    printf("Por favor, seleccione un simbolo colocando un numero en la consola:\n");
    for (int i = 0; i < MAXSYMB; i++)
    {
        printf("\t%i: %s\n", (i + 1), getSymbolName(i));
    }
    printf("Su numero ~>  ");
    scanf("%d", &simbolo);

    // Se verifica el numero @TODO revisar esto
    if (simbolo <= MAXSYMB && simbolo > 0)
    {
        return simbolo - 1;
    }
    else
    {
        printf("No ha seleccionado un valor valido : ");
        return getSymbol();
    }
}

/* Funcion que obtiene por consola el número de la fiat
  @return fiat seleccionada por el usuario
*/
int getFiat()
{
    int fiat; // Variable que guarda el nro de la fiat

    // Se solicita por consola elegir una fiat
    printf("Por favor, seleccione una moneda fiat colocando un numero en la consola:\n");
    for (int i = 0; i < MAXFIAT; i++)
    {
        printf("\t%i: %s\n", (i + 1), getFiatName(i));
    }
    printf("Su numero ~>  ");
    scanf("%d", &fiat);

    // Se verifica el numero @TODO revisar esto
    if (fiat <= MAXFIAT && fiat > 0)
    {
        return fiat - 1;
    }
    else
    {
        printf("No ha seleccionado un valor valido : ");
        return getFiat();
    }
}

/* Funcion que obtiene por consola el número de monedas a comprar
  @return nro de monedas seleccionado por el usuario
*/
double getNCoins()
{
    float cantidad; // Variable que guarda la cantidad de monedas

    // Se pide por consola ingresar la cantidad de monedas
    printf("Por favor, escriba por consola la cantidad de monedas a comprar:\n");
    printf("Su numero ~>  ");
    scanf("%f", &cantidad);

    // Se verifica el numero
    if (cantidad > 0)
    {
        return (double)cantidad;
    }
    else
    {
        printf("No ha seleccionado un valor valido : ");
        return getNCoins();
    }
}