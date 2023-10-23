#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node *next;
    struct Node *back;
    struct Node *start;
    struct Node *end;
    int num;
} Node;

void node_insertion(Node *node);

void node_deletion(Node *node, int num);

int node_addition(Node *node);

void node_reverse(Node *node);

void node_sort(Node *node);

void node_printout(Node *node);

bool node_search(Node *node, int num);

int *nodetoarr(Node *node);

void free_node(Node *node);

int node_numbers(Node *node);