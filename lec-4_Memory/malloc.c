#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


int main(void)
{
    char *s = get_string("s:");

    char *t = malloc(strlen(s) +1);
    // here wlile going through the loop the computer would reapetedly be finding strlen(s) by checking each block
    //which just consumes time so set a constant variable = strlen(s) + 1
    for (int i = 0, n = strlen(s) + 1; i < n ; i++)
    //if \0 not copyied to t then
    //while printing t it would keep on printing till a \0 comes along
    {
        t[i] = s[i];
    }

    if (strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }

    printf("s: %s\n", s);
    printf("t: %s\n", t);
    printf("s: %p\n", s);
    printf("t: %p\n", t);
}