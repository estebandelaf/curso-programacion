#include <stdio.h>
#include <stdlib.h>

void sort(int *numeros, int n)
{
	int i, j, swap;
	for (i=0; i<n-1; i++) {
		for (j=0; j<n-i-1; j++) {
			if (numeros[j] > numeros[j+1]) {
				swap = numeros[j];
				numeros[j] = numeros[j+1];
				numeros[j+1] = swap;
			}
		}
	}
}

void rsort(int *numeros, int n)
{
	int i, j, swap;
	for (i=0; i<n-1; i++) {
		for (j=0; j<n-i-1; j++) {
			if (numeros[j] < numeros[j+1]) {
				swap = numeros[j];
				numeros[j] = numeros[j+1];
				numeros[j+1] = swap;
			}
		}
	}
}

void imprimir(int numeros[], int n)
{
	int i;
	printf("numeros: ");
	for (i=0; i<n; i++) {
		printf("%d ", numeros[i]);
	}
	printf("\n");
}

int main()
{
	int numeros[10] = {1,3,6,2,4,3,1,8,6,9};
	imprimir (numeros, 10);
	sort(numeros, 10);
	imprimir (numeros, 10);
	rsort(numeros, 10);
	imprimir (numeros, 10);
	return EXIT_SUCCESS;
}
