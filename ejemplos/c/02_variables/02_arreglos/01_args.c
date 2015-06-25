#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
	int i, N;
	if (argc>1) {
		N = atoi(argv[1]);
		for (i=1; i<=N; i++)
        		printf("%d\n", i);
		return 0;
	} else {
		return 1;
	}
}

