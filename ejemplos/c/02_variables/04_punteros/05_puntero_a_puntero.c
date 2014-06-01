#include <stdio.h>
#include <stdlib.h>

int main()
{
	int b = 2;
	int *a = &b;
	int **c = &a;
	printf ("&b = %lu\n", (unsigned long int)&b);
	printf ("a = %lu\n", (unsigned long int)a);
	printf ("*a = %d\n", *a);
	printf ("&a = %lu\n", (unsigned long int)&a);
	printf ("c = %lu\n", (unsigned long int)c);
	printf ("*c = %lu\n", (unsigned long int)*c);
	printf ("**c = %d\n", **c);
	**c = 5;
	printf ("b = %d\n", b);
	b = 8;
	printf("**c = %d\n", **c);
	return EXIT_SUCCESS;
}
