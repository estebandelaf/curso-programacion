#include <stdio.h>

int main()
{
	int i;
	char n1;
	unsigned char n2;
	for (i=0; i<=300; i++) {
	    n1 = n2 = i;
	    printf("n1 = %d, n2 = %d\n", n1, n2);
	}
	return 0;
}
