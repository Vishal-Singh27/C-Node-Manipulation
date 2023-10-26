#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

int get_int(char* txt);
int get_numfromstart(char *txt, int start);
int get_numfromstarttoend(char *txt, int start, int end);
char *get_string(char *txt);
void print_arr(int arrlen, int *arr);

int get_int(char *txt) 
{
    char numstr[20];

    loop:
    printf("%s", txt);
    scanf("%s", numstr);

    for (int i = 0; i < strlen(numstr); i++) {
        if (isdigit(numstr[i]) == 0) {
            printf("\nEnter an integer!!\n\n");
            goto loop;
        }
    }

    return atoi(numstr);
}

int get_numfromstart(char *txt, int start) {
    int num;
    char numstr[20];

    loop:
    printf("%s", txt);
    scanf("%s", numstr);

    if (isdigit(numstr[0]) == 0 && numstr[0] != '-') {
        printf("\nEnter a number greater than %i!!\n\n", start);
        goto loop;
    }

    for (int i = 0; i < strlen(numstr); i++) {
        if (isdigit(numstr[i]) == 0) {
            printf("\nEnter a number greater than %i!!\n\n", start);
            goto loop;
        }
    }

    num = atoi(numstr);
    
    if (num < start) {
        printf("\nEnter a number greater than %i!!\n\n", start);
        goto loop;
    }

    return atoi(numstr);
}

int get_numfromstarttoend(char *txt, int start, int end) {
    int num;
    char numstr[20];

    loop:
    printf("%s", txt);
    scanf("%s", numstr);

    if (isdigit(numstr[0]) == 0 && numstr[0] != '-') {
        printf("\nEnter a number greater than %i and less than %i!!\n\n", start, end);
        goto loop;
    }

    for (int i = 0; i < strlen(numstr); i++) {
        if (isdigit(numstr[i]) == 0) {
            printf("\nEnter a number greater than %i and less than %i!!\n\n", start, end);
            goto loop;
        }
    }

    num = atoi(numstr);
    
    if (num < start || num > end) {
        printf("\nEnter a number greater than %i and less than %i!!\n\n", start, end);
        goto loop;
    }

    return atoi(numstr);
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