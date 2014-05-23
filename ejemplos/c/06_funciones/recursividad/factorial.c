#include <stdio.h>

/**
 * Factorial secuencial
 */
int f (int n)
{
    int i, f=1;
    for (i=2; i<=n; i++) {
        f = f * i;
    }
    return f;
}

/**
 * Factorial recursivo
 */
int fr (int n) {
    if (n<=1)
        return 1;
    return n * fr (n-1);
}

int main ()
{
    int i;
    for (i=0; i<5; i++) {
        printf("f(%d) = %d\n", i, f(i));
        printf("fr(%d) = %d\n", i, fr(i));
    }
    return 0;
}
