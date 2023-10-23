#include <stdio.h>
#include "node.h"
#include "basic_functions.h"
#include <string.h>

int main(void) 
{
    /*
        Declaring the node
    */
    Node *node = malloc(sizeof(Node));
    Node *start = node;
    Node *end;
    start->back = NULL;

    /*
        Getting input of the node
    */
    while (true) {
        char *input = get_string("Enter a number(Type 'stop' to stop inputting numbers): ");

        if (strcmp(input, "Stop") == 0 || strcmp(input, "stop") == 0) {
            node->next = NULL;
            end = node;

            while (node != NULL) {
                node->end = end;
                node->start = start->next;
                node = node->back;
            }

            break;
        }

        else {
            node->next = malloc(sizeof(Node));
            node->next->back = node;
            node = node->next;
            node->num = atoi(input);
        }
    }
    node = start->next;
    free(start);
    start = node;

    /*
        Menu Stuff
    */
    int choice; // Declaring the variable to store user's choice

    // Getting the user's choice
    do 
    {
        // Printing out the menu
        printf("\nWhat do you wish to do: \n");
        printf("1: Node Insertion\n");
        printf("2: Node Element Deletion\n");
        printf("3: Addition of all elements in the node\n");
        printf("4: Reverse the Node\n");
        printf("5: Sort the node\n");
        printf("6: Print the node out\n");
        printf("7: Search something in the node\n");
        printf("8: Convert the node to an array\n");
        printf("9: Print the no. of connected nodes\n");
        printf("10: Exit the program\n");
        choice = get_int("Answer: ");

        if (choice < 1 || choice > 9)
        {
            printf("\nEnter a number b/w 1-9!!\n\n");
        }
    }
    while (choice < 1 || choice > 9);

    /*
        Performing the action that user wants to perform
    */
    switch (choice) {
        case 1:
            node_insertion(node, get_int("Enter the index: "), get_int("Enter the number to insert: "));
            break;
        case 2:
            node_deletion(node, get_int("Enter the index: "));
            break;
        case 3:
            printf("Addition of all no. in node: %i\n", node_addition(node));
            return 0;
        case 4:
            node_reverse(node);
            break;
        case 5:
            node_sort(node);
            break;
        case 6:
            break;
        case 7:
            if (node_search(node, get_int("Enter the no. to search: ")) == true) {
                printf("Yes the no. is in the node!\n");
                return 0;
            }
            else {
                printf("No the no. is not in the node\n");
                return 0;
            }
        case 8:
            print_arr(node_numbers(node), nodetoarr(node));
            return 0;

        case 9:
            printf("The no. of nodes are %i\n", node_numbers(node));
        
        default:
            exit(0);
    }

    /*
        Printing out the resultant node
    */
    printf("\nResultant Node: \n");
    node_printout(node);

    /*
        Freeing the node
    */
    free_node(node);

    /*
        Returning the main function
    */
    return 0;
}