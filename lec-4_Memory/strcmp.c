#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    char *s = get_string("s: ");
    char *t = get_string("t: ");
    if (s == t)//will not work as here the value stored in s
          //is actually just the address of its first character
    {
        printf("same\n");
    }
    else
    {
        printf("different\n");
    }

    //strcmp()
    if (strcmp(s, t) == 0)
    {
        printf("SAME\n");
    }
    else
    printf("DIFFERENT\n");



    if (strlen(s) == strlen(t))
    {
        int k = 0;
        for (int i = 0 ; i < strlen(s) ; i++)
        {
            if(*(s + i) == *(t + i))
            k++;
        }
        if (k == strlen(s))
        {
            printf("EQUAL\n");
        }
        else
        {
            printf("DIFF\n");
        }
    }
    else
    printf("IDIOT\n");
}