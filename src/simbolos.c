#include "../inc/simbolos.h"

// Arreglo que guarda los simbolos validos
char simbolos_validos[MAXSYMB][MAXLEGHTSYMB] = {"BTC", "ETH", "DOT", "ADA", "DOGE", "ALGO", "MATIC"};
char fiat_validas[MAXFIAT][MAXLEGHTSYMB] = {"USD", "EUR", "ARS"};

char *getSymbolName(int simbolo)
{
    return simbolos_validos[simbolo];
}

char *getFiatName(int fiat)
{
    return fiat_validas[fiat];
}