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
    scanf("%s", str);

    return str;
}

void print_arr(int arrlen, int *arr) {
    printf("[");
    for (int i = 0; i < arrlen; i++) {
        if (i != arrlen - 1 && i != 0) {
            printf(" %i,", arr[i]);
        }
        else if (i == 0) {
            printf("%i,", arr[i]);
        }

        else {
            printf(" %i", arr[i]);
        }
    }
    printf("]\n");
}