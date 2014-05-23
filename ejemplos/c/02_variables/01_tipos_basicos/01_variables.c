#include <stdio.h> /* printf */
#include <stdlib.h> /* EXIT_SUCCESS */

/**
 * Función main que no recibe argumentos
 */
int main(void)
{
	/* crear diferentes tipos de variables */
	int entero = 65;
	double decimal = 3.4;
	char letra1 = 'A'; /* ASCCI */
	char letra2 = (char) entero; /* cast de entero a char*/
	/* mostrarlas */
	/* man 3 printf */
	printf("Variable | Valor\n");
	printf("---------|--------\n");
	printf("Entero   | %d\n", entero);
	printf("Decimal  | %f\n", decimal);
	printf("Decimal  | %.1f\n", decimal);
	printf("Letra1   | %c\n", letra1);
	printf("Letra2   | %c\n", letra2);
	/* retorno al sistema */
	return EXIT_SUCCESS;
}
