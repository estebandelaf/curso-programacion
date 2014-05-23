#include <stdio.h>
#include <stdlib.h>

int main()
{
	int edad = 4;
	if (edad<2) {
		printf("Bebé\n");
	}
	else if(edad<14) {
		printf("Niño\n");
	}
	else if (edad<18) {
		printf("Adolescente\n");
	}
	else {
		printf("Adulto\n");
	}
	return EXIT_SUCCESS;
}
