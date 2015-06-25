#include <stdio.h>
#include <stdlib.h>

/* Ejemplo input.txt:
 * 1
 * 2
 * 3
 * 5
 * 6
 * 3
 * 2
 * 8
 * 1
 */

int main()
{
	FILE *input;
	int valor, suma = 0;
	input = fopen("input.txt", "r");
	while (fscanf(input, "%d", &valor)==1) {
		if (valor!=2) {
			suma = suma + valor; /* suma += valor; */
		}
	}
	fclose(input);
	printf("suma = %d\n", suma);
	return EXIT_SUCCESS;
}
