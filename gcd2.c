#include <stdio.h>

int gcd(int a, int b);

int main()
{
    int a, b;
    printf("Enter a, b: ");
    scanf("%d", &a);
    scanf("%d", &b);
    printf("Gcd of %d, %d: %d", a, b, gcd(a, b));
}

int gcd(int m, int n)
{
    int rem;
    while (n > 0)
    {
        rem = m % n;
        m = n;
        n = rem;
    }
    return m;
}
