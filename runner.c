#include <stdio.h>
#include "node.h"
#include "basic_functions.h"
#include <string.h>

int main(void) 
{
    /*
        Declaring the node
    */
    Node *node = NULL;
    Node *start;
    Node *end;

    /*
        Getting input of the node
    */
    Node *tmpnode = NULL;
    while (true) {
        char *input = get_string("Enter a number(Type 'stop' to stop inputting numbers): ");

        if (strcmp(input, "Stop") == 0 || strcmp(input, "stop") == 0 || strcmp(input, ":wq") == 0) {
            node->next = NULL;
            end = node;

            while (node != NULL) {
                node->end = end;
                node->start = start;
                node = node->back;
            }

            break;
        }

        else {
            if (node == NULL) {
                node = malloc(sizeof(Node));
                start = node;
                node->back = NULL;
                node->num = atoi(input);
            }
            
            else {
                node->next = calloc(sizeof(Node), 1);
                node->next->back = node;
                node = node->next;
                node->num = atoi(input);
            }
        }
    }
    node = start;

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
            free_node(node);
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
                free_node(node);
                return 0;
            }
            else {
                printf("No the no. is not in the node\n");
                free_node(node);
                return 0;
            }
        case 8:
            print_arr(node_numbers(node), nodetoarr(node));
            free_node(node);
            return 0;

        case 9:
            printf("The no. of nodes are %i\n", node_numbers(node));
        
        default:
            free_node(node);
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