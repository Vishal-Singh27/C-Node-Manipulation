#include "node.h"

void node_insertion(Node *node, int index, int num) {
    int total_nodes = node_numbers(getandupdate_nodestart(node));
    if (index > total_nodes + 1) {
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
    if (node_numbers(getandupdate_nodestart(node)) < index) {
        printf("\nDeletion not possible!\n");
        return;
    }
    int count = 1;
    node = node->start;
    while (node != NULL) {
        if (count == index) {
            Node *remnode = node;
            if (node->back != NULL) {
                remnode->back->next = node->next;
                node = node->next;
            }
            else {
                remnode->next->back = NULL;
                node = node->next;
            }
            free(remnode);
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
    Node *tmpnode;

    while (node != NULL) {
        tmpnode = node->back;
        free(node);
        node = tmpnode;
    }
    return;

}

Node *getandupdate_nodestart(Node *node) {
    if (node == NULL) {
        return node;
    }

    else if (node->back == NULL) {
        return node;
    }

    Node *start;
    while (node->back != NULL) {
        node = node->back;

        if (node->back == NULL) {
            start = node;
        }
    }

    // Now updating start in every nodes
    node = start;
    while (node != NULL) {
        node->start = start;
        node = node->next;
    }
    return start;
}

void update_nodeend(Node *node) {
    if (node == NULL) {
        return;
    }
    node = node->start;
    Node *end;
    while (node->next != NULL) {
        node = node->next;

        if (node->next == NULL) {
            end = node;
        }
    }

    // Now updating start in every nodes
    node = end;
    while (node != NULL) {
        node->end = end;
        node = node->back;
    }
}