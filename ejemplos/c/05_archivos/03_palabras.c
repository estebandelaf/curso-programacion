#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Ejemplo archivo input.txt:
Conozco alguien que nadie vió
ni el mundo submarino de Jacques Cousteau
Conozco alguien que nadie probó
ni el veterano que en la guerra voló
No es acerca de un pelafustán
que tomo sus guarifaifas
es sobre mi alma Funk
que nace gracias a esta huea
*/

int main()
{
	int palabras = 0;
	char buffer[1024], *ptr, *sep = " ";
	FILE *input = fopen("input.txt", "r");
	while (fgets(buffer, sizeof(buffer), input) != NULL) {
		ptr = strtok(buffer, sep);
		if (ptr!=NULL)
			palabras++;
		while ((ptr=strtok(NULL, sep))!=NULL)
			palabras++;
	}
	fclose(input);
	printf ("Palabras encontradas: %d\n", palabras);
	return EXIT_SUCCESS;
}
