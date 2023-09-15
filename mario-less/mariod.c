#include <cs50.h>
#include <stdio.h>

int get_hieght(void);
void print_hill(int n);

int main(void)
{
    string l = get_string("Can i have your name? ");
    {
        printf("Hello %s welcome to the mario world \n ", l);
    }
    int hieght = get_hieght();
    print_hill(hieght);
}

int get_hieght(void)
{
    int n ;
    do
    {
        n = get_int("Hieght of hill (between[1,8]) :- ");
    }
    while (n < 1 || n > 8);
    return n;
}

void print_hill(int n)
{
    for (int i = 0 ; i < n ; i++)
    {
        for (int j = 1 ; j < n - i  ; j++)
        {
            printf(" ");
        }
        for (int b = 0 ; b < i + 1 ; b++)
        {
            printf("#");
        }
        printf("\n");
    }
    {
        printf(" Well there you go!!\n Thank you!\n Have a Good Day.\n ");
    }

}











































