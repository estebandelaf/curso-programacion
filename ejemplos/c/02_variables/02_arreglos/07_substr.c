#include <stdio.h>
#include <stdlib.h>

char *substr(char *string, int desde, int largo)
{
	int i, j;
	char *s = (char *) malloc(sizeof(char)*(largo+1)); /* char s[largo+1] */
	for (i=0, j=desde; i<largo; i++, j++) {
		s[i] = string[j];
	}
	/*i=0;
	j=desde;
	while(i<largo) {
		s[i] = string[j];
		i++;
		j++;
	}*/
	s[largo] = '\0';
	return s;
}

int main(int argc, char *argv[])
{
	int desde, largo;
	if (argc!=4) {
		fprintf(stderr, "[error] modo de uso: %s STRING DESDE LARGO\n", 
							argv[0]);
		return EXIT_FAILURE;
	}
	desde = atoi(argv[2]);
	largo = atoi(argv[3]);
	/* hacer "cosas" con el string */
	/* substr("hola mundo", 2, 5) => "la mu" */
	printf("substr(%s, %d, %d) = \"%s\"\n",
	       argv[1], desde, largo, substr(argv[1], desde, largo));
	/* todo ok */
	return EXIT_SUCCESS;
}
