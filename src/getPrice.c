#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <curl/curl.h>
#include "../inc/getPrice.h"

#define MAXLINES  200
#define MAXLEGHT  512

// Estructura que guarda el header
struct curl_slist header;

int getPrice(){

    serverRequest();

    FILE* f = fopen("./tmp/price","r");
    char saver[MAXLINES][MAXLEGHT];
    int i = 0;
    char tmp[MAXLEGHT];
    char price[MAXLEGHT];

    while(!feof(f) && !ferror(f)){
      if(fgets(saver[i],MAXLEGHT,f) !=NULL){
        if(strstr(saver[i],"price") != NULL){
          strcpy(tmp,saver[i]);
        }
        i++;
      }
    }
    strcpy(price,strtok(tmp, " "));
    strcpy(price,strtok(NULL, ","));
    

    // Se cierra el archivo
    fclose(f);

    return atoi(price);
}

void serverRequest(){
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

    // Se configura curl
    curl_easy_setopt(curl, CURLOPT_VERBOSE, 0); // Poner este bit en 1 para que la libreria exprese los comandos
    curl_easy_setopt(curl, CURLOPT_URL, "https://rest.coinapi.io/v1/quotes/BITSTAMP_SPOT_BTC_USD/current");
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
