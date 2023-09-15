#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
     int k = atoi(argv[1]);

     char *s = malloc(sizeof(char) * k + 1);
     if (s == NULL)
     return 1;
     printf("s: ");
     scanf("%s", s);

     int f = s[0] - s[strlen(s) - 1];
     k = s[0] + s[strlen(s) - 1];
     printf("%i\n%i\n", f, k - 194);
     free(s);
}