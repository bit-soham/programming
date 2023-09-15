 #include <stdio.h>
 #include <cs50.h>

 int main(void)
 {
   // printing powers of 2
    int i = get_int("Size: ");
    int power[i];
    power[0] = 1;
    for (int p = 1 ; p <= i ; p++)
    {
    power[p] = power[p-1] * 2 ;
    printf("%i\n", power[p-1]);
    }
 }

