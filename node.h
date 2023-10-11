typedef struct Node
{
    struct Node *next;
    struct Node *back;
    struct Node *start;
    int num;
} Node;

void node_insertion(Node *node);

void node_deletion(Node *node);

void node_addition(Node *node);

void node_reverse(Node *node);

void node_sort(Node *node);

void node_printout(Node *node);

void node_search(Node *node, int num);

int *nodetoarr(Node *node);