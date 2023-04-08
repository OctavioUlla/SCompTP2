#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <curl/curl.h>
#include "../inc/getPrice.h"

#define MAXLEGHTSYMB 6

int64_t mult(int64_t cantidad, int64_t precio);

int main(void)
{
  int simbolo;               // Variable que guarda un numero de 0 a MAXLENGHTSYMB
  double precio;             // variable que guarda el precio
  char nombre[MAXLEGHTSYMB]; // String que guarda el nombre
  simbolo = getSymbol();
  //@TODO agregar verificacion de que sea un numero valido
  precio = getPrice(simbolo, nombre);

  // Se imprime por pantalla el nombre de la moneda y el precio
  printf("Precio %s: %f\n", nombre, precio);

  int64_t precioFinal = mult(3, 5);
  printf("PrecioFinal: %ld\n", precioFinal);

  return 0;
}
