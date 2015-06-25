#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char palabra[] = "Mi palabra";
	printf("Palabra: %s\n", palabra);
	/* palabra = "otra palabra"; */ /* error! */
	return EXIT_SUCCESS;
}
