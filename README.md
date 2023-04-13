# **_SistCompTP2_**

#### En el TP#2 se diseño e implemento una Calculadora de Cotización de Criptomonedas. La capa superior recupera la cotización de 7 criptomonedas obtenidas mediante la biblioteca CURL de C y la API Rest de la pagina BITSTAMP. El programa luego convoca con los datos de la consulta a rutinas en ensamblador que realizan la multiplicacion de la cantidad de monedas a comprar por el precio de las mismas.

## Modo de uso:

  #### 1. ```$~ make all ``` (para construir el proyecto).
  #### 2. ``` $~ ./bin./getPrice ``` (para ejetuctar el programa).
  #### 3. Luego, se pide ingresar por consola un numero correspondiente al signo del cual queremos saber su cotizacion.
  #### 4. A continuacion, se pide ingresar otro numero correspondiente a la fiat contra la cual queremos expresar el valor del signo.
  #### 5. Por ultimo, se pide ingresar por consola la cantidad de monedas a comprar. 
> Ahora el programa imprimira la cotizacion solicitada 
