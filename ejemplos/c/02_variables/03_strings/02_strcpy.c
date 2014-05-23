#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char palabra[100] = "Mi palabra";
	printf("Palabra: %s\n", palabra);
	/*palabra = "Otra palabra";*/
	strcpy(palabra, "Otra palabra");
	printf("Palabra: %s\n", palabra);
	return EXIT_SUCCESS;
}
