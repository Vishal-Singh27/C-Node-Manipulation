#include <stdio.h>
#include <stdlib.h>

int get_int(char *txt) 
{
    int num;
    printf("%s", txt);
    scanf("%i", &num);

    return num;
}

char *get_string(char *txt)
{
    char *str = calloc(sizeof(char *), 200);

    printf("%s", txt);
    scanf("%[^\n]", str);

    return str;
}