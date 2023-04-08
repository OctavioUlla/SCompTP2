#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <curl/curl.h>
#include "../inc/getPrice.h"


int main(void)
{
  printf("Precio BTC: %i\n",getPrice());

  return 0;
}

