#include <stdio.h>
#include <stdlib.h>

/* Ejemplo entrada estándar (stdin.txt):
3
6
18
56
34
9
67
-1
*/

int main()
{
	int edad,
	bebes = 0,
	ninios = 0,
	jovenes = 0,
	adultos_jovenes = 0,
	adultos = 0,
	adultos_mayores = 0;
	float total;
	/* solicitar edades "infinitamente" */
	while (1) {
		printf("Ingrese edad de la persona: ");
		scanf("%d", &edad);
		printf("%d\n", edad);
		if (edad==-1)
			break; /* rompe el ciclo */
		else if (edad<2)
			bebes++;
		else if (edad<14)
			ninios++;
		else if (edad<18)
			jovenes++;
		else if (edad<40)
			adultos_jovenes++;
		else if (edad<65)
			adultos++;
		else
			adultos_mayores++;
	}
	/* mostrar estadística */
	total = bebes + ninios + jovenes + adultos_jovenes + adultos + adultos_mayores;
	printf("Bebes           %.1f%%\n", (bebes/total)*100);
	printf("Niños           %.1f%%\n", (ninios/total)*100);
	printf("Jóvenes         %.1f%%\n", (jovenes/total)*100);
	printf("Adultos jóvenes %.1f%%\n", (adultos_jovenes/total)*100);
	printf("Adultos         %.1f%%\n", (adultos/total)*100);
	printf("Adultos mayores %.1f%%\n", (adultos_mayores/total)*100);
	return EXIT_SUCCESS;
}
