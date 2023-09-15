#include <stdio.h>

int main(void)
{
    char *s = "GOOD SIGHT!";
    printf("%p\n", s);
    printf("%c\n", *s);
    printf("%s\n", s);
    printf("%c\n", *(s+5));
    printf("%p\n", &s[5]);
    for (int i = 0 ; i < 4 ; i++)
    {
        printf("%c", *(s+i));
    }
    printf("NESS WHAT A");
    for (int i = 4; i < 11 ; i++)
    {
        printf("%c", *(s+i));
    }
    printf("\n");
}