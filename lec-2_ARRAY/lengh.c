#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string name = get_string("What's your name? ");

    int n = 0;
    while (name[n] != '\0')
    {
         printf ("%c\n", name[n]);
        n++;
    }



}