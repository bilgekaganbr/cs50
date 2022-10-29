#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;

    //The user is asked the height of the pyramid
    do
    {
        height = get_int("Enter the height of the pyramid(between 1 and 8): ");
    }

    //Constraints
    while (height < 1 || height > 8);

    //Building rows
    for (int i = 1; i <= height; i++)
    {

        //Spaces before the first half of the pyramid
        for (int j = 1; j <= height - i; j++)
        {
            printf(" ");
        }

        //The first half of the pyramid
        for (int k = 1; k <= i; k++)
        {
            printf("#");
        }

        //Space between the two halves of the pyramid
        printf(" ");

        //The second half of the pyramid
        for (int l = 1; l <= i; l++)
        {
            printf("#");
        }

        //The next row
        printf("\n");
    }
}