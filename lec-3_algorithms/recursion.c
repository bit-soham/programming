 #include <cs50.h>
 #include <stdio.h>
void draw(int n);
int main(void)
// but this will be an infinite loop
{
    // '1'is inside () therefore it is a input to the fxn draw
    draw(1);// here 1 is like the input which is equated to int n
             // like how here
             // int hieght = get_int("Hieght: ");
             //draw(hieght);
}

void draw(int n) // int n is the input given to the draw fxn or the argument the fxn recieves
{
    for (int i = 0 ; i < n ; i++)
    {
        printf("#");
    }
    printf("\n");
    draw(n + 1);// here as n is equated to 1 here now we recursivly or again use draw function with draw(1+1) = draw(2)
               // therefore we repeat the entire draw function now by equating int n to 2 now

}








































//purana method
 //void draw(int n);

 //int main(void)
 //{
      // int hieght = get_int("Hieght: ");
      //draw(hieght);
  //}


//void draw(int n)
 //{
   // for (int i = 0; i < n ; i++)
    //{
       //  for (int j = 0 ; j < i+1; j++)
        //{
          //  printf("#");
        //}
        //printf("\n");
    //}
 //}