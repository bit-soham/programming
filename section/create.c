#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Wrong usage: Try ./create [filename]\n");
        return 1;
    }
    int filename_lengh = strlen(argv[1]);

    char *filename = malloc(sizeof(char) * (filename_lengh + 1));//*A string of characters need space for a null terminater

    sprintf(filename, "%s", argv[1]);

    FILE *new_file = fopen(filename, "w");
    if (new_file == NULL)//*check if file can be opened
    {
        printf("File not found\n");
        return 1;
    }
    free(filename);//*free after any malloc
    fclose(new_file);//*close any opened file

}