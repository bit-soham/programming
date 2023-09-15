#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2 )
    {
        printf("Usage: ./caesar key\n");
        return 0;
    }
    int key = atoi(argv[1]);
    string s = get_string("Text: ");
    int size = strlen(s);
    char c[size];
    printf("cipher text: ");
    for( int i = 0; i < size ; i++)
    {
    if(isupper(s[i]))
    {
        s[i] -= 65;
        c[i] = (s[i] + key)%26;
        c[i] += 65;
        printf("%c", c[i]);
    }
    else if(islower(s[i]))
    {
        s[i] -= 97;
        c[i] = (s[i] + key)%26;
        c[i] += 97;
        printf("%c", c[i]);
    }

    else
    {
    c[i] = s[i];
    printf("%c", c[i]);
    }

     }
     printf("\n");



}