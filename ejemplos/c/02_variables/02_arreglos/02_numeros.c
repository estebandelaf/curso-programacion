#include <stdio.h>
#include <strings.h>
#define N 10
int main()
{
	int numeros[N];

	/* alternativa 1 para inicializar el arreglo */
/*	int i;
	for (i=0; i<N; i++)
		numeros[i] = 0;*/

	/* alternativa 2 para inicializar el arreglo */
	bzero(numeros, sizeof(int)*N);

	numeros[5] = 55;
	numeros[9] = 100;
	printf("numeros[5] = %d\n", numeros[5]);
	printf("numeros[9] = %d\n", numeros[9]);
	printf("numeros[8] = %d\n", numeros[8]);
	return 0;
}

