#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string s = "HI!34567890abc";
    char *t1 = &s[0];
    char *t2 = &s[1];
    char **i1 = &s;
    string *i = &s;
    printf("address of H = %p\n", t1);//adress of H
    printf("what s contain = %p\n", s);//printing what s contain
    printf("address of I = %p\n", t2);// address of I
    printf("address of s = %p\n", i1);//address of s
    printf("address of s = %p\n", s);//adress of s
    printf("%s\n", s + 0xa);
}