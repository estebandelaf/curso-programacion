#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct persona {
	int run;
	char *nombre;
	int edad;
};

struct persona *persona_crear(int run, char *nombre, int edad)
{
	struct persona *p = (struct persona *) malloc (sizeof(struct persona));
	p->nombre = (char *) malloc (100);
	p->run = run;
	strcpy(p->nombre, nombre);
	p->edad = edad;
	return p;
}

void persona_mostrar(struct persona *p)
{
	printf("%s tiene RUN %d y %d años\n", p->nombre, p->run, p->edad);
}

void persona_borrar(struct persona *p)
{
	free(p->nombre);
	free(p);
}

int main()
{
	struct persona *p1, *p2;
	p1 = persona_crear (12345, "Persona 1", 29);
	p2 = persona_crear (67890, "Persona 2", 15);
	persona_mostrar(p1);
	persona_mostrar(p2);
	persona_borrar(p1);
	persona_borrar(p2);
	return EXIT_SUCCESS;
}
