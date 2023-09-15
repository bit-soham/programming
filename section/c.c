#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
// same as in file b just using return function
int main(void)
{

    string s = get_string("tell: ");
    for (int i = 0 ; i < strlen(s)-1 ; i++)
    {
        if( s[i+1] < s[i])
        {
            printf("NO\n");
            return 0;
        }
        else
        {
            printf("YES\n");
            return 0;
        }
    }
}