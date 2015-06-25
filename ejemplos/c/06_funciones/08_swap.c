#include <stdio.h>
void swap(int *v1, int *v2)
{
    int aux = *v1;
    *v1 = *v2;
    *v2 = aux;
}
int main()
{
    int a=1, b=2;
    swap(&a, &b);
    printf("a=%d y b=%d\n", a, b);
    return 0;
}
