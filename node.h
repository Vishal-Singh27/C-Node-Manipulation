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

void node_insertion(Node *node, int index, int num);

void node_deletion(Node *node, int index);

int node_addition(Node *node);

void node_reverse(Node *node);

void node_sort(Node *node);

void node_printout(Node *node);

bool node_search(Node *node, int num);

int *nodetoarr(Node *node);

void free_node(Node *node);

int node_numbers(Node *node);

Node *getandupdate_nodestart(Node *node);

void update_nodeend(Node *node);