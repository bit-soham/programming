#include <cs50.h>
#include <stdio.h>

void swap(int *a, int *b);

int main(void)
{
    int x = 4;
    int y = 6;
    printf("(%i,%i)\n", x, y);
    swap(&x, &y);
    printf("(%i,%i)\n", x, y);
}




void swap(int *a, int *b)//address is not being exchanged
//with this int *a = &x, int *b = &y, here * indicates that variable is storing address
//a stores address of x, b stores address of y
{
    printf("(%p,%p)\n", a, b);
    int tmp = *a; //*a just points to x
    *a = *b;//here *b means go to the address in b .i.e the value 'y'
    //similiarly with *a here * means go to
    *b = tmp;
    printf("(%p,%p)\n", a, b);
}