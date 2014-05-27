#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct persona {
	int run;
	char nombre[100];
	int edad;
};

int main()
{
	struct persona p1, p2;
	p1.run = 12345;
	strcpy(p1.nombre, "Persona 1");
	p1.edad = 29;
	p2.run = 67890;
	strcpy(p2.nombre, "Persona 2");
	p2.edad = 15;
	printf("%s tiene RUN %d y %d años\n", p1.nombre, p1.run, p1.edad);
	printf("%s tiene RUN %d y %d años\n", p2.nombre, p2.run, p2.edad);
	return EXIT_SUCCESS;
}
