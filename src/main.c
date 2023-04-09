#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <curl/curl.h>

#include "../inc/getPrice.h"

#define MAXLEGHTSYMB 5 // Largo maximo de cada simbolo

double mult(double cantidad, double precio); // Funcion que multiplica el precio por la cantidad

int main(void)
{
  int simbolo;               // Variable que guarda un numero de 0 a MAXSYMB
  int fiat;                  // Variable que guarda un numero de 0 a MAXFIAT
  double precio;             // Variable que guarda el precio unitario
  double cantidad;           // Variable que guarda la cantidad de monedas a comprar
  double precioFinal;        // Variable que guarda el precio * cantidad
  char nombre_simbolo[MAXLEGHTSYMB]; // String que guarda el nombre del simbolo
  char nombre_fiat[MAXLEGHTSYMB];    // String que guarda el nombre de la fiat

  // Se imprime la bienvenida
  printf("Hola!Bienvenid@ a la calculadora de precios de cryptomonedas\n");
  sleep(2);
  system("clear");

  // Se pide el simbolo
  simbolo = getSymbol();
  system("clear");

  // Se pide la fiat
  fiat = getFiat();
  system("clear");

  // Se obtiene el precio y se lo imprime por pantalla
  precio = getPrice(simbolo,nombre_simbolo,fiat,nombre_fiat);
  printf("Precio de %s en %s: %f\n",nombre_simbolo,nombre_fiat,precio);

  // Se pide la cantidad de monedas y se calcula el resultado
  cantidad = getNCoins();
  precioFinal = mult(cantidad, precio);
  system("clear");

  // Se imprime el resultado final y el agradecimiento
  printf("%.*f unidades de %s equivalen a %.*f %s\n",2,cantidad,nombre_simbolo,2,precioFinal,nombre_fiat);
  printf("\nGracias por usar nuestra calculadora!\n~ Grupo Paulo Carteras ~");
  printf("\n\t->Antonio Viglietti\n\t->Lara Scarafia\n\t->Octavio Ulla\n");
  sleep(10);

  return 0;
}
