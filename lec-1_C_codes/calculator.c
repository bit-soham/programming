#include<cs50.h>
#include<stdio.h>

int main(void)
{
    printf("operations :1 = '+', 2 = '-' ,3 = '*' ,4 = '/'\n");
    {
    long x = get_long("x: ");
    long y = get_long("y: ");
    int o;
    do
    {
        o = get_int("operation: ");
    }
    while (o < 1 || o > 4);

    if (o == 1 )
    {
        printf("answer =%li\n" , x + y);
    }
     else if (o == 2 )
     {
        printf("%li\n" , x - y);
     }
     else if (o == 3)
     {
        printf("answer =%li\n" , x * y);
     }
     else if (o == 4)
     {
        double z =  (double)x / (double) y;
         printf("answer = %.20f\n" , z);
     }

    }
}