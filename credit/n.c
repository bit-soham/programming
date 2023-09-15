#include <cs50.h>
#include <stdio.h>
int get_sum(long int n,long inti);
void print_carddata(int s,long int n,long int o,int count);
int main(void)
{
    int count = 0;
    int sum = 0;
    long int i = 1;
    long int o = 1 ;
    long int n = get_long("What's your credit card No.: ");
   //Finding Luhn's sum
   int s = get_sum(n,i);

   // Finding No. of digits
    do
    {
       count++;
        o*=10;
    }
    while(n % (o) != n );

    // printing type of card or if card is INVALID
    print_carddata(s,n,o,count);



}








int get_sum(long int n, long int i)
{
int sum = 0;
do
   {
    int x = (n % (10*i)) /i ;

    int y = (n % (100*i)) /(10*i) ;

    i = i*100;

    int z = y*2;
    if(z > 9)
    {
        z = z/10 + z%10 ;
    }
    sum = sum + z + x;

   }
    while (n % i != n);
    return sum;
}


void print_carddata(int s,long int n,long int o,int count)
{
    if(s % 10 != 0)
    {
        printf("INVALID\n");
    }
    else if((count == 13 || count == 16) && (n % (o)-n % (o/10) == 4*(o/10)) )
    {
        printf("VISA\n");
    }
    else if((count == 16) && (n % (o) - n % (o/100) >= 51*(o/100)) && (n % (o) - n % (o/100) <= 55*(o/100) ))
    {
        printf("MASTERCARD\n");
    }
    else if((count == 15) && (n % o - n % (o/100) == 34*(o/100) || n % o - n % (o/100) == 37*(o/100) ))
    {
        printf("AMEX\n");
    }
}