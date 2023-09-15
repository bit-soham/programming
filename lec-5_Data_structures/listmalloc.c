#include <stdio.c>
#include <stdlib.h>


int main(void)
{

    int *list = malloc(sizeof(int) * 3);
    if (list == NULL)
    {
        return 1;
    }
    list[0] = 1; // or *list
    list[1] = 2; // or *list + 1
    list[2] = 3;

    //....

    int *tmp = malloc(4 * sizeof(int));
    if (tmp == NULL)
    {
        free(list);
        return 1;
    }

    for (int i = 0; i < 3 ; i++)
    {
        tmp[i] = list[i];
    }
    tmp[3] = list[2];

    free(list);// free the original list of memory

    list = tmp; //now list points to where tmp points

    for (int i = 0 ; i < 3 ; i++)
    {
        printf("%i\n", list[1]);
    }

    free(list);
}