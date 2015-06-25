#include<stdio.h>
#include <string.h>
#define N 11
int main()
{
	char string[N], string2[N], string3[] = "hola mundo",
		string4[] = {'h', 'o', 'l', 'a'};
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
/*	string[10] = '\0';*/
/*	string2 = "hola mundo";*/ /* NO FUNCIONA!! */
/*	string3 = "chao mundo";*/ /* NO FUNCIONA!! */
	strcpy(string2, "hola mundo");
	printf("string3 = %s\n", string3);
	strcpy(string3, "chao mundo");
	printf("string = %s\n", string);
	printf("string2 = %s\n", string2);
	printf("string3 = %s\n", string3);
	printf("string4 = %s\n", string4);
	strcpy(string4, "chao");	
	printf("string4 = %s\n", string4);
	return 0;
}

