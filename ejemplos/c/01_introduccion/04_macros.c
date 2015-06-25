#include <stdio.h>
#include <stdlib.h>

#define PI 3.14
#define cuadrado(x) x*x
#define suma(x,y) x+y
#define suma2(x,y) (x+y)

int main()
{
	printf("PI = %.2f\n", PI);
	printf("cuadrado(2) = %d\n", cuadrado(2));
	/* las macros son reemplazadas por preprocesador antes de compilar
	 *    printf("PI = %.2f\n", 3.14);
	 *    printf("cuadrado(2) = %d", 2*2);
	 */
	printf("suma(1,2) = %d\n", suma(1,2));
	printf("2*suma(1,2) = %d\n", 2*suma(1,2)); /* 2*1+2 */
	printf("2*suma2(1,2) = %d\n", 2*suma2(1,2)); /* 2*(1+2) */
	return EXIT_SUCCESS;
}
