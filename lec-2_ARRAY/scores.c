#include <stdio.h>
#include <cs50.h>

const int m = 7;


double average(int lengh, int array[]);

int main(void)
{
    int score[m];
    for ( int i = 0 ; i < m; i++)
    {
        score[i] = get_int("Score: ");
    }

    printf("average:- %f\n" , average(m, score));
    //here 'm' and  'score' are the inputs to the function average
    //where m becomes assigned to lengh and score is assigned to the array[] in there

}

double average(int lengh , int array[])// here
{
    int sum =0 ;
    for ( int i = 0 ; i < lengh ; i++)
    {
        sum += array[i];
    }
    return sum/ (double) lengh ;

}
