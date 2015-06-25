##Laboratorio de programación 2014-1

***Francisco Valdivia***
***Roberto Moreno***

#Tarea N°5

La tarea que usted realizará consiste en desarrollar un programa en C.

**Constará de sólo una parte. Según la funcionalidad efectiva de esta, la tarea será evaluada.**

Notas sobre la tarea:

No se aceptaran tareas que no cumplan con estándar ISO C90 (o sea que den error). 
Tampoco se aceptaran tareas con segmentation fault inmediatos (al ejecutar) o que no compilan.
- Se descontará 1 décima por cada warning.
- Se descontará 0.5 décimas por cada bloque de memoria que se pierda con memory leaks.

La tarea consiste en crear un programa que lea un archivo de entrada (input.txt) que vendra con el siguiente formato:
```
3
*
5 3 0 0 7 0 0 0 0 
6 0 0 1 9 5 0 0 0 
0 9 8 0 0 0 0 6 0 
8 0 0 0 6 0 0 0 3 
4 0 0 8 0 3 0 0 1 
7 0 0 0 2 0 0 0 6 
0 6 0 0 0 0 2 8 0 
0 0 0 4 1 9 0 0 5 
0 0 0 0 8 0 0 7 9 
*
5 3 0 0 7 0 0 0 0 
6 0 0 1 9 5 0 0 0 
0 9 8 0 0 0 0 6 0 
8 0 0 0 6 0 0 0 3 
4 0 0 8 0 3 0 0 1 
7 0 0 0 2 0 0 0 6 
0 6 0 0 0 0 2 8 0 
0 0 0 4 1 9 0 0 5 
0 0 0 0 8 0 0 7 9 
*
5 3 0 0 7 0 0 0 0 
6 0 0 1 9 5 0 0 0 
0 9 8 0 0 0 0 6 0 
8 0 0 0 6 0 0 0 3 
4 0 0 8 0 3 0 0 1 
7 0 0 0 2 0 0 0 6 
0 6 0 0 0 0 2 8 0 
0 0 0 4 1 9 0 0 5 
0 0 0 0 8 0 0 7 9 
*
```

En donde la primera linea indica el numero de los X sudoku's a resolver seguido de un conjunto de X sudoku's separados por el caracter '*'

Con esos datos rellenar un arreglo de dos dimensiones y proceder a verificar si estan correctamente desarrollados o no. Luego entregar por pantalla la siguiente respuesta.
```
SUDOKU 1:
SUDOKU OK
SUDOKU 2:
ERROR EN CUADRICULA X
SUDOKU 3:
ERROR EN FILA Y
ERROR EN COLUMNA Z
```

Los siguientes son los tipos de errores que se piden identificar:
* ERROR EN CUADRICULA X
* ERROR EN FILA Y
* ERROR EN COLUMNA Z

La fecha de entrega tope es el 20 de junio de 2014 a las 23.59 hrs. GMT -4

Deben programar su tarea usando el IDE online disponible aquí http://profesores.ing.unab.cl/~delaf/ide
Luego enviar el proyecto completo descargandolo de la misma página en formato .tar.gz

Cualquier duda y la tarea la deben hacer llegar a mi correo:  r.morenoperez[at]uandresbello.edu

Éxito!
