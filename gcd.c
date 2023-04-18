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
    if (m % n == 0)
    {
        return n;
    }
    else
        return gcd(n, m % n);
}
