/* Ejemplo de como usar bzero para inicializar solo una
parte de la memoria y dejar datos en el resto sin tocar */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#define N 100
void imprimir(char *s, int size)
{
    int i;
    for (i=0; i<size; i++) {
        printf("%c", s[i]);
    }
    printf("\n");
}
int main()
{
    char *palabra = calloc(N, sizeof(char));
    strcpy(palabra, "hola mundo");
    imprimir(palabra, N);
    bzero(palabra, sizeof(char)*3);
    printf("s = %s\n", palabra);
    imprimir(palabra, N);
    free(palabra);
    return 0;
}
