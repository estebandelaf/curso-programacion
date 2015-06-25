#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int n = atoi(argv[1]);
	if (n%2) { /* 0 es False y !=0 Verdadero */
		printf("%d es impar\n", n);
	} else {
		printf("%d es par\n", n);
	}
	return EXIT_SUCCESS;
}
