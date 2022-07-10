/**
 *
 * Ejemplo estructuras: administración de personas y armas que poseen
 *
 * Compilar con:
 *   $ gcc -Wall -ansi -pedantic 06_armas.c -o 06_armas
 *
 * Ejecutar con:
 *   $ ./06_armas
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARMAS 8

struct fecha {
	int dia, mes, anio;
};

struct arma {
	int codigo;
	char marca[10];
	char modelo[10];
};

struct persona {
	int run;
	char nombre[100];
	/*struct fecha *fecha_nacimiento;*/
	struct fecha fecha_nacimiento;
	struct arma armas[MAX_ARMAS];
};

struct persona *persona_crear(int run, char *nombre, int dia, int mes, int anio)
{
	int i;
	struct persona *p;
	p = (struct persona *) malloc(sizeof(struct persona));
	p->run = run;
	strcpy(p->nombre, nombre);
	/*p->fecha_nacimiento = (struct fecha *) malloc(sizeof(struct fecha));
	p->fecha_nacimiento->dia = dia;
	p->fecha_nacimiento->mes = mes;
	p->fecha_nacimiento->anio = anio;*/
	p->fecha_nacimiento.dia = dia;
	p->fecha_nacimiento.mes = mes;
	p->fecha_nacimiento.anio = anio;
	for (i=0; i<MAX_ARMAS; i++) {
		p->armas[i].codigo = 0;
	}
	return p;
}

int persona_agregar_arma(struct persona *p, int codigo, char *marca, char *modelo)
{
	int i;
	for (i=0; i<MAX_ARMAS; i++) {
		if (p->armas[i].codigo==0) {
			break;
		}
	}
	if (i==8) {
		return 1;
	}
	p->armas[i].codigo = codigo;
	strcpy(p->armas[i].marca, marca);
	strcpy(p->armas[i].modelo, modelo);
	return 0;
}

int persona_eliminar_arma(struct persona *p, int codigo)
{
	int i;
	for (i=0; i<MAX_ARMAS; i++) {
		if (p->armas[i].codigo==codigo) {
			break;
		}
	}
	if (i==8) {
		return 1;
	}
	p->armas[i].codigo = 0;
	return 0;
}

void persona_mostrar(struct persona *p)
{
	int i;
	printf("%s tiene las siguientes armas:\n", p->nombre);
	for (i=0; i<MAX_ARMAS; i++) {
		if (p->armas[i].codigo!=0) {
			printf("- %s %s\n", p->armas[i].marca, p->armas[i].modelo);
		}
	}
}

/**
 * Función principal del programa: corresponde al caso de prueba
 */
int main()
{
	struct persona *p;
	p = persona_crear(123, "Juan", 17, 3, 1991);
	persona_agregar_arma(p, 78, "Glock", "17");
	persona_agregar_arma(p, 77, "CZ", "P09");
	persona_mostrar(p);
	persona_eliminar_arma(p, 78);
	persona_mostrar(p);
	free(p);
	return EXIT_SUCCESS;
}
