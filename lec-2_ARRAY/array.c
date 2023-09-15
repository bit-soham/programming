 #include <stdio.h>
 #include<cs50.h>

 int main(void)
{
 string words[2];// an array of strings which branches into an array of characters

  words[0] = "Fight";
  words[1] = "Back";

  printf("%s\n", words[0]);
  printf("%s\n", words[1]);
  printf("%c%c%c %c%c\n" , words[0][0], words[0][1], words[0][2], words[0][3], words[0][4]);
  printf("%c%c %c%c\n" , words[1][0], words[1][1], words[1][2], words[1][3]);
   //words[0][0] go to word array's first string in that go to the first char of the string
   printf("%i %i %i %i %i\n" , words[1][0], words[1][1], words[1][2], words[1][3], words[1][4]);
}


