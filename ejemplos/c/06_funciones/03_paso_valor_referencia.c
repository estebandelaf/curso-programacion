#include <stdio.h>
#include <stdlib.h>

int suma(int a, int b)
{
	return a + b;
}

int resta (int a, int b)
{
	return a - b;
}

void suma_resta (int a, int b, int *s, int *r)
{
	*s = a + b;
	*r = a - b;
}

int main()
{
	int v1, v2;
	printf("1+2 = %d\n", suma(1,2));
	printf("1-2 = %d\n", resta(1,2));
	suma_resta(1,2,&v1,&v2);
	printf("1+2 = %d\n", v1);
	printf("1-2 = %d\n", v2);
	return EXIT_SUCCESS;
}

