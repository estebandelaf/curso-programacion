#include <stdio.h>
#include <stdlib.h>
#define LINEA_LEN 4096

int main()
{
	FILE *fd; /* file descriptor */
	char linea[LINEA_LEN];
	fd = fopen("input.txt", "r");
	while (fgets(linea, LINEA_LEN, fd)!=NULL) {
		printf("%s", linea);
	}
	fclose(fd);
	return EXIT_SUCCESS;
}
