#include<stdio.h>
#define N 11
int largo(char string[])
{
	int largo = 0;
	while (string[largo]!='\0')
		largo++;
	return largo;
}
int largo2(char *strings[])
{
	int largo = 0;
	while (strings[largo]!=NULL)
		largo++;
	return largo;
}
int main()
{
	char string[N];
	char *strings[] = {"pedro", "juan", "diego", NULL};
	string[0] = 'h';
	string[1] = 'o';
	string[2] = 'l';
	string[3] = 'a';
	string[4] = ' ';
	string[5] = 'm';
	string[6] = 'u';
	string[7] = 'n';
	string[8] = 'd';
	string[9] = 'o';
	string[10] = '\0';
	printf("largo(string) = %d\n", largo(string));
	string[0] = 'h';
	string[1] = 'o';
	string[2] = 'l';
	string[3] = 'a';
	string[4] = '\0';
	printf("largo(string) = %d\n", largo(string));
	printf("largo(strings) = %d\n", largo2(strings));
	return 0;
}

