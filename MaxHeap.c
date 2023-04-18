#include <stdio.h>

void Heapify(int A[], int n);
void AdjustMax(int A[], int i, int n);

int main()
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    int A[n + 1];
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &A[i]);
    }
    Heapify(A, n);

    for (int i = 1; i <= n; i++)
    {
        printf("%d ", A[i]);
    }

    return 0;
}

void Heapify(int A[], int n)
{
    for (int i = n / 2; i >= 1; i--)
    {
        AdjustMax(A, i, n);
    }
}

void AdjustMax(int A[], int i, int n)
{
    int j = 2 * i;
    int item;
    item = A[i];
    while (j <= n)
    {
        if ((j < n) && (A[j] < A[j + 1]))
        {
            j = j + 1;
        }
        if (item >= A[j])
            break;
        A[j / 2] = A[j];
        j = 2 * j;
    }
    A[j / 2] = item;
}
