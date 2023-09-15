#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    /// but here if the list has to be updated and gets longer and longer
    /// the phone no. , name may not be sychronized something might get misplaced
    /// i has to be updated
    // with below code
    //string names[] = {"Carter", "David"};
    //string numbers[] = {"+1-617-495-100", "+1-949-468-2750"};
    typedef struct
    {
        string name;
        string number;

    }
    person;

    // an array with datatype person
    person people[2];

    // how to enter data into it
    people[0].name = "carter";
    people[0].number = "+1-617-495-1000";
    people[1].name = "David";
    people[1].number = "+1-434-245-1330";



    string name = get_string("Name: ");
    for (int i = 0 ; i < 2 ; i++)
    {
            // STRCMP CHECKS IF STRINGS ARE SAME(0) OR NOT(1,2,3,...)
        if (strcmp(people[i].name,name) == 0) //imp
        {
            printf("Found %s\n", people[i].number);//imp
            return 0;
        }

    }
    {
        printf("Not found\n");
        return 1;
    }
}