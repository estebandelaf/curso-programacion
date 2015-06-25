#include <stdio.h>
#include <stdlib.h>
size_t strlen(char *s)
{
	size_t c = 0;
	while (s[c]!='\0')
		c++;
	return c;
}
char *strcpy(char *destino, char *origen)
{
	size_t i, largo = strlen(origen);
	for (i=0; i<largo; i++) {
		destino[i] = origen[i];
		/* *(destino+i) = *(origen+i); */
	}
	/*
	i=0;
	while (origen[i]!='\0') {
		destino[i] = origen[i];
		i++;
	}
	*/
	return destino;
}
int main()
{
    char *string1 = "hola mundo";
    char *string2;
    string2 = (char *) malloc(sizeof(char)*(strlen(string1)+1));
    strcpy(string2, string1);
    printf("%s\n", string2);
    return 0;
}
