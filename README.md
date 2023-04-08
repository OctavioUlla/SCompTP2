# SCompTP2

Para aprobar el TP#2 se debe diseñar e implementar una Calculadora de Cotización de Criptomonedas. La capa superior recuperará la cotización de al menos dos criptomonedas que pueden ser obtenidas de alguna de "Las 12 mejores API del mercado de valores para crear productos financieros". Se recomienda el uso de API Rest y python. Los datos de consulta realizados deben ser entregados a un programa en C que convocará rutinas en ensamblador para que hagan los cálculos de conversión y devuelvan las cotizaciones en pesos, u$s y euros. Luego el programa en C o python mostrará los cálculos obtenidos.-

Se debe utilizar el stack para convocar, enviar parámetros y devolver resultados. O sea utilizar las convenciones de llamadas de lenguajes de alto nivel a bajo nivel.-

La defensa del trabajo es GRUPAL (mínimo 2 estudiantes, máximo 3).

Las presentaciones de los trabajos se realizarán utilizando GitHub (una cuenta privada). Cada grupo debe asignar un responsable (con email institucional) como usuario de la cuenta de GitHub. Se debe realizar un commit brevemente comentado con cada funcionalidad implementada y validada.-


Modo de uso:
$~ make all (para construir el proyecto)
$~ ./bin./getPrice (para ejetuctar el programa)
Luego, se ingresa un numero por consola y el programa devuelve el precio del simbolo seleccionado