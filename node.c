#include "node.h"

void node_insertion(Node *node, int index, int num) {
    int count = 1;
    Node *newnode;

    while (node != NULL) {
        if (count == index) {
            newnode = malloc(sizeof(Node));
            newnode->num = num;
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
    int count = 1;
    while (node != NULL) {
        if (count == index) {
            node->back->next = node->next;
            free(node);
            return;
        }
        count++;
        node = node->next;
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
    node = node->end;

    while (node != NULL) {
        node = node->back;

        if (node == NULL) {
            return;
        }

        free(node->next);
    }

    return;
}