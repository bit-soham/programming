#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef struct node
{
    int number;
    struct node *next; //pointer to a node
}
node;

//stack format or pre prepend
int main(int argc, char *argv[])
{
    node *list = NULL;

    for (int i = 1 ; i < argc ; i++)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return 1;
        }
        n -> number = atoi(argv[i]);
        n -> next = NULL;

        n -> next = list;// n -> next points to where list was pointing which was NULL in first time then pointed to the next input
        list = n;//now list points to where all n was pointing

    }


    node *ptr = list;
    while (ptr != NULL)
    {
        printf(" %i ", ptr -> number);
        node *next = ptr -> next;
        free(ptr);
        ptr = next;
    }
    free(ptr);// after freeing ptr we cannot use it any more
}