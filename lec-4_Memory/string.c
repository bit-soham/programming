#include <stdio.h>

int main(void)
{
    int n = 50;
    int *p = &n;// here *p means p stores an address
    printf("%p\n", p);//here printing the address of n

    printf("%i\n", *p);//here *p means go to the adress stored in p
                       ///// or dereference pointer 'p'
                       //therefore going to the address in p we get n
}
