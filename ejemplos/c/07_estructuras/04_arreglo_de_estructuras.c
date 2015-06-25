#include <stdio.h>
#include <stdlib.h>

#define N 5

struct e {
	int c1;
	int c2;
};

struct contenedor {
	struct e arreglo[N];
	int cantidad;
};

int main()
{
	int i;
	struct contenedor c;
	c.cantidad = 0;
	for (i=0; i<2; i++) {
		c.arreglo[i].c1 = i;
		c.arreglo[i].c2 = i+1;
		c.cantidad++;
	}
	for (i=0; i<c.cantidad; i++) {
		printf("[%d] c1 = %d y c1 = %d\n",
		       i, c.arreglo[i].c1, c.arreglo[i].c2
		);
	}
	return EXIT_SUCCESS;
}
