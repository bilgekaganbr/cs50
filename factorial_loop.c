#include <cs50.h>
#include <stdio.h>

int fact(int n);

int main(void)
{
    int n = get_int("n: ");
    printf("Factorial: %i\n", fact(n));
}

int fact(int n)
{
    int factorial = 1;

    while (n > 0)
    {
        factorial *= n;
        n--;
    }
    return factorial;
}