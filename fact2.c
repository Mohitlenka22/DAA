#include <stdio.h>

int fact(int n);

int main()
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    if (n < 0)
    {
        printf("Factorial doesn't exist for %d.", n);
    }
    else
    {
        printf("Factorial of %d is %d.", n, fact(n));
    }

    return 0;
}

int fact(int n)
{
    if (n == 0)
        return 1;
    else
        return n * fact(n - 1);
}