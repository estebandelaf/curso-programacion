#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LINEA_LEN 4096

int file_char_count(const char *archivo, char c)
{
	FILE *fd; /* file descriptor */
	char linea[LINEA_LEN];
	size_t largo, i;
	int contador = 0;
	fd = fopen(archivo, "r");
	while (fgets(linea, LINEA_LEN, fd)!=NULL) {
		largo = strlen(linea);
		for (i=0; i<largo; i++) {
			if (linea[i] == c) {
				contador++;
			}
		}
	}
	fclose(fd);
	return contador;
}

int main()
{
	printf("count(a) = %d\n", file_char_count("input.txt", 'a'));
	printf("count(e) = %d\n", file_char_count("input.txt", 'e'));
	printf("count(i) = %d\n", file_char_count("input.txt", 'i'));
	printf("count(o) = %d\n", file_char_count("input.txt", 'o'));
	printf("count(u) = %d\n", file_char_count("input.txt", 'u'));
	return EXIT_SUCCESS;
}
