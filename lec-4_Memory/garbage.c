#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    //int scores[1024];
    //for (int i = 0 ; i < 1024 ; i++)
    //{
     //   printf("%i\n", scores[i]);
    //}

    int *x;// indicates a variable that will store an address
    int *y;

    x = malloc(sizeof(int));

    *x = 42;//go to that address and store an integer 42 there
    *y = 13;//y is not initialized to any address and contians just a garbage no.
            // so codewill not work
    y = x;// y is now initialized the same address as x

    *y = 13;

    printf("%i\n", *y);
    printf("%i\n", *x);
}
