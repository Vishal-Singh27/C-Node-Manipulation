#include <stdio.h>
#include "node.h"
#include "basic_functions.h"

int main(void) 
{
    // Declaring the choice variable
    int choice;

    // Getting the user's choice
    do 
    {
        // Printing out the menu
        printf("What do you wish to do: \n");
        printf("1: Node Insertion\n");
        printf("2: Node Element Deletion\n");
        printf("3: Addition of all elements in the node\n");
        printf("4: Reverse the Node\n");
        printf("5: Sort the node\n");
        printf("6: Print the node out\n");
        printf("7: Search something in the node\n");
        printf("8: Convert the node to an array\n");
        printf("9: Exit the program\n");
        choice = get_int("Answer: ");

        if (choice < 1 || choice > 9)
        {
            printf("\nEnter a number b/w 1-9!!\n\n");
        }
    }
    while (choice < 1 || choice > 9);
}