#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    string s = get_string("TEXT: ");
    int lcount = 0;
    int scount = 0;
    int wcount = 0;

    // finding no. of letters ,words, sentences.
    for (int i = 0 ; i < strlen(s) ; i++)
    {
        if (isalpha(s[i])) // if(((s[i] > 64 ) && (s[i] < 91)) || ((s[i] > 96 ) && (s[i] < 123)))
        {
            lcount++;
        }
        if (isblank(s[i]) || s[i] == 46 || s[i] == 33 || s[i] == 63)
        {
            wcount++;
        }
        if (s[i] == 46 || s[i] == 33 || s[i] == 63)
        {
            scount++;
        }

        // checking if spaces , fullstops ... side by side do not count 2 words

        if ((isblank(s[i]) || s[i] == 46 || s[i] == 33 || s[i] == 63) && (isblank(s[i + 1]) || s[i + 1] == 46 || s[i + 1] == 33
                || s[i + 1] == 63))
            //    blank space   full stop .     ex mark !      Q mark ?
        {
            wcount--;
        }

    }

    double L = ((double) lcount / wcount) * 100;

    double S = ((double) scount / wcount) * 100;

    double index = 0.0588 * L - 0.296 * S - 15.8;

    // rounding off to integer or zero decimal places
    int grade = (int) round(index);

    //printing grade
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }

    else
    {
        printf("Grade %i\n", grade);
    }

}