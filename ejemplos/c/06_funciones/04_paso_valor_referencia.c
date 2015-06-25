#include <stdio.h>
/* ejemplo de paso por valor */
void suma_resta(int a, int b, int s, int r)
{
    s = a + b;
    r = a - b;
    printf("suma=%d y resta=%d\n", s, r);
}
/* ejemplo de paso por referencia */
void suma_resta2(int a, int b, int *s, int *r)
{
    *s = a + b;
    *r = a - b;
    printf("suma=%d y resta=%d\n", *s, *r);
}
int main()
{
    int v1=2, v2=3, v3=0, v4=0;
    printf("Paso por valor:\n");
    suma_resta(v1, v2, v3, v4);
    printf("v3=%d y v4=%d\n", v3, v4);
    printf("\nPaso por referencia:\n");
    suma_resta2(v1, v2, &v3, &v4);
    printf("v3=%d y v4=%d\n", v3, v4);
    return 0;
}
