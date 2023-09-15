#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGH 1000

int main(void)
{
    char s[MAX_LENGH];
    printf("s: ");
    scanf("%s", s);
    printf("s: %s\n", s);
}












 //   OR
 //   char *s = malloc(sizeof(char)*MAX_LENGH);
   // if(s == NULL)
    //{
     //   printf("Allocation Error");
    //}

   // printf("name: ");
    //int i = 0;
 //   do
   // {
    //    scanf("%c", s + i);
     ///   i++;
    //}
   // while(*(s + i - 1) != '\n');

    //*(s + i - 1) = '\0';
   // printf("%s\n", s);
//
  //  free(s);


//}