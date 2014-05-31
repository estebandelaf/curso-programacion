#include <stdio.h>

/* prototipo o firma de la función saludar */
void saludar(char*);

int main ()
{
	saludar("Pepe");
	return 0;
}

void saludar(char *nombre)
{
	printf("Hola %s!\n", nombre);
}
