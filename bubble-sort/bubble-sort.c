// Practice writing a function to find a max value

#include <cs50.h>
#include <stdio.h>

int max(int array[], int n);

int main(void)
{
    int n;
    do
    {
        n = get_int("Number of elements: ");
    }
    while (n < 1);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = get_int("Element %i: ", i);
    }

    printf("The max value is %i.\n", max(arr, n));
}


int max(int array[], int n)
{
    int swap_counter = 0;
    do
    {
        int i = 0;
        swap_counter = 0;
        do
        {

            if (array[i] > array[i+1])
            {

                int k = array[i];
                array[i] = array[i + 1];
                array[i + 1] = k;
                swap_counter++;
                
            }
            i++;
        }
        while(i < n - 1);
    }
    while(swap_counter != 0);
    return array[n-1];
}




























//{
//     int l = 0 ;
  //   for(int j = 0 ; j < n ; j++)
    // {
    //     printf("int %i\n", array[j]);
  //   }
//
 //   if (array[i] > array[i+1])
  //  {
 //       printf("%i,%i\n", array[i], array[i + 1]);
  //      int k = array[i];
    //    array[i] = array[i + 1];
      //  array[i + 1] = k;
        //swap_counter++;
        //printf("%i,%i\n", array[i], array[i + 1]);
    //}
    //if (i == n - 2)
   // {
   //     if (swap_counter == 0)
  //      {
  //          for(int j = 0 ; j < n ; j++)
 //           {
 //               printf("int %i\n", array[j]);
//            }
  //          return array[n - 1] ;
//
  //      }
    //    else
      //  swap_counter = 0;
        //i = 0;
      //  l++;
    //}

   // max(array, n, i + 1, swap_counter);

//}
