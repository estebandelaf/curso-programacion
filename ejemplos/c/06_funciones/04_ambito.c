#include <stdio.h>
#include <stdlib.h>

int a = 1;
int b = 2;
int c = 3;

void imprimir()
{
	printf("IMPRIMIR: a=%d, b=%d, c=%d\n", a, b, c);
}

void modificar()
{
	a = 1111;
	b = 2222;
	printf ("MODIFICAR: a=%d, b=%d, c=%d\n", a, b, c);
	imprimir();
}

void  asignar(int a, int b)
{
	int c = a + b + 1;
	printf ("ASIGNAR: a=%d, b=%d, c=%d\n", a, b, c);
	imprimir();
	a = 11111;
	b = 22222;
	printf ("ASIGNAR: a=%d, b=%d, c=%d\n", a, b, c);
	imprimir();
}

int main()
{
	int a = 11;
	int b = 22;
	int c = 33;
	printf ("MAIN: a=%d, b=%d, c=%d\n", a, b, c);
	imprimir();
	modificar();
	printf ("MAIN: a=%d, b=%d, c=%d\n", a, b, c);
	imprimir();
	asignar(111,222);
	printf ("MAIN: a=%d, b=%d, c=%d\n", a, b, c);
	imprimir();
	c = 3;
	printf ("MAIN: a=%d, b=%d, c=%d\n", a, b, c);
	imprimir();
	return EXIT_SUCCESS;
}
