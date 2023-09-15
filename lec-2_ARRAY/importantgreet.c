#include <stdio.h>
#include <cs50.h>

      // this inside the bracket is input or argument
int main(int argc, string argv[])// here argc is automatically counting the size of array
              // which is argv[] which is command line arguments or inputs in comand line
           //Yes, command-line arguments in C can be thought of as inputs to your program. When you run a C program from the command line,
               // you can pass additional values (referred to as "command-line arguments") to the program as strings. These arguments are stored in the argv[] array in the main() function.

   {
    if (argc ==4 )
    printf("hello, %s %s\n", argv[1] , argv[3]);
    else
    printf("hello, world\n");
  }
//./greet Utpal kumar Bit greet is ist block of array
//hello,Utpal Bit