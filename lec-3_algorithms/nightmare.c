#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>


void search(int array[][size],int size);
int main(int argc, string argv[])
{
    int n = get_int("Search for: ");
    int m = ceil(log2(argc));
    int array[m][size];
    for (int i = 0; i < argc ; i++)
    {
        array[0][i] = atoi(argv[i]);
    }
    int size = argc;
    search(array[0][],size);

}

void search_vla(int array[][argc],int size,int n)
    {

        if (size == 1)
        {
            printf("Found");
            return;
        }
        int mid = floor(size/2);
        if (array[k][mid] == n)
        {
            printf("Found\n");
        }
        else if (array[k][mid] > n)
        {
            search(array[k+1][mid], mid, int n);
        }
        else
        {
            search(array[k+1][size - mid], size - mid, int n);
        }

    }





































        if (k == ceil(log2(size)))
        {
            printf("Not Found\n");
            return;
        }
        int num = floor(size/2);
        if (array[k][num] == n)
        {
            printf("found\n");
        }
        else if (array1[floor(size/2)] > n)
        {
            for (j = 0 ; j < floor(size/2) ; j++)
            {
                array2[j] = array1[j];
            }
            size = floor(size/2);
        }
         else if (array1[floor(size/2)] < n)
        {
            for (j = floor(size/2) ; j < (size - floor(size/2)) ; j++)
            {
                array2[j] = array1[j];
            }
            size = size - floor(size/2);
        }
        search(k+1);



