#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

//check if characters
// in ascending or descending order

int main(void)
{
    int k = 0;
    int j = 0;
    string s = get_string("tell: ");
    for (int i = 0 ; i < strlen(s) ; i++)
    {
        if( s[i+1] > s[i])
        {
            k++;
        }
        else
        j++;

    }
    if (k == strlen(s)-1)
     {
        printf("YES\n");
     }
      else
      {
        printf("NO\n");
      }
}