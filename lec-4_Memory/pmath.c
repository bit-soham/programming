#include <stdio.h>


int main(void)
{
    char *s = "GOOD NIGHT";
    printf("%s\n", s);
    printf("%s\n", s + 1);//goes to the next  block after going to a address of 's'
    printf("%s\n", s + 2);//and then prints like it would print a string
    printf("%s\n", s + 9);//keeps printing char till the  \0 block
}