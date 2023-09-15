#include <stdio.h>
#include <cs50.h>
#include <stdint.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Improper Usage.\n");
        return 1;
    }
`
    //open file
    string filename = argv[1];
    FILE *pdf = fopen(filename, "r");
    if (pdf == NULL)
    {
        printf("NO such file found.\n");
        return 1;
    }

    uint8_t buffer[4];
    // u-unsigned int of 8 bits   _t means that it(u-unsigned int of 8 bits) itself is a data type
    //unisigned = +ve int, signed = +ve,-ve int.
    fread(buffer, 1, 4, pdf);
    // buffer itself is an array so no '&' needed
    uint8_t signature[4] = {37, 80, 68, 70};

    for (int i = 0 ; i < 4 ; i++)
    {
        if (bufffer[i] != signature[i])
        {
            printf("Not a PDF\n");
            fclose(pdf);
            return 0 ;
        }
        printf("%i ", buffer[i]);
    }
    printf("likely a PDF");
    printf("\n");
    fclose(pdf);
}