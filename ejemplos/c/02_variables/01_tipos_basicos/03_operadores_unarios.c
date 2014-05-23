#include <stdio.h>
#include <stdlib.h>

/**
 * Ejemplo de operadores unarios:
 * n++ => n = n + 1
 * n-- => n = n - 1
 * Pero si es n++ primero se usa y luego se incrementa,
 * en cambio si es ++n primero se incrementa y luego se usa
 * Lo mismo para --
 */
int main()
{
	int n = 0;
	printf("n   %d\n", n);   /* 0 */
	printf("n++ %d\n", n++); /* 0 */
	printf("++n %d\n", ++n); /* 2 */
	printf("n-- %d\n", n--); /* 2 */
	printf("n   %d\n", n);   /* 1 */
	return EXIT_SUCCESS;
}
