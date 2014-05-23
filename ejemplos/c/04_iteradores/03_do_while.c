#include <stdio.h>
#include <stdlib.h>

/**
 * do-while ejecuta SIEMPRE al menos una vez el código del while (del do en
 * estricto rigor)
 */

int main()
{
	do {
		printf ("Ejecutando una vez while a pesar que es falso\n");
	} while (0);
	return EXIT_SUCCESS;
}
