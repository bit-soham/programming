#include <stdio.h>


int main(void)
{  //each works for an array of integer 
    char *s = "HI!";
    printf("%p\n", &s);//prints the address of the variable s
    printf("%p\n", s);//prints the address of the first character of string s
    printf("%p\n", &s[0]);// same as above one
    printf("%s\n", s);//here %s tells printf to go to the first character of
                      //the address stored in variable s and then move through each element of s forward until  it reaches \0
    printf("%c\n", *s);// goes to address stored in s anfd prints the char in that addresss
    printf("%c\n", *(s+1));//goes to the address of s and adds 1 and prints the char in it
    printf("%c\n", *(s) + 1);///same function as above
}