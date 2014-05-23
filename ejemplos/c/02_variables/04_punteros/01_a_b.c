#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a = 3, *b = NULL;
	printf ("a = %d\n", a);
	/* esto no se hace */
	/*b = (int*)a;
	 *    printf ("b = %d\n", b);
	 *    printf ("*b = %d\n", *b);*/
	b = &a; /* asignamos la direccion de memoria de "a" a "b" */
	printf ("b = %lu\n", (unsigned long int)b);
	printf ("*b = %d\n", *b);
	a = 2;
	printf ("a = %d\n", a);
	printf ("*b = %d\n", *b);
	*b = 5;
	printf ("a = %d\n", a);
	printf ("*b = %d\n", *b);
	return EXIT_SUCCESS;
}

