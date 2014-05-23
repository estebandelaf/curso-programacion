#include <stdio.h>
#include <stdlib.h>

int strlen (char *s)
{
	int c = 0;
	while (s[c]!='\0')
		c++;
	return c;
}

int main(void)
{
	char *string = "Hola Mundo!";
	printf ("Largo del string \"%s\" es %d\n", string, strlen(string));
	return EXIT_SUCCESS;
}
