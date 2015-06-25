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
	FILE *input; /* descriptor de archivo / fd */
	int valor;
	input = fopen("input.txt", "r");
	/*if (input==NULL) {
		printf("[error]: no se pudo abrir archivo\n");
		return EXIT_FAILURE;
	}*/
	/* aparte de fscanf existe: vfscanf, fgets, fgetc y read */
	while (fscanf(input, "%d", &valor)==1) {
		printf("%d\n", valor);
	}
	fclose(input);
	return EXIT_SUCCESS;
}
