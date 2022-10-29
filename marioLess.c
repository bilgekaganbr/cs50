#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;

    do
    {
        height = get_int("Enter the height of the pyramid(between 1 and 8): ");
    }
    while (height < 1 || height > 8);

    // Building rows
    for (int i = 1; i <= height; i++)
    {
        //Building columns with space. If we imagine a square, we would need as many hash symbols in each row
        //as the number of that row and enough space to complete the size of the square. That is height minus number row or number
        //of hash symbols.
        for (int j = 1; j <= height - i; j++)
        {
            printf(" ");
        }
        //In each row, we would need as many hash symbols as the number of that row. So, if our loop for hash symbols runs up to the
        //row number, we get our goal.
        for (int k = 1; k <= i; k++)
        {
            printf("#");
        }
        //Next row
        printf("\n");
    }
    //Ps: Sorry if I couldn't explain myself :)

}