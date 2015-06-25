#include <stdio.h>
#include <stdlib.h>

/* Ejemplo input.txt:
1 a
2 hola
3 c
a b
*/

int main()
{
	FILE *input;
	char string[100];
	input = fopen("input.txt", "r");
	while (fscanf(input, "%s", string)==1) {
		printf("%s\n", string);
	}
	fclose(input);
	return EXIT_SUCCESS;
}
 
