#include <stdio.h>
#include <cs50.h>

int main(void)
{
    char *s = "HI!";
    printf("%s\n" , s);//s is just a string
    printf("%p\n" , s);//s is just an address
    printf("%p\n" , &s[0]);
    printf("%p\n" , &s[1]);
    printf("%p\n" , &s[2]);

}