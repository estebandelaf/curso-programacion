#include <stdio.h>

#define ARRAY_SIZE 10

float suma(float v[], int n)
{
	int i;
	float s = 0;
	for (i=0; i<n; i++) {
		s += v[i];
	}
	return s;
}

float promedio(float v[], int n)
{
	return suma(v,n)/n;
}

float maximo(float v[], int n)
{
	float m = -999; /* valor mínimo del conjunto de datos */
	int i;
	for (i=0; i<n; i++) {
		if (v[i]>m) {
			m = v[i];
		}
	}
	return m;
}

float minimo(float v[], int n)
{
	float m = 999; /* valor máximo del conjunto de datos */
	int i;
	for (i=0; i<n; i++) {
		if (v[i]<m) {
			m = v[i];
		}
	}
	return m;
}

int main()
{
	float valores[ARRAY_SIZE];
	/* asignar valores "manualmente" */
	valores[0] = 1.1;
	valores[1] = 3.7;
	valores[2] = 2.1;
	valores[3] = 5.6;
	valores[4] = 6.6;
	valores[5] = 5.1;
	valores[6] = 2.4;
	valores[7] = 8.9;
	valores[8] = 0.5;
	valores[9] = 3.9;
	/* mostrar estadísticas */
	printf("suma = %.1f\n", suma(valores, ARRAY_SIZE));
	printf("promedio = %.1f\n", promedio(valores, ARRAY_SIZE));
	printf("maximo = %.1f\n", maximo(valores, ARRAY_SIZE));
	printf("minimo = %.1f\n", minimo(valores, ARRAY_SIZE));
	/* todo ok */
	return 0;
}
