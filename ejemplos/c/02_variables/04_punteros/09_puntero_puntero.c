#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 3
#define M 100

int main()
{
	char **p;
	int i, j;
	p = (char **) malloc(sizeof(char *)*N);
	for (i=0; i<N; i++) {
		*(p+i) = (char *) malloc(sizeof(char)*M);
	}
	/* aquí tienen lo equivalente a char p[N][M] */
	strcpy(p[0], "Pedro");
	strcpy(p[1], "Juan");
	strcpy(p[2], "Diego");
	for (i=0; i<N; i++) {
		for (j=0; j<M && p[i][j]!='\0'; j++) {
			printf("%c ", p[i][j]);
		}
		printf("\n");
	}
	for (i=0; i<N; i++) {
		free(p[i]);
	}
	free(p);
	return EXIT_SUCCESS;
}
