#include <stdio.h>

int get_int(char* txt) {
    int num;
    printf("%s", txt);
    scanf("%i", &num);

    return num;
}