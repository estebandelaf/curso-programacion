#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char *string1 = "hola mundo";
    char *string2;
    string2 = (char *) malloc(sizeof(char)*(strlen(string1)+1));
    strcpy(string2, string1);
    printf("%s\n", string2);
    /* string2 = "chao mundo"; */ /* NO FUNCIONA! */
    strcpy(string2, "chao mundo");
    printf("%s\n", string2);
    return 0;
}
