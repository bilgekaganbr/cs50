#include <stdio.h>
#include <cs50.h>

bool valid_triangle(float a, float b, float c);

int main(void)
{
    float a = get_float("a: ");
    float b = get_float("b: ");
    float c = get_float("c: ");

    bool validity = valid_triangle(a, b, c);

    if (validity == true)
    {
        printf("The triangle is valid\n");
    }
    else
    {
        printf("The triangle is not valid\n");
    }

}

bool valid_triangle(float a, float b, float c)
{
    if (a > 0 && b > 0 && c > 0)
    {
        if ((a + b > c) && (a + c > b) && (b + c > a))
        {
            return true;
        }
        else
        {
            return false;
        }

    }

    else
    {
        return false;
    }
}