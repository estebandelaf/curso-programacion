#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int i, hasta;
	if (argc!=2) {
		printf("[error] modo de uso: %s NÚMERO", argv[0]);
		return EXIT_FAILURE;
	}
	hasta = atoi(argv[1]);
	for(i=2; i<=hasta; ++i)
		if (i%2==0)
			printf("%d\n", i);
		return EXIT_SUCCESS;
}
