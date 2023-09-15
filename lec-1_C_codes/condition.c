#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int X = get_int("Number of skills you currently have? ");
    printf("currently time travelling 5 years through elon's time slicer have\n patience...\n");
    int Y = get_int("Number of skills you have now?? ");
    if (X < Y)
    {
        printf("you are indeed on the rooad to sucess my friend!\n");
    }
    else if (X > Y)
    {
        printf("you have failed my friend You may rest in peace now BOOM!!!\n");
    }
    else if (X == Y)
    {
        printf("Were you on board my time slicer :o!!\n");
    }
}