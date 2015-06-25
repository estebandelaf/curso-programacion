#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#define N 5

struct e {
	int c1;
	int c2;
};

int main()
{
	int i;
	struct e *arreglo[N];
	for (i=0; i<N; i++) {
		arreglo[i] = NULL;
	}
	arreglo[0] = (struct e*) malloc(sizeof(struct e));
	bzero(arreglo[0], sizeof(struct e));
	arreglo[0]->c1 = 2;
	arreglo[0]->c2 = 3;
	arreglo[2] = (struct e*) malloc(sizeof(struct e));
	bzero(arreglo[2], sizeof(struct e));
	arreglo[2]->c1 = 7;
	arreglo[2]->c2 = -1;
	for (i=0; i<N; i++) {
		if (arreglo[i]!=NULL) {
			printf("[%d] c1 = %d y c2 = %d\n",
			       i, arreglo[i]->c1, arreglo[i]->c2
			);
		}
	}
	for (i=0; i<N; i++) {
		if (arreglo[i]!=NULL)
			free(arreglo[i]);
	}
	return EXIT_SUCCESS;
}

