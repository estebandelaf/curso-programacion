#include <stdio.h>

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
