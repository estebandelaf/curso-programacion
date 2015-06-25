#include <stdio.h>

#define DICT_SIZE 10

char *keys[DICT_SIZE];
char *vals[DICT_SIZE];

void dict_add(char *k, char *v)
{
	
}

void dict_del(char *k)
{
	
}

char *dict_get(char *k)
{
	return NULL;
}

int main()
{
	int i;
	for (i=0; i<DICT_SIZE; i++) {
		keys[i] = NULL;
		vals[i] = NULL;
	}
	/* caso de pruebas */
	dict_add("a", "1");
	dict_add("b", "57");
	dict_add("c", "30");
	dict_del("b");
	printf("a = %s\n", dict_get("a")); /* "1" */
	printf("b = %s\n", dict_get("b")); /* NULL*/
	printf("c = %s\n", dict_get("c")); /* "30" */
	/* todo ok */
	return 0;
}
