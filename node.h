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

// Declaring the functions
Node *add_to_node(Node *node, int num);

void node_printout(Node *node);

int node_numbers(Node *node);

void update_nodestart(Node *node);

void update_nodeend(Node *node);

void free_node(Node *node);

void node_insertion(Node *node, int index, int num);

void node_deletion(Node *node, int index);

int node_addition(Node *node);

void node_reverse(Node *node);

void node_sort(Node *node);

bool node_search(Node *node, int num);

int *nodetoarr(Node *node);

// Defining the functions
Node *add_to_node(Node *node, int num) {
    if (node == NULL) {
        node = malloc(sizeof(Node));
        node->start = node;
    }

    else {
        while (node->next != NULL) {
            node = node->next;
        }
        node->next = malloc(sizeof(Node));
        node->next->back = node;
        node = node->next;
    }

    node->num = num;
    return node;
}

// Now the function's definitions
void node_insertion(Node *node, int index, int num) {
    int total_nodes = node_numbers(node->start);
    if (index > total_nodes + 1 || index < 1) {
        printf("\nInsertion not possible!\n");
        return;
    }

    else if (index == total_nodes + 1) {
        update_nodeend(node);
        Node *newnode = malloc(sizeof(Node));
        newnode->num = num;
        node->end->next = newnode;
        newnode->next = NULL;
        newnode->back = node->end;
        return;
    }

    int count = 1;
    Node *newnode;

    while (node != NULL) {
        if (count == index) {
            newnode = malloc(sizeof(Node));
            newnode->num = num;
            if (node->back != NULL)
                node->back->next = newnode;
            newnode->back = node->back;
            newnode->next = node;
            node->back = newnode;
            return;
        }

        count++;
        node = node->next;
    }
}

void node_deletion(Node *node, int index) {
    if (node_numbers(node->start) < index || 1 > index) {
        printf("\nDeletion not possible!\n");
        return;
    }

    node = node->start;

    int count = 1;

    while (node != NULL) {
        if (count == index) {
            if (node == node->start) {
                Node *tmpnode = node->next;
                tmpnode->back = NULL;
                free(node);
                update_nodestart(tmpnode);
                return;
            }

            else if (node == node->end) {
                Node *tmpnode = node->end->back;
                tmpnode->next = NULL;
                free(node);
                update_nodeend(tmpnode);
                printf("Yay");
                return;
            }

            else {
                node->back->next = node->next;
                node->next->back = node->back;
                free(node);
                return;
            }
        }

        node = node->next;
        count++;
    }
}

int node_addition(Node *node) {
    int sum = 0;

    while (node != NULL) {
        sum += node->num;
        node = node->next;
    }

    return sum;
}

void node_reverse(Node *node) {
    Node *tmpnode = node->end;

    while (node->back != tmpnode && node != tmpnode) {
        int tmp = node->num;
        node->num = tmpnode->num;
        tmpnode->num = tmp;

        node = node->next;
        tmpnode = tmpnode->back;
    }
}

void node_sort(Node *node) {
    Node *nodenavigate = node;
    Node *tmpnode = node;
    Node *tmpnode1 = node->end;

    if (nodenavigate == NULL || tmpnode == NULL || tmpnode1 == NULL) {
        printf("Technical error.....\n");
        return;
    }

    while (nodenavigate != nodenavigate->end) {
        while (tmpnode != tmpnode1 )
        {
            if (tmpnode->num > tmpnode->next->num) {
                int tmp = tmpnode->num;
                tmpnode->num = tmpnode->next->num;
                tmpnode->next->num = tmp;
            }

            tmpnode = tmpnode->next;
        }

        nodenavigate = nodenavigate->next;
        tmpnode1 = tmpnode1->back;
        tmpnode = node;
    }
}

void node_printout(Node *node) {
    while (node != NULL) {
        printf("%i\n", (int) node->num);
        node = node->next;
    }
}

bool node_search(Node *node, int num){
    while (node != NULL) {
        if (num == node->num) {
            return true;
        }

        node = node->next;
    }

    return false;
}

int node_numbers(Node *node){
    int count = 0;

    while (node != NULL) {
        count++;
        node = node->next;
    }

    return count;
}

int *nodetoarr(Node *node) {
    int *arr = calloc(sizeof(int), node_numbers(node));
    int i = 0;
    while (node != NULL) {
        arr[i] = node->num;
        i++;
        node = node->next;
    }

    return arr;
}

void free_node(Node *node) {
    if (node == NULL) {
        printf("\nCannot free a NULL node\n\n");
        return;
    }

    node = node->end;
    Node *tmpnode;

    while (node != NULL) {
        tmpnode = node->back;
        free(node);
        node = tmpnode;
    }
    return;

}

Node *getnodestart(Node *node) {
    if (node == NULL) {
        printf("\nNode is already NULL when getting the starting point in node!\n\n");
        exit(1);
    }

    while (node->back != NULL) {
        node = node->back;
    }

    return node;
}

void update_nodestart(Node *node) {
    if (node == NULL) {
        printf("\nNode is already NULL when updating start in node!\n\n");
        exit(1);
    }
    Node *start = NULL;

    while (node->back != NULL) {
        node = node->back;

        if (node->back == NULL) {
            start = node;
        }
    }
    start = node;

    // Now updating start in every nodes
    while (node != NULL) {
        node->start = start;
        node = node->next;
    }

    return;
}

void update_nodeend(Node *node) {
    if (node == NULL) {
        printf("\nNode is NULL when updating end in node!\n\n");
        exit(1);
    }

    node = node->start;
    Node *end = node;

    while (node->next != NULL) {
        node = node->next;
    }

    end = node;

    // Now updating start in every nodes
    while (node != NULL) {
        node->end = end;
        node = node->back;
    }
    return;
}