#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("Before: ");
    printf("After: ");
    for (int i =0; i < strlen(s); i++)
    {
        if(s[i] >= 'a' && s[i] <= 'z') // in ctype.h lib this can be written as|
                  //if(s[i] >= 'a' && s[i] <= 'z') == if(islower(s[i]))
        {                              // means if 's[i] "is lowercase"'
            printf("%c", s[i] -=32); // s[i] -= 32 == toupper(s[i]) in ctype library
                                 //means convert s[i] to upper

        }
        else
        {
            printf("%c", s[i]);
        }

    }
printf("\n");

}