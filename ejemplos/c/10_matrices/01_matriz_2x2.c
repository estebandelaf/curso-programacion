#include <stdio.h>
#include <stdlib.h>

#define N 2
#define M 2

int main()
{
	int matriz[N][M], i, j;
	matriz[0][0] = 1;
	matriz[0][1] = 2;
	matriz[1][0] = 3;
	matriz[1][1] = 4;
	for (i=0; i<N; i++) {
		for (j=0; j<M; j++){
			printf ("%d ", matriz[i][j]);
		}
		printf("\n");
	}
	return EXIT_SUCCESS;
}
