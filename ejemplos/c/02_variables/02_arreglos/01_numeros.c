#include <stdio.h>
#include <stdlib.h>

int main()
{
	int numeros[5];
	numeros[0] = 24;
	numeros[1] = -2;
	numeros[2] = 100;
	numeros[3] = 1000000000;
	numeros[4] = 10000000000; /* esto "revienta" el entero */
	printf ("numeros[0] = %d\n", numeros[0]);
	printf ("numeros[1] = %d\n", numeros[1]);
	printf ("numeros[2] = %d\n", numeros[2]);
	printf ("numeros[3] = %d\n", numeros[3]);
	printf ("numeros[4] = %d\n", numeros[4]);
	return EXIT_SUCCESS;
}

