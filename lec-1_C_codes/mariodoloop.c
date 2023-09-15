#include <stdio.h>
#include <cs50.h>
#include <unistd.h>

int get_size(void);
void print_grid(int n);

int main(void)
{
    //Get size of brick
    int n = get_size();

   // Print grid of bricks
   print_grid(n);

}










































int get_size(void)
{
    int n;
    do
    {
        n = get_int("Size: ");
    }
    while(n < 1);
    return n;
}


void print_grid(n)
{
    for(int i = 0 ; i  < n ; i++)
    {
         for(int j = 0 ; j < n ; j++)
    {
        printf("#");
    }
    printf("\n");
    }
}