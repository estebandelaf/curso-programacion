#include <stdio.h>
void main()

{
    int ival, remainder;
    printf("Entero : ");
    scanf("%d", &ival);

    remainder = ival % 2;

    if (remainder == 0)

        printf("%d es un par y el modulo calculado fue %d \n", ival, remainder);

    else

        printf("%d es impar\n", ival);

}
