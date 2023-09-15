 #include <stdio.h>
 #include<cs50.h>

 int main(void)
 {
     string s = "HHII!";
     printf("%s\n", s);
     printf("%c%c%c%c%c\n" , s[0], s[1], s[2], s[3], s[4]  );
     printf("%c%c%c%c%c\n" , s[3], s[4], s[0], s[2] ,s[2] );
     printf("%i %i %i %i %i %i \n " , s[0], s[1], s[2], s[3], s[4], s[5]);

 }