#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <curl/curl.h>
#include "../inc/getPrice.h"

#define MAXLINES  20 // Maximas lineas que se leen de archivo price
#define MAXLEGHT  512 // Macimo numero de caracteres por linea
#define URL_MAX 512 // Largo maximo del URL
#define MAXSYMB 5 // Cantidad maxima de simbolos
#define MAXLEGHTSYMB 5 // Largo maximo de cada simbolo

// Arreglo que guarda los simbolos validos
char simbolos_validos[MAXSYMB][MAXLEGHTSYMB] = {"BTC","ETH","DOT","ADA","DOGE"};

// Estructura que guarda el header
struct curl_slist header;

/* Funcion que obtiene el precio de un simbolo
  @param simbolo simbolo a obtener el precio
  @param combre Referencia al String donde se guardara el nombre del simbolo
  @return el precio en formato double
*/
double getPrice(int simbolo,char* nombre){
    // Se escrib el nombre del simbolo
    strcpy(nombre,simbolos_validos[simbolo]);
    // Se pide al sercido el precio del Simbolo
    serverRequest(simbolo);

    return formatPrice();
}

/* Funcion que pide al servidor el valor de un simbolo
  @param simbolo simbolo a obtener su precio
*/
void serverRequest(int simbolo){
  // Se crea el objeto curl
  CURL *curl;
  CURLcode res;

  // Se llena la estructura header
  header.data = "X-CoinAPI-Key: CD7B2B0E-4577-4035-A59C-54F68F576A4F";
  header.next = NULL;

  // Se abre el archivo
  FILE* f = fopen("./tmp/price","w");

  // Se inicia curl
  curl = curl_easy_init();

  if(curl) {
    // Se genera el url para el simbolo obtenido
    char url[URL_MAX] =  "https://rest.coinapi.io/v1/quotes/BITSTAMP_SPOT_";
    char url_h[URL_MAX] = "_USD/current";
    strcat(url,simbolos_validos[simbolo]);
    strcat(url,url_h);

    // Se configura curl
    curl_easy_setopt(curl, CURLOPT_VERBOSE, 0); // Poner este bit en 1 para que la libreria exprese los comandos
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, &header);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, f);

    // Se realiza una peticion
    res = curl_easy_perform(curl);
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));
 
    // Se realiza cleanup de la libreria
    curl_easy_cleanup(curl);

  }

  // Se cierra el archivo
  fclose(f);
}

/* Funcion que obtiene por consola el número del simbolo
  @return simbolo seleccionado por el usuario
*/
int getSymbol(){
  int simbolo;
  printf("Seleccione un simbolo colocando un numero en la consola:\n");
  for(int i=0;i<MAXSYMB;i++){
    printf("\t%i: %s\n", (i+1),simbolos_validos[i]);
  }
  printf("Su numero ~>  ");
  // Se pide por pantalla un número
  scanf("%d",&simbolo);
  // Se verifica el numero
  if(simbolo<=MAXSYMB && simbolo>0 ){
    return simbolo-1;
  }else{
    printf("No ha seleccionado un valor valido : ");
    return getSymbol();
  } 
  
  
}
/* Funcion que formatea el valor del precio a un valor double
  @return valor del simbolo en formato double
*/
double formatPrice(){
  // Se abre el archivo
  FILE* f = fopen("./tmp/price","r");
  // Variables que sirven para recorrer el archivo
  int i = 0;
  char saver[MAXLINES][MAXLEGHT];
  char price[MAXLEGHT];
  // Recorremos el archivo buscando el precio
  while(!feof(f) && !ferror(f)){
    if(fgets(saver[i],MAXLEGHT,f) !=NULL){
      if(strstr(saver[i],"price") != NULL){
        strcpy(price,saver[i]);
      }
      i++;
    }
  }
  // Cortamos la cadena para dejar solo el precio
  strcpy(price,strtok(price, " "));
  strcpy(price,strtok(NULL, ","));
  
  // Se cierra el archivo
  fclose(f);

  // Devolvemos el precio en formato double
  return atof(price);
}