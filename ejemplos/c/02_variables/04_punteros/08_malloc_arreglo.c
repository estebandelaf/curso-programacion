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

int main()
{
	int N, i, *x;
	scanf("%d", &N);
	/*int x[N];*/
	x = (int *) malloc(sizeof(int)*N);
	for (i=0; i<N; i++)
		x[i] = N-i;
	imprimir(x, N);
	return EXIT_SUCCESS;
}
