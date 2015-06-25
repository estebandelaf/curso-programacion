#include <stdio.h>
#include <stdlib.h>

void imprimir(int numeros[], int n)
{
	int i;
	printf("numeros: ");
	for (i=0; i<n; i++) {
		printf("%d ", numeros[i]);
	}
	printf("\n");
}

void imprimir2(int *numeros, int n)
{
	int i;
	printf("numeros: ");
	for (i=0; i<n; i++) {
		printf("%d ", *(numeros+i));
	}
	printf("\n");
}

int main()
{
	int numeros[3];
	numeros[0] = 5;
	numeros[1] = -3;
	numeros[2] = 7;
	imprimir(numeros, 3);
	printf("*numeros = %d\n", *numeros);
	printf("*(numeros+1) = %d\n", *(numeros+1));
	printf("*(numeros+2) = %d\n", *(numeros+2));
	imprimir2(numeros, 3);
	return EXIT_SUCCESS;
}

