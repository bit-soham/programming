#include <stdio.h>

int main(void)
{
    char buffer[13];

    int i = 50;
    sprintf(buffer, "This is CS%i", i);
    printf("%s\n", buffer);

    float f = 50.0;
    sprintf(buffer, "This is CS%.0f", f);
    printf("%s\n", buffer);
}