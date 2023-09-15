#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string strings[] = {"battle ship" , "boot" , "cannon" , "iron:" , "thimble", "top hat"};
     string s = get_string("Strings: ");
     for (int i = 0; i < 6 ; i++) // if i < 7 the it would have
                                 //  been segmentation fault as the computer would
                                 // be checking something that is'nt there
     {
        // does not work for strings -> if (strings[i] == s)
        // use this
        if(strcmp(strings[i],s) == 0)
        {
            printf("Found\n");
            return 0;
        }
     }

     {
        printf("Not Found\n");
        return 1;
     }
}