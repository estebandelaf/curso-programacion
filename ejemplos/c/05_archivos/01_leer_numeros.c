#include <stdio.h>
#include <stdlib.h>

/* Ejemplo input.txt:
1
2
3
5
6
3
2
8
1
*/

int main()
{
	FILE *input;
	int valor;
	input = fopen("input.txt", "r");
	while (fscanf(input, "%d", &valor)==1) {
		printf("%d\n", valor);
	}
	fclose(input);
	return EXIT_SUCCESS;
}
