#include <cs50.h>
#include <stdio.h>
void draw(int n);

int main(void)
{
    int hieght = get_int("Hieght:");
    draw(hieght);
}

void draw(int n)
{
     if(n <= 0)
     {
        return; // return means only this function will end which is draw(0), draw(-1)
     }
              // here for ex you put hieght 2 then n=2
    draw(n-1); // 1 here we initiate  draw(1) and proceed down later after excuting draw(1)
               // on excecuting draw(0) n=0 the draw(0)function is terminated but in line 1  we proceed down
    for(int i = 0 ; i < n ; i++) // and here draw with n = 1  this '#' now as in line 1 draw(1) is executed and we
                                // now execute rest part of draw(2) function with n = 2 printing '##'
    {
         printf("#");
    }
    printf("\n");

}