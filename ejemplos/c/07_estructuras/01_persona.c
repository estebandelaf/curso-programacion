#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct persona {
	int run;
	char nombre[100];
};

int main()
{
	struct persona p1, p2;
	p1.run = 12345;
	strcpy(p1.nombre, "Persona 1");
	p2.run = 67890;
	strcpy(p2.nombre, "Persona 2");
	printf("%s tiene RUN %d\n", p1.nombre, p1.run);
	printf("%s tiene RUN %d\n", p2.nombre, p2.run);
	return EXIT_SUCCESS;
}
