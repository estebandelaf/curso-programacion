#include <stdio.h> /* printf */
#include <stdlib.h> /* EXIT_SUCCESS */

/**
 * Función main que no recibe argumentos
 */
int main(void)
{
	/* división es entera, hay que explicitar decimales */
	printf ("Resultado: %f\n", (1+2.0/3.0*1+2*3-1));
	printf ("Resultado: %d\n", (int)(1+2.0/3.0*1+2*3-1));
	/*printf ("Potencia: %d\n", 2**2); no existe operador ** */
	printf ("Módulo: %d\n", 3%2);
	return EXIT_SUCCESS;
}
