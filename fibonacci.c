#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n = get_int("n: ");
    int fib[n - 1];

    fib[0] = 1;
    fib[1] = 1;

    for (int i = 2; i < n; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    for (int i = 0; i < n; i++)
    {
        printf("%i ", fib[i]);
    }
    printf("\n");
}

