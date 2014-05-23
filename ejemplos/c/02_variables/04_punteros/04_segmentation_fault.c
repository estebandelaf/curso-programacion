#include <stdio.h>
#include <stdlib.h>

/**
 * En caso de segmentation faul no se indica donde fue, esto es un problema.
 * Para saber en que parte del código ocurrió el error se puede utilizar GDB
 * Para usar GDB es necesario pasar el flag -ggdb a gcc, luego ejecutamos con:
 * $ gdb ./main
 * Dentro de gdb corremos el programa:
 * (gdb) r
 * Y GDB nos dirá donde fue el error:
 * Program received signal SIGSEGV, Segmentation fault.
 * 0 x0000000000400530 in main () at main*.c:7
 * 7           printf ("*a = %d\n", *a);
 */

int main()
{
	int *a = NULL;
	printf ("*a = %d\n", *a);
	return EXIT_SUCCESS;
}
