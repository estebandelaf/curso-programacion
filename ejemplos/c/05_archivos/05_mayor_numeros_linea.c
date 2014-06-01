#include <stdio.h>
#include <stdlib.h>

/* Ejemplo input.txt:
1 2
2 3
3 2
5 5
6 1
3 4
2 6
8 3
1 5
*/

int main()
{
	FILE *input, *output;
	int n1, n2;
	input = fopen("input.txt", "r");
	output = fopen("output.txt", "w");
	while (fscanf(input, "%d %d", &n1, &n2)==2) {
		if (n1 > n2)
			fprintf(output, "%d\n", n1);
		else
			fprintf(output, "%d\n", n2);
	}
	fclose(input);
	fclose(output);
	printf("Número mayor de cada línea guardados en output.txt");
	return EXIT_SUCCESS;
}
