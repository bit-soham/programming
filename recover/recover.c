#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // check
    if (argc != 2)
    {
        printf("Incorrect Usage\n");
        return 1;
    }
    int i = 0;

    FILE *backup = fopen(argv[1], "r");
    if (backup == NULL)
    {
        printf("%s not found\n", argv[1]);
        return 2;
    }
    {

        uint8_t buffer[512];
        FILE *newfile;

        // read for backup to buffer
        while (fread(buffer, 1, 512, backup)) // read 1 byte and 512 of them at once
        {
            if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
            {
                // first close previos file
                if (i > 0)
                {
                    fclose(newfile); // takes input of FILE * format
                }
                // create new file
                char *filename = malloc(sizeof(char) * 8);
                if (filename == NULL)
                {
                    fclose(backup);
                    return 1;
                }
                sprintf(filename, "%03i.jpg", i);
                FILE *new_file = fopen(filename, "w");
                newfile = new_file;
                i++;
                free(filename);
            }
            // write
            if (i > 0)
            {
                fwrite(buffer, 1, 512, newfile); // written from buffer to newfile
            }
        }
        if (i == 0)
        {
            printf("no jpg file in %s\n", argv[1]);
            fclose(backup);
            return 0;
        }
        // close the last file
        fclose(newfile);
        fclose(backup);
    }
}