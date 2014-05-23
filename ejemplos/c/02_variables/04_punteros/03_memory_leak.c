#include <stdio.h>
#include <stdlib.h>

/**
 * Si no liberamos la memoria solicitada con free tendremos memory leaks,
 * estos se pueden chequear con:
 * $ valgrind --leak-check=full ./main
 */

int main()
{
	int *a = (int*) malloc(sizeof(int));
	*a = 1;
	printf ("*a = %d\n", *a);
	return EXIT_SUCCESS;
}
