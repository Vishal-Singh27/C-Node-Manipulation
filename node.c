#include "node.h"

void node_insertion(Node *node);

void node_deletion(Node *node);

void node_addition(Node *node);

void node_reverse(Node *node);

void node_sort(Node *node);

void node_printout(Node *node) {
    while (node != NULL) {
        printf("%i", (int) node->num);
        node = node->next;
    }
}

bool node_search(Node *node, int num)
{
    while (node != NULL) {
        if (num == node->num) {
            return true;
        }

        node = node->next;
    }

    return false;
}

int node_numbers(Node *node)
{
    int count = 0;

    while (node != NULL)
    {
        count++;
        node = node->next;
    }

    return count;
}

int *nodetoarr(Node *node)
{
    int *arr = calloc(sizeof(int), node_numbers(node));
    int i = 0;

    while (node != NULL)
    {
        arr[i] = node->num;
        i++;
    }
}

void free_node(Node *node)
{
    node = node->end;

    while (node != NULL)
    {
        node = node->back;

        if (node == NULL)
        {
            return;
        }

        free(node->next);
    }

    return;
}