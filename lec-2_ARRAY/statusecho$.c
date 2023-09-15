#include <stdio.h>
#include <cs50.h>


int main(int argc , string argv[] )
{
    if (argc!=2)
    {
        printf("Missing command-line argument\n");
        return 1;
    }
    else
    {
        printf("hello, %s\n", argv[1]);
        return 0;
    }
}
// echo $?
//ARRAY/ $ make status
//ARRAY/ $ ./status
//Missing command-line argument
//ARRAY/ $ echo $?
//1
//ARRAY/ $ ./status soham
//hello, soham
//ARRAY/ $ echo $?
//0
//ARRAY/ $ echo $?
//0
//ARRAY/ $