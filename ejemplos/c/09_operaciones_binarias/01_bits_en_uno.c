#include <stdio.h>
#include <stdlib.h>

int bits_en_uno(int x)
{
	int count;
	for (count=0; x!=0; x>>=1)
		if (x & 1)
			count++;
	return count;
}

int main(int argc, char *argv[])
{
	int n;
	if (argc!=2) {
		printf("[error] modo de uso %s NÚMERO\n", argv[0]);
		return EXIT_FAILURE;
	}
	n = atoi(argv[1]);
	printf("Bits en 1 en número %d: %d\n", n, bits_en_uno(n));
	return EXIT_SUCCESS;
}
