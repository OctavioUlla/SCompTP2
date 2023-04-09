#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <curl/curl.h>
#include "../inc/getPrice.h"

#define MAXLEGHTSYMB 6

double mult(double cantidad, double precio);

int main(void)
{
  int simbolo;               // Variable que guarda un numero de 0 a MAXSYMB
  int fiat;               // Variable que guarda un numero de 0 a MAXFIAT
  double precio;             // variable que guarda el precio
  double cantidad;
  double precioFinal;
  char nombre_simbolo[MAXLEGHTSYMB]; // String que guarda el nombre_simbolo
  char nombre_fiat[MAXLEGHTSYMB];
  
  simbolo = getSymbol();
  fiat = getFiat();
  //@TODO agregar verificacion de que sea un numero valido
  precio = getPrice(simbolo, nombre_simbolo,fiat,nombre_fiat);

  // Se imprime por pantalla el nombre_simbolo de la moneda y el precio
  printf("Precio %s en %s: %f\n", nombre_simbolo,nombre_fiat, precio);

  cantidad = getNCoins();

  precioFinal = mult(cantidad, precio);
  printf("%f unidades de %s equivalen a %f %s\n",cantidad,nombre_simbolo, precioFinal,nombre_fiat);

  return 0;
}
