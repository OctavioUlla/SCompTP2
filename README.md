# **_SistCompTP2_**

#### En el TP#2 se diseñó e implementó una Calculadora de Cotización de Criptomonedas. La capa superior recupera la cotización de 7 criptomonedas obtenidas mediante la biblioteca CURL de C y la API Rest de la pagina BITSTAMP. El programa luego convoca con los datos de la consulta a rutinas en ensamblador que realizan la multiplicación de la cantidad de monedas a comprar por el precio de las mismas y devuelve la cotización solicitada.

## Modo de uso:

  #### 1. ```$~ make all ``` (para construir el proyecto).
  #### 2. ``` $~ ./bin./getPrice ``` (para ejetuctar el programa).
  #### 3. Luego, se pide ingresar por consola un número correspondiente al signo del cual se quiere saber su cotización.
  #### 4. A continuación, se pide ingresar otro número correspondiente a la fiat contra la cual se quiere expresar el valor del signo.
  #### 5. Por último, se pide ingresar por consola la cantidad de monedas a comprar. 
> Ahora el programa imprimirá la cotización solicitada 
