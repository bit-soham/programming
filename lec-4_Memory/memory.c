#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int *x = malloc(3 * sizeof(int)); //sizeof(int) means 4 bytes
                                      //*x representing that x is a variable storing address
   if (x == NULL)
   {
    return 1;
   }
   x[0] = 72;
   x[1] = 73;
   x[2] = 74;
   free(x);
}