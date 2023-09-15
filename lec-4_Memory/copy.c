#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>


int main(void)
{
    char *s = get_string("s:");

    char *t = s; //here the address of s is copyied to s
                // therfore now s and t have the same memory address
                //therfore any change to s also chaneges t and vice versa
    if (strlen(s) > 0)
    {
        t[0] = toupper(t[0]);
    }

    printf("s: %s\n", s);
    printf("t: %s\n", t);
    printf("s: %p\n", s);
    printf("t: %p\n", t);
}