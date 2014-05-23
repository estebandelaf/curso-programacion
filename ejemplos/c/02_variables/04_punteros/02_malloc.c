#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *a = (int*) malloc(sizeof(int));
	*a = 1;
	printf ("*a = %d\n", *a);
	free (a);
	return EXIT_SUCCESS;
}
