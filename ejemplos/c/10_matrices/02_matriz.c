#include <stdio.h>
#include <stdlib.h>

int **matriz_crear(int n, int m)
{
	int **matriz = (int **) malloc(sizeof(int *)*n), i;
	for (i=0; i<n; i++)
		matriz[i] = (int *)malloc(sizeof(int)*m);
	return matriz;
}

int **matriz_desde_string(char *s, int n, int m)
{
	int **matriz = matriz_crear(n, m), pos=0, i, j;
	for (i=0; i<n; i++) {
		for (j=0; j<m; j++){
			matriz[i][j] = (int)s[pos] - 48;
			pos++;
		}
	}
	return matriz;
}

int **matriz_sumar(int **m1, int **m2, int n, int m)
{
	int **matriz = matriz_crear(n, m), i, j;
	for (i=0; i<n; i++) {
		for (j=0; j<m; j++){
			matriz[i][j] = m1[i][j] + m2[i][j];
		}
	}
	return matriz;
}

void matriz_imprimir(int **matriz, int n, int m)
{
	int i, j;
	for (i=0; i<n; i++) {
		for (j=0; j<m; j++){
			printf ("%3d ", matriz[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	/* ejemplo matriz 2x2 */
	int **matriz1 = matriz_desde_string("1234", 2, 2);
	matriz_imprimir(matriz1, 2, 2);
	printf("\n");
	/* ejemplo matriz 3x3 */
	int **matriz2 = matriz_desde_string("123456789", 3, 3);
	matriz_imprimir(matriz2, 3, 3);
	printf("\n");
	/* ejemplo matriz 2x4 */
	int **matriz3 = matriz_desde_string("12345678", 2, 4);
	matriz_imprimir(matriz3, 2, 4);
	printf("\n");
	/* ejemplo matriz 4x2 */
	int **matriz4 = matriz_desde_string("12345678", 4, 2);
	matriz_imprimir(matriz4, 4, 2);
	printf("\n");
	/* ejemplo de suma de matrices */
	int **matriz5 = matriz_sumar(matriz3, matriz3, 2, 4);
	matriz_imprimir(matriz5, 2,4);
	/* código con memory leaks!! corregir */
	return 0;
}
