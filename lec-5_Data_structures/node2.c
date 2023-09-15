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

    for (int i = argc - 1 ; i > 0 ; i--)//easy
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return 1;
        }
        n -> number = atoi(argv[i]);

        n -> next = NULL;

        n -> next = list;
        list = n;

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
    printf("\n");
}